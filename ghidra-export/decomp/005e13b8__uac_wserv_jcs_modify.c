// func _uac_wserv_jcs_modify @ 005e13b8 size=9188

void _uac_wserv_jcs_modify(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 auVar9 [4];
  char *pcVar10;
  char *pcVar11;
  undefined4 *__src;
  size_t __n;
  char *pcVar12;
  undefined8 uVar13;
  uint local_920;
  undefined4 local_91c;
  undefined4 local_918;
  undefined4 local_914;
  undefined4 local_910;
  char acStack_90c [64];
  undefined1 local_8cc;
  undefined4 local_8c8;
  undefined4 local_8c4;
  undefined4 local_8c0;
  char acStack_8bc [39];
  undefined1 local_895;
  undefined4 local_894;
  undefined4 local_890;
  char acStack_88c [64];
  undefined1 local_84c;
  char acStack_848 [127];
  undefined1 local_7c9;
  char *local_7c8;
  char acStack_7c4 [150];
  undefined1 local_72e;
  undefined1 local_72d [4];
  undefined1 local_729 [4];
  byte local_725;
  uint local_724;
  uint local_720;
  undefined4 local_71c;
  char acStack_718 [49];
  undefined1 local_6e7;
  uint local_6e6;
  uint local_6e2;
  int local_6de;
  undefined1 auStack_6da [128];
  undefined4 local_65a;
  undefined4 local_656;
  undefined1 local_652;
  undefined1 local_651;
  undefined1 local_64e;
  undefined1 local_64d;
  undefined2 local_64c;
  undefined2 local_64a;
  undefined2 local_648;
  undefined1 local_646;
  undefined1 local_645;
  undefined1 local_644;
  undefined1 auStack_640 [283];
  int local_525;
  int local_521;
  byte local_51d;
  uint local_51c;
  uint local_518;
  undefined1 auStack_514 [220];
  undefined1 auStack_438 [517];
  undefined1 auStack_233 [523];
  
  memset(auStack_438,0,0x40a);
  local_91c = 0;
  local_920 = 0;
  iVar4 = apmngr_db_get_ap_max();
  uVar5 = apmngr_db_get_ap_max();
  iVar4 = FUN_004082a0((iVar4 >> 5) + (uint)((uVar5 & 0x1f) != 0),4,0xaf7);
  if (iVar4 == 0) {
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n","_uac_wserv_jcs_modify",0xafa);
LAB_005e159c:
      pcVar12 = (char *)0xffffffff;
      pcVar11 = (char *)0xffffffff;
      goto LAB_005e14c4;
    }
  }
  else {
    memset(auStack_640,0,0x205);
    memset(acStack_848,0,0x205);
    iVar6 = json_object_object_get(param_1,"serv_id");
    if (iVar6 != 0) {
      iVar7 = json_object_get_type(iVar6);
      if (iVar7 == 3) {
        pcVar12 = (char *)json_object_get_int(iVar6);
      }
      else {
        iVar7 = json_object_get_type();
        if (iVar7 == 2) {
          uVar13 = json_object_get_double(iVar6);
          pcVar12 = (char *)__fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
        }
        else {
          pcVar12 = (char *)0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_jcs_modify",0xb04);
          }
        }
      }
      if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_modify() begin, id=%d.\r\n",
               "_uac_wserv_jcs_modify",0xb06,pcVar12);
      }
      iVar6 = wserv_db_get_entry_by_id(pcVar12,auStack_640);
      pcVar11 = (char *)0xffffffff;
      if (iVar6 != 0) goto LAB_005e14c4;
      memcpy(acStack_848,auStack_640,0x205);
      local_7c8 = pcVar12;
      iVar6 = json_object_object_get(param_1,"enable");
      if ((iVar6 == 0) || (iVar7 = json_object_get_type(iVar6), iVar7 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_modify",0xb10);
        }
        pcVar11 = "";
      }
      else {
        pcVar11 = (char *)json_object_get_string(iVar6);
      }
      strncpy((char *)&local_920,pcVar11,3);
      local_920 = local_920 & 0xffffff00;
      iVar6 = strcmp((char *)&local_920,"on");
      if (iVar6 == 0) {
        local_72d = (undefined1  [4])0x1;
      }
      else {
        uVar5 = (uint)local_72d & 3;
        puVar3 = (uint *)(local_72d + -uVar5);
        *puVar3 = *puVar3 & -1 << (4 - uVar5) * 8 | 0U >> uVar5 * 8;
        puVar1 = local_72d + 3;
        uVar5 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar5) =
             *(uint *)(puVar1 + -uVar5) & 0xffffffffU >> (uVar5 + 1) * 8 | 0 << (3 - uVar5) * 8;
      }
      iVar6 = json_object_object_get(param_1,"auto_bind");
      if (iVar6 == 0) {
        pcVar11 = (char *)0xffffffff;
        if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_005e14c4;
        pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
        uVar8 = 0xb1b;
        pcVar11 = "auto_bind";
      }
      else {
        iVar7 = json_object_get_type(iVar6);
        if (iVar7 == 6) {
          pcVar11 = (char *)json_object_get_string(iVar6);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_wserv_jcs_modify",0xb1c);
          }
          pcVar11 = "";
        }
        strncpy((char *)&local_920,pcVar11,3);
        local_920 = local_920 & 0xffffff00;
        iVar6 = strncmp((char *)&local_920,"on",4);
        if (iVar6 == 0) {
          local_729 = (undefined1  [4])0x1;
        }
        else {
          uVar5 = (uint)local_729 & 3;
          puVar3 = (uint *)(local_729 + -uVar5);
          *puVar3 = *puVar3 & -1 << (4 - uVar5) * 8 | 0U >> uVar5 * 8;
          puVar1 = local_729 + 3;
          uVar5 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar5) =
               *(uint *)(puVar1 + -uVar5) & 0xffffffffU >> (uVar5 + 1) * 8 | 0 << (3 - uVar5) * 8;
        }
        if (local_729 == (undefined1  [4])0x0) {
          local_725 = 0;
          local_724 = local_724 & 0xff | 0x7f7f00;
LAB_005e1708:
          iVar6 = json_object_object_get(param_1,"ssid_id");
          if (iVar6 != 0) {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 6) {
              pcVar11 = (char *)json_object_get_string(iVar6);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_jcs_modify",0xb3c);
              }
              pcVar11 = "";
            }
            strncpy(acStack_848,pcVar11,0x7f);
            local_7c9 = 0;
          }
          iVar6 = json_object_object_get(param_1,"ssid");
          if ((iVar6 == 0) || (iVar7 = json_object_get_type(iVar6), iVar7 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_uac_wserv_jcs_modify",0xb40);
            }
            pcVar11 = "";
          }
          else {
            pcVar11 = (char *)json_object_get_string(iVar6);
          }
          strncpy(acStack_718,pcVar11,0x31);
          local_6e7 = 0;
          iVar6 = json_object_object_get(param_1,"ssid_code_type");
          if (iVar6 == 0) {
LAB_005e17f4:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_wserv_jcs_modify",0xb43);
            }
            local_71c = 0xffffffff;
          }
          else {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 3) {
              local_71c = json_object_get_int(iVar6);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 != 2) goto LAB_005e17f4;
              uVar13 = json_object_get_double(iVar6);
              local_71c = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            }
          }
          iVar6 = json_object_object_get(param_1,&DAT_006ce874);
          if ((iVar6 == 0) || (iVar7 = json_object_get_type(iVar6), iVar7 != 6)) {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_uac_wserv_jcs_modify",0xb46);
            }
            pcVar11 = "";
          }
          else {
            pcVar11 = (char *)json_object_get_string(iVar6);
          }
          strncpy(acStack_7c4,pcVar11,0x96);
          local_72e = 0;
          iVar6 = json_object_object_get(param_1,"isolate");
          if (iVar6 == 0) {
LAB_005e18a0:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                     ,"_uac_wserv_jcs_modify",0xb49);
            }
            local_6e6 = 0;
          }
          else {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 1) {
              local_6e6 = json_object_get_boolean(iVar6);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 != 3) goto LAB_005e18a0;
              iVar6 = json_object_get_int(iVar6);
              local_6e6 = (uint)(iVar6 != 0);
            }
          }
          iVar6 = json_object_object_get(param_1,&DAT_006a6fbc);
          if (iVar6 == 0) {
LAB_005e18f8:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                     ,"_uac_wserv_jcs_modify",0xb4c);
            }
            local_6e2 = 0;
          }
          else {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 1) {
              local_6e2 = json_object_get_boolean(iVar6);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 != 3) goto LAB_005e18f8;
              iVar6 = json_object_get_int(iVar6);
              local_6e2 = (uint)(iVar6 != 0);
            }
          }
          iVar6 = json_object_object_get(param_1,"encryption");
          if (iVar6 == 0) {
LAB_005e1950:
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                     "_uac_wserv_jcs_modify",0xb4f);
            }
            local_6de = -1;
          }
          else {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 3) {
              local_6de = json_object_get_int(iVar6);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 != 2) goto LAB_005e1950;
              uVar13 = json_object_get_double(iVar6);
              local_6de = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
            }
          }
          memset(auStack_6da,0,0x80);
          if (local_6de == 2) {
            iVar6 = json_object_object_get(param_1,"auth");
            if (iVar6 == 0) {
              pcVar11 = (char *)0xffffffff;
              if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
              goto LAB_005e14c4;
              pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
              uVar8 = 0xb6d;
              pcVar11 = "auth";
            }
            else {
              iVar7 = json_object_get_type(iVar6);
              if (iVar7 == 3) {
                local_8c8 = json_object_get_int(iVar6);
              }
              else {
                iVar7 = json_object_get_type();
                if (iVar7 == 2) {
                  uVar13 = json_object_get_double(iVar6);
                  local_8c8 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_modify",0xb6e);
                  }
                  local_8c8 = 0xffffffff;
                }
              }
              iVar6 = json_object_object_get(param_1,"cipher");
              if (iVar6 == 0) {
                pcVar11 = (char *)0xffffffff;
                if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                goto LAB_005e14c4;
                pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                uVar8 = 0xb71;
                pcVar11 = "cipher";
              }
              else {
                iVar7 = json_object_get_type(iVar6);
                if (iVar7 == 3) {
                  local_8c4 = json_object_get_int(iVar6);
                }
                else {
                  iVar7 = json_object_get_type();
                  if (iVar7 == 2) {
                    uVar13 = json_object_get_double(iVar6);
                    local_8c4 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_uac_wserv_jcs_modify",0xb72);
                    }
                    local_8c4 = 0xffffffff;
                  }
                }
                iVar6 = json_object_object_get(param_1,"key_update_intv");
                if (iVar6 == 0) {
                  pcVar11 = (char *)0xffffffff;
                  if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                  goto LAB_005e14c4;
                  pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                  uVar8 = 0xb75;
                  pcVar11 = "key_update_intv";
                }
                else {
                  iVar7 = json_object_get_type(iVar6);
                  if (iVar7 == 3) {
                    local_8c0 = json_object_get_int(iVar6);
                  }
                  else {
                    iVar7 = json_object_get_type();
                    if (iVar7 == 2) {
                      uVar13 = json_object_get_double(iVar6);
                      local_8c0 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb76);
                      }
                      local_8c0 = 0xffffffff;
                    }
                  }
                  iVar6 = json_object_object_get(param_1,"radius_ip");
                  if (iVar6 == 0) {
                    pcVar11 = (char *)0xffffffff;
                    if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                    goto LAB_005e14c4;
                    pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                    uVar8 = 0xb79;
                    pcVar11 = "radius_ip";
                  }
                  else {
                    iVar7 = json_object_get_type(iVar6);
                    if (iVar7 == 6) {
                      pcVar11 = (char *)json_object_get_string(iVar6);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb7a);
                      }
                      pcVar11 = "";
                    }
                    strncpy(acStack_8bc,pcVar11,0x27);
                    local_895 = 0;
                    iVar6 = json_object_object_get(param_1,"radius_port");
                    if (iVar6 == 0) {
                      pcVar11 = (char *)0xffffffff;
                      if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                      goto LAB_005e14c4;
                      pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                      uVar8 = 0xb7d;
                      pcVar11 = "radius_port";
                    }
                    else {
                      iVar7 = json_object_get_type(iVar6);
                      if (iVar7 == 3) {
                        local_894 = json_object_get_int(iVar6);
                      }
                      else {
                        iVar7 = json_object_get_type();
                        if (iVar7 == 2) {
                          uVar13 = json_object_get_double(iVar6);
                          local_894 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_wserv_jcs_modify",0xb7e);
                          }
                          local_894 = 0xffffffff;
                        }
                      }
                      iVar6 = json_object_object_get(param_1,"radius_acct_port");
                      if (iVar6 == 0) {
                        pcVar11 = (char *)0xffffffff;
                        if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                        goto LAB_005e14c4;
                        pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                        uVar8 = 0xb81;
                        pcVar11 = "radius_acct_port";
                      }
                      else {
                        iVar7 = json_object_get_type(iVar6);
                        if (iVar7 == 3) {
                          local_890 = json_object_get_int(iVar6);
                        }
                        else {
                          iVar7 = json_object_get_type();
                          if (iVar7 == 2) {
                            uVar13 = json_object_get_double(iVar6);
                            local_890 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                          }
                          else {
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_uac_wserv_jcs_modify",0xb82);
                            }
                            local_890 = 0xffffffff;
                          }
                        }
                        iVar6 = json_object_object_get(param_1,"radius_pwd");
                        if (iVar6 != 0) {
                          iVar7 = json_object_get_type(iVar6);
                          if (iVar7 == 6) {
                            pcVar11 = (char *)json_object_get_string(iVar6);
                          }
                          else {
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                     ,"_uac_wserv_jcs_modify",0xb86);
                            }
                            pcVar11 = "";
                          }
                          strncpy(acStack_88c,pcVar11,0x40);
                          local_84c = 0;
                          __src = &local_8c8;
                          __n = 0x80;
                          goto LAB_005e219c;
                        }
                        pcVar11 = (char *)0xffffffff;
                        if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                        goto LAB_005e14c4;
                        pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                        uVar8 = 0xb85;
                        pcVar11 = "radius_pwd";
                      }
                    }
                  }
                }
              }
            }
          }
          else if ((local_6de == 4) || (local_6de == 1)) {
            iVar6 = json_object_object_get(param_1,"auth");
            if (iVar6 == 0) {
              pcVar11 = (char *)0xffffffff;
              if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
              goto LAB_005e14c4;
              pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
              uVar8 = 0xb5a;
              pcVar11 = "auth";
            }
            else {
              iVar7 = json_object_get_type(iVar6);
              if (iVar7 == 3) {
                local_918 = json_object_get_int(iVar6);
              }
              else {
                iVar7 = json_object_get_type();
                if (iVar7 == 2) {
                  uVar13 = json_object_get_double(iVar6);
                  local_918 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_modify",0xb5b);
                  }
                  local_918 = 0xffffffff;
                }
              }
              iVar6 = json_object_object_get(param_1,"cipher");
              if (iVar6 == 0) {
                pcVar11 = (char *)0xffffffff;
                if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                goto LAB_005e14c4;
                pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                uVar8 = 0xb5e;
                pcVar11 = "cipher";
              }
              else {
                iVar7 = json_object_get_type(iVar6);
                if (iVar7 == 3) {
                  local_914 = json_object_get_int(iVar6);
                }
                else {
                  iVar7 = json_object_get_type();
                  if (iVar7 == 2) {
                    uVar13 = json_object_get_double(iVar6);
                    local_914 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_uac_wserv_jcs_modify",0xb5f);
                    }
                    local_914 = 0xffffffff;
                  }
                }
                iVar6 = json_object_object_get(param_1,"key_update_intv");
                if (iVar6 == 0) {
                  pcVar11 = (char *)0xffffffff;
                  if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                  goto LAB_005e14c4;
                  pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                  uVar8 = 0xb62;
                  pcVar11 = "key_update_intv";
                }
                else {
                  iVar7 = json_object_get_type(iVar6);
                  if (iVar7 == 3) {
                    local_910 = json_object_get_int(iVar6);
                  }
                  else {
                    iVar7 = json_object_get_type();
                    if (iVar7 == 2) {
                      uVar13 = json_object_get_double(iVar6);
                      local_910 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb63);
                      }
                      local_910 = 0xffffffff;
                    }
                  }
                  iVar6 = json_object_object_get(param_1,"key");
                  if (iVar6 != 0) {
                    iVar7 = json_object_get_type(iVar6);
                    if (iVar7 == 6) {
                      pcVar11 = (char *)json_object_get_string(iVar6);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb67);
                      }
                      pcVar11 = "";
                    }
                    strncpy(acStack_90c,pcVar11,0x40);
                    __src = &local_918;
                    local_8cc = 0;
                    __n = 0x50;
LAB_005e219c:
                    memcpy(auStack_6da,__src,__n);
                    goto LAB_005e19a4;
                  }
                  pcVar11 = (char *)0xffffffff;
                  if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                  goto LAB_005e14c4;
                  pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                  uVar8 = 0xb66;
                  pcVar11 = "key";
                }
              }
            }
          }
          else {
LAB_005e19a4:
            iVar6 = json_object_object_get(param_1,"bw_ctrl_enable");
            if (iVar6 == 0) {
              pcVar11 = (char *)0xffffffff;
              if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
              goto LAB_005e14c4;
              pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
              uVar8 = 0xb8f;
              pcVar11 = "bw_ctrl_enable";
            }
            else {
              iVar7 = json_object_get_type(iVar6);
              if (iVar7 == 3) {
                local_652 = json_object_get_int(iVar6);
              }
              else {
                iVar7 = json_object_get_type();
                if (iVar7 == 2) {
                  uVar13 = json_object_get_double(iVar6);
                  local_652 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_modify",0xb90);
                  }
                  local_652 = 0xff;
                }
              }
              iVar6 = json_object_object_get(param_1,"bw_ctrl_mode");
              if (iVar6 == 0) {
                pcVar11 = (char *)0xffffffff;
                if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                goto LAB_005e14c4;
                pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                uVar8 = 0xb93;
                pcVar11 = "bw_ctrl_mode";
              }
              else {
                iVar7 = json_object_get_type(iVar6);
                if (iVar7 == 3) {
                  local_651 = json_object_get_int(iVar6);
                }
                else {
                  iVar7 = json_object_get_type();
                  if (iVar7 == 2) {
                    uVar13 = json_object_get_double(iVar6);
                    local_651 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_uac_wserv_jcs_modify",0xb94);
                    }
                    local_651 = 0xff;
                  }
                }
                iVar6 = json_object_object_get(param_1,"bw_ctrl_mode");
                if (iVar6 == 0) {
                  pcVar11 = (char *)0xffffffff;
                  if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                  goto LAB_005e14c4;
                  pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                  uVar8 = 0xb97;
                  pcVar11 = "bw_ctrl_mode";
                }
                else {
                  iVar7 = json_object_get_type(iVar6);
                  if (iVar7 == 3) {
                    local_651 = json_object_get_int(iVar6);
                  }
                  else {
                    iVar7 = json_object_get_type();
                    if (iVar7 == 2) {
                      uVar13 = json_object_get_double(iVar6);
                      local_651 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb98);
                      }
                      local_651 = 0xff;
                    }
                  }
                  iVar6 = json_object_object_get(param_1,"igmp_snooping_enable");
                  if (iVar6 == 0) {
                    pcVar11 = (char *)0xffffffff;
                    if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                    goto LAB_005e14c4;
                    pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                    uVar8 = 0xb9b;
                    pcVar11 = "igmp_snooping_enable";
                  }
                  else {
                    iVar7 = json_object_get_type(iVar6);
                    if (iVar7 == 6) {
                      pcVar11 = (char *)json_object_get_string(iVar6);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_modify",0xb9c);
                      }
                      pcVar11 = "";
                    }
                    strncpy((char *)&local_920,pcVar11,3);
                    local_920 = local_920 & 0xffffff00;
                    iVar6 = strcmp((char *)&local_920,"on");
                    local_64e = iVar6 == 0;
                    iVar6 = json_object_object_get(param_1,"igmp_drop_unknown");
                    if (iVar6 == 0) {
                      pcVar11 = (char *)0xffffffff;
                      if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                      goto LAB_005e14c4;
                      pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                      uVar8 = 0xba7;
                      pcVar11 = "igmp_drop_unknown";
                    }
                    else {
                      iVar7 = json_object_get_type(iVar6);
                      if (iVar7 == 3) {
                        local_64d = json_object_get_int(iVar6);
                      }
                      else {
                        iVar7 = json_object_get_type();
                        if (iVar7 == 2) {
                          uVar13 = json_object_get_double(iVar6);
                          local_64d = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                        }
                        else {
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_uac_wserv_jcs_modify",0xba8);
                          }
                          local_64d = 0xff;
                        }
                      }
                      iVar6 = json_object_object_get(param_1,"igmp_2g_rate");
                      if (iVar6 == 0) {
                        pcVar11 = (char *)0xffffffff;
                        if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                        goto LAB_005e14c4;
                        pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                        uVar8 = 0xbab;
                        pcVar11 = "igmp_2g_rate";
                      }
                      else {
                        iVar7 = json_object_get_type(iVar6);
                        if (iVar7 == 3) {
                          local_64c = json_object_get_int(iVar6);
                        }
                        else {
                          iVar7 = json_object_get_type();
                          if (iVar7 == 2) {
                            uVar13 = json_object_get_double(iVar6);
                            local_64c = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
                          }
                          else {
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_uac_wserv_jcs_modify",0xbac);
                            }
                            local_64c = 0xffff;
                          }
                        }
                        iVar6 = json_object_object_get(param_1,"igmp_5g_rate");
                        if (iVar6 == 0) {
                          pcVar11 = (char *)0xffffffff;
                          if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                          goto LAB_005e14c4;
                          pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                          uVar8 = 0xbaf;
                          pcVar11 = "igmp_5g_rate";
                        }
                        else {
                          iVar7 = json_object_get_type(iVar6);
                          if (iVar7 == 3) {
                            local_64a = json_object_get_int(iVar6);
                          }
                          else {
                            iVar7 = json_object_get_type();
                            if (iVar7 == 2) {
                              uVar13 = json_object_get_double(iVar6);
                              local_64a = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13)
                              ;
                            }
                            else {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                       ,"_uac_wserv_jcs_modify",0xbb0);
                              }
                              local_64a = 0xffff;
                            }
                          }
                          iVar6 = json_object_object_get(param_1,"igmp_query_interval");
                          if (iVar6 == 0) {
                            pcVar11 = (char *)0xffffffff;
                            if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
                            goto LAB_005e14c4;
                            pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                            uVar8 = 0xbb3;
                            pcVar11 = "igmp_query_interval";
                          }
                          else {
                            iVar7 = json_object_get_type(iVar6);
                            if (iVar7 == 3) {
                              local_648 = json_object_get_int(iVar6);
                            }
                            else {
                              iVar7 = json_object_get_type();
                              if (iVar7 == 2) {
                                uVar13 = json_object_get_double(iVar6);
                                local_648 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),
                                                         (int)uVar13);
                              }
                              else {
                                if (jcs_err_switch != 0) {
                                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                         ,"_uac_wserv_jcs_modify",0xbb4);
                                }
                                local_648 = 0xffff;
                              }
                            }
                            iVar6 = json_object_object_get(param_1,"igmp_max_resp_time");
                            if (iVar6 == 0) {
                              pcVar11 = (char *)0xffffffff;
                              if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)
                                 ) goto LAB_005e14c4;
                              pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                              uVar8 = 2999;
                              pcVar11 = "igmp_max_resp_time";
                            }
                            else {
                              iVar7 = json_object_get_type(iVar6);
                              if (iVar7 == 3) {
                                local_646 = json_object_get_int(iVar6);
                              }
                              else {
                                iVar7 = json_object_get_type();
                                if (iVar7 == 2) {
                                  uVar13 = json_object_get_double(iVar6);
                                  local_646 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),
                                                           (int)uVar13);
                                }
                                else {
                                  if (jcs_err_switch != 0) {
                                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                           ,"_uac_wserv_jcs_modify",3000);
                                  }
                                  local_646 = 0xff;
                                }
                              }
                              iVar6 = json_object_object_get(param_1,"igmp_snooping_switch");
                              if (iVar6 == 0) {
                                pcVar11 = (char *)0xffffffff;
                                if ((g_wserv_error == 0) ||
                                   (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_005e14c4;
                                pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                                uVar8 = 0xbbb;
                                pcVar11 = "igmp_snooping_switch";
                              }
                              else {
                                iVar7 = json_object_get_type(iVar6);
                                if (iVar7 == 6) {
                                  pcVar11 = (char *)json_object_get_string(iVar6);
                                }
                                else {
                                  if (jcs_err_switch != 0) {
                                    printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                           ,"_uac_wserv_jcs_modify",0xbbc);
                                  }
                                  pcVar11 = "";
                                }
                                strncpy((char *)&local_920,pcVar11,3);
                                local_920 = local_920 & 0xffffff00;
                                iVar6 = strcmp((char *)&local_920,"on");
                                local_645 = iVar6 == 0;
                                iVar6 = json_object_object_get(param_1,"igmp_query_switch");
                                if (iVar6 == 0) {
                                  pcVar11 = (char *)0xffffffff;
                                  if ((g_wserv_error == 0) ||
                                     (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_005e14c4;
                                  pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                                  uVar8 = 0xbc7;
                                  pcVar11 = "igmp_query_switch";
                                }
                                else {
                                  iVar7 = json_object_get_type(iVar6);
                                  if (iVar7 == 6) {
                                    pcVar11 = (char *)json_object_get_string(iVar6);
                                  }
                                  else {
                                    if (jcs_err_switch != 0) {
                                      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                             ,"_uac_wserv_jcs_modify",0xbc8);
                                    }
                                    pcVar11 = "";
                                  }
                                  strncpy((char *)&local_920,pcVar11,3);
                                  local_920 = local_920 & 0xffffff00;
                                  iVar6 = strcmp((char *)&local_920,"on");
                                  local_644 = iVar6 == 0;
                                  iVar6 = json_object_object_get(param_1,"up_limit");
                                  if (iVar6 == 0) {
                                    pcVar11 = (char *)0xffffffff;
                                    if ((g_wserv_error == 0) ||
                                       (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                    goto LAB_005e14c4;
                                    pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                                    uVar8 = 0xbd4;
                                    pcVar11 = "up_limit";
                                  }
                                  else {
                                    iVar7 = json_object_get_type(iVar6);
                                    if (iVar7 == 3) {
                                      local_65a = json_object_get_int(iVar6);
                                    }
                                    else {
                                      iVar7 = json_object_get_type();
                                      if (iVar7 == 2) {
                                        uVar13 = json_object_get_double(iVar6);
                                        local_65a = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),
                                                                 (int)uVar13);
                                      }
                                      else {
                                        if (jcs_err_switch != 0) {
                                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                                 ,"_uac_wserv_jcs_modify",0xbd5);
                                        }
                                        local_65a = 0xffffffff;
                                      }
                                    }
                                    iVar6 = json_object_object_get(param_1,"down_limit");
                                    if (iVar6 == 0) {
                                      pcVar11 = (char *)0xffffffff;
                                      if ((g_wserv_error == 0) ||
                                         (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                      goto LAB_005e14c4;
                                      pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
                                      uVar8 = 0xbd8;
                                      pcVar11 = "down_limit";
                                    }
                                    else {
                                      iVar7 = json_object_get_type(iVar6);
                                      if (iVar7 == 3) {
                                        local_656 = json_object_get_int(iVar6);
                                      }
                                      else {
                                        iVar7 = json_object_get_type();
                                        if (iVar7 == 2) {
                                          uVar13 = json_object_get_double(iVar6);
                                          local_656 = __fixunsdfsi((int)((ulonglong)uVar13 >> 0x20),
                                                                   (int)uVar13);
                                        }
                                        else {
                                          if (jcs_err_switch != 0) {
                                            printf(
                                                  "[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                                  ,"_uac_wserv_jcs_modify",0xbd9);
                                          }
                                          local_656 = 0xffffffff;
                                        }
                                      }
                                      iVar6 = json_object_object_get(param_1,"mlo_switch");
                                      if (iVar6 != 0) {
                                        iVar7 = json_object_get_type(iVar6);
                                        if (iVar7 == 1) {
                                          local_720 = json_object_get_boolean(iVar6);
                                        }
                                        else {
                                          iVar7 = json_object_get_type();
                                          if (iVar7 == 3) {
                                            iVar6 = json_object_get_int(iVar6);
                                            local_720 = (uint)(iVar6 != 0);
                                          }
                                          else if (jcs_err_switch == 0) {
                                            local_720 = 0;
                                          }
                                          else {
                                            printf(
                                                  "[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                                                  ,"_uac_wserv_jcs_modify",0xbdd);
                                            local_720 = 0;
                                          }
                                        }
                                      }
                                      iVar6 = memcmp(auStack_640,acStack_848,0x205);
                                      if (iVar6 != 0) {
                                        uVar5 = 1;
                                        iVar6 = memcmp(auStack_514,&local_71c,0xd9);
                                        if ((iVar6 == 0) &&
                                           ((undefined1  [4])local_525 == local_72d)) {
                                          uVar5 = (uint)(local_518 != local_720);
                                        }
                                        bVar2 = local_72d != (undefined1  [4])0x0;
                                        if ((g_wserv_debug != 0) &&
                                           (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                          printf("<wserv>[debug]%s(): %d  -> need_rebind: %d\r\n",
                                                 "_uac_wserv_jcs_modify",0xbef,uVar5);
                                        }
                                        if (uVar5 == 0) {
LAB_005e2f10:
                                          if ((g_wserv_debug != 0) &&
                                             (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                            printf(
                                                  "<wserv>[debug]%s(): %d  -> modify wservice[%d].\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xbfd,pcVar12);
                                          }
                                          pcVar11 = (char *)wserv_db_entry_modify(acStack_848);
                                          if (pcVar11 != (char *)0xffffffff) {
                                            memcpy(auStack_438,acStack_848,0x205);
                                            memcpy(auStack_233,auStack_640,0x205);
                                            uac_wservice_callback_proc(2,auStack_438);
                                            if (!bVar2 && uVar5 != 0) {
                                              if ((g_wserv_debug != 0) &&
                                                 (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                                printf(
                                                  "<wserv>[debug]%s(): %d  -> disable wservice[%d].\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xc0d,pcVar12);
                                              }
                                              pcVar11 = (char *)wserv_db_entry_disable
                                                                          (pcVar12,_uac_wserv_add_cb
                                                                          );
                                            }
                                            if (bVar2 && uVar5 != 0) {
                                              if ((g_wserv_debug != 0) &&
                                                 (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                                printf(
                                                  "<wserv>[debug]%s(): %d  -> enable wservice[%d].\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xc13,pcVar12);
                                              }
                                              pcVar11 = (char *)wserv_db_entry_enable
                                                                          (pcVar12,_uac_wserv_add_cb
                                                                          );
                                            }
                                            if (pcVar11 == (char *)0xffffffff) {
                                              auVar9 = local_729;
                                              if (g_wserv_error != 0) {
                                                iVar6 = is_target_debug_ap();
                                                if (iVar6 == 0) {
                                                  uVar5 = (uint)local_729 & 3;
                                                  auVar9 = (undefined1  [4])
                                                           (*(int *)(local_729 + -uVar5) <<
                                                           uVar5 * 8);
                                                }
                                                else {
                                                  printf(
                                                  "<wserv>[error]%s(): %d  -> wserv_db_entry_enable/disable() add fail\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xc19);
                                                  auVar9 = local_729;
                                                }
                                              }
                                            }
                                            else {
                                              uac_wservice_sync_all_wlan_to_re();
                                              auVar9 = local_729;
                                            }
                                            if ((auVar9 != (undefined1  [4])0x0) &&
                                               ((((undefined1  [4])local_521 != auVar9 ||
                                                 ((local_51c << 8) >> 0x10 !=
                                                  (local_724 << 8) >> 0x10)) ||
                                                ((local_51c >> 0x18 | (uint)local_51d << 8) !=
                                                 (local_724 >> 0x18 | (uint)local_725 << 8))))) {
                                              uac_wservice_refresh_bind_list
                                                        (pcVar12,local_724 >> 0x18 |
                                                                 (uint)local_725 << 8,
                                                         (local_724 << 8) >> 0x10,iVar4,&local_91c);
                                            }
                                            iVar6 = apmngr_db_get_ap_max();
                                            uVar5 = apmngr_db_get_ap_max();
                                            iVar6 = wserv_db_entry_get_binded_ap_id_bm
                                                              (pcVar12,iVar4,
                                                               (iVar6 >> 5) +
                                                               (uint)((uVar5 & 0x1f) != 0),
                                                               &local_91c);
                                            if (((iVar6 != 0) && (g_wserv_error != 0)) &&
                                               (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                              printf(
                                                  "<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xc2f,pcVar12);
                                            }
                                            _uac_wserv_update_aps_md5(iVar4,local_91c);
                                            if (pcVar11 == (char *)0x0) {
                                              pcVar11 = local_7c8;
                                            }
                                            goto LAB_005e14c4;
                                          }
                                          if ((g_wserv_error == 0) ||
                                             (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                          goto LAB_005e14c4;
                                          pcVar10 = 
                                          "<wserv>[error]%s(): %d  -> wserv_db_entry_modify() fail\r\n"
                                          ;
                                          uVar8 = 0xc03;
                                        }
                                        else {
                                          if ((g_wserv_debug != 0) &&
                                             (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                                            printf(
                                                  "<wserv>[debug]%s(): %d  -> disable wservice[%d].\r\n"
                                                  ,"_uac_wserv_jcs_modify",0xbf3,pcVar12);
                                          }
                                          iVar6 = wserv_db_entry_disable(pcVar12,_uac_wserv_del_cb);
                                          if (iVar6 != -1) {
                                            uac_wservice_sync_all_wlan_to_re();
                                            goto LAB_005e2f10;
                                          }
                                          pcVar11 = (char *)0xffffffff;
                                          if ((g_wserv_error == 0) ||
                                             (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                          goto LAB_005e14c4;
                                          pcVar10 = 
                                          "<wserv>[error]%s(): %d  -> wserv_db_entry_disable() fail\r\n"
                                          ;
                                          uVar8 = 0xbf7;
                                        }
                                        printf(pcVar10,"_uac_wserv_jcs_modify",uVar8);
                                        goto LAB_005e14c4;
                                      }
                                      pcVar11 = (char *)0xffffffff;
                                      if ((g_wserv_debug == 0) ||
                                         (iVar6 = is_target_debug_ap(), iVar6 == 0))
                                      goto LAB_005e14c4;
                                      pcVar10 = 
                                      "<wserv>[debug]%s(): %d  -> wservice[%d] no change.\r\n";
                                      uVar8 = 0xbe2;
                                      pcVar11 = pcVar12;
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
        else {
          iVar6 = json_object_object_get(param_1,"default_bind_vlan");
          if (iVar6 == 0) {
            pcVar11 = (char *)0xffffffff;
            if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
            goto LAB_005e14c4;
            pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
            uVar8 = 0xb2a;
            pcVar11 = "default_bind_vlan";
          }
          else {
            iVar7 = json_object_get_type(iVar6);
            if (iVar7 == 3) {
              uVar5 = json_object_get_int(iVar6);
            }
            else {
              iVar7 = json_object_get_type();
              if (iVar7 == 2) {
                uVar13 = json_object_get_double(iVar6);
                uVar5 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
              }
              else {
                uVar5 = 0xffffffff;
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_uac_wserv_jcs_modify",0xb2b);
                }
              }
            }
            local_725 = (byte)((uVar5 & 0xffff) >> 8);
            local_724 = local_724 & 0xffffff | (uVar5 & 0xffff) << 0x18;
            iVar6 = json_object_object_get(param_1,"default_bind_freq");
            if (iVar6 != 0) {
              iVar7 = json_object_get_type(iVar6);
              if (iVar7 == 3) {
                uVar5 = json_object_get_int(iVar6);
              }
              else {
                iVar7 = json_object_get_type();
                if (iVar7 != 2) {
                  if (jcs_err_switch == 0) {
                    local_724 = local_724 & 0xff0000ff | 0xffff00;
                  }
                  else {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_modify",0xb30);
                    local_724 = local_724 & 0xff0000ff | 0xffff00;
                  }
                  goto LAB_005e1708;
                }
                uVar13 = json_object_get_double(iVar6);
                uVar5 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
              }
              local_724 = local_724 & 0xff0000ff | (uVar5 & 0xffff) << 8;
              goto LAB_005e1708;
            }
            pcVar11 = (char *)0xffffffff;
            if ((g_wserv_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
            goto LAB_005e14c4;
            pcVar10 = "<wserv>[error]%s(): %d  -> %s not found!\r\n";
            uVar8 = 0xb2f;
            pcVar11 = "default_bind_freq";
          }
        }
      }
      printf(pcVar10,"_uac_wserv_jcs_modify",uVar8,pcVar11);
      pcVar11 = (char *)0xffffffff;
      goto LAB_005e14c4;
    }
    pcVar12 = (char *)0xffffffff;
    if (g_wserv_error != 0) {
      iVar6 = is_target_debug_ap();
      if (iVar6 == 0) {
        pcVar11 = (char *)0xffffffff;
        goto LAB_005e14c4;
      }
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_modify",0xb03,"serv_id")
      ;
      goto LAB_005e159c;
    }
  }
  pcVar12 = (char *)0xffffffff;
  pcVar11 = (char *)0xffffffff;
LAB_005e14c4:
  uVar8 = json_object_new_int(pcVar11);
  json_object_object_add(param_2,"serv_id",uVar8);
  if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_modify() finish, id=%d.\r\n",
           "_uac_wserv_jcs_modify",0xc3b,pcVar12);
  }
  if (iVar4 != 0) {
    FUN_00407df0(iVar4);
  }
  return;
}

