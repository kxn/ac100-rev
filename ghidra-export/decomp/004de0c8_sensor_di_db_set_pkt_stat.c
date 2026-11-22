// func sensor_di_db_set_pkt_stat @ 004de0c8 size=3460

/* WARNING: Removing unreachable block (ram,0x004de258) */
/* WARNING: Removing unreachable block (ram,0x004de75c) */
/* WARNING: Removing unreachable block (ram,0x004de82c) */

undefined4 sensor_di_db_set_pkt_stat(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *__src;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  char *pcVar13;
  void *__src_00;
  void *__src_01;
  int iVar14;
  char acStack_a8 [49];
  char local_77;
  char *local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  void *local_30;
  void *local_2c;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_pkt_stat ENTER\n",
           "sensor_di_db_set_pkt_stat",0x8ce);
  }
  if (((param_1 == (undefined4 *)0x0) || (*(short *)((int)param_1 + 6) < 1)) || (param_1[5] == 0)) {
    uVar12 = 0;
    if (sensor_di_warning_switch != 0) {
      pcVar13 = "[SENSOR_DI_WARNING]%s()/line %d : pkt_stat or ssid_cnt is NULL\n";
      uVar10 = 0x8d4;
LAB_004de1cc:
      printf(pcVar13,"sensor_di_db_set_pkt_stat",uVar10);
    }
  }
  else {
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_get_sensor_node_from_cached_list(*param_1);
    local_6c = iVar1;
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_id=%d not exists_in cached list\n",
               "sensor_di_db_set_pkt_stat",0x8dd,*param_1);
      }
    }
    else {
      if (*(short *)(iVar1 + 0x1c514) == *(short *)(param_1 + 1)) {
        iVar14 = *(int *)(iVar1 + 0x1c520) % 3;
        iVar11 = *(int *)(iVar1 + 0x1c520) + 1;
        *(int *)(iVar1 + 0x1c520) = iVar11;
        *(undefined4 *)(iVar1 + (iVar14 + 29000) * 4 + 4) = param_1[4];
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : del_earliest_pkt_stat_data update_times=%d,idx=%d\n"
                 ,"_sensor_di_db_del_earliest_pkt_stat_data",0x2d4,iVar11,iVar14);
        }
        local_5c = local_6c + 0x1c530;
        for (iVar11 = FUN_004081b0(local_5c); iVar11 != 0; iVar11 = FUN_00408680(iVar11)) {
          *(int *)(iVar1 + 0x1c518) = *(int *)(iVar1 + 0x1c518) - *(int *)(iVar11 + 0x40);
          *(int *)(iVar1 + 0x1c51c) = *(int *)(iVar1 + 0x1c51c) - *(int *)(iVar11 + 0x44);
          for (iVar2 = FUN_004081b0(iVar11 + 0x48); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
            iVar7 = iVar2 + iVar14 * 0x40;
            *(int *)(iVar11 + 0x40) =
                 *(int *)(iVar11 + 0x40) - (*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x1c));
            iVar8 = iVar2 + iVar14 * 0x68;
            iVar6 = iVar2 + iVar14 * 0x30;
            *(int *)(iVar11 + 0x44) =
                 *(int *)(iVar11 + 0x44) - (*(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x20));
            iVar5 = ((*(int *)(iVar2 + 0x14) - *(int *)(iVar8 + 0x24)) - *(int *)(iVar7 + 0x15c)) -
                    *(int *)(iVar6 + 0x21c);
            *(int *)(iVar2 + 0x14) = iVar5;
            iVar6 = ((*(int *)(iVar2 + 0x18) - *(int *)(iVar8 + 0x28)) - *(int *)(iVar7 + 0x160)) -
                    *(int *)(iVar6 + 0x220);
            *(int *)(iVar2 + 0x18) = iVar6;
            if (iVar5 < 0) {
              *(undefined4 *)(iVar2 + 0x14) = 0;
              if (iVar6 < 0) {
                *(undefined4 *)(iVar2 + 0x18) = 0;
              }
            }
            else if (iVar6 < 0) {
              *(undefined4 *)(iVar2 + 0x18) = 0;
            }
            iVar5 = iVar14 * 0x40;
            memset((void *)(iVar2 + iVar14 * 0x68 + 0x24),0,0x68);
            memset((void *)(iVar2 + iVar5 + 0x15c),0,0x40);
            memset((void *)(iVar2 + iVar14 * 0x30 + 0x21c),0,0x30);
            iVar6 = FUN_004081b0(iVar2 + 0x2ac);
            local_70 = (char *)(iVar2 + 0xc);
            local_68 = iVar5 + 0x150;
            for (; iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
              *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) - *(int *)(iVar6 + 0x14);
              iVar9 = iVar6 + iVar14 * 0x68;
              iVar7 = iVar6 + iVar14 * 0x30;
              *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) - *(int *)(iVar6 + 0x18);
              iVar8 = ((*(int *)(iVar6 + 0x14) - *(int *)(iVar9 + 0x1c)) -
                      *(int *)(iVar6 + iVar5 + 0x154)) - *(int *)(iVar7 + 0x214);
              *(int *)(iVar6 + 0x14) = iVar8;
              iVar7 = ((*(int *)(iVar6 + 0x18) - *(int *)(iVar9 + 0x20)) -
                      *(int *)(iVar6 + iVar5 + 0x158)) - *(int *)(iVar7 + 0x218);
              *(int *)(iVar6 + 0x18) = iVar7;
              if (iVar8 < 0) {
                *(undefined4 *)(iVar6 + 0x14) = 0;
                if (iVar7 < 0) {
                  *(undefined4 *)(iVar6 + 0x18) = 0;
                }
              }
              else if (iVar7 < 0) {
                *(undefined4 *)(iVar6 + 0x18) = 0;
              }
              memset((void *)(iVar6 + iVar14 * 0x68 + 0x1c),0,0x68);
              memset((void *)(iVar6 + local_68 + 4),0,0x40);
              memset((void *)(iVar6 + iVar14 * 0x30 + 0x214),0,0x30);
              iVar7 = *(int *)(iVar2 + 0x1c) + *(int *)(iVar6 + 0x14);
              *(int *)(iVar2 + 0x1c) = iVar7;
              *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + *(int *)(iVar6 + 0x18);
              if (iVar7 < 0) {
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : *********pkt_stat_bssid_node->sta_airtime=%d *********\n"
                         ,"_sensor_di_db_del_earliest_pkt_stat_data",0x323);
                }
                di_printmac(local_70);
                *(undefined4 *)(iVar2 + 0x1c) = 0;
              }
              if (*(int *)(iVar2 + 0x20) < 0) {
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : *********pkt_stat_bssid_node->sta_pkt_num=%d *********\n"
                         ,"_sensor_di_db_del_earliest_pkt_stat_data",0x329);
                }
                di_printmac(local_70);
                *(undefined4 *)(iVar2 + 0x20) = 0;
              }
            }
            iVar6 = *(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x1c) + *(int *)(iVar11 + 0x40);
            *(int *)(iVar11 + 0x40) = iVar6;
            *(int *)(iVar11 + 0x44) =
                 *(int *)(iVar11 + 0x44) + *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x20);
            if (iVar6 < 0) {
              if (sensor_di_debug_switch != 0) {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : *********pkt_stat_ssid_node->airtime=%d *********\n"
                       ,"_sensor_di_db_del_earliest_pkt_stat_data",0x333);
              }
              if (sensor_di_debug_switch == 0) {
                *(undefined4 *)(iVar11 + 0x40) = 0;
              }
              else {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : ssid is = %s\n",
                       "_sensor_di_db_del_earliest_pkt_stat_data",0x334,iVar11 + 0xc);
                *(undefined4 *)(iVar11 + 0x40) = 0;
              }
            }
            if (*(int *)(iVar11 + 0x44) < 0) {
              if (sensor_di_debug_switch != 0) {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : *********pkt_stat_ssid_node->pkt_num=%d *********\n"
                       ,"_sensor_di_db_del_earliest_pkt_stat_data",0x339);
              }
              if (sensor_di_debug_switch == 0) {
                *(undefined4 *)(iVar11 + 0x44) = 0;
              }
              else {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : ssid is = %s\n",
                       "_sensor_di_db_del_earliest_pkt_stat_data",0x33a,iVar11 + 0xc);
                *(undefined4 *)(iVar11 + 0x44) = 0;
              }
            }
          }
          iVar6 = *(int *)(iVar1 + 0x1c518) + *(int *)(iVar11 + 0x40);
          *(int *)(iVar1 + 0x1c518) = iVar6;
          iVar2 = *(int *)(iVar1 + 0x1c51c) + *(int *)(iVar11 + 0x44);
          *(int *)(iVar1 + 0x1c51c) = iVar2;
          if (iVar6 < 0) {
            *(undefined4 *)(iVar1 + 0x1c518) = 0;
            if (iVar2 < 0) {
              *(undefined4 *)(iVar1 + 0x1c51c) = 0;
            }
          }
          else if (iVar2 < 0) {
            *(undefined4 *)(iVar1 + 0x1c51c) = 0;
          }
        }
        local_60 = (int)*(short *)((int)param_1 + 6);
        pcVar13 = (char *)param_1[5];
        memset(acStack_a8,0,0x32);
        if ((local_60 < 1) || (pcVar13 == (char *)0x0)) {
          if (sensor_di_warning_switch != 0) {
            printf("[SENSOR_DI_WARNING]%s()/line %d : input invalid\n",
                   "_sensor_di_db_set_pkt_stat_ssid",0x28c);
          }
        }
        else {
          local_68 = 0;
          local_70 = pcVar13;
          do {
            local_77 = local_70[0x31];
            if (local_77 == '\0') {
              strcpy(acStack_a8,local_70);
              uVar12 = *(undefined4 *)(iVar1 + 0x1c53c);
            }
            else {
              uVar12 = *(undefined4 *)(iVar1 + 0x1c53c);
            }
            pvVar3 = (void *)FUN_00407fa0(uVar12,acStack_a8);
            if (pvVar3 == (void *)0x0) {
              if (sensor_di_debug_switch != 0) {
                printf("[SENSOR_DI_DEBUG]%s()/line %d : not found ssid_node\n",
                       "_sensor_di_db_set_pkt_stat_ssid",0x29c);
              }
              pvVar3 = (void *)FUN_00408450(0x54,0x29d);
              if (pvVar3 == (void *)0x0) {
                if (sensor_di_err_switch != 0) {
                  pcVar13 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                  uVar12 = 0x2a0;
LAB_004dedf8:
                  printf(pcVar13,"_sensor_di_db_set_pkt_stat_ssid",uVar12);
                }
LAB_004deb5c:
                if (sensor_di_err_switch != 0) {
                  printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_db_set_pkt_stat_ssid fail EXIT\n"
                         ,"_sensor_di_db_set_pkt_stat_ssid",0x2c3);
                }
                if (sensor_di_err_switch != 0) {
                  printf("[SENSOR_DI_ERROR]%s()/line %d : set pkt_stat_ssid fail\n",
                         "sensor_di_db_set_pkt_stat",0x8f3);
                }
                FUN_00407f30(l_sensor_di_data_mutex);
                uVar12 = 0xffffffff;
                if (sensor_di_err_switch == 0) {
                  return 0xffffffff;
                }
                pcVar13 = "[SENSOR_DI_ERROR]%s()/line %d : sensor_di_db_set_pkt_stat fail EXIT\n";
                uVar10 = 0x8fd;
                goto LAB_004de1cc;
              }
              memset(pvVar3,0,0x54);
              memcpy((void *)((int)pvVar3 + 0xc),local_70,0x31);
              *(char *)((int)pvVar3 + 0x3d) = local_70[0x31];
              uVar4 = FUN_00407fe0(iVar1 + 0x1c530);
              *(undefined2 *)((int)pvVar3 + 0x3e) = uVar4;
              FUN_0051ad88((int)pvVar3 + 0x48);
              FUN_00408380(*(undefined4 *)(iVar1 + 0x1c53c),pvVar3);
              FUN_004086b0(iVar1 + 0x1c530,pvVar3);
            }
            local_58 = (int)*(short *)(local_70 + 0x3c);
            __src_01 = *(void **)(local_70 + 0x40);
            if ((local_58 < 1) || (__src_01 == (void *)0x0)) {
              if (sensor_di_err_switch != 0) {
                printf("[SENSOR_DI_ERROR]%s()/line %d : input invalid\n",
                       "_sensor_di_db_set_pkt_stat_bssid",0x24c);
              }
            }
            else {
              local_64 = 0;
              local_48 = (*(int *)(iVar1 + 0x1c520) + -1) % 3;
              local_50 = local_48 * 0x68;
              local_4c = local_48 << 6;
              local_48 = local_48 * 0x30;
              local_34 = (int)pvVar3 + 0x48;
              local_30 = pvVar3;
              do {
                pvVar3 = (void *)FUN_00407fa0(*(undefined4 *)(iVar1 + 0x1c540),__src_01);
                if (pvVar3 == (void *)0x0) {
                  if (sensor_di_debug_switch != 0) {
                    printf("[SENSOR_DI_DEBUG]%s()/line %d : not found bssid_node\n",
                           "_sensor_di_db_set_pkt_stat_bssid",599);
                  }
                  pvVar3 = (void *)FUN_00408450(0x2b8,600);
                  if (pvVar3 == (void *)0x0) {
                    if (sensor_di_err_switch != 0) {
                      pcVar13 = "[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail\n";
                      uVar12 = 0x25b;
LAB_004dedc4:
                      printf(pcVar13,"_sensor_di_db_set_pkt_stat_bssid",uVar12);
                    }
LAB_004deb40:
                    if (sensor_di_err_switch != 0) {
                      printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_db_set_pkt_stat_bssid fail EXIT\n"
                             ,"_sensor_di_db_set_pkt_stat_bssid",0x280);
                    }
                    if (sensor_di_err_switch == 0) goto LAB_004deb5c;
                    pcVar13 = "[SENSOR_DI_ERROR]%s()/line %d : set_pkt_stat_bssid_fail\n";
                    uVar12 = 0x2ae;
                    goto LAB_004dedf8;
                  }
                  memset(pvVar3,0,0x2b8);
                  memcpy((void *)((int)pvVar3 + 0xc),__src_01,6);
                  FUN_0051ad88((int)pvVar3 + 0x2ac);
                  FUN_00408380(*(undefined4 *)(iVar1 + 0x1c540),pvVar3);
                  FUN_004086b0(local_34,pvVar3);
                  di_printmac((void *)((int)pvVar3 + 0xc));
                }
                memcpy((void *)((int)pvVar3 + 0x24 + local_50),(void *)((int)__src_01 + 0x1c),0x68);
                memcpy((void *)((int)pvVar3 + 0x15c + local_4c),(void *)((int)__src_01 + 0x84),0x40)
                ;
                memcpy((void *)((int)pvVar3 + 0x21c + local_48),(void *)((int)__src_01 + 0xc4),0x30)
                ;
                _sensor_di_db_set_pkt_stat_frame
                          ((int)pvVar3 + 0x14,(int)pvVar3 + 0x18,(int)pvVar3 + 0x24,
                           (int)pvVar3 + 0x15c,(int)pvVar3 + 0x21c);
                local_54 = (int)*(short *)((int)__src_01 + 0x18);
                __src_00 = *(void **)((int)__src_01 + 0xf4);
                if ((0 < local_54) && (__src_00 != (void *)0x0)) {
                  iVar11 = 0;
                  local_3c = (*(int *)(iVar1 + 0x1c520) + -1) % 3;
                  local_44 = local_3c * 0x68;
                  local_40 = local_3c << 6;
                  local_3c = local_3c * 0x30;
                  local_38 = (int)pvVar3 + 0x2ac;
                  local_2c = pvVar3;
                  do {
                    pvVar3 = (void *)FUN_00407fa0(*(undefined4 *)(iVar1 + 0x1c544),__src_00);
                    if (pvVar3 == (void *)0x0) {
                      if (sensor_di_debug_switch != 0) {
                        printf("[SENSOR_DI_DEBUG]%s()/line %d : not found sta_node\n",
                               "_sensor_di_db_set_pkt_stat_sta",0x219);
                      }
                      pvVar3 = (void *)FUN_00408450(0x2a4,0x21a);
                      if (pvVar3 == (void *)0x0) {
                        if (sensor_di_err_switch != 0) {
                          printf("[SENSOR_DI_ERROR]%s()/line %d : mem malloc fail \n",
                                 "_sensor_di_db_set_pkt_stat_sta",0x21d);
                        }
                        if (sensor_di_err_switch != 0) {
                          printf("[SENSOR_DI_ERROR]%s()/line %d : _sensor_di_db_set_pkt_stat_sta fail EXIT\n"
                                 ,"_sensor_di_db_set_pkt_stat_sta",0x23f);
                        }
                        if (sensor_di_err_switch == 0) goto LAB_004deb40;
                        pcVar13 = "[SENSOR_DI_ERROR]%s()/line %d : set_pkt_stat_sta_fail\n";
                        uVar12 = 0x26d;
                        goto LAB_004dedc4;
                      }
                      memset(pvVar3,0,0x2a4);
                      memcpy((void *)((int)pvVar3 + 0xc),__src_00,6);
                      FUN_00408380(*(undefined4 *)(iVar1 + 0x1c544),pvVar3);
                      FUN_004086b0(local_38,pvVar3);
                      di_printmac((void *)((int)pvVar3 + 0xc));
                    }
                    memcpy((void *)((int)pvVar3 + 0x1c + local_44),(void *)((int)__src_00 + 0x10),
                           0x68);
                    iVar11 = iVar11 + 1;
                    memcpy((void *)((int)pvVar3 + 0x154 + local_40),(void *)((int)__src_00 + 0x78),
                           0x40);
                    __src = (void *)((int)__src_00 + 0xb8);
                    __src_00 = (void *)((int)__src_00 + 0xe8);
                    memcpy((void *)((int)pvVar3 + 0x214 + local_3c),__src,0x30);
                    _sensor_di_db_set_pkt_stat_frame
                              ((int)pvVar3 + 0x14,(int)pvVar3 + 0x18,(int)pvVar3 + 0x1c,
                               (int)pvVar3 + 0x154,(int)pvVar3 + 0x214);
                    pvVar3 = local_2c;
                  } while (iVar11 < local_54);
                  *(undefined4 *)((int)local_2c + 0x1c) = 0;
                  *(undefined4 *)((int)local_2c + 0x20) = 0;
                  iVar11 = FUN_004081b0((int)local_2c + 0x2ac);
                  if (iVar11 != 0) {
                    iVar14 = *(int *)((int)pvVar3 + 0x1c);
                    while( true ) {
                      *(int *)((int)pvVar3 + 0x1c) = iVar14 + *(int *)(iVar11 + 0x14);
                      *(int *)((int)pvVar3 + 0x20) =
                           *(int *)((int)pvVar3 + 0x20) + *(int *)(iVar11 + 0x18);
                      iVar11 = FUN_00408680(iVar11);
                      if (iVar11 == 0) break;
                      iVar14 = *(int *)((int)pvVar3 + 0x1c);
                    }
                  }
                }
                pvVar3 = local_30;
                local_64 = local_64 + 1;
                __src_01 = (void *)((int)__src_01 + 0xf8);
              } while (local_64 < local_58);
              *(undefined4 *)((int)local_30 + 0x40) = 0;
              *(undefined4 *)((int)local_30 + 0x44) = 0;
              for (iVar11 = FUN_004081b0((int)local_30 + 0x48); iVar11 != 0;
                  iVar11 = FUN_00408680(iVar11)) {
                *(int *)((int)pvVar3 + 0x40) =
                     *(int *)((int)pvVar3 + 0x40) +
                     *(int *)(iVar11 + 0x14) + *(int *)(iVar11 + 0x1c);
                *(int *)((int)pvVar3 + 0x44) =
                     *(int *)((int)pvVar3 + 0x44) +
                     *(int *)(iVar11 + 0x18) + *(int *)(iVar11 + 0x20);
              }
            }
            local_68 = local_68 + 1;
            local_70 = local_70 + 0x44;
          } while (local_68 < local_60);
          *(undefined4 *)(local_6c + 0x1c518) = 0;
          *(undefined4 *)(local_6c + 0x1c51c) = 0;
          for (iVar11 = FUN_004081b0(local_5c); iVar11 != 0; iVar11 = FUN_00408680(iVar11)) {
            *(int *)(iVar1 + 0x1c518) = *(int *)(iVar1 + 0x1c518) + *(int *)(iVar11 + 0x40);
            *(int *)(iVar1 + 0x1c51c) = *(int *)(iVar1 + 0x1c51c) + *(int *)(iVar11 + 0x44);
          }
        }
        FUN_00407f30(l_sensor_di_data_mutex);
        if (sensor_di_debug_switch == 0) {
          return 0;
        }
        printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_pkt_stat success EXIT\n",
               "sensor_di_db_set_pkt_stat",0x8f9);
        return 0;
      }
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : chnl unmatch\n","sensor_di_db_set_pkt_stat",0x8e4);
      }
    }
    FUN_00407f30(l_sensor_di_data_mutex);
    uVar12 = 0;
  }
  return uVar12;
}

