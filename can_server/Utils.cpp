//
//  Utils.cpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Utils.hpp"

bool Utils::every(float time, float *last, float every)
{
    if (time - *last > every) {
        *last = time;
        return true;
    }
    return false;
}

void Utils::print_msg(CANMSG msg)
{
    printf("%u %x %u ", msg.time, msg.address, msg.len);
    if (msg.len >= 0) printf("%02x ", msg.data[0]);
    if (msg.len >= 1) printf("%02x ", msg.data[1]);
    if (msg.len >= 2) printf("%02x ", msg.data[2]);
    if (msg.len >= 3) printf("%02x ", msg.data[3]);
    if (msg.len >= 4) printf("%02x ", msg.data[4]);
    if (msg.len >= 5) printf("%02x ", msg.data[5]);
    if (msg.len >= 6) printf("%02x ", msg.data[6]);
    if (msg.len >= 7) printf("%02x ", msg.data[7]);
    printf("\n");
}

void Utils::parse_param(CANMSG_param *param, uint8_t *bytes, bool output)
{
    uint32_t val2 = (bytes[4] << 24) | (bytes[5] << 16) | (bytes[6] << 8) | (bytes[7]);
    uint32_t val1 = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | (bytes[3]);
    uint32_t new_val = 0;
    
    if (param->offset + param->len < 32) {
        new_val = val1 << param->offset;
    } else if (param->offset >= 32) {
        new_val = val2 << (param->offset - 32);
    } else {
        new_val = (val1 << param->offset) | (val2 >> (32 - param->offset));
    }
    new_val = new_val >> (32 - param->len);
    param->val = new_val;
    if (output) {
        printf("%s: %llu\n", param->en_desc.c_str(), param->val);
    }
}
