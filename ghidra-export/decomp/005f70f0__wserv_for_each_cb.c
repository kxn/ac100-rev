// func _wserv_for_each_cb @ 005f70f0 size=2004

undefined4
_wserv_for_each_cb(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  char *__dest;
  int *__src;
  undefined4 uVar6;
  size_t sVar7;
  char *__nptr;
  undefined4 uVar8;
  char *pcVar9;
  int iVar10;
  int local_300;
  int local_2fc;
  int local_2f8;
  char acStack_2f4 [68];
  int local_2b0;
  int local_2ac;
  int local_2a8;
  char acStack_2a4 [40];
  int local_27c;
  int local_278;
  char acStack_274 [68];
  char acStack_230 [127];
  undefined1 local_1b1;
  int local_1b0;
  char acStack_1ac [151];
  undefined1 local_115 [4];
  undefined1 local_111 [4];
  undefined1 uStack_10d;
  undefined4 local_10c;
  int local_108;
  int local_104;
  char acStack_100 [50];
  int local_ce;
  int local_ca;
  undefined1 local_c6 [4];
  undefined1 auStack_c2 [128];
  int local_42;
  int local_3e;
  undefined1 local_3a;
  undefined1 local_39;
  bool local_36;
  undefined1 local_35;
  ushort local_34;
  ushort local_32;
  ushort local_30;
  undefined1 local_2e;
  bool local_2d;
  bool local_2c;
  
  iVar10 = 0;
  memset(acStack_230,0,0x205);
  memset(&local_300,0,0x50);
  memset(&local_2b0,0,0x80);
  local_10c = CONCAT31(local_10c._0_3_,1);
  while( true ) {
    uVar5 = (uint)local_c6 & 3;
    if (iVar10 < param_2 == 0) break;
    pcVar9 = (char *)*param_4;
    if ((pcVar9 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) {
      if (g_wserv_error == 0) {
        return 1;
      }
      iVar10 = is_target_debug_ap();
      if (iVar10 == 0) {
        return 1;
      }
      pcVar9 = "<wserv>[error]%s(): %d  -> column_name or column_value is null!\r\n";
      uVar6 = 0x7d;
      goto LAB_005f73c8;
    }
    iVar4 = strcmp(pcVar9,"serv_id");
    if (iVar4 == 0) {
      local_1b0 = atoi(__nptr);
    }
    else {
      iVar4 = strcmp(pcVar9,"enable");
      if (iVar4 == 0) {
        local_115 = (undefined1  [4])atoi(__nptr);
        iVar4 = strcmp(__nptr,"on");
        if (iVar4 == 0) {
          local_115 = (undefined1  [4])0x1;
        }
        else {
          uVar5 = (uint)local_115 & 3;
          puVar3 = (uint *)(local_115 + -uVar5);
          *puVar3 = *puVar3 & -1 << (4 - uVar5) * 8 | 0U >> uVar5 * 8;
          puVar1 = local_115 + 3;
          uVar5 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar5) =
               *(uint *)(puVar1 + -uVar5) & 0xffffffffU >> (uVar5 + 1) * 8 | 0 << (3 - uVar5) * 8;
        }
      }
      else {
        iVar4 = strncmp(pcVar9,"auto_bind",10);
        if (iVar4 == 0) {
          iVar4 = strncmp(__nptr,"on",3);
          if (iVar4 == 0) {
            local_111 = (undefined1  [4])0x1;
          }
          else {
            uVar5 = (uint)local_111 & 3;
            puVar3 = (uint *)(local_111 + -uVar5);
            *puVar3 = *puVar3 & -1 << (4 - uVar5) * 8 | 0U >> uVar5 * 8;
            puVar1 = local_111 + 3;
            uVar5 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar5) =
                 *(uint *)(puVar1 + -uVar5) & 0xffffffffU >> (uVar5 + 1) * 8 | 0 << (3 - uVar5) * 8;
          }
        }
        else {
          iVar4 = strncmp(pcVar9,"default_bind_vlan",0x12);
          if (iVar4 == 0) {
            uVar5 = atoi(__nptr);
            uStack_10d = (undefined1)((uVar5 & 0xffff) >> 8);
            local_10c = local_10c & 0xffffff | (uVar5 & 0xffff) << 0x18;
          }
          else {
            iVar4 = strncmp(pcVar9,"default_bind_freq",0x12);
            if (iVar4 == 0) {
              uVar5 = atoi(__nptr);
              local_10c = local_10c & 0xff0000ff | (uVar5 & 0xffff) << 8;
            }
            else {
              iVar4 = strcmp(pcVar9,"ssid");
              __dest = acStack_100;
              if (iVar4 == 0) {
                sVar7 = 0x31;
LAB_005f7490:
                strncpy(__dest,__nptr,sVar7);
              }
              else {
                iVar4 = strcmp(pcVar9,"ssid_code_type");
                if (iVar4 == 0) {
                  local_104 = atoi(__nptr);
                }
                else {
                  iVar4 = strcmp(pcVar9,"desc");
                  __dest = acStack_1ac;
                  if (iVar4 == 0) {
                    sVar7 = 0x96;
                    goto LAB_005f7490;
                  }
                  iVar4 = strcmp(pcVar9,"isolate");
                  if (iVar4 == 0) {
                    local_ce = atoi(__nptr);
                  }
                  else {
                    iVar4 = strcmp(pcVar9,"ssidbrd");
                    if (iVar4 == 0) {
                      local_ca = atoi(__nptr);
                    }
                    else {
                      iVar4 = strcmp(pcVar9,"encryption");
                      if (iVar4 == 0) {
                        local_c6 = (undefined1  [4])atoi(__nptr);
                      }
                      else {
                        iVar4 = strcmp(pcVar9,"auth");
                        if (iVar4 == 0) {
                          local_300 = atoi(__nptr);
                          local_2b0 = local_300;
                        }
                        else {
                          iVar4 = strcmp(pcVar9,"cipher");
                          if (iVar4 == 0) {
                            local_2fc = atoi(__nptr);
                            local_2ac = local_2fc;
                          }
                          else {
                            iVar4 = strcmp(pcVar9,"radius_ip");
                            __dest = acStack_2a4;
                            if (iVar4 == 0) {
                              sVar7 = 0x27;
                              goto LAB_005f7490;
                            }
                            iVar4 = strcmp(pcVar9,"radius_port");
                            if (iVar4 == 0) {
                              local_27c = atoi(__nptr);
                            }
                            else {
                              iVar4 = strcmp(pcVar9,"radius_acct_port");
                              if (iVar4 == 0) {
                                local_278 = atoi(__nptr);
                              }
                              else {
                                iVar4 = strcmp(pcVar9,"radius_pwd");
                                __dest = acStack_274;
                                if (iVar4 == 0) {
LAB_005f75fc:
                                  sVar7 = 0x40;
                                  goto LAB_005f7490;
                                }
                                iVar4 = strcmp(pcVar9,"key_update_intv");
                                if (iVar4 == 0) {
                                  local_2f8 = atoi(__nptr);
                                  local_2a8 = local_2f8;
                                }
                                else {
                                  iVar4 = strcmp(pcVar9,"key");
                                  __dest = acStack_2f4;
                                  if (iVar4 == 0) goto LAB_005f75fc;
                                  iVar4 = strcmp(pcVar9,"bw_ctrl_enable");
                                  if (iVar4 == 0) {
                                    iVar4 = atoi(__nptr);
                                    local_3a = (char)iVar4;
                                  }
                                  else {
                                    iVar4 = strcmp(pcVar9,"bw_ctrl_mode");
                                    if (iVar4 == 0) {
                                      iVar4 = atoi(__nptr);
                                      local_39 = (char)iVar4;
                                    }
                                    else {
                                      iVar4 = strcmp(pcVar9,"igmp_snooping_enable");
                                      if (iVar4 == 0) {
                                        iVar4 = strncmp(__nptr,"on",3);
                                        local_36 = iVar4 == 0;
                                      }
                                      else {
                                        iVar4 = strcmp(pcVar9,"igmp_drop_unknown");
                                        if (iVar4 == 0) {
                                          iVar4 = atoi(__nptr);
                                          local_35 = (char)iVar4;
                                        }
                                        else {
                                          iVar4 = strcmp(pcVar9,"igmp_2g_rate");
                                          if (iVar4 == 0) {
                                            iVar4 = atoi(__nptr);
                                            local_34 = (ushort)iVar4 & 0xff;
                                          }
                                          else {
                                            iVar4 = strcmp(pcVar9,"igmp_5g_rate");
                                            if (iVar4 == 0) {
                                              iVar4 = atoi(__nptr);
                                              local_32 = (ushort)iVar4 & 0xff;
                                            }
                                            else {
                                              iVar4 = strcmp(pcVar9,"igmp_query_interval");
                                              if (iVar4 == 0) {
                                                iVar4 = atoi(__nptr);
                                                local_30 = (ushort)iVar4 & 0xff;
                                              }
                                              else {
                                                iVar4 = strcmp(pcVar9,"igmp_max_resp_time");
                                                if (iVar4 == 0) {
                                                  iVar4 = atoi(__nptr);
                                                  local_2e = (char)iVar4;
                                                }
                                                else {
                                                  iVar4 = strcmp(pcVar9,"igmp_snooping_switch");
                                                  if (iVar4 == 0) {
                                                    iVar4 = strncmp(__nptr,"on",3);
                                                    local_2d = iVar4 == 0;
                                                  }
                                                  else {
                                                    iVar4 = strcmp(pcVar9,"igmp_query_switch");
                                                    if (iVar4 == 0) {
                                                      iVar4 = strncmp(__nptr,"on",3);
                                                      local_2c = iVar4 == 0;
                                                    }
                                                    else {
                                                      iVar4 = strcmp(pcVar9,"up_limit");
                                                      if (iVar4 == 0) {
                                                        local_42 = atoi(__nptr);
                                                      }
                                                      else {
                                                        iVar4 = strcmp(pcVar9,"down_limit");
                                                        if (iVar4 == 0) {
                                                          local_3e = atoi(__nptr);
                                                        }
                                                        else {
                                                          iVar4 = strcmp(pcVar9,"ssid_id");
                                                          if (iVar4 == 0) {
                                                            strncpy(acStack_230,__nptr,0x80);
                                                            local_1b1 = 0;
                                                          }
                                                          else {
                                                            iVar4 = strcmp(pcVar9,"mlo_switch");
                                                            if (iVar4 == 0) {
                                                              local_108 = atoi(__nptr);
                                                            }
                                                            else {
                                                              iVar4 = strcmp(pcVar9,"priv_key");
                                                              if (iVar4 != 0) {
                                                                if (g_wserv_error == 0) {
                                                                  return 1;
                                                                }
                                                                iVar10 = is_target_debug_ap();
                                                                if (iVar10 == 0) {
                                                                  return 1;
                                                                }
                                                                printf(
                                                  "<wserv>[error]%s(): %d  -> invalid column_name[%s]! WSERV_DESCR:%s\r\n"
                                                  ,"_wserv_for_each_cb",0x11e,*param_4,&DAT_006ce874
                                                  );
                                                  return 1;
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
              }
            }
          }
        }
      }
    }
    iVar10 = iVar10 + 1;
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  uVar2 = (uint)(local_c6 + 3) & 3;
  uVar5 = (*(int *)(local_c6 + -uVar5) << uVar5 * 8 |
          (uint)(iVar10 < param_2) & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar2 + 1) * 8 |
          *(uint *)(local_c6 + 3 + -uVar2) >> (3 - uVar2) * 8;
  if ((uVar5 == 1) || (uVar5 == 4)) {
    __src = &local_300;
    sVar7 = 0x50;
  }
  else {
    if (uVar5 != 2) {
      memset(auStack_c2,0,0x80);
      goto LAB_005f740c;
    }
    __src = &local_2b0;
    sVar7 = 0x80;
  }
  memcpy(auStack_c2,__src,sVar7);
LAB_005f740c:
  uVar8 = 0;
  iVar10 = wserv_db_entry_load(acStack_230);
  if (((iVar10 != 0) && (uVar8 = 1, g_wserv_error != 0)) &&
     (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
    pcVar9 = "<wserv>[error]%s(): %d  -> wserv_db_entry_load() fail!\r\n";
    uVar6 = 0x133;
LAB_005f73c8:
    uVar8 = 1;
    printf(pcVar9,"_wserv_for_each_cb",uVar6);
  }
  return uVar8;
}

