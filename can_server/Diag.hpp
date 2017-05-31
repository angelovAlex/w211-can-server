//
//  Diag.hpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Diag_hpp
#define Diag_hpp

#include <iostream>

class Diag {
    
    float diag_keep_alive_last_sent = 0;
    bool enabled = false;
    
    public:
    static Diag& global_session()
    {
        static Diag canB;
        return canB;
    }
    
    void start();
    void stop();
    void loop(float time);
};

#endif /* Diag_hpp */
