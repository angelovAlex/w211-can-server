//
//  Simulators.hpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Simulators_hpp
#define Simulators_hpp

#include <iostream>
#include "CANMSG.hpp"


class AGW_Simulator {
    float agw_package_last_sent = 0;
    
public:
    static AGW_Simulator& global()
    {
        static AGW_Simulator sim;
        return sim;
    }
    bool enabled = false;
    
    void receive(CANMSG msg);
    void loop(float time);
};

#endif /* Simulators_hpp */
