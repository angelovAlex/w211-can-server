//
//  BusB.hpp
//  can_server
//
//  Created by Alex Angelov on 26/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef BusB_hpp
#define BusB_hpp

#include <iostream>
#include "CANMSG.hpp"
#include "Units.hpp"
#include "Features.hpp"


class Parser;
class BusB {
    
    int fd;
    Parser *parser;
    
public:
    Unit_Kombi unit_kombi = Unit_Kombi();
    Unit_SAM_V unit_sam_v = Unit_SAM_V();
    Unit_DBE   unit_dbe = Unit_DBE();
    Unit_EZS   unit_ezs = Unit_EZS();
    Unit_TVL   unit_tvl = Unit_TVL();
    Unit_TVR   unit_tvr = Unit_TVR();
    Unit_THL   unit_thl = Unit_THL();
    Unit_THR   unit_thr = Unit_THR();
    Unit_KLA   unit_kla = Unit_KLA();
    
    Feature_Windows features_windows = Feature_Windows();
    
    float every_second = 0;
    
    static BusB& b()
    {
        static BusB canB;
        return canB;
    }
    void setFd(int fd, Parser *parser);
    void receive_raw(char *str, unsigned int len);
    
    void send(CANMSG msg);
    void receive(CANMSG msg);
    void loop(float time);
};

#endif /* BusB_hpp */
