//
//  main.cpp
//  can_server
//
//  Created by Alex Angelov on 26/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "Parser.hpp"
#include "Bus.hpp"
#include <sys/time.h>
#include "Simulators.hpp"


int set_interface_attribs (int fd, int speed, int parity)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
        printf ("error %d from tcgetattr\n", errno);
        return -1;
    }
    
    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);
    
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
    
    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;
    
    if (tcsetattr (fd, TCSANOW, &tty) != 0)
    {
        printf ("error %d from tcsetattr\n", errno);
        return -1;
    }
    return 0;
}

void
set_blocking (int fd, int should_block)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
        printf ("error %d from tggetattr\n", errno);
        return;
    }
    
    tty.c_cc[VMIN]  = should_block ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    
    if (tcsetattr (fd, TCSANOW, &tty) != 0)
        printf ("error %d setting term attributes\n", errno);
}

int main(int argc, const char * argv[]) {
    char *portname = "/dev/cu.wchusbserial1420";
    
    
    AGW_Simulator::global().enabled = false;
    
    
    int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        CANMSG msg = CANMSG(0x0038, 5, 0x13, 0x28, 0x04, 0x03, 0x02, 0x00);
        BusB::b().receive(msg);
        
        printf("error %d opening %s: %s\n", errno, portname, strerror (errno));
        return 0;
    }
    
    set_interface_attribs (fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
    set_blocking (fd, 0);                // set no blocking
    
    Parser parser = Parser();
    BusB::b().setFd(fd, &parser);
    
    char buf [1000];
    ssize_t n;
    struct timeval begin;
    gettimeofday(&begin, NULL);
    unsigned long long begin_time = begin.tv_sec * 1000000LL + begin.tv_usec;
    
    struct timeval end;
    float time;
    while (true) {
        gettimeofday(&end, NULL);
        time = ((end.tv_sec * 1000000LL + end.tv_usec) - begin_time)/1000000.0;
        BusB::b().loop(time);
        n = read (fd, buf, sizeof buf);
        if (n > 0){
            buf[n] = '\0';
            BusB::b().receive_raw(buf, n);
        }
    }
    
    return 0;
}
