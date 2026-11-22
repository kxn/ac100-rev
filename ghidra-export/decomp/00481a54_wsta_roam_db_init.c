// func wsta_roam_db_init @ 00481a54 size=848

/* WARNING: Removing unreachable block (ram,0x00481a84) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 wsta_roam_db_init(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *__format;
  
  iVar1 = wsta_profile_get_max_wstation();
  uVar2 = wsta_profile_get_max_wstation();
  max_roam_sta = uVar2 / 0x14 + iVar1;
  l_wsta_roam_data = FUN_00407f00("wsta_roam_mutex",1);
  if (l_wsta_roam_data == 0) {
    if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
    __format = "[WSTA_ROAM_ERROR]%s()/%d Create database mutex failed.\n";
    uVar3 = 0x231;
  }
  else {
    DAT_00767544 = FUN_004080e0(max_roam_sta);
    if (DAT_00767544 == 0) {
      if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
      __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
      uVar3 = 0x239;
    }
    else {
      DAT_00767548 = FUN_004082a0(max_roam_sta,0x4c,0x23d);
      if (DAT_00767548 == 0) {
        if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
        __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
        uVar3 = 0x240;
      }
      else {
        uVar3 = wsta_profile_get_max_wstation();
        DAT_0076754c = FUN_004080a0(_wsta_roam_pmk_mac_obj,_wsta_roam_pmk_mac_key,
                                    _wsta_roam_pmk_mac_cmp,uVar3);
        if (DAT_0076754c == 0) {
          if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
          __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
          uVar3 = 0x24a;
        }
        else {
          DAT_00767554 = FUN_00408340(0x3c,0,_wsta_roam_pmk_idle_timer_handle,0,0,
                                      "wsta_roam_db_init",0x24e);
          if (DAT_00767554 == -1) {
            if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
            uVar3 = 0x251;
            __format = "[WSTA_ROAM_ERROR]%s()/%d uac_timer_add() fail!\n";
          }
          else {
            uVar3 = apmngr_db_get_ap_max();
            DAT_00767558 = FUN_004082a0(uVar3,0x28,0x256);
            if (DAT_00767558 == 0) {
              if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
              __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
              uVar3 = 0x259;
            }
            else {
              DAT_0076755c = FUN_004082a0(1,0x78,0x25c);
              if (DAT_0076755c == 0) {
                if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
                __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
                uVar3 = 0x25f;
              }
              else {
                uVar3 = wsta_profile_get_max_wstation();
                DAT_00767560 = FUN_004080a0(_wsta_roam_sta_rcd_mac_obj,_wsta_roam_sta_rcd_mac_key,
                                            _wsta_roam_sta_rcd_mac_cmp,uVar3);
                if (DAT_00767560 == 0) {
                  if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
                  __format = "[WSTA_ROAM_ERROR]%s()/%d no memory!\n";
                  uVar3 = 0x269;
                }
                else {
                  DAT_00767564 = FUN_00408340(0x3c,0,_wsta_roam_sta_tmprcd_idle_timer_handle,0,0,
                                              "wsta_roam_db_init",0x26d);
                  if (DAT_00767564 == -1) {
                    if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
                    __format = "[WSTA_ROAM_ERROR]%s()/%d uac_timer_add() fail!\n";
                    uVar3 = 0x270;
                  }
                  else {
                    iVar1 = _wsta_roam_read_config();
                    if (iVar1 == 0) {
                      stats_db_ctl_rssi_register(_wsta_roam_rssi_switch,_wsta_roam_rssi_interval);
                      stats_db_ctl_rssi_update();
                      _high_per_ap_chn_info = 0;
                      _DAT_00767570 = 0;
                      return 0;
                    }
                    if (wsta_roam_err_switch == '\0') goto LAB_00481c48;
                    __format = "[WSTA_ROAM_ERROR]%s()/%d _wsta_roam_read_config_from_uci() fail!\n";
                    uVar3 = 0x278;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf(__format,"wsta_roam_db_init",uVar3);
LAB_00481c48:
  wsta_roam_db_uninit();
  return 0xffffffff;
}

