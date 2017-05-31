//
//  Diag.cpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Diag.hpp"
#include "Utils.hpp"
#include "Bus.hpp"
#include "CANMSG.hpp"

void Diag::start()
{
    
}

void Diag::stop()
{
    
}

void Diag::loop(float time)
{
    if (!enabled) return;
    if (Utils::every(time, &diag_keep_alive_last_sent, 1.0)) {
        //send canB.sendMsg(0x1c, 8, 0x02, 0x3e, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff);
        BusB::b().send(CANMSG(CAN_D_RQ_GLOBAL_ID, 8, 0x02, 0x3e, 0x02));
    }
}
