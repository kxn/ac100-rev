// func _uac_mac_auth_group_jcs_modify_for_ssid @ 0044d64c size=2724

void _uac_mac_auth_group_jcs_modify_for_ssid(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *__s;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *__dest;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  undefined8 uVar9;
  undefined4 local_5e8;
  undefined4 local_5e4;
  char local_5e0 [8];
  ushort local_5d8;
  char local_5d4 [16];
  uint local_5c4;
  undefined1 auStack_5c0 [12];
  undefined4 local_5b4;
  int local_5b0;
  char acStack_5ac [155];
  undefined1 local_511;
  char acStack_510 [155];
  undefined1 local_475;
  undefined4 local_43c;
  char acStack_438 [1025];
  undefined1 local_37;
  int local_30;
  
  local_5e4 = 0;
  memset(acStack_438,0,0x402);
  local_5e8 = 0;
  local_5e0[0] = '\0';
  local_5e0[1] = '\0';
  local_5e0[2] = '\0';
  local_5e0[3] = '\0';
  local_5e0[4] = '\0';
  local_5e0[5] = '\0';
  local_5e0[6] = '\0';
  local_5e0[7] = '\0';
  local_5d8 = 0;
  local_5d4[0] = '\0';
  local_5d4[1] = '\0';
  local_5d4[2] = '\0';
  local_5d4[3] = '\0';
  local_5d4[4] = '\0';
  local_5d4[5] = '\0';
  local_5d4[6] = '\0';
  local_5d4[7] = '\0';
  local_5d4[8] = '\0';
  local_5d4[9] = '\0';
  local_5d4[10] = '\0';
  local_5d4[0xb] = '\0';
  local_5d4[0xc] = '\0';
  local_5d4[0xd] = '\0';
  local_5d4[0xe] = '\0';
  local_5d4[0xf] = '\0';
  local_5c4 = 0;
  memset(auStack_5c0,0,0x188);
  uVar1 = wserv_profile_get_max_wservice();
  __s = (void *)FUN_004082a0(uVar1,4,0x448);
  if (__s == (void *)0x0) {
    if (macauth_err_switch == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = -1;
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_modify_for_ssid",1099);
    }
    goto LAB_0044d7fc;
  }
  iVar2 = wserv_profile_get_max_wservice();
  memset(__s,-1,iVar2 << 2);
  iVar2 = mac_auth_profile_get_max_mac();
  iVar3 = FUN_004082a0(iVar2 + 0x1fU >> 5,4,0x44f);
  if (iVar3 == 0) {
    if (macauth_err_switch == 0) {
      __dest = (char *)0x0;
      iVar2 = -1;
    }
    else {
      __dest = (char *)0x0;
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_modify_for_ssid",0x452);
      iVar2 = -1;
    }
  }
  else {
    uVar4 = mac_auth_profile_get_max_mac();
    __dest = (char *)FUN_004082a0((uVar4 >> 2) + 1,1,0x455);
    if (__dest == (char *)0x0) {
      iVar2 = -1;
      if (macauth_err_switch != 0) {
        pcVar7 = "[MACAUTH_ERROR]%s()/%d no memory.\n";
        uVar1 = 0x458;
        goto LAB_0044d918;
      }
    }
    else {
      memset(auStack_5c0,0,0x188);
      local_5b4 = 0xffffffff;
      iVar2 = json_object_object_get(param_1,"id");
      if (iVar2 == 0) {
        iVar2 = -1;
        if (macauth_err_switch != 0) {
          pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
          uVar1 = 0x45f;
          pcVar8 = "id";
          goto LAB_0044dbf4;
        }
      }
      else {
        iVar5 = json_object_get_type(iVar2);
        if (iVar5 == 3) {
          iVar2 = json_object_get_int(iVar2);
        }
        else {
          iVar5 = json_object_get_type();
          if (iVar5 == 2) {
            uVar9 = json_object_get_double(iVar2);
            iVar2 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
          }
          else {
            iVar2 = -1;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_mac_auth_group_jcs_modify_for_ssid",0x460);
            }
          }
        }
        iVar5 = mac_auth_db_group_entry_get(iVar2,auStack_5c0);
        if (iVar5 == 0) {
          local_30 = local_5b0;
          iVar5 = json_object_object_get(param_1,"enable");
          if (iVar5 == 0) {
            iVar2 = -1;
            if (macauth_err_switch != 0) {
              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
              uVar1 = 0x469;
              pcVar8 = "enable";
LAB_0044dbf4:
              printf(pcVar7,"_uac_mac_auth_group_jcs_modify_for_ssid",uVar1,pcVar8);
            }
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 6) {
              pcVar7 = (char *)json_object_get_string(iVar5);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x46a);
              }
              pcVar7 = "";
            }
            strncpy(local_5e0,pcVar7,9);
            local_5d8 = local_5d8 & 0xff00;
            local_5b0 = _macauth_enable_str2int(local_5e0);
            iVar5 = json_object_object_get(param_1,"type");
            if (iVar5 == 0) {
              iVar2 = -1;
              if (macauth_err_switch != 0) {
                pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                uVar1 = 0x46e;
                pcVar8 = "type";
                goto LAB_0044dbf4;
              }
            }
            else {
              iVar6 = json_object_get_type(iVar5);
              if (iVar6 == 6) {
                pcVar7 = (char *)json_object_get_string(iVar5);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x46f);
                }
                pcVar7 = "";
              }
              strncpy(local_5d4,pcVar7,0x13);
              local_5c4 = local_5c4 & 0xffffff00;
              local_43c = _macauth_group_type_str2int(local_5d4);
              iVar5 = json_object_object_get(param_1,"name");
              if (iVar5 == 0) {
                iVar2 = -1;
                if (macauth_err_switch != 0) {
                  pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                  uVar1 = 0x473;
                  pcVar8 = "name";
                  goto LAB_0044dbf4;
                }
              }
              else {
                iVar6 = json_object_get_type(iVar5);
                if (iVar6 == 6) {
                  pcVar7 = (char *)json_object_get_string(iVar5);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x474);
                  }
                  pcVar7 = "";
                }
                strncpy(acStack_5ac,pcVar7,0x9b);
                local_511 = 0;
                iVar5 = json_object_object_get(param_1,&DAT_00684958);
                if (iVar5 == 0) {
                  iVar2 = -1;
                  if (macauth_err_switch != 0) {
                    pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                    uVar1 = 0x477;
                    pcVar8 = "note";
                    goto LAB_0044dbf4;
                  }
                }
                else {
                  iVar6 = json_object_get_type(iVar5);
                  if (iVar6 == 6) {
                    pcVar7 = (char *)json_object_get_string(iVar5);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x478);
                    }
                    pcVar7 = "";
                  }
                  strncpy(acStack_510,pcVar7,0x9b);
                  local_475 = 0;
                  iVar5 = json_object_object_get(param_1,"mac_id_map");
                  if (iVar5 == 0) {
                    iVar2 = -1;
                    if (macauth_err_switch != 0) {
                      pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                      uVar1 = 0x47b;
                      pcVar8 = "mac_id_map";
                      goto LAB_0044dbf4;
                    }
                  }
                  else {
                    __n = 0;
                    uVar4 = mac_auth_profile_get_max_mac();
                    if (uVar4 >> 2 != 0) {
                      uVar4 = mac_auth_profile_get_max_mac();
                      __n = uVar4 >> 2;
                    }
                    iVar6 = json_object_get_type(iVar5);
                    if (iVar6 == 6) {
                      pcVar7 = (char *)json_object_get_string(iVar5);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x47c);
                      }
                      pcVar7 = "";
                    }
                    strncpy(__dest,pcVar7,__n);
                    __dest[__n] = '\0';
                    iVar5 = json_object_object_get(param_1,"old_serv_id_map");
                    if (iVar5 == 0) {
                      iVar2 = -1;
                      if (macauth_err_switch != 0) {
                        pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                        uVar1 = 0x47f;
                        pcVar8 = "old_serv_id_map";
                        goto LAB_0044dbf4;
                      }
                    }
                    else {
                      iVar6 = json_object_get_type(iVar5);
                      if (iVar6 == 6) {
                        pcVar7 = (char *)json_object_get_string(iVar5);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x480);
                        }
                        pcVar7 = "";
                      }
                      strncpy(acStack_438,pcVar7,0x401);
                      local_37 = 0;
                      if (macauth_debug_switch != 0) {
                        printf("[MACAUTH_DEBUG]%s()/%d status:%d,type:%d,name:%s,note:%s,ssid:%s,mac:%s\n"
                               ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x483,local_5b0,local_43c,
                               acStack_5ac,acStack_510,acStack_438,__dest);
                      }
                      iVar5 = mac_auth_db_get_bind_ssid(__s);
                      if (iVar5 == 0) {
                        iVar5 = mac_auth_bind_ssid(acStack_438,__s,1,&local_5e4,0xffffffff,1);
                        if (iVar5 == 0) {
                          memset(acStack_438,0,0x402);
                          iVar5 = json_object_object_get(param_1,"serv_id_map");
                          if (iVar5 == 0) {
                            iVar2 = -1;
                            if (macauth_err_switch != 0) {
                              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                              uVar1 = 0x493;
                              pcVar8 = "serv_id_map";
                              goto LAB_0044dbf4;
                            }
                          }
                          else {
                            iVar6 = json_object_get_type(iVar5);
                            if (iVar6 == 6) {
                              pcVar7 = (char *)json_object_get_string(iVar5);
                            }
                            else {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                       ,"_uac_mac_auth_group_jcs_modify_for_ssid",0x494);
                              }
                              pcVar7 = "";
                            }
                            strncpy(acStack_438,pcVar7,0x401);
                            local_37 = 0;
                            local_5e4 = 0;
                            iVar5 = mac_auth_bind_ssid(acStack_438,__s,1,&local_5e4,iVar2,0);
                            if (iVar5 == 0) {
                              if (macauth_debug_switch != 0) {
                                printf("[MACAUTH_DEBUG]%s()/%d ssid cnt is %d.\n",
                                       "_uac_mac_auth_group_jcs_modify_for_ssid",0x49f,local_5e4);
                              }
                              iVar6 = mac_auth_bind_mac(__dest,iVar3,&local_5e8);
                              if (iVar6 == 0) {
                                if (macauth_debug_switch != 0) {
                                  printf("[MACAUTH_DEBUG]%s()/%d mac cnt is %d.\n",
                                         "_uac_mac_auth_group_jcs_modify_for_ssid",0x4a6,local_5e8);
                                }
                                iVar5 = mac_auth_db_group_entry_set_for_ssid(auStack_5c0,__s,iVar3);
                                if (iVar5 == 0) {
                                  if ((local_5b0 != 0) || (local_30 != 0)) {
                                    _uac_mac_auth_sta_check_trigger();
                                  }
                                }
                                else {
                                  iVar2 = iVar5;
                                  if (macauth_err_switch != 0) {
                                    pcVar7 = 
                                    "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_set() failed.\n";
                                    uVar1 = 0x4aa;
                                    goto LAB_0044d918;
                                  }
                                }
                              }
                              else {
                                iVar2 = iVar5;
                                if (macauth_err_switch != 0) {
                                  pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() failed.\n";
                                  uVar1 = 0x4a2;
LAB_0044d918:
                                  printf(pcVar7,"_uac_mac_auth_group_jcs_modify_for_ssid",uVar1);
                                }
                              }
                            }
                            else {
                              iVar2 = iVar5;
                              if (macauth_err_switch != 0) {
                                pcVar7 = "[MACAUTH_ERROR]%s()/%d parse ssid str %s failed.\n";
                                uVar1 = 0x49b;
                                pcVar8 = acStack_438;
                                goto LAB_0044dbf4;
                              }
                            }
                          }
                        }
                        else {
                          iVar2 = -1;
                          if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d parse ssid str %s failed.\n";
                            uVar1 = 0x48d;
                            pcVar8 = acStack_438;
                            goto LAB_0044dbf4;
                          }
                        }
                      }
                      else {
                        iVar2 = -1;
                        if (macauth_err_switch != 0) {
                          pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_ssid() failed.\n";
                          uVar1 = 0x486;
                          goto LAB_0044d918;
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
          iVar2 = -1;
          if (macauth_err_switch != 0) {
            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_entry_get() failed.\n";
            uVar1 = 0x463;
            goto LAB_0044d918;
          }
        }
      }
    }
  }
  FUN_00407df0(__s);
  if (iVar3 != 0) {
    FUN_00407df0(iVar3);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
LAB_0044d7fc:
  uVar1 = json_object_new_int(iVar2);
  json_object_object_add(param_2,"id",uVar1);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_set() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_modify_for_ssid",0x4c4,iVar2);
  }
  return;
}

