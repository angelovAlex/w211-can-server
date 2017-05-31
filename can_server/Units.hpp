//
//  Blocks.hpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Units_hpp
#define Units_hpp

#include <iostream>
#include <string>
#include "CANMSG.hpp"



class Unit_TVL {
public:
    struct Signal_TVL_A3 {
        
        uint32_t id = 0x0018;
        
        CANMSG_param FESTE_VL = CANMSG_param("FESTE_VL", "1/Ankerumdre", "Front left window position", 12, 12);
        //...and so on
    } signal_tvl_a3;
    
    bool parse(CANMSG msg);
};

class Unit_TVR {
public:
    struct Signal_TVR_A3 {
        
        uint32_t id = 0x0019;
        
        CANMSG_param FESTE_VR = CANMSG_param("FESTE_VR", "1/Ankerumdre", "Front right window position", 12, 12);
        //...and so on
    } signal_tvr_a3;
    
    bool parse(CANMSG msg);
};

class Unit_EZS {
public:
    struct Signal_EZS_A1 {
        
        uint32_t id = 0x0000;
        
        CANMSG_param TVL_ENTRI = CANMSG_param("TVL_ENTRI", "", "Release front left door", 47, 1);
        CANMSG_param TVL_VERRI = CANMSG_param("TVL_VERRI", "", "Lock front left door", 46, 1);
        //...and so on
    } signal_ezs_a1;
    
    bool parse(CANMSG msg);
};

class Unit_DBE {
public:
    struct Signal_DBE_A1 {
        
        uint32_t id = 0x0014;
        CANMSG_param T_INNEN = CANMSG_param("T_INNEN", "°C", "internal temperature, offset", 8, 8);
        //...and so on
    } signal_dbe_a1;
    
    float inside_temp = -999;
    
    bool parse(CANMSG msg);
};

class Unit_SAM_V {
public:
    struct Signal_SAM_V_A2 {
        uint32_t id = 0x0017;
        uint32_t every_ms = 0;
        CANMSG_param T_AUSSEN_B = CANMSG_param("T_AUSSEN_B", "°C", "Outside air temperature", 0, 8);
        CANMSG_param P_KAELTE = CANMSG_param("P_KAELTE", "bar", "Pressure refrigerant R134a", 8, 16);
        CANMSG_param T_KAELTE = CANMSG_param("T_KAELTE", "°C", "Temperature of refrigerant R134a", 24, 16);
        CANMSG_param I_KOMP = CANMSG_param("I_KOMP", "mA", "Current compressor main control valve", 40, 8);
    } signal_sam_v_a2;
    
    float outside_temp = -999;
    
    bool parse(CANMSG msg);
};

class Unit_Kombi {
    
public:
    struct Signal_KOMBI_A1 {
        uint32_t id = 0x000c;
        uint32_t every_ms = 50;
        CANMSG_param KL_58D_B = CANMSG_param("KL_58D_B", "%", "Brightness instrument lighting", 0, 8);
        CANMSG_param V_SIGNAL = CANMSG_param("V_SIGNAL", "km/h", "vehicle speed", 8, 8);
        CANMSG_param SP_PARK_SPERR = CANMSG_param("SP_PARK_SPERR", "", "Mirror in parking position", 23, 1);
        //...and so on
    } signal_kombi_a1;
    
    struct Signal_KOMBI_A2 {
        uint32_t id = 0x0038;
        uint32_t every_ms = 1000;
        CANMSG_param TAGE_ZAHL = CANMSG_param("TAGE_ZAHL", "Tage", "Daily circulation payers", 0, 16);
        CANMSG_param TAG = CANMSG_param("TAG", "Tage", "Day", 16, 8);
        CANMSG_param MONAT = CANMSG_param("MONAT", "Monate", "month", 24, 8);
        CANMSG_param JAHR = CANMSG_param("JAHR", "Jahre", "year", 32, 8);
    } signal_kombi_a2;
    
    struct Signal_KOMBI_A7 {
        uint32_t id = 0x0194;
        uint32_t every_ms = 200;
        CANMSG_param DISP_DIMM = CANMSG_param("DISP_DIMM", "%", "Display Dimming", 0, 8);
        CANMSG_param KOMBI_MW_OK = CANMSG_param("KOMBI_MW_OK", "", "Combi is multi-value", 15, 1);
        CANMSG_param HD_BEGRENZ = CANMSG_param("HD_BEGRENZ", "", "Rear lid restraint on", 10, 1);
    } signal_kombi_a7;
    
    struct Signal_NM_KOMBI {
        uint32_t id = 0x0414;
        uint32_t every_ms = 1000;
        CANMSG_param DISP_DIMM = CANMSG_param("NM", "", "Network Management", 0, 64);
    } signal_nm_kombi;
    
    struct Signal_KOMBI_A6 {
        uint32_t id = 0x009e;
        uint32_t every_ms = 1000;
        CANMSG_param SCHLUE_ID_KI = CANMSG_param("SCHLUE_ID_KI", "", "Key from COMBI", 0, 32);
        CANMSG_param KM_KI = CANMSG_param("KM_KI", "km", "The distance traveled from KOMBI", 32, 24);
    } signal_kombi_a6;
    
    
    
    bool parse(CANMSG msg);
};


#endif /* Units_hpp */
