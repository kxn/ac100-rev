// func _uac_mac_auth_group_jcs_add_for_ssid @ 0044e660 size=2192

void _uac_mac_auth_group_jcs_add_for_ssid(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__dest;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  undefined4 local_5e0;
  undefined4 local_5dc;
  char local_5d8 [8];
  ushort local_5d0;
  char local_5cc [16];
  uint local_5bc;
  undefined1 auStack_5b8 [12];
  int local_5ac;
  int local_5a8;
  char acStack_5a4 [155];
  undefined1 local_509;
  char acStack_508 [155];
  undefined1 local_46d;
  undefined4 local_434;
  char acStack_430 [1025];
  undefined1 local_2f;
  
  memset(auStack_5b8,0,0x188);
  local_5dc = 0;
  memset(acStack_430,0,0x402);
  local_5e0 = 0;
  local_5d8[0] = '\0';
  local_5d8[1] = '\0';
  local_5d8[2] = '\0';
  local_5d8[3] = '\0';
  local_5d8[4] = '\0';
  local_5d8[5] = '\0';
  local_5d8[6] = '\0';
  local_5d8[7] = '\0';
  local_5d0 = 0;
  local_5cc[0] = '\0';
  local_5cc[1] = '\0';
  local_5cc[2] = '\0';
  local_5cc[3] = '\0';
  local_5cc[4] = '\0';
  local_5cc[5] = '\0';
  local_5cc[6] = '\0';
  local_5cc[7] = '\0';
  local_5cc[8] = '\0';
  local_5cc[9] = '\0';
  local_5cc[10] = '\0';
  local_5cc[0xb] = '\0';
  local_5cc[0xc] = '\0';
  local_5cc[0xd] = '\0';
  local_5cc[0xe] = '\0';
  local_5cc[0xf] = '\0';
  local_5bc = 0;
  local_5ac = -1;
  uVar1 = wserv_profile_get_max_wservice();
  iVar2 = FUN_004082a0(uVar1,4,0x259);
  if (iVar2 == 0) {
    if (macauth_err_switch == 0) {
      iVar3 = -1;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_add_for_ssid",0x25d);
      iVar3 = -1;
    }
  }
  else {
    iVar3 = mac_auth_profile_get_max_mac();
    iVar4 = FUN_004082a0(iVar3 + 0x1fU >> 5,4,0x261);
    if (iVar4 == 0) {
      if (macauth_err_switch == 0) {
        __dest = (char *)0x0;
        iVar3 = -1;
      }
      else {
        __dest = (char *)0x0;
        printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_add_for_ssid",0x264);
        iVar3 = -1;
      }
    }
    else {
      uVar5 = mac_auth_profile_get_max_mac();
      __dest = (char *)FUN_004082a0((uVar5 >> 2) + 1,1,0x268);
      if (__dest == (char *)0x0) {
        iVar3 = -1;
        if (macauth_err_switch != 0) {
          pcVar7 = "[MACAUTH_ERROR]%s()/%d no memory.\n";
          uVar1 = 0x26b;
LAB_0044e874:
          printf(pcVar7,"_uac_mac_auth_group_jcs_add_for_ssid",uVar1);
        }
      }
      else {
        iVar3 = mac_auth_db_get_bind_ssid(iVar2);
        if (iVar3 == 0) {
          iVar3 = json_object_object_get(param_1,"enable");
          if (iVar3 == 0) {
            iVar3 = -1;
            if (macauth_err_switch != 0) {
              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
              uVar1 = 0x276;
              pcVar8 = "enable";
LAB_0044ec00:
              printf(pcVar7,"_uac_mac_auth_group_jcs_add_for_ssid",uVar1,pcVar8);
            }
          }
          else {
            iVar6 = json_object_get_type(iVar3);
            if (iVar6 == 6) {
              pcVar7 = (char *)json_object_get_string(iVar3);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_mac_auth_group_jcs_add_for_ssid",0x277);
              }
              pcVar7 = "";
            }
            strncpy(local_5d8,pcVar7,9);
            local_5d0 = local_5d0 & 0xff00;
            local_5a8 = _macauth_enable_str2int(local_5d8);
            iVar3 = json_object_object_get(param_1,"type");
            if (iVar3 == 0) {
              iVar3 = -1;
              if (macauth_err_switch != 0) {
                pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                uVar1 = 0x27b;
                pcVar8 = "type";
                goto LAB_0044ec00;
              }
            }
            else {
              iVar6 = json_object_get_type(iVar3);
              if (iVar6 == 6) {
                pcVar7 = (char *)json_object_get_string(iVar3);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_mac_auth_group_jcs_add_for_ssid",0x27c);
                }
                pcVar7 = "";
              }
              strncpy(local_5cc,pcVar7,0x13);
              local_5bc = local_5bc & 0xffffff00;
              local_434 = _macauth_group_type_str2int(local_5cc);
              iVar3 = json_object_object_get(param_1,"name");
              if (iVar3 == 0) {
                iVar3 = -1;
                if (macauth_err_switch != 0) {
                  pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                  uVar1 = 0x280;
                  pcVar8 = "name";
                  goto LAB_0044ec00;
                }
              }
              else {
                iVar6 = json_object_get_type(iVar3);
                if (iVar6 == 6) {
                  pcVar7 = (char *)json_object_get_string(iVar3);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_uac_mac_auth_group_jcs_add_for_ssid",0x281);
                  }
                  pcVar7 = "";
                }
                strncpy(acStack_5a4,pcVar7,0x9b);
                local_509 = 0;
                iVar3 = json_object_object_get(param_1,&DAT_00684958);
                if (iVar3 == 0) {
                  iVar3 = -1;
                  if (macauth_err_switch != 0) {
                    pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                    uVar1 = 0x284;
                    pcVar8 = "note";
                    goto LAB_0044ec00;
                  }
                }
                else {
                  iVar6 = json_object_get_type(iVar3);
                  if (iVar6 == 6) {
                    pcVar7 = (char *)json_object_get_string(iVar3);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_uac_mac_auth_group_jcs_add_for_ssid",0x285);
                    }
                    pcVar7 = "";
                  }
                  strncpy(acStack_508,pcVar7,0x9b);
                  local_46d = 0;
                  iVar3 = json_object_object_get(param_1,"serv_id_map");
                  if (iVar3 == 0) {
                    iVar3 = -1;
                    if (macauth_err_switch != 0) {
                      pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                      uVar1 = 0x288;
                      pcVar8 = "serv_id_map";
                      goto LAB_0044ec00;
                    }
                  }
                  else {
                    iVar6 = json_object_get_type(iVar3);
                    if (iVar6 == 6) {
                      pcVar7 = (char *)json_object_get_string(iVar3);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_mac_auth_group_jcs_add_for_ssid",0x289);
                      }
                      pcVar7 = "";
                    }
                    strncpy(acStack_430,pcVar7,0x401);
                    local_2f = 0;
                    iVar3 = json_object_object_get(param_1,"mac_id_map");
                    if (iVar3 == 0) {
                      iVar3 = -1;
                      if (macauth_err_switch != 0) {
                        pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                        uVar1 = 0x28c;
                        pcVar8 = "mac_id_map";
                        goto LAB_0044ec00;
                      }
                    }
                    else {
                      __n = 0;
                      uVar5 = mac_auth_profile_get_max_mac();
                      if (uVar5 >> 2 != 0) {
                        uVar5 = mac_auth_profile_get_max_mac();
                        __n = uVar5 >> 2;
                      }
                      iVar6 = json_object_get_type(iVar3);
                      if (iVar6 == 6) {
                        pcVar7 = (char *)json_object_get_string(iVar3);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_uac_mac_auth_group_jcs_add_for_ssid",0x28d);
                        }
                        pcVar7 = "";
                      }
                      strncpy(__dest,pcVar7,__n);
                      __dest[__n] = '\0';
                      if (macauth_debug_switch != 0) {
                        printf("[MACAUTH_DEBUG]%s()/%d status:%d,type:%d,name:%s,note:%s,ssid:%s,mac:%s\n"
                               ,"_uac_mac_auth_group_jcs_add_for_ssid",0x290,local_5a8,local_434,
                               acStack_5a4,acStack_508,acStack_430,__dest);
                      }
                      iVar3 = mac_auth_bind_mac(__dest,iVar4,&local_5e0);
                      if (iVar3 == 0) {
                        iVar3 = mac_auth_db_group_entry_add_for_ssid(auStack_5b8,iVar4);
                        if (iVar3 == 0) {
                          if (macauth_debug_switch != 0) {
                            printf("[MACAUTH_DEBUG]%s()/%d group entry id is %d.\n",
                                   "_uac_mac_auth_group_jcs_add_for_ssid",0x29b,local_5ac);
                          }
                          iVar3 = mac_auth_bind_ssid(acStack_430,iVar2,1,&local_5dc,local_5ac,0);
                          if (iVar3 == 0) {
                            iVar3 = mac_auth_db_set_bind_ssid(iVar2);
                            if (iVar3 == 0) {
                              if (local_5a8 != 0) {
                                _uac_mac_auth_sta_check_trigger();
                              }
                              iVar3 = local_5ac;
                              if (macauth_debug_switch != 0) {
                                printf("[MACAUTH_DEBUG]%s()/%d ssid cnt is %d.\n",
                                       "_uac_mac_auth_group_jcs_add_for_ssid",0x2ac,local_5dc);
                                iVar3 = local_5ac;
                              }
                            }
                            else if (macauth_err_switch != 0) {
                              pcVar7 = 
                              "[MACAUTH_ERROR]%s()/%d mac_auth_db_set_bind_ssid() failed.\n";
                              uVar1 = 0x2a5;
                              goto LAB_0044e874;
                            }
                          }
                          else if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d parse ssid str %s failed.\n";
                            uVar1 = 0x29f;
                            pcVar8 = acStack_430;
                            goto LAB_0044ec00;
                          }
                        }
                        else {
                          iVar3 = -1;
                          if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_entry_add() failed.\n";
                            uVar1 = 0x298;
                            goto LAB_0044e874;
                          }
                        }
                      }
                      else {
                        iVar3 = -1;
                        if (macauth_err_switch != 0) {
                          pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() failed.\n";
                          uVar1 = 0x293;
                          goto LAB_0044e874;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          iVar3 = -1;
          if (macauth_err_switch != 0) {
            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() failed.\n";
            uVar1 = 0x271;
            goto LAB_0044e874;
          }
        }
      }
    }
    FUN_00407df0(iVar2);
    if (iVar4 != 0) {
      FUN_00407df0(iVar4);
    }
    if (__dest != (char *)0x0) {
      FUN_00407df0(__dest);
    }
    if (-1 < iVar3) goto LAB_0044e794;
  }
  mac_auth_db_group_entry_release_id_for_ssid(local_5ac);
LAB_0044e794:
  uVar1 = json_object_new_int(iVar3);
  json_object_object_add(param_2,"id",uVar1);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_add() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_add_for_ssid",0x2c4,iVar3);
  }
  return;
}

