// func wportal_db_init @ 0042c920 size=3288

undefined4 wportal_db_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  char local_134 [4];
  char *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined2 local_11c;
  undefined2 local_11a;
  char *local_118;
  undefined4 local_114;
  char local_110 [64];
  undefined4 local_d0;
  char *local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined2 local_b8;
  undefined2 local_b6;
  undefined4 *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  char *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined2 local_94;
  undefined2 local_92;
  undefined4 *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  char *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  undefined2 local_6e;
  char *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  char *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  char *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined4 *local_24;
  undefined4 local_20;
  
  FUN_0051ad88(&g_wportal_event_list);
  wportal_rdt_mutex = FUN_00407f00("wportal_rdt_mutex",1);
  if (wportal_rdt_mutex == 0) {
    uVar8 = 0xffffffff;
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d Create database mutex failed.\n";
    pcVar4 = "wportal_db_init";
    uVar5 = 0xb70;
  }
  else {
    rdt_list = (void *)FUN_00408450(0x16c16c,0xb75);
    if (rdt_list == (void *)0x0) {
      uVar8 = 0xffffffff;
      if (wportal_err_switch == 0) {
        return 0xffffffff;
      }
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_ERR]%s()/%d Malloc rdt_list failed.\n";
      pcVar4 = "wportal_db_init";
      uVar5 = 0xb78;
    }
    else {
      memset(rdt_list,0,0x16c16c);
      iface_list = (void *)FUN_00408450(0x2d80,0xb7d);
      if (iface_list == (void *)0x0) {
        uVar8 = 0xffffffff;
        if (wportal_err_switch == 0) {
          return 0xffffffff;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0xffffffff;
        }
        __format = "[WPORTAL_ERR]%s()/%d Malloc iface_list failed.\n";
        pcVar4 = "wportal_db_init";
        uVar5 = 0xb80;
      }
      else {
        memset(iface_list,0,0x2d80);
        wportal_ftt_mutex = FUN_00407f00("wportal_ftt_mutex",1);
        if (wportal_ftt_mutex == 0) {
          uVar8 = 0xffffffff;
          if (wportal_err_switch == 0) {
            return 0xffffffff;
          }
          iVar6 = is_target_debug_ap();
          if (iVar6 == 0) {
            return 0xffffffff;
          }
          __format = "[WPORTAL_ERR]%s()/%d Create wportal_ftt_mutex failed.\n";
          pcVar4 = "wportal_db_init";
          uVar5 = 0xb89;
        }
        else {
          ftt_tree = FUN_00407dc0(_ftt_sort_func,_ftt_compare_func,_ftt_destroy_func);
          if (ftt_tree == 0) {
            uVar8 = 0xffffffff;
            if (wportal_err_switch == 0) {
              return 0xffffffff;
            }
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              return 0xffffffff;
            }
            __format = "[WPORTAL_ERR]%s()/%d Create ftt_tree failed.\n";
            pcVar4 = "wportal_db_init";
            uVar5 = 0xb90;
          }
          else {
            wportal_aut_mutex = FUN_00407f00("wportal_aut_mutex",1);
            if (wportal_aut_mutex == 0) {
              uVar8 = 0xffffffff;
              if (wportal_err_switch == 0) {
                return 0xffffffff;
              }
              iVar6 = is_target_debug_ap();
              if (iVar6 == 0) {
                return 0xffffffff;
              }
              __format = "[WPORTAL_ERR]%s()/%d Create wportal_aut_mutex failed.\n";
              pcVar4 = "wportal_db_init";
              uVar5 = 0xb98;
            }
            else {
              wportal_nsa_mutex = FUN_00407f00("wportal_nsa_mutex",1);
              if (wportal_nsa_mutex == 0) {
                uVar8 = 0xffffffff;
                if (wportal_err_switch == 0) {
                  return 0xffffffff;
                }
                iVar6 = is_target_debug_ap();
                if (iVar6 == 0) {
                  return 0xffffffff;
                }
                __format = "[WPORTAL_ERR]%s()/%d Create wportal_nsa_mutex failed.\n";
                pcVar4 = "wportal_db_init";
                uVar5 = 0xba0;
              }
              else {
                vlan_list_array_for_aut = FUN_00408450(0xc000,0xba5);
                iVar6 = 0;
                if (vlan_list_array_for_aut == 0) {
                  uVar8 = 0xffffffff;
                  if (wportal_err_switch == 0) {
                    return 0xffffffff;
                  }
                  iVar6 = is_target_debug_ap();
                  if (iVar6 == 0) {
                    return 0xffffffff;
                  }
                  __format = "[WPORTAL_ERR]%s()/%d Create vlan_list_array_for_aut failed.\n";
                  pcVar4 = "wportal_db_init";
                  uVar5 = 0xba8;
                }
                else {
                  do {
                    iVar3 = vlan_list_array_for_aut + iVar6;
                    iVar6 = iVar6 + 0xc;
                    FUN_0051ad88(iVar3);
                  } while (iVar6 != 0xc000);
                  vlan_list_array_for_nsa = FUN_00408450(0xc000,0xbb2);
                  iVar6 = 0;
                  if (vlan_list_array_for_nsa == 0) {
                    uVar8 = 0xffffffff;
                    if (wportal_err_switch == 0) {
                      return 0xffffffff;
                    }
                    iVar6 = is_target_debug_ap();
                    if (iVar6 == 0) {
                      return 0xffffffff;
                    }
                    __format = "[WPORTAL_ERR]%s()/%d Create vlan_list_array_for_nsa failed.\n";
                    pcVar4 = "wportal_db_init";
                    uVar5 = 0xbb5;
                  }
                  else {
                    do {
                      iVar3 = vlan_list_array_for_nsa + iVar6;
                      iVar6 = iVar6 + 0xc;
                      FUN_0051ad88(iVar3);
                    } while (iVar6 != 0xc000);
                    iVar6 = wserv_profile_get_max_wservice();
                    uVar7 = 0;
                    ssid_list_array_for_aut = FUN_00408450(iVar6 * 0xc,0xbbf);
                    if (ssid_list_array_for_aut == 0) {
                      uVar8 = 0xffffffff;
                      if (wportal_err_switch == 0) {
                        return 0xffffffff;
                      }
                      iVar6 = is_target_debug_ap();
                      if (iVar6 == 0) {
                        return 0xffffffff;
                      }
                      __format = "[WPORTAL_ERR]%s()/%d Create ssid_list_array_for_aut failed.\n";
                      pcVar4 = "wportal_db_init";
                      uVar5 = 0xbc2;
                    }
                    else {
                      while( true ) {
                        uVar1 = wserv_profile_get_max_wservice();
                        iVar6 = uVar7 * 0xc;
                        if (uVar1 <= uVar7) break;
                        uVar7 = uVar7 + 1;
                        FUN_0051ad88(ssid_list_array_for_aut + iVar6);
                      }
                      iVar6 = wserv_profile_get_max_wservice();
                      uVar7 = 0;
                      ssid_list_array_for_nsa = FUN_00408450(iVar6 * 0xc,0xbcc);
                      if (ssid_list_array_for_nsa == 0) {
                        uVar8 = 0xffffffff;
                        if (wportal_err_switch == 0) {
                          return 0xffffffff;
                        }
                        iVar6 = is_target_debug_ap();
                        if (iVar6 == 0) {
                          return 0xffffffff;
                        }
                        __format = "[WPORTAL_ERR]%s()/%d Create ssid_list_array_for_nsa failed.\n";
                        pcVar4 = "wportal_db_init";
                        uVar5 = 0xbcf;
                      }
                      else {
                        while( true ) {
                          uVar1 = wserv_profile_get_max_wservice();
                          iVar6 = uVar7 * 0xc;
                          if (uVar1 <= uVar7) break;
                          uVar7 = uVar7 + 1;
                          FUN_0051ad88(ssid_list_array_for_nsa + iVar6);
                        }
                        aut_list = FUN_00408450(0xc,0xbd8);
                        if (aut_list == 0) {
                          uVar8 = 0xffffffff;
                          if (wportal_err_switch == 0) {
                            return 0xffffffff;
                          }
                          iVar6 = is_target_debug_ap();
                          if (iVar6 == 0) {
                            return 0xffffffff;
                          }
                          __format = "[WPORTAL_ERR]%s()/%d Create aut_list failed.\n";
                          pcVar4 = "wportal_db_init";
                          uVar5 = 0xbdb;
                        }
                        else {
                          FUN_0051ad88(aut_list);
                          nsa_list = FUN_00408450(0xc,0xbe0);
                          if (nsa_list == 0) {
                            uVar8 = 0xffffffff;
                            if (wportal_err_switch == 0) {
                              return 0xffffffff;
                            }
                            iVar6 = is_target_debug_ap();
                            if (iVar6 == 0) {
                              return 0xffffffff;
                            }
                            __format = "[WPORTAL_ERR]%s()/%d Create aut_list failed.\n";
                            pcVar4 = "wportal_db_init";
                            uVar5 = 0xbe3;
                          }
                          else {
                            FUN_0051ad88(nsa_list);
                            aut_tree = FUN_00407dc0(_aut_sort_func,_aut_compare_func,
                                                    _aut_destroy_func);
                            if (aut_tree == 0) {
                              uVar8 = 0xffffffff;
                              if (wportal_err_switch == 0) {
                                return 0xffffffff;
                              }
                              iVar6 = is_target_debug_ap();
                              if (iVar6 == 0) {
                                return 0xffffffff;
                              }
                              __format = "[WPORTAL_ERR]%s()/%d Create aut_tree failed.\n";
                              pcVar4 = "wportal_db_init";
                              uVar5 = 0xbeb;
                            }
                            else {
                              nsa_tree = FUN_00407dc0(_nsa_sort_func,_nsa_compare_func,
                                                      _nsa_destroy_func);
                              if (nsa_tree == 0) {
                                uVar8 = 0xffffffff;
                                if (wportal_err_switch == 0) {
                                  return 0xffffffff;
                                }
                                iVar6 = is_target_debug_ap();
                                if (iVar6 == 0) {
                                  return 0xffffffff;
                                }
                                __format = "[WPORTAL_ERR]%s()/%d Create nsa_tree failed.\n";
                                pcVar4 = "wportal_db_init";
                                uVar5 = 0xbf2;
                              }
                              else {
                                username_hash_for_aut =
                                     FUN_004080a0(_wportal_username_obj_hash_func,
                                                  _wportal_username_key_hash_func,
                                                  _wportal_username_cmp_func,g_max_session);
                                if (username_hash_for_aut == 0) {
                                  uVar8 = 0xffffffff;
                                  if (wportal_err_switch == 0) {
                                    return 0xffffffff;
                                  }
                                  iVar6 = is_target_debug_ap();
                                  if (iVar6 == 0) {
                                    return 0xffffffff;
                                  }
                                  __format = 
                                  "[WPORTAL_ERR]%s()/%d Create username_hash_for_aut failed.\n";
                                  pcVar4 = "wportal_db_init";
                                  uVar5 = 0xbfa;
                                }
                                else {
                                  username_hash_for_nsa =
                                       FUN_004080a0(_wportal_username_obj_hash_func,
                                                    _wportal_username_key_hash_func,
                                                    _wportal_username_cmp_func,g_max_session);
                                  if (username_hash_for_nsa == 0) {
                                    uVar8 = 0xffffffff;
                                    if (wportal_err_switch == 0) {
                                      return 0xffffffff;
                                    }
                                    iVar6 = is_target_debug_ap();
                                    if (iVar6 == 0) {
                                      return 0xffffffff;
                                    }
                                    __format = 
                                    "[WPORTAL_ERR]%s()/%d Create username_hash_for_nsa failed.\n";
                                    pcVar4 = "wportal_db_init";
                                    uVar5 = 0xc02;
                                  }
                                  else {
                                    dm_calling_station_hash =
                                         FUN_004080a0(_wportal_dm_calling_station_obj_func,
                                                      _wportal_dm_calling_station_key_func,
                                                      _wportal_dm_calling_station_cmp_func,
                                                      g_max_session);
                                    if (dm_calling_station_hash == 0) {
                                      uVar8 = 0xffffffff;
                                      if (wportal_err_switch == 0) {
                                        return 0xffffffff;
                                      }
                                      iVar6 = is_target_debug_ap();
                                      if (iVar6 == 0) {
                                        return 0xffffffff;
                                      }
                                      __format = 
                                      "[WPORTAL_ERR]%s()/%d Create dm_calling_station_hash failed.\n"
                                      ;
                                      pcVar4 = "wportal_db_init";
                                      uVar5 = 0xc0b;
                                    }
                                    else {
                                      dm_sessid_rbtree =
                                           FUN_00407dc0(_wportal_dm_sessid_sort_func,
                                                        _wportal_dm_sessid_compare_func,
                                                        _wportal_dm_sessid_destroy_func);
                                      if (dm_sessid_rbtree == 0) {
                                        uVar8 = 0xffffffff;
                                        if (wportal_err_switch == 0) {
                                          return 0xffffffff;
                                        }
                                        iVar6 = is_target_debug_ap();
                                        if (iVar6 == 0) {
                                          return 0xffffffff;
                                        }
                                        __format = 
                                        "[WPORTAL_ERR]%s()/%d Create dm_sessid_rbtree failed.\n";
                                        pcVar4 = "wportal_db_init";
                                        uVar5 = 0xc13;
                                      }
                                      else {
                                        dm_framed_ip_hash =
                                             FUN_004080a0(_wportal_dm_framed_ip_obj_func,
                                                          _wportal_dm_framed_ip_key_func,
                                                          _wportal_dm_framed_ip_cmp_func,
                                                          g_max_session);
                                        if (dm_framed_ip_hash == 0) {
                                          uVar8 = 0xffffffff;
                                          if (wportal_err_switch == 0) {
                                            return 0xffffffff;
                                          }
                                          iVar6 = is_target_debug_ap();
                                          if (iVar6 == 0) {
                                            return 0xffffffff;
                                          }
                                          __format = 
                                          "[WPORTAL_ERR]%s()/%d Create dm_framed_ip_hash failed.\n";
                                          pcVar4 = "wportal_db_init";
                                          uVar5 = 0xc1b;
                                        }
                                        else {
                                          wportal_rds_srv_mutex =
                                               FUN_00407f00("wportal_rds_srv_mutex",1);
                                          if (wportal_rds_srv_mutex == 0) {
                                            uVar8 = 0xffffffff;
                                            if (wportal_err_switch == 0) {
                                              return 0xffffffff;
                                            }
                                            iVar6 = is_target_debug_ap();
                                            if (iVar6 == 0) {
                                              return 0xffffffff;
                                            }
                                            __format = 
                                            "[WPORTAL_ERR]%s()/%d Create wportal_rds_srv_mutex failed.\n"
                                            ;
                                            pcVar4 = "wportal_db_init";
                                            uVar5 = 0xc23;
                                          }
                                          else {
                                            rds_srv_tree_index =
                                                 FUN_00407dc0(_rds_srv_sort_func,
                                                              _rds_srv_compare_func,
                                                              _rds_srv_destroy_func);
                                            if (rds_srv_tree_index == 0) {
                                              uVar8 = 0xffffffff;
                                              if (wportal_err_switch == 0) {
                                                return 0xffffffff;
                                              }
                                              iVar6 = is_target_debug_ap();
                                              if (iVar6 == 0) {
                                                return 0xffffffff;
                                              }
                                              __format = 
                                              "[WPORTAL_ERR]%s()/%d Create rds_srv_tree failed.\n";
                                              pcVar4 = "wportal_db_init";
                                              uVar5 = 0xc2a;
                                            }
                                            else {
                                              rds_srv_hash_addr =
                                                   FUN_004086f0(_wportal_rds_hash_obj_func,
                                                                _wportal_rds_hash_key_func,
                                                                _wportal_rds_hash_cmp_func);
                                              if (rds_srv_hash_addr == 0) {
                                                uVar8 = 0xffffffff;
                                                if (wportal_err_switch == 0) {
                                                  return 0xffffffff;
                                                }
                                                iVar6 = is_target_debug_ap();
                                                if (iVar6 == 0) {
                                                  return 0xffffffff;
                                                }
                                                __format = 
                                                "[WPORTAL_ERR]%s()/%d Create rds_srv_hash failed.\n"
                                                ;
                                                pcVar4 = "wportal_db_init";
                                                uVar5 = 0xc31;
                                              }
                                              else {
                                                uVar8 = wserv_profile_get_max_wservice();
                                                wportal_wserv_node = FUN_004082a0(uVar8,8,0xc36);
                                                uVar7 = 0;
                                                if (wportal_wserv_node == 0) {
                                                  uVar8 = 0xffffffff;
                                                  if (wportal_err_switch == 0) {
                                                    return 0xffffffff;
                                                  }
                                                  iVar6 = is_target_debug_ap();
                                                  if (iVar6 == 0) {
                                                    return 0xffffffff;
                                                  }
                                                  __format = 
                                                  "[WPORTAL_ERR]%s()/%d Create wportal_wserv_node failed.\n"
                                                  ;
                                                  pcVar4 = "wportal_db_init";
                                                  uVar5 = 0xc39;
                                                }
                                                else {
                                                  for (; uVar1 = wserv_profile_get_max_wservice(),
                                                      uVar7 < uVar1; uVar7 = uVar7 + 1) {
                                                    puVar2 = (undefined4 *)
                                                             (wportal_wserv_node + uVar7 * 8);
                                                    puVar2[1] = 0;
                                                    *puVar2 = 0;
                                                  }
                                                  local_138 = 0;
                                                  local_13c = 0;
                                                  memset(local_134,0,0x20);
                                                  memset(local_110,0,0x20);
                                                  local_b4 = &local_138;
                                                  local_d0 = 0;
                                                  local_b6 = 4;
                                                  local_92 = 4;
                                                  local_90 = &local_13c;
                                                  local_140 = 0x3c;
                                                  local_88 = 2;
                                                  local_a8 = "age_time";
                                                  local_c8 = 0;
                                                  local_c0 = 0;
                                                  local_84 = "age_enable";
                                                  local_cc = "portal_port";
                                                  local_64 = 3;
                                                  local_b0 = 0;
                                                  local_a4 = 0;
                                                  local_c4 = 1;
                                                  local_bc = 10;
                                                  local_b8 = 1;
                                                  local_ac = 1;
                                                  local_a0 = 1;
                                                  local_98 = 10;
                                                  local_94 = 1;
                                                  local_80 = 1;
                                                  local_7c = 1;
                                                  local_70 = 1;
                                                  local_6e = 0x20;
                                                  local_60 = "auth_mode";
                                                  local_9c = 0;
                                                  local_8c = 0;
                                                  local_78 = 0;
                                                  local_74 = 0;
                                                  local_68 = 0;
                                                  local_5c = 1;
                                                  local_4a = 0x20;
                                                  local_3c = "dns_upd_intv";
                                                  local_58 = 1;
                                                  local_4c = 1;
                                                  local_40 = 4;
                                                  local_34 = 1;
                                                  local_28 = 1;
                                                  local_24 = &local_140;
                                                  local_26 = 4;
                                                  local_54 = 0;
                                                  local_50 = 0;
                                                  local_44 = 0;
                                                  local_38 = 0;
                                                  local_30 = 0;
                                                  local_2c = 10;
                                                  local_20 = 0;
                                                  local_6c = local_134;
                                                  local_48 = local_110;
                                                  iVar6 = FUN_00408120("authentication","portal",
                                                                       &local_d0,5);
                                                  if (iVar6 == 0) {
                                                    wportal_set_dns_upate_intvl(local_140);
                                                    wportal_set_portal_port(local_138);
                                                    wportal_set_portal_age_time(local_13c);
                                                    iVar6 = strcmp(local_134,"on");
                                                    wportal_set_portal_age_enable(iVar6 == 0);
                                                    iVar6 = strcmp(local_110,"ssid");
                                                    uVar8 = 0;
                                                    if (iVar6 != 0) {
                                                      iVar6 = strcmp(local_110,"vlan");
                                                      uVar8 = 1;
                                                      if (iVar6 != 0) {
                                                        iVar6 = strcmp(local_110,"interface");
                                                        uVar8 = 2;
                                                        if (iVar6 != 0) {
                                                          iVar6 = strcmp(local_110,"interface_ssid")
                                                          ;
                                                          uVar8 = 0xffffffff;
                                                          if (iVar6 == 0) {
                                                            uVar8 = 0;
                                                          }
                                                        }
                                                      }
                                                    }
                                                    wportal_set_mode(uVar8);
                                                  }
                                                  else if ((wportal_err_switch != 0) &&
                                                          (iVar6 = is_target_debug_ap(), iVar6 != 0)
                                                          ) {
                                                    printf(
                                                  "[WPORTAL_ERR]%s()/%d uci req parse failed.\n",
                                                  "_wportal_read_port_config",0x5fa);
                                                  }
                                                  _wportal_read_portal_config();
                                                  _wportal_read_radius_config();
                                                  _ftext("authentication","free_auth_list",0,
                                                         _wportal_ftt_section_parse);
                                                  memset(local_110,0,0x40);
                                                  local_134[0] = '\0';
                                                  local_134[1] = '\0';
                                                  local_134[2] = '\0';
                                                  local_134[3] = '\0';
                                                  local_128 = 0;
                                                  local_124 = 0;
                                                  local_130 = "local_wireless_auth";
                                                  local_120 = 0;
                                                  local_12c = 1;
                                                  local_11c = 1;
                                                  local_114 = 0;
                                                  local_11a = 0x40;
                                                  local_118 = local_110;
                                                  iVar6 = FUN_00408120("profile","portal_config",
                                                                       local_134,1);
                                                  if (iVar6 == 0) {
                                                    if (local_110[0] == '\0') {
                                                      return 0;
                                                    }
                                                    iVar6 = atoi(local_110);
                                                    wportal_set_authen_capability(iVar6);
                                                    return 0;
                                                  }
                                                  uVar8 = 0;
                                                  if (wportal_err_switch == 0) {
                                                    return 0;
                                                  }
                                                  iVar6 = is_target_debug_ap();
                                                  if (iVar6 == 0) {
                                                    return 0;
                                                  }
                                                  __format = 
                                                  "[WPORTAL_ERR]%s()/%d uci req parse failed.\n";
                                                  pcVar4 = "_wportal_read_capability_config";
                                                  uVar5 = 0x625;
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
  printf(__format,pcVar4,uVar5);
  return uVar8;
}

