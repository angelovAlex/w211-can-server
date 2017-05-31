//
//  Features.hpp
//  can_server
//
//  Created by Alex Angelov on 31/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Features_hpp
#define Features_hpp

#include <stdio.h>

class BusB;
class Feature_Windows {
    
public:
    struct s1 {
        bool enabled = true;
        float last_window_control_package_sent = 0;
        bool keep_opening_window = false;
    } open_windows_on_unlock_when_hot;
    
    struct s2 {
        bool enabled = true;
        float last_window_control_package_sent = 0;
        bool keep_closing_window = false;
    } close_windows_on_lock;
    
    void loop(BusB *bus, float time);
};

#endif /* Features_hpp */
