// func sensor_di_db_pkt_stat_cache_refresh @ 004e0ef4 size=3284

undefined4 sensor_di_db_pkt_stat_cache_refresh(undefined4 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  void *__s;
  void *__s_00;
  int iVar7;
  void *pvVar8;
  int iVar9;
  undefined4 *puVar10;
  void *pvVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  
  uVar14 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    sensor_di_db_pkt_stat_cache_free();
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar3 = _sensor_di_db_get_sensor_node_from_cached_list(param_2);
    if (iVar3 == 0) {
      FUN_00407f30(l_sensor_di_data_mutex);
    }
    else {
      *param_1 = param_2;
      param_1[1] = (int)*(short *)(iVar3 + 0x1c514);
      uVar4 = *(int *)(iVar3 + 0x1c528) + *(int *)(iVar3 + 0x1c524) + *(int *)(iVar3 + 0x1c52c);
      for (iVar5 = FUN_004081b0(iVar3 + 0x1c530); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
        uVar12 = 0;
        if (uVar4 != 0) {
          if (uVar4 == 0) {
            trap(7);
          }
          uVar12 = (uint)(*(int *)(iVar5 + 0x40) * 10000) / uVar4;
          if ((int)uVar12 < 0) {
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### air_time_percent=%d #########\n",
                     "sensor_di_db_pkt_stat_cache_refresh",0xc3b);
            }
            uVar12 = 0;
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n","sensor_di_db_pkt_stat_cache_refresh",
                     0xc3c,iVar5 + 0xc);
            }
          }
        }
        iVar9 = *(int *)(iVar3 + 0x1c51c);
        iVar13 = 0;
        if (iVar9 != 0) {
          if (iVar9 == 0) {
            trap(7);
          }
          iVar13 = (*(int *)(iVar5 + 0x44) * 10000) / iVar9;
          if (iVar13 < 0) {
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### pkt_num_percent=%d #########\n",
                     "sensor_di_db_pkt_stat_cache_refresh",0xc4b);
            }
            iVar13 = 0;
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n","sensor_di_db_pkt_stat_cache_refresh",
                     0xc4c,iVar5 + 0xc);
            }
          }
        }
        if ((9 < (int)uVar12) || (9 < iVar13)) {
          puVar10 = param_1 + 2;
          uVar6 = FUN_00407fe0(puVar10);
          if ((uVar6 < 300) && (__s = (void *)FUN_00408450(0x44,0xc5c), __s != (void *)0x0)) {
            memset(__s,0,0x44);
            memcpy((void *)((int)__s + 0xc),(void *)(iVar5 + 0xc),0x31);
            *(undefined1 *)((int)__s + 0x3d) = *(undefined1 *)(iVar5 + 0x3d);
            uVar1 = *(undefined2 *)(iVar5 + 0x3e);
            *(short *)((int)__s + 0x42) = (short)iVar13;
            *(short *)((int)__s + 0x40) = (short)uVar12;
            *(undefined2 *)((int)__s + 0x3e) = uVar1;
            uVar12 = *(int *)(iVar3 + 0x1c528) + *(int *)(iVar3 + 0x1c524) +
                     *(int *)(iVar3 + 0x1c52c);
            for (iVar9 = FUN_004081b0(iVar5 + 0x48); iVar9 != 0; iVar9 = FUN_00408680(iVar9)) {
              uVar6 = 0;
              if (uVar12 == 0) {
LAB_004e1150:
                iVar13 = *(int *)(iVar5 + 0x44);
              }
              else {
                if (uVar12 == 0) {
                  trap(7);
                }
                uVar6 = (uint)(*(int *)(iVar9 + 0x14) * 10000) / uVar12;
                if (-1 < (int)uVar6) goto LAB_004e1150;
                if (sensor_di_debug_switch != 0) {
                  printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### air_time_percent=%d #########\n"
                         ,"_sensor_di_db_cache_bssid_refresh",0x65b);
                }
                uVar6 = 0;
                di_printmac(iVar9 + 0xc);
                iVar13 = *(int *)(iVar5 + 0x44);
              }
              iVar16 = 0;
              if (iVar13 != 0) {
                if (iVar13 == 0) {
                  trap(7);
                }
                iVar16 = ((*(int *)(iVar9 + 0x18) + *(int *)(iVar9 + 0x20)) * 10000) / iVar13;
                if (iVar16 < 0) {
                  if (sensor_di_debug_switch != 0) {
                    printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### pkt_num_percent=%d #########\n"
                           ,"_sensor_di_db_cache_bssid_refresh",0x66b);
                  }
                  iVar16 = 0;
                  di_printmac(iVar9 + 0xc);
                }
              }
              if (((9 < (int)uVar6) || (9 < iVar16)) &&
                 (__s_00 = (void *)FUN_00408450(0x84,0x677), __s_00 != (void *)0x0)) {
                memset(__s_00,0,0x84);
                memcpy((void *)((int)__s_00 + 0xe),(void *)(iVar9 + 0xc),6);
                uVar1 = *(undefined2 *)(iVar5 + 0x3e);
                *(short *)((int)__s_00 + 0x14) = (short)uVar6;
                *(undefined2 *)((int)__s_00 + 0xc) = uVar1;
                *(short *)((int)__s_00 + 0x16) = (short)iVar16;
                uVar6 = *(int *)(iVar3 + 0x1c528) + *(int *)(iVar3 + 0x1c524) +
                        *(int *)(iVar3 + 0x1c52c);
                for (iVar13 = FUN_004081b0(iVar9 + 0x2ac); iVar13 != 0;
                    iVar13 = FUN_00408680(iVar13)) {
                  uVar17 = 0;
                  if (uVar6 == 0) {
LAB_004e1240:
                    iVar16 = *(int *)(iVar9 + 0x20);
                  }
                  else {
                    if (uVar6 == 0) {
                      trap(7);
                    }
                    uVar17 = (uint)(*(int *)(iVar13 + 0x14) * 10000) / uVar6;
                    if (-1 < (int)uVar17) goto LAB_004e1240;
                    if (sensor_di_debug_switch != 0) {
                      printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### airtime_percent=%d #########\n"
                             ,"_sensor_di_db_cache_sta_refresh",0x5f5);
                    }
                    uVar17 = 0;
                    di_printmac(iVar13 + 0xc);
                    iVar16 = *(int *)(iVar9 + 0x20);
                  }
                  iVar15 = 0;
                  if (iVar16 != 0) {
                    if (iVar16 == 0) {
                      trap(7);
                    }
                    iVar15 = (*(int *)(iVar13 + 0x18) * 10000) / iVar16;
                    if (iVar15 < 0) {
                      if (sensor_di_debug_switch != 0) {
                        printf("[SENSOR_DI_DEBUG]%s()/line %d : ######### pkt_num_percent=%d #########\n"
                               ,"_sensor_di_db_cache_sta_refresh",0x605);
                      }
                      iVar15 = 0;
                      di_printmac(iVar13 + 0xc);
                    }
                  }
                  if ((9 < (int)uVar17) || (9 < iVar15)) {
                    iVar16 = FUN_004081b0(param_1 + 8);
                    for (; iVar16 != 0; iVar16 = FUN_00408680(iVar16)) {
                      iVar7 = memcmp((void *)(iVar13 + 0xc),(void *)(iVar16 + 0x12),6);
                      if (iVar7 == 0) {
                        if (sensor_di_debug_switch != 0) {
                          printf("[SENSOR_DI_DEBUG]%s()/line %d : =========find dup sta node ===========\n"
                                 ,"_sensor_di_db_cache_sta_refresh",0x61a);
                        }
                        di_printmac((void *)(iVar13 + 0xc));
                        goto LAB_004e1600;
                      }
                    }
                    pvVar8 = (void *)FUN_00408450(0x2a4,0x626);
                    if (pvVar8 != (void *)0x0) {
                      memset(pvVar8,0,0x2a4);
                      memcpy((void *)((int)pvVar8 + 0xc),(void *)(iVar9 + 0xc),6);
                      memcpy((void *)((int)pvVar8 + 0x12),(void *)(iVar13 + 0xc),6);
                      *(short *)((int)pvVar8 + 0x18) = (short)uVar17;
                      *(short *)((int)pvVar8 + 0x1a) = (short)iVar15;
                      memset((void *)((int)pvVar8 + 0x1c),0,0xc);
                      memset((void *)((int)pvVar8 + 0x28),0,0x30);
                      memset((void *)((int)pvVar8 + 0x58),0,0x30);
                      if (uVar6 == 0) {
                        uVar17 = *(uint *)(iVar13 + 0x18);
                      }
                      else {
                        if (uVar6 == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x1c) =
                             (short)((uint)((*(int *)(iVar13 + 0x1c) + *(int *)(iVar13 + 0x84) +
                                            *(int *)(iVar13 + 0xec)) * 10000) / uVar6);
                        if (uVar6 == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x1e) =
                             (short)((uint)((*(int *)(iVar13 + 0x154) + *(int *)(iVar13 + 0x194) +
                                            *(int *)(iVar13 + 0x1d4)) * 10000) / uVar6);
                        if (uVar6 == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x20) =
                             (short)((uint)((*(int *)(iVar13 + 0x214) + *(int *)(iVar13 + 0x244) +
                                            *(int *)(iVar13 + 0x274)) * 10000) / uVar6);
                        uVar17 = *(uint *)(iVar13 + 0x18);
                      }
                      iVar16 = iVar13;
                      pvVar11 = pvVar8;
                      if (uVar17 != 0) {
                        if (uVar17 == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x22) =
                             (short)((uint)((*(int *)(iVar13 + 0x20) + *(int *)(iVar13 + 0x88) +
                                            *(int *)(iVar13 + 0xf0)) * 10000) / uVar17);
                        if (*(uint *)(iVar13 + 0x18) == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x24) =
                             (short)((uint)((*(int *)(iVar13 + 0x158) + *(int *)(iVar13 + 0x198) +
                                            *(int *)(iVar13 + 0x1d8)) * 10000) /
                                    *(uint *)(iVar13 + 0x18));
                        if (*(uint *)(iVar13 + 0x18) == 0) {
                          trap(7);
                        }
                        *(short *)((int)pvVar8 + 0x26) =
                             (short)((uint)((*(int *)(iVar13 + 0x218) + *(int *)(iVar13 + 0x248) +
                                            *(int *)(iVar13 + 0x278)) * 10000) /
                                    *(uint *)(iVar13 + 0x18));
                      }
                      do {
                        if (uVar6 == 0) {
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        else {
                          if (uVar6 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x28) =
                               (short)(((*(int *)(iVar16 + 0x8c) + *(int *)(iVar16 + 0x24) +
                                         *(int *)(iVar16 + 0xf4) & 0xffffU) * 10000) / uVar6);
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        if (uVar17 != 0) {
                          if (uVar17 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x58) =
                               (short)(((*(int *)(iVar16 + 0x90) + *(int *)(iVar16 + 0x28) +
                                         *(int *)(iVar16 + 0xf8) & 0xffffU) * 10000) / uVar17);
                        }
                        iVar16 = iVar16 + 8;
                        pvVar11 = (void *)((int)pvVar11 + 2);
                      } while (iVar16 != iVar13 + 0x60);
                      iVar16 = iVar13;
                      pvVar11 = pvVar8;
                      do {
                        if (uVar6 == 0) {
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        else {
                          if (uVar6 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x40) =
                               (short)(((*(int *)(iVar16 + 0x19c) + *(int *)(iVar16 + 0x15c) +
                                         *(int *)(iVar16 + 0x1dc) & 0xffffU) * 10000) / uVar6);
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        if (uVar17 != 0) {
                          if (uVar17 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x70) =
                               (short)(((*(int *)(iVar16 + 0x1a0) + *(int *)(iVar16 + 0x160) +
                                         *(int *)(iVar16 + 0x1e0) & 0xffffU) * 10000) / uVar17);
                        }
                        iVar16 = iVar16 + 8;
                        pvVar11 = (void *)((int)pvVar11 + 2);
                      } while (iVar16 != iVar13 + 0x38);
                      iVar16 = iVar13;
                      pvVar11 = pvVar8;
                      do {
                        if (uVar6 == 0) {
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        else {
                          if (uVar6 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x4e) =
                               (short)(((*(int *)(iVar16 + 0x24c) + *(int *)(iVar16 + 0x21c) +
                                         *(int *)(iVar16 + 0x27c) & 0xffffU) * 10000) / uVar6);
                          uVar17 = *(uint *)(iVar13 + 0x18);
                        }
                        if (uVar17 != 0) {
                          if (uVar17 == 0) {
                            trap(7);
                          }
                          *(short *)((int)pvVar11 + 0x7e) =
                               (short)(((*(int *)(iVar16 + 0x250) + *(int *)(iVar16 + 0x220) +
                                         *(int *)(iVar16 + 0x280) & 0xffffU) * 10000) / uVar17);
                        }
                        iVar16 = iVar16 + 8;
                        pvVar11 = (void *)((int)pvVar11 + 2);
                      } while (iVar16 != iVar13 + 0x28);
                      FUN_004086b0(param_1 + 8,pvVar8);
                    }
                  }
LAB_004e1600:
                }
                memset((void *)((int)__s_00 + 0x18),0,0xc);
                memset((void *)((int)__s_00 + 0x24),0,0x30);
                memset((void *)((int)__s_00 + 0x54),0,0x30);
                if (uVar12 == 0) {
                  uVar6 = *(uint *)(iVar9 + 0x18);
                }
                else {
                  if (uVar12 == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x18) =
                       (short)((uint)((*(int *)(iVar9 + 0x24) + *(int *)(iVar9 + 0x8c) +
                                      *(int *)(iVar9 + 0xf4)) * 10000) / uVar12);
                  if (uVar12 == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x1a) =
                       (short)((uint)((*(int *)(iVar9 + 0x15c) + *(int *)(iVar9 + 0x19c) +
                                      *(int *)(iVar9 + 0x1dc)) * 10000) / uVar12);
                  if (uVar12 == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x1c) =
                       (short)((uint)((*(int *)(iVar9 + 0x21c) + *(int *)(iVar9 + 0x24c) +
                                      *(int *)(iVar9 + 0x27c)) * 10000) / uVar12);
                  uVar6 = *(uint *)(iVar9 + 0x18);
                }
                iVar13 = iVar9;
                pvVar8 = __s_00;
                if (uVar6 != 0) {
                  if (uVar6 == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x1e) =
                       (short)((uint)((*(int *)(iVar9 + 0x28) + *(int *)(iVar9 + 0x90) +
                                      *(int *)(iVar9 + 0xf8)) * 10000) / uVar6);
                  if (*(uint *)(iVar9 + 0x18) == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x20) =
                       (short)((uint)((*(int *)(iVar9 + 0x160) + *(int *)(iVar9 + 0x1a0) +
                                      *(int *)(iVar9 + 0x1e0)) * 10000) / *(uint *)(iVar9 + 0x18));
                  if (*(uint *)(iVar9 + 0x18) == 0) {
                    trap(7);
                  }
                  *(short *)((int)__s_00 + 0x22) =
                       (short)((uint)((*(int *)(iVar9 + 0x220) + *(int *)(iVar9 + 0x250) +
                                      *(int *)(iVar9 + 0x280)) * 10000) / *(uint *)(iVar9 + 0x18));
                }
                do {
                  if (uVar12 == 0) {
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  else {
                    if (uVar12 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x24) =
                         (short)(((*(int *)(iVar13 + 0x94) + *(int *)(iVar13 + 0x2c) +
                                   *(int *)(iVar13 + 0xfc) & 0xffffU) * 10000) / uVar12);
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  if (uVar6 != 0) {
                    if (uVar6 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x54) =
                         (short)(((*(int *)(iVar13 + 0x98) + *(int *)(iVar13 + 0x30) +
                                   *(int *)(iVar13 + 0x100) & 0xffffU) * 10000) / uVar6);
                  }
                  iVar13 = iVar13 + 8;
                  pvVar8 = (void *)((int)pvVar8 + 2);
                } while (iVar13 != iVar9 + 0x60);
                iVar13 = iVar9;
                pvVar8 = __s_00;
                do {
                  if (uVar12 == 0) {
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  else {
                    if (uVar12 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x3c) =
                         (short)(((*(int *)(iVar13 + 0x1a4) + *(int *)(iVar13 + 0x164) +
                                   *(int *)(iVar13 + 0x1e4) & 0xffffU) * 10000) / uVar12);
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  if (uVar6 != 0) {
                    if (uVar6 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x6c) =
                         (short)(((*(int *)(iVar13 + 0x1a8) + *(int *)(iVar13 + 0x168) +
                                   *(int *)(iVar13 + 0x1e8) & 0xffffU) * 10000) / uVar6);
                  }
                  iVar13 = iVar13 + 8;
                  pvVar8 = (void *)((int)pvVar8 + 2);
                } while (iVar13 != iVar9 + 0x38);
                iVar13 = iVar9;
                pvVar8 = __s_00;
                do {
                  if (uVar12 == 0) {
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  else {
                    if (uVar12 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x4a) =
                         (short)(((*(int *)(iVar13 + 0x254) + *(int *)(iVar13 + 0x224) +
                                   *(int *)(iVar13 + 0x284) & 0xffffU) * 10000) / uVar12);
                    uVar6 = *(uint *)(iVar9 + 0x18);
                  }
                  if (uVar6 != 0) {
                    if (uVar6 == 0) {
                      trap(7);
                    }
                    *(short *)((int)pvVar8 + 0x7a) =
                         (short)(((*(int *)(iVar13 + 600) + *(int *)(iVar13 + 0x228) +
                                   *(int *)(iVar13 + 0x288) & 0xffffU) * 10000) / uVar6);
                  }
                  iVar13 = iVar13 + 8;
                  pvVar8 = (void *)((int)pvVar8 + 2);
                } while (iVar13 != iVar9 + 0x28);
                FUN_004086b0(param_1 + 5,__s_00);
                FUN_00408380(param_1[0x137],__s_00);
              }
            }
            iVar9 = FUN_004081b0(puVar10);
            if (iVar9 == 0) {
LAB_004e1978:
              FUN_004086b0(puVar10,__s);
              if (*(ushort *)((int)__s + 0x3e) < 300) {
                param_1[(short)*(ushort *)((int)__s + 0x3e) + 0xb] = __s;
              }
            }
            else {
              uVar2 = *(ushort *)((int)__s + 0x42);
              while ((uint)*(ushort *)((int)__s + 0x40) + (uint)uVar2 <=
                     (uint)*(ushort *)(iVar9 + 0x40) + (uint)*(ushort *)(iVar9 + 0x42)) {
                iVar9 = FUN_00408680();
                if (iVar9 == 0) goto LAB_004e1978;
                uVar2 = *(ushort *)((int)__s + 0x42);
              }
              FUN_00408170(iVar9,__s);
              if (*(ushort *)((int)__s + 0x3e) < 300) {
                param_1[(short)*(ushort *)((int)__s + 0x3e) + 0xb] = __s;
              }
            }
          }
        }
      }
      uVar14 = 0;
      FUN_00407f30(l_sensor_di_data_mutex);
    }
  }
  return uVar14;
}

