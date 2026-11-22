// func apmngr_db_sqlite_template_restore @ 005359b8 size=2116

undefined4
apmngr_db_sqlite_template_restore(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

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
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_30;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[APMNGR_ERROR]%s()/%d Input value invalid.\n","apmngr_db_sqlite_template_restore",
               0xf24);
        return 1;
      }
      return 1;
    }
  }
  else {
    uVar11 = 0xffffffff;
    uVar9 = 0xffffffff;
    puVar13 = param_3;
    puVar14 = param_4;
    for (local_30 = 0; local_30 < param_2; local_30 = local_30 + 1) {
      pcVar7 = (char *)*puVar14;
      if ((pcVar7 == (char *)0x0) || (pcVar10 = (char *)*puVar13, pcVar10 == (char *)0x0)) {
        if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_WARNING]%s()/%d column_name or column_value is null!\n",
                 "apmngr_db_sqlite_template_restore",0xf2d);
        }
      }
      else {
        iVar1 = strcmp(pcVar7,"entry_id");
        if (iVar1 == 0) {
          uVar2 = atoi(pcVar10);
          if (((int)uVar2 < 0) ||
             ((uVar9 = uVar2, apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar2 &&
              (((int)uVar2 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar2)))))) {
            uVar8 = 1;
            if (apmngr_err_switch == '\0') {
              return 1;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 1;
            }
            pcVar7 = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n";
            uVar6 = 0xf36;
LAB_00535c20:
            printf(pcVar7,"apmngr_db_sqlite_template_restore",uVar6,uVar2);
            return uVar8;
          }
        }
        else {
          iVar1 = strcmp(pcVar7,"group_id");
          if (iVar1 == 0) {
            uVar2 = atoi(pcVar10);
            if (((int)uVar2 < 0) || (uVar11 = uVar2, apmngr_group_num_max <= (int)uVar2)) {
              uVar8 = 1;
              if (apmngr_err_switch == '\0') {
                return 1;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 1;
              }
              pcVar7 = "[APMNGR_ERROR]%s()/%d Invalid group gid[%d].\n";
              uVar6 = 0xf3f;
              goto LAB_00535c20;
            }
          }
          else {
            iVar1 = strcmp(pcVar7,"model_id");
            if (((iVar1 == 0) && (param_1 != 0)) && (*(int *)(param_1 + 4) != 0)) {
              iVar1 = atoi(pcVar10);
              iVar1 = apdb_id_valid(iVar1);
              if (iVar1 == 0) {
                uVar8 = 0;
                FUN_00407ec0(uVar9,*(undefined4 *)(param_1 + 4),param_1 + 8);
                if (apmngr_err_switch == '\0') {
                  return 0;
                }
                iVar1 = is_target_debug_ap();
                if (iVar1 == 0) {
                  return 0;
                }
                uVar2 = atoi((char *)*puVar13);
                pcVar7 = "[APMNGR_ERROR]%s()/%d model id %d is invalid!\n";
                uVar6 = 0xf4f;
                goto LAB_00535c20;
              }
            }
          }
        }
      }
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    if ((uVar9 != 0xffffffff) && (uVar11 != 0xffffffff)) {
      uVar2 = uVar9;
      if (49999 < (int)uVar9) {
        uVar2 = (uVar9 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar1 = g_apmngr_entry_array + uVar2 * 0x2d8;
      *(short *)(iVar1 + 0x12) = (short)uVar11;
      *(short *)(iVar1 + 0x10) = (short)uVar9;
      iVar12 = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 1;
      *(undefined4 *)(iVar1 + 0x3c) = 1;
      do {
        if (param_2 <= iVar12) {
          FUN_00408380(g_apmngr_template_hash,iVar1);
          FUN_004086b0(g_apmngr_group_array + (uint)*(ushort *)(iVar1 + 0x12) * 0x84 + 0x78,iVar1);
          g_apmngr_template_num = g_apmngr_template_num + 1;
          apmngr_db_id_cost(0,uVar9 & 0xffff);
          return 0;
        }
        pcVar7 = (char *)*param_4;
        if ((pcVar7 == (char *)0x0) || (pcVar10 = (char *)*param_3, pcVar10 == (char *)0x0)) {
          if ((apmngr_warning_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[APMNGR_WARNING]%s()/%d column_name or column_value is null!\n",
                   "apmngr_db_sqlite_template_restore",0xf66);
          }
        }
        else {
          iVar3 = strcmp(pcVar7,"entry_name");
          __dest = (char *)(iVar1 + 0x4e);
          if (iVar3 == 0) {
            sVar4 = 0x99;
            goto LAB_00535e20;
          }
          iVar3 = strcmp(pcVar7,"model_id");
          if (iVar3 == 0) {
            iVar3 = atoi(pcVar10);
            *(int *)(iVar1 + 0x40) = iVar3;
          }
          else {
            iVar3 = strcmp(pcVar7,"hardware_ver");
            if (iVar3 == 0) {
              sscanf(pcVar10,"%hd.%hd",iVar1 + 0x44,iVar1 + 0x46);
            }
            else {
              iVar3 = strcmp(pcVar7,"ap_keep_alive");
              if (iVar3 == 0) {
                iVar3 = atoi(pcVar10);
                *(char *)(iVar1 + 0xe8) = (char)iVar3;
              }
              else {
                iVar3 = strcmp(pcVar7,"client_keep_alive");
                if (iVar3 == 0) {
                  iVar3 = atoi(pcVar10);
                  *(short *)(iVar1 + 0xea) = (short)iVar3;
                }
                else {
                  iVar3 = strcmp(pcVar7,"client_idle");
                  if (iVar3 == 0) {
                    iVar3 = atoi(pcVar10);
                    *(int *)(iVar1 + 0xec) = iVar3;
                  }
                  else {
                    iVar3 = strcmp(pcVar7,"offline_selfmanage");
                    if (iVar3 == 0) {
                      iVar3 = strcmp(pcVar10,"on");
                      *(uint *)(iVar1 + 0xf0) = (uint)(iVar3 == 0);
                    }
                    else {
                      iVar3 = strcmp(pcVar7,"username");
                      __dest = (char *)(iVar1 + 0xf4);
                      if (iVar3 == 0) {
                        sVar4 = 0x1f;
                      }
                      else {
                        iVar3 = strcmp(pcVar7,"password");
                        __dest = (char *)(iVar1 + 0x114);
                        if (iVar3 != 0) {
                          iVar3 = strcmp(pcVar7,"phy_wire_vlan_1");
                          if (iVar3 == 0) {
                            iVar3 = atoi(pcVar10);
                            *(short *)(iVar1 + 0x128) = (short)iVar3;
                          }
                          else {
                            iVar3 = strcmp(pcVar7,"phy_wire_vlan_2");
                            if (iVar3 == 0) {
                              iVar3 = atoi(pcVar10);
                              *(short *)(iVar1 + 0x12a) = (short)iVar3;
                            }
                            else {
                              iVar3 = strcmp(pcVar7,"phy_wire_vlan_3");
                              if (iVar3 == 0) {
                                iVar3 = atoi(pcVar10);
                                *(short *)(iVar1 + 300) = (short)iVar3;
                              }
                              else {
                                iVar3 = strcmp(pcVar7,"phy_wire_vlan_4");
                                if (iVar3 == 0) {
                                  iVar3 = atoi(pcVar10);
                                  *(short *)(iVar1 + 0x12e) = (short)iVar3;
                                }
                                else {
                                  iVar3 = strcmp(pcVar7,"ap_trunk");
                                  if (iVar3 == 0) {
                                    iVar3 = atoi(pcVar10);
                                    *(int *)(iVar1 + 0x124) = iVar3;
                                  }
                                  else {
                                    iVar3 = strcmp(pcVar7,"led");
                                    if (iVar3 == 0) {
                                      iVar3 = atoi(pcVar10);
                                      *(int *)(iVar1 + 0x1b8) = iVar3;
                                    }
                                    else {
                                      iVar3 = strcmp(pcVar7,"telnet_status");
                                      if (iVar3 == 0) {
                                        iVar3 = atoi(pcVar10);
                                        *(char *)(iVar1 + 0x206) = (char)iVar3;
                                      }
                                      else {
                                        iVar3 = strcmp(pcVar7,"led_wifi_sync");
                                        if (iVar3 == 0) {
                                          iVar3 = strcmp(pcVar10,"on");
                                          *(bool *)(iVar1 + 0x130) = iVar3 == 0;
                                        }
                                        else {
                                          iVar3 = strcmp(pcVar7,"led_timer_enable");
                                          if (iVar3 == 0) {
                                            iVar3 = strcmp(pcVar10,"on");
                                            *(bool *)(iVar1 + 0x1bc) = iVar3 == 0;
                                          }
                                          else {
                                            iVar3 = strcmp(pcVar7,"led_close_date");
                                            if (iVar3 == 0) {
                                              uVar5 = apmngr_db_date_parse(pcVar10);
                                              *(undefined1 *)(iVar1 + 0x1bd) = uVar5;
                                            }
                                            else {
                                              iVar3 = strcmp(pcVar7,"led_open_date");
                                              if (iVar3 == 0) {
                                                uVar5 = apmngr_db_date_parse(pcVar10);
                                                *(undefined1 *)(iVar1 + 0x1c1) = uVar5;
                                              }
                                              else {
                                                iVar3 = strcmp(pcVar7,"bluetooth_enable");
                                                if (iVar3 == 0) {
                                                  iVar3 = strcmp(pcVar10,"on");
                                                  *(bool *)(iVar1 + 0x131) = iVar3 == 0;
                                                }
                                                else {
                                                  iVar3 = strcmp(pcVar7,"ap_mesh_switch");
                                                  if (iVar3 == 0) {
                                                    iVar3 = strcmp(pcVar10,"on");
                                                    *(bool *)(iVar1 + 0x207) = iVar3 == 0;
                                                  }
                                                  else {
                                                    iVar3 = strcmp(pcVar7,"firmware_id");
                                                    if (iVar3 == 0) {
                                                      sVar4 = strlen(pcVar10);
                                                      FUN_00408280(iVar1 + 0x218,pcVar10,sVar4);
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
                          goto LAB_00535cc4;
                        }
                        sVar4 = 0xf;
                      }
LAB_00535e20:
                      strncpy(__dest,pcVar10,sVar4);
                    }
                  }
                }
              }
            }
          }
        }
LAB_00535cc4:
        param_3 = param_3 + 1;
        iVar12 = iVar12 + 1;
        param_4 = param_4 + 1;
      } while( true );
    }
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[APMNGR_ERROR]%s()/%d Invalid id[%d], gid[%d].\n",
               "apmngr_db_sqlite_template_restore",0xf54,uVar9,uVar11);
        return 1;
      }
      return 1;
    }
  }
  return 1;
}

