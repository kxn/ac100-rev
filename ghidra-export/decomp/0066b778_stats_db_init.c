// func stats_db_init @ 0066b778 size=1904

/* WARNING: Removing unreachable block (ram,0x0066b808) */

undefined4 stats_db_init(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *__format;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_78 [12];
  char *local_6c;
  undefined4 local_68;
  code *local_60;
  
  iVar1 = wsta_profile_get_max_wstation();
  uVar2 = wsta_profile_get_max_wstation();
  stat_gloabl_data_mutex = FUN_00407f00("stats_global_mutex",1);
  if (stat_gloabl_data_mutex == 0) {
    if (stats_err_switch == '\0') goto LAB_0066babc;
    __format = "[STATISTICS_ERROR]%s()/%d Create database mutex failed.\n";
    uVar3 = 0x6c8;
  }
  else {
    ap_mac_empty = 0;
    DAT_007cc99c = 0;
    l_stats_data = FUN_00407f00("stats_mutex",1);
    if (l_stats_data == 0) {
      if (stats_err_switch == '\0') goto LAB_0066babc;
      __format = "[STATISTICS_ERROR]%s()/%d Create database mutex failed.\n";
      uVar3 = 0x6cf;
    }
    else {
      iVar1 = uVar2 / 10 + iVar1;
      DAT_007cc8dc = FUN_004080e0(iVar1);
      if (DAT_007cc8dc == 0) {
        if (stats_err_switch == '\0') goto LAB_0066babc;
        __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
        uVar3 = 0x6d5;
      }
      else {
        FUN_0051ad88(&g_stats_cb_list);
        DAT_007cc8e4 = FUN_004082a0(iVar1,0x1c0,0x6da);
        if (DAT_007cc8e4 == 0) {
          if (stats_err_switch == '\0') goto LAB_0066babc;
          __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
          uVar3 = 0x6dd;
        }
        else {
          uVar3 = wsta_profile_get_max_wstation();
          DAT_007cc8e0 = FUN_004080a0(_stats_sta_mac_obj,_stats_sta_mac_key,_stats_sta_mac_cmp,uVar3
                                     );
          if (DAT_007cc8e0 == 0) {
            if (stats_err_switch == '\0') goto LAB_0066babc;
            __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
            uVar3 = 0x6e7;
          }
          else {
            DAT_007cc8e8 = FUN_00408340(0x3c,0,_stats_sta_idle_timer_handle,0,0,"stats_db_init",
                                        0x6eb);
            if (DAT_007cc8e8 == -1) {
              if (stats_err_switch == '\0') goto LAB_0066babc;
              __format = "[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n";
              uVar3 = 0x6ee;
            }
            else {
              uVar3 = apmngr_db_get_ap_max();
              DAT_007cc8ec = FUN_004082a0(uVar3,0x1e0,0x6f3);
              if (DAT_007cc8ec == 0) {
                if (stats_err_switch == '\0') goto LAB_0066babc;
                __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
                uVar3 = 0x6f6;
              }
              else {
                iVar10 = 0;
                iVar1 = apmngr_db_get_ap_max();
                DAT_007cc8f0 = FUN_004082a0(iVar1 << 1,0x168,0x6f9);
                if (DAT_007cc8f0 == 0) {
                  if (stats_err_switch == '\0') goto LAB_0066babc;
                  __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
                  uVar3 = 0x6fc;
                }
                else {
                  for (; iVar1 = apmngr_db_get_ap_max(), iVar10 < iVar1; iVar10 = iVar10 + 1) {
                    iVar8 = iVar10 * 0x1e0;
                    iVar1 = DAT_007cc8ec + iVar8;
                    if (iVar1 == -0x18) {
                      uRamfffffff0 = 0;
                    }
                    else {
                      *(undefined4 *)(iVar1 + 0x74) = 0xffffffff;
                      *(undefined4 *)(iVar1 + 0x78) = 0xffffffff;
                      *(undefined4 *)(iVar1 + 0x7c) = 0xffffffff;
                      *(undefined4 *)(iVar1 + 0x80) = 0xffffffff;
                      *(undefined4 *)(iVar1 + 0x84) = 0xffffffff;
                      *(undefined4 *)(iVar1 + 0x88) = 0;
                      *(undefined4 *)(iVar1 + 8) = 0;
                    }
                    *(undefined4 *)(iVar1 + 0xc) = 0;
                    uVar3 = rdmngr_profile_get_max_rd_per_ap();
                    uVar3 = FUN_004082a0(uVar3,8,0x706);
                    *(undefined4 *)(iVar1 + 0x1d8) = uVar3;
                    if (*(int *)(DAT_007cc8ec + iVar8 + 0x1d8) == 0) goto LAB_0066babc;
                    iVar1 = 0;
                    iVar11 = iVar10 * 0x2d0;
                    do {
                      iVar4 = DAT_007cc8ec + iVar8;
                      *(undefined1 *)(*(int *)(iVar4 + 0x1d8) + iVar1) = 1;
                      *(int *)(*(int *)(DAT_007cc8ec + iVar8 + 0x1d8) + iVar1 + 4) =
                           DAT_007cc8f0 + iVar11;
                      iVar4 = *(int *)(*(int *)(iVar4 + 0x1d8) + iVar1 + 4);
                      uVar3 = rdmngr_profile_get_max_wlan_per_rd();
                      uVar3 = FUN_004082a0(uVar3,0x100,0x70f);
                      *(undefined4 *)(iVar4 + 0x160) = uVar3;
                      if (*(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar8 + 0x1d8) + iVar1 + 4) +
                                  0x160) == 0) goto LAB_0066babc;
                      iVar4 = 0;
                      reset_stats_db_rd_sample();
                      uVar2 = 1;
                      while (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 <= uVar5) {
                        iVar6 = *(int *)(*(int *)(*(int *)(DAT_007cc8ec + iVar8 + 0x1d8) + iVar1 + 4
                                                 ) + 0x160) + iVar4;
                        uVar2 = uVar2 + 1;
                        if (iVar6 != 0) {
                          *(undefined1 *)(iVar6 + 0x48) = 0;
                          *(undefined4 *)(iVar6 + 0x14) = 0xffffffff;
                          *(undefined4 *)(iVar6 + 0x18) = 0xffffffff;
                          *(undefined4 *)(iVar6 + 0x58) = 0xffffffff;
                          *(undefined4 *)(iVar6 + 0x5c) = 0xffffffff;
                        }
                        iVar4 = iVar4 + 0x100;
                      }
                      iVar1 = iVar1 + 8;
                      iVar11 = iVar11 + 0x168;
                    } while (iVar1 != 0x10);
                  }
                  apmngr_db_foreach_proc(0xff7fffff,_stats_db_ap_radio_stat_init,0);
                  iVar1 = apmngr_db_get_ap_max();
                  iVar10 = rdmngr_profile_get_max_rd_per_ap();
                  DAT_007cc8f4 = FUN_004080a0(_stats_bssid_obj,_stats_bssid_key,_stats_bssid_cmp,
                                              iVar1 * iVar10);
                  if (DAT_007cc8f4 == 0) {
                    if (stats_err_switch == '\0') goto LAB_0066babc;
                    __format = "[STATISTICS_ERROR]%s()/%d no memory!\n";
                    uVar3 = 0x724;
                  }
                  else {
                    DAT_007cc8f8 = FUN_00407e50("ac_statistics",600,400,_fail_sta_sc_free_cb,
                                                _fail_sta_sc_handle);
                    if (DAT_007cc8f8 == 0) {
                      if (stats_err_switch == '\0') goto LAB_0066babc;
                      __format = "[STATISTICS_ERROR]%s()/%d Create schedule container failed!\n";
                      uVar3 = 0x72d;
                    }
                    else {
                      FUN_00408600(DAT_007cc8f8,1);
                      client_auth_success_container =
                           FUN_00407e50("client_auth_success_container",0xb4,400,
                                        _auth_ok_sta_sc_free_cb,_auth_ok_sta_sc_handle);
                      if (client_auth_success_container == 0) {
                        if (stats_err_switch == '\0') goto LAB_0066babc;
                        __format = "[STATISTICS_ERROR]%s()/%d Failed to create client container\n";
                        uVar3 = 0x735;
                      }
                      else {
                        puVar7 = &g_sta_cur_time;
                        puVar9 = &g_sta_first_time;
                        iVar1 = 0;
                        FUN_00408600(client_auth_success_container,1);
                        do {
                          *puVar7 = 0;
                          *puVar9 = 0;
                          puVar7[1] = 0;
                          puVar9[1] = 0;
                          *(undefined4 *)((int)&g_sta_sample_cnt + iVar1) = 0;
                          iVar10 = FUN_00408340(*(undefined4 *)((int)&stat_sample_time + iVar1),0,
                                                *(undefined4 *)
                                                 ((int)&stats_info_sample_timer_hdl + iVar1),0,0,
                                                "stats_db_init",0x741);
                          *(int *)((int)&DAT_007cc900 + iVar1) = iVar10;
                          if (iVar10 == -1) {
                            if (stats_err_switch == '\0') goto LAB_0066babc;
                            __format = "[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n";
                            uVar3 = 0x744;
                            goto LAB_0066bab4;
                          }
                          iVar1 = iVar1 + 4;
                          puVar7 = puVar7 + 2;
                          puVar9 = puVar9 + 2;
                        } while (iVar1 != 0x10);
                        DAT_007cc8fc = FUN_00408340(0x3c,0,_stats_ap_idle_timer_handle,0,0,
                                                    "stats_db_init",0x748);
                        if (DAT_007cc8fc == -1) {
                          if (stats_err_switch == '\0') goto LAB_0066babc;
                          __format = "[STATISTICS_ERROR]%s()/%d uac_timer_add() fail!\n";
                          uVar3 = 0x74b;
                        }
                        else {
                          memset(auStack_78,0,0x4c);
                          local_6c = "stats_db";
                          local_68 = 2;
                          local_60 = stats_db_callback_wtp_leave;
                          iVar1 = apmngr_callback_register(auStack_78);
                          if (iVar1 != -1) {
                            iVar10 = 0;
                            FUN_0051ad88(&g_bssid_changed_callback_list);
                            iVar1 = 0;
                            do {
                              iVar10 = iVar10 + 1;
                              FUN_0051ad88(&g_sample_time_changed_callback_list + iVar1);
                              iVar1 = iVar10 * 0xc;
                            } while (iVar10 != 4);
                            iVar1 = FUN_004084d0("ac_statics",2,stats_sta_jcs_report_para_set);
                            if (iVar1 == 0) {
                              return 0;
                            }
                            goto LAB_0066babc;
                          }
                          if (stats_err_switch != '\0') {
                            printf("[STATISTICS_ERROR]%s()/%d register callback to apmngr failed.\n"
                                   ,"stats_db_apmngr_callback_init",0xaa1);
                          }
                          if (stats_err_switch == '\0') goto LAB_0066babc;
                          __format = 
                          "[STATISTICS_ERROR]%s()/%d stats_db_apmngr_callback_init() fail!\n";
                          uVar3 = 0x752;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0066bab4:
  printf(__format,"stats_db_init",uVar3);
LAB_0066babc:
  stats_db_uninit();
  return 0xffffffff;
}

