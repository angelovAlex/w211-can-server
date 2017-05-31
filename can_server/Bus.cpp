//
//  BusB.cpp
//  can_server
//
//  Created by Alex Angelov on 26/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Bus.hpp"
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "Parser.hpp"
#include "Diag.hpp"
#include "Utils.hpp"
#include "Simulators.hpp"

void BusB::setFd(int fd, Parser *parser)
{
    this->fd = fd;
    this->parser = parser;
    this->parser->BusB = this;
}

void BusB::send(CANMSG msg)
{
    char buf[100];
    sprintf(buf, "r %d %d %x %x %x %x %x %x %x %x\n", msg.address, msg.len, msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7]);
    size_t len = strlen(buf);
    ssize_t wrote = write(this->fd, buf, len);
    //printf("-> %s", buf);
    //usleep(100);
}

void BusB::receive_raw(char *str, ssize_t len)
{
    this->parser->parse_string(str, len);
}

void BusB::receive(CANMSG msg)
{
    //received a msg
    
    bool parsed = false;
    if (!parsed) parsed = unit_kombi.parse(msg);
    if (!parsed) parsed = unit_sam_v.parse(msg);
    if (!parsed) parsed = unit_dbe.parse(msg);
    if (!parsed) parsed = unit_ezs.parse(msg);
    if (!parsed) parsed = unit_tvl.parse(msg);
    if (!parsed) parsed = unit_tvr.parse(msg);
    
    if (!parsed) Utils::print_msg(msg);
}

void BusB::loop(float time)
{
    Diag::global_session().loop(time);  //when enabled, sends global diag session package every second
    AGW_Simulator::global().loop(time); //when enabled simulates AGW, DON'T USE IN REAL CAR
    
    features_windows.loop(this, time);
    
    if (Utils::every(time, &every_second, 1.0)) {
        printf("temp: %f\n", unit_sam_v.outside_temp);
        printf("ouside temp: %f\n", unit_dbe.inside_temp);
    }
}
