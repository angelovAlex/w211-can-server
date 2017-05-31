//
//  Features.cpp
//  can_server
//
//  Created by Alex Angelov on 31/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Features.hpp"
#include "Bus.hpp"
#include "Utils.hpp"


#define W_LF 0b00010000
#define W_RF 0b00100000
#define W_ALL 0b11110000
#define W_OPEN 0x0
#define W_CLOSE 0b00000100
#define W_AUTO 0b00000010
#define W_MAN 0b00000000
#define W_TEST 0b00001000

void Feature_Windows::loop(BusB *bus, float time) {
    
    //start opening window on unlock command
    if (bus->unit_ezs.signal_ezs_a1.TVL_ENTRI.val == 1 &&
        bus->unit_dbe.inside_temp > 25.0 &&
        //unit_sam_v.outside_temp < 29 &&
        (bus->unit_tvl.signal_tvl_a3.FESTE_VL.val < 500 || bus->unit_tvr.signal_tvr_a3.FESTE_VR.val < 500)) {
        open_windows_on_unlock_when_hot.keep_opening_window = true;
    }
    
    //keep opening window until we opened it
    if (open_windows_on_unlock_when_hot.keep_opening_window == true) {
        if (Utils::every(time, &open_windows_on_unlock_when_hot.last_window_control_package_sent, 0.02)) {
            uint8_t val = 0;
            if (bus->unit_tvl.signal_tvl_a3.FESTE_VL.val < 500) {
                val = W_LF;
            }
            if (bus->unit_tvr.signal_tvr_a3.FESTE_VR.val < 500) {
                val |= W_RF;
            }
            if (val > 0) {
                bus->send(CANMSG(80, 1, val | W_OPEN));
            } else {
                open_windows_on_unlock_when_hot.keep_opening_window = false;
            }
        }
    }
    
    //start closing window on lock command
    if (bus->unit_ezs.signal_ezs_a1.TVL_VERRI.val == 1 &&
        (bus->unit_tvl.signal_tvl_a3.FESTE_VL.val > 100 || bus->unit_tvr.signal_tvr_a3.FESTE_VR.val > 100)) {
        close_windows_on_lock.keep_closing_window = true;
    }
    
    //keep closing windows until it's closed
    if (close_windows_on_lock.keep_closing_window == true) {
        if (Utils::every(time, &open_windows_on_unlock_when_hot.last_window_control_package_sent, 0.02)) {
        
            uint8_t val = 0;
            if (bus->unit_tvl.signal_tvl_a3.FESTE_VL.val > 150) {
                val = W_LF;
            }
            if (bus->unit_tvr.signal_tvr_a3.FESTE_VR.val > 150) {
                val = W_RF;
            }
            if (val > 0) {
                bus->send(CANMSG(80, 1, val | W_CLOSE));
            } else {
                close_windows_on_lock.keep_closing_window = false;
            }
        }
    }

}
