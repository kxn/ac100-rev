// func _uac_mac_auth_group_jcs_modify @ 0044eef0 size=2836

void _uac_mac_auth_group_jcs_modify(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *__s;
  int iVar2;
  uint uVar3;
  char *__dest;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  undefined8 uVar9;
  undefined4 local_218;
  undefined4 local_214;
  char local_210 [8];
  ushort local_208;
  char local_204 [16];
  uint local_1f4;
  char acStack_1f0 [50];
  undefined1 local_1be;
  undefined1 auStack_1bc [12];
  undefined4 local_1b0;
  int local_1ac;
  char acStack_1a8 [155];
  undefined1 local_10d;
  char acStack_10c [155];
  undefined1 local_71;
  char acStack_70 [50];
  undefined1 local_3e;
  undefined4 local_38;
  int local_30;
  
  local_214 = 0;
  memset(acStack_1f0,0,0x33);
  local_218 = 0;
  local_210[0] = '\0';
  local_210[1] = '\0';
  local_210[2] = '\0';
  local_210[3] = '\0';
  local_210[4] = '\0';
  local_210[5] = '\0';
  local_210[6] = '\0';
  local_210[7] = '\0';
  local_208 = 0;
  local_204[0] = '\0';
  local_204[1] = '\0';
  local_204[2] = '\0';
  local_204[3] = '\0';
  local_204[4] = '\0';
  local_204[5] = '\0';
  local_204[6] = '\0';
  local_204[7] = '\0';
  local_204[8] = '\0';
  local_204[9] = '\0';
  local_204[10] = '\0';
  local_204[0xb] = '\0';
  local_204[0xc] = '\0';
  local_204[0xd] = '\0';
  local_204[0xe] = '\0';
  local_204[0xf] = '\0';
  local_1f4 = 0;
  memset(auStack_1bc,0,0x188);
  iVar1 = mac_auth_profile_get_max_vlan();
  __s = (void *)FUN_004082a0(iVar1 + 1,4,0x3b2);
  if (__s == (void *)0x0) {
    if (macauth_err_switch == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = -1;
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_modify",0x3b5);
    }
    goto LAB_0044f0a4;
  }
  iVar1 = mac_auth_profile_get_max_vlan();
  memset(__s,-1,(iVar1 + 1) * 4);
  iVar1 = mac_auth_profile_get_max_mac();
  iVar2 = FUN_004082a0(iVar1 + 0x1fU >> 5,4,0x3b9);
  if (iVar2 == 0) {
    if (macauth_err_switch == 0) {
      __dest = (char *)0x0;
      iVar1 = -1;
    }
    else {
      __dest = (char *)0x0;
      printf("[MACAUTH_ERROR]%s()/%d no memory.\n","_uac_mac_auth_group_jcs_modify",0x3bc);
      iVar1 = -1;
    }
  }
  else {
    uVar3 = mac_auth_profile_get_max_mac();
    __dest = (char *)FUN_004082a0((uVar3 >> 2) + 1,1,0x3bf);
    if (__dest == (char *)0x0) {
      iVar1 = -1;
      if (macauth_err_switch != 0) {
        pcVar7 = "[MACAUTH_ERROR]%s()/%d no memory.\n";
        uVar5 = 0x3c2;
        goto LAB_0044f1c0;
      }
    }
    else {
      memset(auStack_1bc,0,0x188);
      local_1b0 = 0xffffffff;
      iVar1 = json_object_object_get(param_1,"id");
      if (iVar1 == 0) {
        iVar1 = -1;
        if (macauth_err_switch != 0) {
          pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
          uVar5 = 0x3c9;
          pcVar8 = "id";
          goto LAB_0044f49c;
        }
      }
      else {
        iVar4 = json_object_get_type(iVar1);
        if (iVar4 == 3) {
          iVar1 = json_object_get_int(iVar1);
        }
        else {
          iVar4 = json_object_get_type();
          if (iVar4 == 2) {
            uVar9 = json_object_get_double(iVar1);
            iVar1 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
          }
          else {
            iVar1 = -1;
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_mac_auth_group_jcs_modify",0x3ca);
            }
          }
        }
        iVar4 = mac_auth_db_group_entry_get(iVar1,auStack_1bc);
        if (iVar4 == 0) {
          local_30 = local_1ac;
          iVar4 = json_object_object_get(param_1,"enable");
          if (iVar4 == 0) {
            iVar1 = -1;
            if (macauth_err_switch != 0) {
              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
              uVar5 = 0x3d4;
              pcVar8 = "enable";
LAB_0044f49c:
              printf(pcVar7,"_uac_mac_auth_group_jcs_modify",uVar5,pcVar8);
            }
          }
          else {
            iVar6 = json_object_get_type(iVar4);
            if (iVar6 == 6) {
              pcVar7 = (char *)json_object_get_string(iVar4);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_mac_auth_group_jcs_modify",0x3d5);
              }
              pcVar7 = "";
            }
            strncpy(local_210,pcVar7,9);
            local_208 = local_208 & 0xff00;
            local_1ac = _macauth_enable_str2int(local_210);
            iVar4 = json_object_object_get(param_1,"type");
            if (iVar4 == 0) {
              iVar1 = -1;
              if (macauth_err_switch != 0) {
                pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                uVar5 = 0x3d9;
                pcVar8 = "type";
                goto LAB_0044f49c;
              }
            }
            else {
              iVar6 = json_object_get_type(iVar4);
              if (iVar6 == 6) {
                pcVar7 = (char *)json_object_get_string(iVar4);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                         ,"_uac_mac_auth_group_jcs_modify",0x3da);
                }
                pcVar7 = "";
              }
              strncpy(local_204,pcVar7,0x13);
              local_1f4 = local_1f4 & 0xffffff00;
              local_38 = _macauth_group_type_str2int(local_204);
              iVar4 = json_object_object_get(param_1,"name");
              if (iVar4 == 0) {
                iVar1 = -1;
                if (macauth_err_switch != 0) {
                  pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                  uVar5 = 0x3de;
                  pcVar8 = "name";
                  goto LAB_0044f49c;
                }
              }
              else {
                iVar6 = json_object_get_type(iVar4);
                if (iVar6 == 6) {
                  pcVar7 = (char *)json_object_get_string(iVar4);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                           ,"_uac_mac_auth_group_jcs_modify",0x3df);
                  }
                  pcVar7 = "";
                }
                strncpy(acStack_1a8,pcVar7,0x9b);
                local_10d = 0;
                iVar4 = json_object_object_get(param_1,&DAT_00684958);
                if (iVar4 == 0) {
                  iVar1 = -1;
                  if (macauth_err_switch != 0) {
                    pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                    uVar5 = 0x3e2;
                    pcVar8 = "note";
                    goto LAB_0044f49c;
                  }
                }
                else {
                  iVar6 = json_object_get_type(iVar4);
                  if (iVar6 == 6) {
                    pcVar7 = (char *)json_object_get_string(iVar4);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                             ,"_uac_mac_auth_group_jcs_modify",0x3e3);
                    }
                    pcVar7 = "";
                  }
                  strncpy(acStack_10c,pcVar7,0x9b);
                  local_71 = 0;
                  iVar4 = json_object_object_get(param_1,"mac_id_map");
                  if (iVar4 == 0) {
                    iVar1 = -1;
                    if (macauth_err_switch != 0) {
                      pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                      uVar5 = 0x3e6;
                      pcVar8 = "mac_id_map";
                      goto LAB_0044f49c;
                    }
                  }
                  else {
                    __n = 0;
                    uVar3 = mac_auth_profile_get_max_mac();
                    if (uVar3 >> 2 != 0) {
                      uVar3 = mac_auth_profile_get_max_mac();
                      __n = uVar3 >> 2;
                    }
                    iVar6 = json_object_get_type(iVar4);
                    if (iVar6 == 6) {
                      pcVar7 = (char *)json_object_get_string(iVar4);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_mac_auth_group_jcs_modify",999);
                      }
                      pcVar7 = "";
                    }
                    strncpy(__dest,pcVar7,__n);
                    __dest[__n] = '\0';
                    iVar4 = json_object_object_get(param_1,"old_vlan");
                    if (iVar4 == 0) {
                      iVar1 = -1;
                      if (macauth_err_switch != 0) {
                        pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                        uVar5 = 0x3eb;
                        pcVar8 = "old_vlan";
                        goto LAB_0044f49c;
                      }
                    }
                    else {
                      iVar6 = json_object_get_type(iVar4);
                      if (iVar6 == 6) {
                        pcVar7 = (char *)json_object_get_string(iVar4);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_uac_mac_auth_group_jcs_modify",0x3ec);
                        }
                        pcVar7 = "";
                      }
                      strncpy(acStack_1f0,pcVar7,0x32);
                      local_1be = 0;
                      if (macauth_debug_switch != 0) {
                        printf("[MACAUTH_DEBUG]%s()/%d status:%d,type:%d,name:%s,note:%s,vlan:%s,mac:%s\n"
                               ,"_uac_mac_auth_group_jcs_modify",0x3f0,local_1ac,local_38,
                               acStack_1a8,acStack_10c,acStack_1f0,__dest);
                      }
                      iVar4 = mac_auth_db_get_bind_vlan(__s);
                      if (iVar4 == 0) {
                        iVar4 = mac_auth_bind_vlan(acStack_1f0,__s,1,&local_214,0xffffffff,1);
                        if (iVar4 == 0) {
                          memset(acStack_1f0,0,0x33);
                          iVar4 = json_object_object_get(param_1,"vlan");
                          if (iVar4 == 0) {
                            iVar1 = -1;
                            if (macauth_err_switch != 0) {
                              pcVar7 = "[MACAUTH_ERROR]%s()/%d %s not found!\n";
                              uVar5 = 0x400;
                              pcVar8 = "vlan";
                              goto LAB_0044f49c;
                            }
                          }
                          else {
                            iVar6 = json_object_get_type(iVar4);
                            if (iVar6 == 6) {
                              pcVar7 = (char *)json_object_get_string(iVar4);
                            }
                            else {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                       ,"_uac_mac_auth_group_jcs_modify",0x401);
                              }
                              pcVar7 = "";
                            }
                            strncpy(acStack_1f0,pcVar7,0x32);
                            local_1be = 0;
                            iVar6 = json_object_get_type(iVar4);
                            if (iVar6 == 6) {
                              pcVar7 = (char *)json_object_get_string(iVar4);
                            }
                            else {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                       ,"_uac_mac_auth_group_jcs_modify",0x402);
                              }
                              pcVar7 = "";
                            }
                            strncpy(acStack_70,pcVar7,0x32);
                            local_3e = 0;
                            local_214 = 0;
                            iVar4 = mac_auth_bind_vlan(acStack_1f0,__s,1,&local_214,iVar1,0);
                            if (iVar4 == 0) {
                              if (macauth_debug_switch != 0) {
                                printf("[MACAUTH_DEBUG]%s()/%d vlan cnt is %d.\n",
                                       "_uac_mac_auth_group_jcs_modify",0x40d,local_214);
                              }
                              iVar6 = mac_auth_bind_mac(__dest,iVar2,&local_218);
                              if (iVar6 == 0) {
                                if (macauth_debug_switch != 0) {
                                  printf("[MACAUTH_DEBUG]%s()/%d mac cnt is %d.\n",
                                         "_uac_mac_auth_group_jcs_modify",0x414,local_218);
                                }
                                iVar4 = mac_auth_db_group_entry_set(auStack_1bc,__s,iVar2);
                                if (iVar4 == 0) {
                                  if ((local_1ac != 0) || (local_30 != 0)) {
                                    _uac_mac_auth_sta_check_trigger();
                                  }
                                }
                                else {
                                  iVar1 = iVar4;
                                  if (macauth_err_switch != 0) {
                                    pcVar7 = 
                                    "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_set() failed.\n";
                                    uVar5 = 0x418;
                                    goto LAB_0044f1c0;
                                  }
                                }
                              }
                              else {
                                iVar1 = iVar4;
                                if (macauth_err_switch != 0) {
                                  pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_bind_mac() failed.\n";
                                  uVar5 = 0x411;
LAB_0044f1c0:
                                  printf(pcVar7,"_uac_mac_auth_group_jcs_modify",uVar5);
                                }
                              }
                            }
                            else {
                              iVar1 = iVar4;
                              if (macauth_err_switch != 0) {
                                pcVar7 = "[MACAUTH_ERROR]%s()/%d parse vlan str %s failed.\n";
                                uVar5 = 0x409;
                                pcVar8 = acStack_1f0;
                                goto LAB_0044f49c;
                              }
                            }
                          }
                        }
                        else {
                          iVar1 = -1;
                          if (macauth_err_switch != 0) {
                            pcVar7 = "[MACAUTH_ERROR]%s()/%d parse vlan str %s failed.\n";
                            uVar5 = 0x3fa;
                            pcVar8 = acStack_1f0;
                            goto LAB_0044f49c;
                          }
                        }
                      }
                      else {
                        iVar1 = -1;
                        if (macauth_err_switch != 0) {
                          pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_get_bind_vlan() failed.\n";
                          uVar5 = 0x3f4;
                          goto LAB_0044f1c0;
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
          iVar1 = -1;
          if (macauth_err_switch != 0) {
            pcVar7 = "[MACAUTH_ERROR]%s()/%d mac_auth_db_mac_entry_get() failed.\n";
            uVar5 = 0x3ce;
            goto LAB_0044f1c0;
          }
        }
      }
    }
  }
  FUN_00407df0(__s);
  if (iVar2 != 0) {
    FUN_00407df0(iVar2);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
LAB_0044f0a4:
  uVar5 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"id",uVar5);
  if (macauth_debug_switch != 0) {
    printf("[MACAUTH_DEBUG]%s()/%d _uac_mac_auth_group_jcs_set() finish, id=%d.\n",
           "_uac_mac_auth_group_jcs_modify",0x432,iVar1);
  }
  return;
}

