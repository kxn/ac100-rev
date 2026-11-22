// func _uac_mac_auth_group_jcs_add @ 0044ff7c size=1

void _uac_mac_auth_group_jcs_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *__dest;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  char acStack_208 [8];
  ushort uStack_200;
  char acStack_1fc [16];
  uint uStack_1ec;
  char acStack_1e8 [50];
  undefined1 uStack_1b6;
  undefined1 auStack_1b4 [12];
  int iStack_1a8;
  int iStack_1a4;
  char acStack_1a0 [155];
  undefined1 uStack_105;
  char acStack_104 [155];
  undefined1 uStack_69;
  char acStack_68 [50];
  undefined1 uStack_36;
  undefined4 uStack_30;
  
  memset(auStack_1b4,0,0x188);
  uStack_20c = 0;
  memset(acStack_1e8,0,0x33);
  uStack_210 = 0;
  acStack_208[0] = '\0';
  acStack_208[1] = '\0';
  acStack_208[2] = '\0';
  acStack_208[3] = '\0';
  acStack_208[4] = '\0';
  acStack_208[5] = '\0';
  acStack_208[6] = '\0';
  acStack_208[7] = '\0';
  uStack_200 = 0;
  acStack_1fc[0] = '\0';
  acStack_1fc[1] = '\0';
  acStack_1fc[2] = '\0';
  acStack_1fc[3] = '\0';
  acStack_1fc[4] = '\0';
  acStack_1fc[5] = '\0';
  acStack_1fc[6] = '\0';
  acStack_1fc[7] = '\0';
  acStack_1fc[8] = '\0';
  acStack_1fc[9] = '\0';
  acStack_1fc[10] = '\0';
  acStack_1fc[0xb] = '\0';
  acStack_1fc[0xc] = '\0';
  acStack_1fc[0xd] = '\0';
  acStack_1fc[0xe] = '\0';
  acStack_1fc[0xf] = '\0';
  uStack_1ec = 0;
  iStack_1a8 = -1;
  iVar1 = mac_auth_profile_get_max_vlan();
  iVar1 = FUN_004082a0(iVar1 + 1,4,0x1d7);
  if (iVar1 == 0) {
    if (macauth_err_switch == 0) {
      iVar2 = -1;
    }
    else {
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_add",0x1da);
      iVar2 = -1;
    }
  }
  else {
    iVar2 = mac_auth_profile_get_max_mac();
    iVar3 = FUN_004082a0(iVar2 + 0x1fU >> 5,4,0x1dd);
    if (iVar3 == 0) {
      if (macauth_err_switch == 0) {
        __dest = (char *)0x0;
        iVar2 = -1;
      }
      else {
        __dest = (char *)0x0;
        printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_add",0x1e0);
        iVar2 = -1;
      }
    }
    else {
      uVar4 = mac_auth_profile_get_max_mac();
      __dest = (char *)FUN_004082a0((uVar4 >> 2) + 1,1,0x1e3);
      if (__dest == (char *)0x0) {
        iVar2 = -1;
        if (macauth_err_switch != 0) {
          pcVar7 = "[MACAUTH_ERROR]%s()/%d no memory.\n";
          uVar5 = 0x1e6;
LAB_00450190:
          printf(pcVar7,"_uac_mac_auth_group_jcs_add",uVar5);
        }
      }
      else {
        iVar2 = mac_auth_db_get_bind_vlan(iVar1);
        if (iVar2 == 0) {
          iVar2 = json_object_object_get(param_1,"enable");
          if (iVar2 == 0) {
            iVar2 = -1;
            if (macauth_err_switch != 0) {
              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
              uVar5 = 0x1f0;
              pcVar8 = "enable";
LAB_00450558:
              printf(pcVar7,"_uac_mac_auth_group_jcs_add",uVar5,pcVar8);
            }
          }
          else {
            iVar6 = json_object_get_type(iVar2);
            if (iVar6 == 6) {
              pcVar7 = (char *)json_object_get_string(iVar2);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_mac_auth_group_jcs_add",0x1f1);
              }
              pcVar7 = "";
            }
            strncpy(acStack_208,pcVar7,9);
            uStack_200 = uStack_200 & 0xff00;
            iStack_1a4 = _macauth_enable_str2int(acStack_208);
            iVar2 = json_object_object_get(param_1,"type");
            if (iVar2 == 0) {
              iVar2 = -1;
              if (macauth_err_switch != 0) {
                pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                uVar5 = 0x1f5;
                pcVar8 = "type";
                goto LAB_00450558;
              }
            }
            else {
              iVar6 = json_object_get_type(iVar2);
              if (iVar6 == 6) {
                pcVar7 = (char *)json_object_get_string(iVar2);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_mac_auth_group_jcs_add",0x1f6);
                }
                pcVar7 = "";
              }
              strncpy(acStack_1fc,pcVar7,0x13);
              uStack_1ec = uStack_1ec & 0xffffff00;
              uStack_30 = _macauth_group_type_str2int(acStack_1fc);
              iVar2 = json_object_object_get(param_1,"name");
              if (iVar2 == 0) {
                iVar2 = -1;
                if (macauth_err_switch != 0) {
                  pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                  uVar5 = 0x1fa;
                  pcVar8 = "name";
                  goto LAB_00450558;
                }
              }
              else {
                iVar6 = json_object_get_type(iVar2);
                if (iVar6 == 6) {
                  pcVar7 = (char *)json_object_get_string(iVar2);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_uac_mac_auth_group_jcs_add",0x1fb);
                  }
                  pcVar7 = "";
                }
                strncpy(acStack_1a0,pcVar7,0x9b);
                uStack_105 = 0;
                iVar2 = json_object_object_get(param_1,&DAT_00684958);
                if (iVar2 == 0) {
                  iVar2 = -1;
                  if (macauth_err_switch != 0) {
                    pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                    uVar5 = 0x1fe;
                    pcVar8 = "note";
                    goto LAB_00450558;
                  }
                }
                else {
                  iVar6 = json_object_get_type(iVar2);
                  if (iVar6 == 6) {
                    pcVar7 = (char *)json_object_get_string(iVar2);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_uac_mac_auth_group_jcs_add",0x1ff);
                    }
                    pcVar7 = "";
                  }
                  strncpy(acStack_104,pcVar7,0x9b);
                  uStack_69 = 0;
                  iVar2 = json_object_object_get(param_1,"vlan");
                  if (iVar2 == 0) {
                    iVar2 = -1;
                    if (macauth_err_switch != 0) {
                      pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                      uVar5 = 0x202;
                      pcVar8 = "vlan";
                      goto LAB_00450558;
                    }
                  }
                  else {
                    iVar6 = json_object_get_type(iVar2);
                    if (iVar6 == 6) {
                      pcVar7 = (char *)json_object_get_string(iVar2);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_mac_auth_group_jcs_add",0x203);
                      }
                      pcVar7 = "";
                    }
                    strncpy(acStack_1e8,pcVar7,0x32);
                    uStack_1b6 = 0;
                    iVar6 = json_object_get_type(iVar2);
                    if (iVar6 == 6) {
                      pcVar7 = (char *)json_object_get_string(iVar2);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_mac_auth_group_jcs_add",0x204);
                      }
                      pcVar7 = "";
                    }
                    strncpy(acStack_68,pcVar7,0x32);
                    uStack_36 = 0;
                    iVar2 = json_object_object_get(param_1,"mac_id_map");
                    if (iVar2 == 0) {
                      iVar2 = -1;
                      if (macauth_err_switch != 0) {
                        pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                        uVar5 = 0x207;
                        pcVar8 = "mac_id_map";
                        goto LAB_00450558;
                      }
                    }
                    else {
                      __n = 0;
                      uVar4 = mac_auth_profile_get_max_mac();
                      if (uVar4 >> 2 != 0) {
                        uVar4 = mac_auth_profile_get_max_mac();
                        __n = uVar4 >> 2;
                      }
                      iVar6 = json_object_get_type(iVar2);
                      if (iVar6 == 6) {
                        pcVar7 = (char *)json_object_get_string(iVar2);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_uac_mac_auth_group_jcs_add",0x208);
                        }
                        pcVar7 = "";
                      }
                      strncpy(__dest,pcVar7,__n);
                      __dest[__n] = '\0';
                      if (macauth_debug_switch != 0) {
                        printf("[MACAUTH_DEBUG]%s()/%d status:%d,type:%d,name:%s,note:%s,vlan:%s,mac:%s\n"
                               ,"_uac_mac_auth_group_jcs_add",0x20a,iStack_1a4,uStack_30,acStack_1a0
                               ,acStack_104,acStack_1e8,__dest);
                      }
                      iVar2 = mac_auth_bind_mac(__dest,iVar3,&uStack_210);
                      if (iVar2 == 0) {
                        iVar2 = mac_auth_db_group_entry_add(auStack_1b4,iVar3);
                        if (iVar2 == 0) {
                          if (macauth_debug_switch != 0) {
                            printf("[MACAUTH_DEBUG]%s()/%d group entry id is %d.\n",
                                   "_uac_mac_auth_group_jcs_add",0x218,iStack_1a8);
                          }
                          iVar2 = mac_auth_bind_vlan(acStack_1e8,iVar1,1,&uStack_20c,iStack_1a8,0);
                          if (iVar2 == 0) {
                            iVar2 = mac_auth_db_set_bind_vlan(iVar1);
                            if (iVar2 == 0) {
                              if (iStack_1a4 != 0) {
                                _uac_mac_auth_sta_check_trigger();
                              }
                              iVar2 = iStack_1a8;
                              if (macauth_debug_switch != 0) {
                                printf("[MACAUTH_DEBUG]%s()/%d vlan cnt is %d, mac cnt: %d.\n",
                                       "_uac_mac_auth_group_jcs_add",0x22b,uStack_20c,uStack_210);
                                iVar2 = iStack_1a8;
                              }
                            }
                            else if (macauth_err_switch != 0) {
                              pcVar7 = 
                              "[MACAUTH_ERROR]%s()/%d mac_auth_db_set_bind_vlan() failed.\n";
                              uVar5 = 0x224;
                              goto LAB_00450190;
                            }
                          }
                          else if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d parse vlan str %s failed.\n";
                            uVar5 = 0x21d;
                            pcVar8 = acStack_1e8;
                            goto LAB_00450558;
                          }
                        }
                        else {
                          iVar2 = -1;
                          if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_entry_add() failed.\n";
                            uVar5 = 0x214;
                            goto LAB_00450190;
                          }
                        }
                      }
                      else {
                        iVar2 = -1;
                        if (macauth_err_switch != 0) {
                          pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() failed.\n";
                          uVar5 = 0x20d;
                          goto LAB_00450190;
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
            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_vlan() failed.\n";
            uVar5 = 0x1eb;
            goto LAB_00450190;
          }
        }
      }
    }
    FUN_00407df0(iVar1);
    if (iVar3 != 0) {
      FUN_00407df0(iVar3);
    }
    if (__dest != (char *)0x0) {
      FUN_00407df0(__dest);
    }
    if (-1 < iVar2) goto LAB_004500b0;
  }
  mac_auth_db_group_entry_release_id(iStack_1a8);
LAB_004500b0:
  uVar5 = json_object_new_int(iVar2);
  json_object_object_add(param_2,"id",uVar5);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_add() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_add",0x245,iVar2);
  }
  return;
}

