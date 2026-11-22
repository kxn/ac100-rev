// func apmngr_db_sqlite_ap_cfg_restore @ 00534db4 size=3076

undefined4
apmngr_db_sqlite_ap_cfg_restore
          (undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar5;
  size_t sVar4;
  char *__dest;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  uint local_2c;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    if (apmngr_err_switch != '\0') {
      iVar13 = is_target_debug_ap();
      if (iVar13 == 0) {
        return 1;
      }
      printf("[APMNGR_ERROR]%s()/%d Input value invalid.\n","apmngr_db_sqlite_ap_cfg_restore",0xe0b)
      ;
      return 1;
    }
LAB_00534f30:
    uVar8 = 1;
  }
  else {
    uVar12 = 9;
    local_2c = 0xffff;
    uVar11 = 0xffffffff;
    uVar10 = 0xffffffff;
    local_34 = param_4;
    local_30 = param_3;
    for (iVar13 = 0; iVar13 < param_2; iVar13 = iVar13 + 1) {
      pcVar7 = (char *)*local_34;
      if ((pcVar7 == (char *)0x0) || (pcVar9 = (char *)*local_30, pcVar9 == (char *)0x0)) {
        if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_WARNING]%s()/%d column_name or column_value is null!\n",
                 "apmngr_db_sqlite_ap_cfg_restore",0xe14);
        }
      }
      else {
        iVar1 = strcmp(pcVar7,"entry_id");
        if (iVar1 == 0) {
          uVar2 = atoi(pcVar9);
          if (((int)uVar2 < 0) ||
             ((uVar10 = uVar2, apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar2 &&
              (((int)uVar2 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar2)))))) {
            if (apmngr_err_switch != '\0') {
              iVar13 = is_target_debug_ap();
              if (iVar13 == 0) {
                return 1;
              }
              pcVar7 = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n";
              uVar6 = 0xe1d;
LAB_0053531c:
              printf(pcVar7,"apmngr_db_sqlite_ap_cfg_restore",uVar6,uVar2);
              return 1;
            }
            goto LAB_00534f30;
          }
        }
        else {
          iVar1 = strcmp(pcVar7,"group_id");
          if (iVar1 == 0) {
            uVar2 = atoi(pcVar9);
            if (((int)uVar2 < 0) || (uVar11 = uVar2, apmngr_group_num_max <= (int)uVar2)) {
              if ((apmngr_err_switch != '\0') && (iVar13 = is_target_debug_ap(), iVar13 != 0)) {
                pcVar7 = "[APMNGR_ERROR]%s()/%d Invalid group id[%d].\n";
                uVar6 = 0xe26;
                goto LAB_0053531c;
              }
              goto LAB_00534f30;
            }
          }
          else {
            iVar1 = strcmp(pcVar7,"model_id");
            if (iVar1 == 0) {
              if ((param_1 != (undefined4 *)0x0) && (param_1[1] != 0)) {
                iVar1 = atoi(pcVar9);
                iVar1 = apdb_id_valid(iVar1);
                if (iVar1 == 0) {
                  uVar6 = param_1[1];
                  goto LAB_00534fe8;
                }
              }
            }
            else {
              iVar1 = strcmp(pcVar7,"ap_role");
              if (iVar1 == 0) {
                uVar12 = apmngr_db_str_to_role(pcVar9);
              }
              else {
                iVar1 = strcmp(pcVar7,"cap_id");
                if (iVar1 == 0) {
                  local_2c = atoi(pcVar9);
                  local_2c = local_2c & 0xffff;
                }
              }
            }
          }
        }
      }
      local_34 = local_34 + 1;
      local_30 = local_30 + 1;
    }
    if (uVar12 == 9) {
      uVar6 = param_1[1];
LAB_00534fe8:
      uVar8 = 0;
      FUN_00407ec0(uVar10,uVar6,param_1 + 2);
      if (apmngr_err_switch == '\0') {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      uVar10 = atoi((char *)param_3[iVar13]);
      pcVar7 = "[APMNGR_ERROR]%s()/%d model id %d or role %d is invalid!\n";
      uVar6 = 0xe3e;
      uVar11 = uVar12;
    }
    else {
      if ((uVar10 != 0xffffffff) && (uVar11 != 0xffffffff)) {
        if ((uVar12 == 7) &&
           ((((int)uVar10 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar10)) ||
            (apmngr_firm_sensor_num_max <= (int)(uint)g_apmngr_firm_sensor_num)))) {
          if (apmngr_err_switch == '\0') {
            uVar6 = param_1[1];
          }
          else {
            iVar13 = is_target_debug_ap();
            if (iVar13 == 0) {
              uVar6 = param_1[1];
            }
            else {
              printf("[APMNGR_ERROR]%s()/%d Sensor id invalid or exceed of id[%d].\n",
                     "apmngr_db_sqlite_ap_cfg_restore",0xe48,uVar10);
              uVar6 = param_1[1];
            }
          }
          FUN_00407ec0(uVar10,uVar6,param_1 + 2);
          return 0;
        }
        uVar6 = *param_1;
        uVar2 = uVar10;
        if (49999 < (int)uVar10) {
          uVar2 = (uVar10 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        uVar8 = 3;
        iVar13 = g_apmngr_entry_array + uVar2 * 0x2d8;
        if (uVar12 != 7) {
          uVar8 = 1;
        }
        *(short *)(iVar13 + 0x12) = (short)uVar11;
        *(undefined4 *)(iVar13 + 0x3c) = uVar6;
        *(undefined4 *)(iVar13 + 0xc) = uVar8;
        *(uint *)(iVar13 + 0x14) = uVar12;
        *(undefined4 *)(iVar13 + 0x290) = 0xffffffff;
        *(undefined4 *)(iVar13 + 0x2c) = 0xffffffff;
        iVar1 = 0;
        *(undefined4 *)(iVar13 + 0x30) = 0xffffffff;
        *(undefined4 *)(iVar13 + 0x1c) = 1;
        *(short *)(iVar13 + 0x10) = (short)uVar10;
        *(undefined2 *)(iVar13 + 0x28) = 0;
        *(undefined1 *)(iVar13 + 0x2b0) = 0;
        *(short *)(iVar13 + 0x18) = (short)local_2c;
        memset((void *)(iVar13 + 0x218),0xff,0x10);
        local_38 = param_4;
        do {
          if (param_2 <= iVar1) {
            FUN_004086b0(g_apmngr_group_array + (uint)*(ushort *)(iVar13 + 0x12) * 0x84 + 0x78,
                         iVar13);
            FUN_00408380(g_apmngr_ap_hash,iVar13);
            if (*(int *)(iVar13 + 0x14) == 7) {
              g_apmngr_sensor_num = g_apmngr_sensor_num + 1;
              g_apmngr_firm_sensor_num = g_apmngr_firm_sensor_num + 1;
            }
            else {
              g_apmngr_ap_num = g_apmngr_ap_num + 1;
            }
            apmngr_db_id_cost(*(undefined4 *)(iVar13 + 0xc),uVar10 & 0xffff);
            return 0;
          }
          pcVar7 = (char *)*local_38;
          if ((pcVar7 == (char *)0x0) || (pcVar9 = (char *)*param_3, pcVar9 == (char *)0x0)) {
            if ((apmngr_warning_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d column_name or column_value is null!\n",
                     "apmngr_db_sqlite_ap_cfg_restore",0xe65);
            }
          }
          else {
            iVar3 = strcmp(pcVar7,"mac");
            if (iVar3 == 0) {
              sscanf(pcVar9,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",iVar13 + 0x48,iVar13 + 0x49,
                     iVar13 + 0x4a,iVar13 + 0x4b,iVar13 + 0x4c,iVar13 + 0x4d);
            }
            else {
              iVar3 = strcmp(pcVar7,"entry_name");
              __dest = (char *)(iVar13 + 0x4e);
              if (iVar3 == 0) {
                sVar4 = 0x99;
                goto LAB_00535370;
              }
              iVar3 = strcmp(pcVar7,"model_id");
              if (iVar3 == 0) {
                iVar3 = atoi(pcVar9);
                *(int *)(iVar13 + 0x40) = iVar3;
              }
              else {
                iVar3 = strcmp(pcVar7,"hardware_ver");
                if (iVar3 == 0) {
                  sscanf(pcVar9,"%hd.%hd",iVar13 + 0x44,iVar13 + 0x46);
                }
                else {
                  iVar3 = strcmp(pcVar7,"ap_keep_alive");
                  if (iVar3 == 0) {
                    iVar3 = atoi(pcVar9);
                    *(char *)(iVar13 + 0xe8) = (char)iVar3;
                  }
                  else {
                    iVar3 = strcmp(pcVar7,"client_keep_alive");
                    if (iVar3 == 0) {
                      iVar3 = atoi(pcVar9);
                      *(short *)(iVar13 + 0xea) = (short)iVar3;
                    }
                    else {
                      iVar3 = strcmp(pcVar7,"client_idle");
                      if (iVar3 == 0) {
                        iVar3 = atoi(pcVar9);
                        *(int *)(iVar13 + 0xec) = iVar3;
                      }
                      else {
                        iVar3 = strcmp(pcVar7,"offline_selfmanage");
                        if (iVar3 == 0) {
                          iVar3 = strcmp(pcVar9,"on");
                          *(uint *)(iVar13 + 0xf0) = (uint)(iVar3 == 0);
                        }
                        else {
                          iVar3 = strcmp(pcVar7,"username");
                          __dest = (char *)(iVar13 + 0xf4);
                          if (iVar3 == 0) {
                            sVar4 = 0x1f;
                          }
                          else {
                            iVar3 = strcmp(pcVar7,"password");
                            __dest = (char *)(iVar13 + 0x114);
                            if (iVar3 != 0) {
                              iVar3 = strcmp(pcVar7,"phy_wire_vlan_1");
                              if (iVar3 == 0) {
                                iVar3 = atoi(pcVar9);
                                *(short *)(iVar13 + 0x128) = (short)iVar3;
                              }
                              else {
                                iVar3 = strcmp(pcVar7,"phy_wire_vlan_2");
                                if (iVar3 == 0) {
                                  iVar3 = atoi(pcVar9);
                                  *(short *)(iVar13 + 0x12a) = (short)iVar3;
                                }
                                else {
                                  iVar3 = strcmp(pcVar7,"phy_wire_vlan_3");
                                  if (iVar3 == 0) {
                                    iVar3 = atoi(pcVar9);
                                    *(short *)(iVar13 + 300) = (short)iVar3;
                                  }
                                  else {
                                    iVar3 = strcmp(pcVar7,"phy_wire_vlan_4");
                                    if (iVar3 == 0) {
                                      iVar3 = atoi(pcVar9);
                                      *(short *)(iVar13 + 0x12e) = (short)iVar3;
                                    }
                                    else {
                                      iVar3 = strcmp(pcVar7,"ap_trunk");
                                      if (iVar3 == 0) {
                                        iVar3 = atoi(pcVar9);
                                        *(int *)(iVar13 + 0x124) = iVar3;
                                      }
                                      else {
                                        iVar3 = strcmp(pcVar7,"hdap_peer_id");
                                        if (iVar3 == 0) {
                                          *(undefined4 *)(iVar13 + 0xc) = 2;
                                          iVar3 = atoi((char *)*param_3);
                                          *(short *)(iVar13 + 0x298) = (short)iVar3;
                                        }
                                        else {
                                          iVar3 = strcmp(pcVar7,"led");
                                          if (iVar3 == 0) {
                                            iVar3 = atoi(pcVar9);
                                            *(int *)(iVar13 + 0x1b8) = iVar3;
                                          }
                                          else {
                                            iVar3 = strcmp(pcVar7,"telnet_status");
                                            if (iVar3 == 0) {
                                              iVar3 = atoi(pcVar9);
                                              *(char *)(iVar13 + 0x206) = (char)iVar3;
                                            }
                                            else {
                                              iVar3 = strcmp(pcVar7,"led_wifi_sync");
                                              if (iVar3 == 0) {
                                                iVar3 = strcmp(pcVar9,"on");
                                                *(bool *)(iVar13 + 0x130) = iVar3 == 0;
                                              }
                                              else {
                                                iVar3 = strcmp(pcVar7,"led_timer_enable");
                                                if (iVar3 == 0) {
                                                  iVar3 = strcmp(pcVar9,"on");
                                                  *(bool *)(iVar13 + 0x1bc) = iVar3 == 0;
                                                }
                                                else {
                                                  iVar3 = strcmp(pcVar7,"led_close_date");
                                                  if (iVar3 == 0) {
                                                    uVar5 = apmngr_db_date_parse(pcVar9);
                                                    *(undefined1 *)(iVar13 + 0x1bd) = uVar5;
                                                  }
                                                  else {
                                                    iVar3 = strcmp(pcVar7,"led_close_time");
                                                    if (iVar3 == 0) {
                                                      iVar3 = iVar13 + 0x1be;
LAB_00535850:
                                                      apmngr_db_time_parse(pcVar9,iVar3);
                                                    }
                                                    else {
                                                      iVar3 = strcmp(pcVar7,"led_open_date");
                                                      if (iVar3 == 0) {
                                                        uVar5 = apmngr_db_date_parse(pcVar9);
                                                        *(undefined1 *)(iVar13 + 0x1c1) = uVar5;
                                                      }
                                                      else {
                                                        iVar3 = strcmp(pcVar7,"led_open_time");
                                                        if (iVar3 == 0) {
                                                          iVar3 = iVar13 + 0x1c2;
                                                          goto LAB_00535850;
                                                        }
                                                        iVar3 = strcmp(pcVar7,"bluetooth_enable");
                                                        if (iVar3 != 0) {
                                                          iVar3 = strcmp(pcVar7,"account_username");
                                                          __dest = (char *)(iVar13 + 0x132);
                                                          if (iVar3 != 0) {
                                                            iVar3 = strcmp(pcVar7,"account_password"
                                                                          );
                                                            __dest = (char *)(iVar13 + 0x173);
                                                            if (iVar3 != 0) {
                                                              iVar3 = strcmp(pcVar7,
                                                  "cloud_config_id");
                                                  __dest = (char *)(iVar13 + 0x1c5);
                                                  if (iVar3 != 0) {
                                                    iVar3 = strcmp(pcVar7,"lag_mode");
                                                    if (iVar3 == 0) {
                                                      iVar3 = atoi(pcVar9);
                                                      *(char *)(iVar13 + 0x2b2) = (char)iVar3;
                                                    }
                                                    else {
                                                      iVar3 = strcmp(pcVar7,"lag_phy_num");
                                                      if (iVar3 == 0) {
                                                        iVar3 = atoi(pcVar9);
                                                        *(char *)(iVar13 + 0x2b3) = (char)iVar3;
                                                      }
                                                      else {
                                                        iVar3 = strcmp(pcVar7,"new_ap_trunk");
                                                        if (iVar3 == 0) {
                                                          iVar3 = atoi(pcVar9);
                                                          *(char *)(iVar13 + 0x2b1) = (char)iVar3;
                                                        }
                                                        else {
                                                          iVar3 = strcmp(pcVar7,"lag_phy_list");
                                                          __dest = (char *)(iVar13 + 0x2b4);
                                                          if (iVar3 == 0) {
                                                            sVar4 = 0x14;
                                                            goto LAB_00535370;
                                                          }
                                                          iVar3 = strcmp(pcVar7,
                                                  "fit_fat_button_status");
                                                  if (iVar3 == 0) {
                                                    iVar3 = atoi(pcVar9);
                                                    *(char *)(iVar13 + 0x1b4) = (char)iVar3;
                                                  }
                                                  else {
                                                    iVar3 = strcmp(pcVar7,"region_code");
                                                    if (iVar3 == 0) {
                                                      iVar3 = atoi(pcVar9);
                                                      *(char *)(iVar13 + 0x2d1) = (char)iVar3;
                                                    }
                                                    else {
                                                      iVar3 = strcmp(pcVar7,"firmware_id");
                                                      if (iVar3 == 0) {
                                                        sVar4 = strlen(pcVar9);
                                                        FUN_00408280((void *)(iVar13 + 0x218),pcVar9
                                                                     ,sVar4);
                                                      }
                                                      else {
                                                        iVar3 = strcmp(pcVar7,"ap_mesh_switch");
                                                        if (iVar3 == 0) {
                                                          iVar3 = atoi(pcVar9);
                                                          *(char *)(iVar13 + 0x207) = (char)iVar3;
                                                        }
                                                        else {
                                                          iVar3 = strcmp(pcVar7,"ssid_mlo_support");
                                                          if (iVar3 == 0) {
                                                            iVar3 = atoi(pcVar9);
                                                            *(char *)(iVar13 + 0x2d2) = (char)iVar3;
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00535194;
                                                  }
                                                  }
                                                  }
                                                  sVar4 = 0x40;
                                                  goto LAB_00535370;
                                                  }
                                                  iVar3 = atoi(pcVar9);
                                                  *(char *)(iVar13 + 0x131) = (char)iVar3;
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
                              goto LAB_00535194;
                            }
                            sVar4 = 0xf;
                          }
LAB_00535370:
                          strncpy(__dest,pcVar9,sVar4);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_00535194:
          iVar1 = iVar1 + 1;
          param_3 = param_3 + 1;
          local_38 = local_38 + 1;
        } while( true );
      }
      uVar8 = 1;
      if (apmngr_err_switch == '\0') goto LAB_00534f30;
      iVar13 = is_target_debug_ap();
      if (iVar13 == 0) {
        return 1;
      }
      pcVar7 = "[APMNGR_ERROR]%s()/%d Invalid id[%d], gid[%d].\n";
      uVar6 = 0xe43;
    }
    printf(pcVar7,"apmngr_db_sqlite_ap_cfg_restore",uVar6,uVar10,uVar11);
  }
  return uVar8;
}

