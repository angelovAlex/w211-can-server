//
//  Utils.hpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include "CANMSG.hpp"

class Utils {
public:
    static bool every(float time, float *last, float every);
    static void print_msg(CANMSG msg);
    static void parse_param(CANMSG_param *param, uint8_t *bytes, bool output = false);
};

#define CAN_D_RQ_GLOBAL_ID 0x001c
#define CAN_D_RQ_GLOBAL_DESC "Global KWP2000 diagnostic request"

#endif /* Utils_hpp */
