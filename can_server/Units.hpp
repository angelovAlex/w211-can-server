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

class Unit_KLA {
public:
    struct Signal_KLA_A1 {
        
        uint32_t id = 0x0030;
        CANMSG_param LUEFTEN = CANMSG_param("LUEFTEN", "", "Heating of the heating system", 7, 1);
        CANMSG_param HEIZEN = CANMSG_param("HEIZEN", "", "Heater heating", 6, 1);
        CANMSG_param LL_DZA = CANMSG_param("LL_DZA", "", "Idle speed boost for cooling performance", 5, 1);
        CANMSG_param ZH_EIN_OK = CANMSG_param("ZH_EIN_OK", "", "Switch on heater", 4, 1);
        CANMSG_param ZWP_EIN = CANMSG_param("ZWP_EIN", "", "Switch on the auxiliary water pump", 3, 1);
        CANMSG_param IFG_EIN = CANMSG_param("IFG_EIN", "", "Switch on the indoor sensor blower", 2, 1);
        CANMSG_param EC_AKT = CANMSG_param("EC_AKT", "", "EC mode is active", 1, 1);
        CANMSG_param HHS_EIN = CANMSG_param("HHS_EIN", "", "Switch on the heated rear window", 0, 1);
        CANMSG_param NLFTS = CANMSG_param("NLFTS", "%", "Engine fan setpoint speed", 8, 8);
        CANMSG_param M_KOMP = CANMSG_param("M_KOMP", "Nm", "Torque input Cooling compressor", 16, 8);
        CANMSG_param KOMP_STELL = CANMSG_param("KOMP_STELL", "%", "Cooling compressor control signal", 24, 8);
        CANMSG_param ZH_ANF = CANMSG_param("ZH_ANF", "Stufen", "Requirement of heating power", 37, 3);
        CANMSG_param ABVENT_W_ZU = CANMSG_param("ABVENT_W_ZU", "", "Close the shut-off valve", 36, 1);
        CANMSG_param KJAL_ZU = CANMSG_param("KJAL_ZU", "", "Close the cooling louvre", 35, 1);
        CANMSG_param REST_AKT = CANMSG_param("REST_AKT", "", "Residual heat mode active", 34, 1);
        CANMSG_param DEFROST_AKT = CANMSG_param("DEFROST_AKT", "", "Defrost mode active", 33, 1);
        CANMSG_param GEB_LSTG = CANMSG_param("GEB_LSTG", "%", "Blower power", 40, 8);
        CANMSG_param LKU_VORN = CANMSG_param("LKU_VORN", "", "Positioning damper at the bottom", 54, 2);
        CANMSG_param LKM_VORN = CANMSG_param("LKM_VORN", "", "Positioning damper center", 52, 2);
        CANMSG_param LKO_VORN = CANMSG_param("LKO_VORN", "", "Positioning flap above", 50, 2);
        CANMSG_param UL_AKT_KLA = CANMSG_param("UL_AKT_KLA", "", "Recirculation active", 48, 1);
        CANMSG_param T_INNEN_KLA = CANMSG_param("T_INNEN_KLA", "°C", "internal temperature", 56, 8);
    
    } signal_kla_a1;
    
    struct Signal_KLA_A2 {
        
        uint32_t id = 0x0250;

        CANMSG_param KB_MOD_KLA = CANMSG_param("KB_MOD_KLA", "", "Mode Comfort control", 6, 1);
        CANMSG_param KB_RI_KLA = CANMSG_param("KB_RI_KLA", "", "Direction comfort control", 5, 1);
        CANMSG_param SHD_KLA = CANMSG_param("SHD_KLA", "", "SHD / top open / close", 4, 1);
        CANMSG_param FVL_KLA = CANMSG_param("FVL_KLA", "", "Open / close the front left window", 3, 1);
        CANMSG_param FVR_KLA = CANMSG_param("FVR_KLA", "", "Open / close the front right window", 2, 1);
        CANMSG_param FHL_KLA = CANMSG_param("FHL_KLA", "", "Open / close the rear left window", 1, 1);
        CANMSG_param FHR_KLA = CANMSG_param("FHR_KLA", "", "Open / close the rear right window", 0, 1);
        
    } signal_kla_a2;
    
    struct Signal_KLA_A3 {
        
        uint32_t id = 0x02d8;
        
        CANMSG_param T_TAU = CANMSG_param("T_TAU", "°C", "dew point temperature", 0, 8);
    } signal_kla_a3;
    
    struct Signal_KLA_A5 {
        
        uint32_t id = 0x00f1;
        
        CANMSG_param HZL_ANF = CANMSG_param("HZL_ANF", "%", "Heating requirement", 0, 8);
        CANMSG_param T_AUSSEN_WM = CANMSG_param("T_AUSSEN_WM", "°C", "Outdoor air temperature for warm management", 8, 8);
    } signal_kla_a5;
    
    bool parse(CANMSG msg);
};

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

class Unit_THL {
public:
    struct Signal_THL_A1 {
        
        uint32_t id = 0x009a;
        
        CANMSG_param FESTE_HL = CANMSG_param("FESTE_HL", "1/Ankerumdre", "Rear left window position", 4, 12);
        //...and so on
    } signal_thl_a1;
    
    bool parse(CANMSG msg);
};

class Unit_THR {
public:
    struct Signal_THR_A1 {
        
        uint32_t id = 0x009c;
        
        CANMSG_param FESTE_HR = CANMSG_param("FESTE_HR", "1/Ankerumdre", "Right rear window position", 12, 12);
        //...and so on
    } signal_thr_a1;
    
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
