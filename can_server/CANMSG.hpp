//
//  CANMSG.hpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef CANMSG_hpp
#define CANMSG_hpp

#include <iostream>

using namespace std;
struct CANMSG_param {
    string name;
    string measure;
    string en_desc;
    uint8_t offset;
    uint8_t len;
    uint64_t val;
    CANMSG_param(string n, string m, string en_d, uint8_t o, uint8_t l, uint64_t v = 0) : name(n), measure(m), en_desc(en_d), offset(o), len(l), val(v) {};
};

class CANMSG {
    
public:
    uint32_t address;
    uint32_t time;
    uint8_t len;
    uint8_t data[8];
    
    CANMSG();
    CANMSG(uint32_t address, uint8_t len, uint8_t data0 = 0, uint8_t data1 = 0, uint8_t data2 = 0, uint8_t data3 = 0, uint8_t data4 = 0, uint8_t data5 = 0, uint8_t data6 = 0, uint8_t data7 = 0);
};

#endif /* CANMSG_hpp */
