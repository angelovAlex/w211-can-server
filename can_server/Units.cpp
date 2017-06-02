//
//  Units.cpp
//  can_server
//
//  Created by Alex Angelov on 27/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Units.hpp"
#include "Utils.hpp"

bool Unit_KLA::parse(CANMSG msg)
{
    if (msg.address == signal_kla_a1.id) {
        Utils::parse_param(&signal_kla_a1.ABVENT_W_ZU, msg.data);
        Utils::parse_param(&signal_kla_a1.DEFROST_AKT, msg.data);
        Utils::parse_param(&signal_kla_a1.EC_AKT, msg.data);
        Utils::parse_param(&signal_kla_a1.GEB_LSTG, msg.data);
        Utils::parse_param(&signal_kla_a1.HEIZEN, msg.data);
        Utils::parse_param(&signal_kla_a1.HHS_EIN, msg.data);
        Utils::parse_param(&signal_kla_a1.IFG_EIN, msg.data);
        Utils::parse_param(&signal_kla_a1.KJAL_ZU, msg.data);
        Utils::parse_param(&signal_kla_a1.KOMP_STELL, msg.data);
        Utils::parse_param(&signal_kla_a1.LKM_VORN, msg.data);
        Utils::parse_param(&signal_kla_a1.LKO_VORN, msg.data);
        Utils::parse_param(&signal_kla_a1.LKU_VORN, msg.data);
        Utils::parse_param(&signal_kla_a1.LL_DZA, msg.data);
        Utils::parse_param(&signal_kla_a1.LUEFTEN, msg.data);
        Utils::parse_param(&signal_kla_a1.M_KOMP, msg.data);
        Utils::parse_param(&signal_kla_a1.NLFTS, msg.data);
        Utils::parse_param(&signal_kla_a1.REST_AKT, msg.data);
        Utils::parse_param(&signal_kla_a1.T_INNEN_KLA, msg.data);
        Utils::parse_param(&signal_kla_a1.UL_AKT_KLA, msg.data);
        Utils::parse_param(&signal_kla_a1.ZH_ANF, msg.data);
        Utils::parse_param(&signal_kla_a1.ZH_EIN_OK, msg.data);
        Utils::parse_param(&signal_kla_a1.ZWP_EIN, msg.data);
        return true;
    } else if (msg.address == signal_kla_a2.id) {
        Utils::parse_param(&signal_kla_a2.FHL_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.FHR_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.FVL_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.FVR_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.KB_MOD_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.KB_RI_KLA, msg.data);
        Utils::parse_param(&signal_kla_a2.SHD_KLA, msg.data);
        return true;
    } else if (msg.address == signal_kla_a3.id) {
        Utils::parse_param(&signal_kla_a3.T_TAU, msg.data);
        return true;
    } else if (msg.address == signal_kla_a5.id) {
        Utils::parse_param(&signal_kla_a5.HZL_ANF, msg.data);
        Utils::parse_param(&signal_kla_a5.T_AUSSEN_WM, msg.data);
        return true;
    }
    return false;
}

bool Unit_TVR::parse(CANMSG msg)
{
    if (msg.address ==  signal_tvr_a3.id) {
        Utils::parse_param(&signal_tvr_a3.FESTE_VR, msg.data);
        //printf("window position %llu\n", signal_tvl_a3.FESTE_VL.val);
        return true;
    }
    return false;
}

bool Unit_TVL::parse(CANMSG msg)
{
    if (msg.address ==  signal_tvl_a3.id) {
        Utils::parse_param(&signal_tvl_a3.FESTE_VL, msg.data);
        //printf("window position %llu\n", signal_tvl_a3.FESTE_VL.val);
        return true;
    }
    return false;
}

bool Unit_THL::parse(CANMSG msg)
{
    if (msg.address ==  signal_thl_a1.id) {
        Utils::parse_param(&signal_thl_a1.FESTE_HL, msg.data);
        //printf("window position %llu\n", signal_tvl_a3.FESTE_VL.val);
        return true;
    }
    return false;
}

bool Unit_THR::parse(CANMSG msg)
{
    if (msg.address ==  signal_thr_a1.id) {
        Utils::parse_param(&signal_thr_a1.FESTE_HR, msg.data);
        //printf("window position %llu\n", signal_tvl_a3.FESTE_VL.val);
        return true;
    }
    return false;
}

bool Unit_EZS::parse(CANMSG msg)
{
    if (msg.address ==  signal_ezs_a1.id) {
        Utils::parse_param(&signal_ezs_a1.TVL_ENTRI, msg.data);
        Utils::parse_param(&signal_ezs_a1.TVL_VERRI, msg.data);
        //printf("door lock %llu\n", signal_ezs_a1.TVL_VERRI.val);
        return true;
    }
    return false;
}


bool Unit_DBE::parse(CANMSG msg)
{
    if (msg.address ==  signal_dbe_a1.id) {
        Utils::parse_param(&signal_dbe_a1.T_INNEN, msg.data);
        inside_temp = (signal_dbe_a1.T_INNEN.val >> 2) + (signal_dbe_a1.T_INNEN.val & 0x3) * 0.25;
        return true;
    }
    return false;
}

bool Unit_SAM_V::parse(CANMSG msg)
{
    if (msg.address == signal_sam_v_a2.id) {
        Utils::parse_param(&signal_sam_v_a2.I_KOMP, msg.data);
        Utils::parse_param(&signal_sam_v_a2.P_KAELTE, msg.data);
        Utils::parse_param(&signal_sam_v_a2.T_AUSSEN_B, msg.data);
        Utils::parse_param(&signal_sam_v_a2.T_KAELTE, msg.data);
        outside_temp = float(signal_sam_v_a2.T_AUSSEN_B.val / 2.0) - 40.0;
        return true;
    }
    return false;
}

bool Unit_Kombi::parse(CANMSG msg)
{
    if (msg.address == signal_kombi_a1.id) {
        
        return true;
    } else if (msg.address == signal_kombi_a2.id) {
        Utils::parse_param(&signal_kombi_a2.TAGE_ZAHL, msg.data);
        Utils::parse_param(&signal_kombi_a2.JAHR, msg.data);
        Utils::parse_param(&signal_kombi_a2.MONAT, msg.data);
        Utils::parse_param(&signal_kombi_a2.TAG, msg.data);
        return true;
    } else if (msg.address == signal_kombi_a7.id) {
        return true;
    } else if (msg.address == signal_nm_kombi.id) {
        return true;
    } else if (msg.address == signal_kombi_a6.id) {
        Utils::parse_param(&signal_kombi_a6.KM_KI, msg.data);
        Utils::parse_param(&signal_kombi_a6.SCHLUE_ID_KI, msg.data);
        return true;
    }
    return false;
}
