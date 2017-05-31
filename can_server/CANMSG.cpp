//
//  CANMSG.cpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "CANMSG.hpp"


CANMSG::CANMSG()
{
    
}

CANMSG::CANMSG(uint32_t address, uint8_t len, uint8_t data0, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7)
{
    this->address = address;
    this->len = len;
    this->data[0] = data0;
    this->data[1] = data1;
    this->data[2] = data2;
    this->data[3] = data3;
    this->data[4] = data4;
    this->data[5] = data5;
    this->data[6] = data6;
    this->data[7] = data7;
}
