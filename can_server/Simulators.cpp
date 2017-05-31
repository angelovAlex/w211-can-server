//
//  Simulators.cpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Simulators.hpp"
#include "Utils.hpp"
#include "Bus.hpp"
#include "CANMSG.hpp"

void AGW_Simulator::receive(CANMSG msg)
{
    if (!enabled) return;
}

void AGW_Simulator::loop(float time)
{
    if (!enabled) return;
    if (Utils::every(time, &agw_package_last_sent, 0.2)) {
        //BusB::b().send(CANMSG(0, 8, 4, 0, 0, 0, 0, 0, 0, 0));  //EZS
        //BusB::b().send(CANMSG(0x16, 1, 0x7f));                 //Battery Voltage
        //BusB::b().send(CANMSG(0x58, 7, 0x78, 0x74, 0xb2, 0x92, 0x27, 0xd3, 0x50)); //odometer
        //BusB::b().send(CANMSG(0x17, 6, 120, 0xff, 0x43, 0x02, 0x1c, 0x00));
        
        
        //{0, tach1, tach2, 0, 0, 86, 150, 62}
        BusB::b().send(CANMSG(0x308, 8, 0, rand()%23 + 5, 0, 0, 86, 150, 62));
        //BusB::b().send(CANMSG(0x212, 8, 128, 32, 32, 32, 32, 32, 32, 32));
        BusB::b().send(CANMSG(0x328, 8, 191, 254, 123, 193, 0, 2, 0, 0));
        BusB::b().send(CANMSG(0x608, 8, 140, 0, 0, 0 ,0 ,10 , 0, 0));
        //BusB::b().send(CANMSG(0x200, 8, 0, 0, 0, 0, 100, 0, 0, 0));
    }
}
