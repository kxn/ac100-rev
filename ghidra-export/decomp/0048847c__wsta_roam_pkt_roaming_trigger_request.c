// func _wsta_roam_pkt_roaming_trigger_request @ 0048847c size=2936

/* WARNING: Type propagation algorithm not settling */

undefined4
_wsta_roam_pkt_roaming_trigger_request(char *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 *puVar12;
  char *pcVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  void *pvVar19;
  uint uVar20;
  void *__src;
  byte bVar21;
  uint uVar22;
  int local_580;
  int local_57c [2];
  undefined2 local_574;
  undefined4 local_570;
  undefined4 local_56c;
  undefined2 local_568;
  undefined1 auStack_564 [12];
  undefined1 auStack_558 [12];
  uint local_54c;
  undefined4 local_548;
  undefined4 local_544;
  undefined4 local_540;
  undefined1 auStack_53c [36];
  undefined1 auStack_518 [8];
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined1 auStack_4f0 [32];
  uint local_4d0;
  undefined2 local_4cc;
  undefined1 auStack_470 [4];
  int local_46c;
  undefined1 local_468;
  undefined1 local_460;
  undefined1 local_45f;
  undefined1 auStack_308 [16];
  ushort local_2f8;
  undefined2 local_2c0;
  undefined2 local_2be;
  undefined2 local_2bc;
  uint local_30;
  uint local_2c;
  
  memset(auStack_308,0,0x2d8);
  memset(auStack_4f0,0,0x80);
  local_570 = 0;
  local_56c = 0;
  local_568 = 0;
  memset(auStack_53c,0,0x22);
  memset(auStack_518,0,0x28);
  DAT_007675dc = DAT_007675dc + 1;
  iVar9 = apmngr_db_entry_get_by_mac(param_3,auStack_308);
  if (iVar9 == 0) {
    wsta_roam_db_cfg_get(auStack_53c);
    uVar22 = 0;
    stats_db_radio_set_chload_and_nf(local_2f8,*param_1,param_1[1],(int)param_1[2]);
    local_510 = 0;
    local_50c = 1;
    local_508 = 0;
    local_504 = *(undefined4 *)(param_1 + 4);
    wsta_roam_db_ap_stats_cumulate(local_2f8,auStack_518);
    FUN_0051ad88(auStack_558);
    FUN_0051ad88(auStack_564);
    while (uVar22 < *(uint *)(param_1 + 4)) {
      iVar17 = uVar22 * 0x10;
      iVar9 = wsta_db_get_entry_by_mac(*(int *)(param_1 + 8) + iVar17,auStack_4f0);
      if (iVar9 == 0) {
        if (((local_4d0 == local_2f8) && (local_4cc._0_1_ == *param_1)) &&
           ((char)local_4cc == *(char *)(*(int *)(param_1 + 8) + iVar17 + 6))) {
          iVar9 = FUN_004082a0(1,0x260,0x5f6);
          if (iVar9 == 0) {
            uVar15 = 0xffffffff;
            if (wsta_roam_err_switch == '\0') goto LAB_00488948;
            pcVar11 = "[WSTA_ROAM_ERROR]%s()/%d out of memory\n";
            pcVar13 = "_wsta_roam_pkt_roaming_trigger_request";
            uVar14 = 0x5f9;
            goto LAB_004889c8;
          }
          if (wsta_roam_strategy_switch != '\0') {
            pbVar18 = (byte *)(*(int *)(param_1 + 8) + iVar17);
            printf("[WSTA_ROAM_STRATEGY]%s()/%d station[%02x:%02x:%02x:%02x:%02x:%02x] check ok, add it to station-list.\n"
                   ,"_wsta_roam_pkt_roaming_trigger_request",0x5fe,(uint)*pbVar18,(uint)pbVar18[1],
                   (uint)pbVar18[2],(uint)pbVar18[3],(uint)pbVar18[4],(uint)pbVar18[5]);
          }
          *(ushort *)(iVar9 + 0x12) = local_2f8;
          *(char *)(iVar9 + 0x14) = *param_1;
          *(undefined1 *)(iVar9 + 0x15) = 3;
          *(undefined1 *)(iVar9 + 0x16) = *(undefined1 *)(*(int *)(param_1 + 8) + iVar17 + 6);
          *(undefined1 *)(iVar9 + 0x17) = *(undefined1 *)(*(int *)(param_1 + 8) + iVar17 + 7);
          memcpy((void *)(iVar9 + 0xc),(void *)(*(int *)(param_1 + 8) + iVar17),6);
          puVar12 = auStack_558;
          if (*(char *)(*(int *)(param_1 + 8) + iVar17 + 9) != '\0') {
            if (*(int *)(*(int *)(param_1 + 8) + iVar17 + 0xc) == 0) {
              puVar12 = auStack_558;
            }
            else {
              if (wsta_roam_strategy_switch == '\0') {
                iVar10 = *(int *)(param_1 + 8);
              }
              else {
                printf("[WSTA_ROAM_STRATEGY]%s()/%d construct bstm nbrs[%d].\n",
                       "_wsta_roam_pkt_roaming_trigger_request",0x609,uVar22);
                iVar10 = *(int *)(param_1 + 8);
              }
              local_2c = (uint)*(byte *)(iVar10 + iVar17 + 9);
              __src = *(void **)(iVar10 + iVar17 + 0xc);
              local_54c = 0;
              local_548 = 0;
              local_544 = local_544 & 0xffff;
              memset(auStack_470,0,0x168);
              cVar7 = wsta_roam_strategy_switch;
              local_57c[1] = 0;
              local_574 = 0;
              if ((local_2c != 0) && (__src != (void *)0x0)) {
                *(undefined1 *)(iVar9 + 0x1d) = 0;
                *(undefined1 *)(iVar9 + 0x1c) = 0;
                if (cVar7 != '\0') {
                  printf("[WSTA_ROAM_STRATEGY]%s()/%d calculate rcpi method:\n","_bstm_ngr_generate"
                         ,0x553);
                }
                iVar17 = 0;
                local_30 = 2;
                pvVar19 = __src;
                do {
                  if (wsta_roam_strategy_switch == '\0') {
                    bVar21 = *(byte *)((int)pvVar19 + 6);
                  }
                  else {
                    printf("[WSTA_ROAM_STRATEGY]%s()/%d [idx=%d,count=%d]: rcpi[%u], rsni[%u]\n",
                           "_bstm_ngr_generate",0x557,iVar17,local_2c,
                           (uint)*(byte *)((int)pvVar19 + 6),(uint)*(byte *)((int)pvVar19 + 7));
                    bVar21 = *(byte *)((int)pvVar19 + 6);
                  }
                  if (-1 < (char)bVar21) {
                    uVar20 = 1;
                    break;
                  }
                  if (bVar21 == 0xdc) {
LAB_00488c50:
                    uVar20 = 0;
                    break;
                  }
                  uVar20 = 0;
                  if ((byte)(bVar21 + 0x23) < 0x22) break;
                  if (bVar21 == 0xff) goto LAB_00488c50;
                  if ((bVar21 & 1) == 0) {
                    uVar20 = *(byte *)((int)pvVar19 + 7) < 0x3d ^ 1;
                  }
                  uVar8 = uVar20;
                  if ((local_30 != 2) && (uVar8 = local_30, local_30 != uVar20)) {
                    uVar20 = 2;
                    if (wsta_roam_strategy_switch != '\0') {
                      printf("[WSTA_ROAM_STRATEGY]%s()/%d warning:un-consistent rcpi method\n",
                             "_bstm_ngr_generate",0x565);
                    }
                    break;
                  }
                  local_30 = uVar8;
                  iVar17 = iVar17 + 1;
                  pvVar19 = (void *)((int)pvVar19 + 9);
                } while (iVar17 < (int)local_2c);
                if (wsta_roam_strategy_switch != '\0') {
                  printf("[WSTA_ROAM_STRATEGY]%s()/%d calculate rcpi method [%d]\n",
                         "_bstm_ngr_generate",0x56a,uVar20);
                }
                if (uVar20 != 2) {
                  iVar17 = stats_db_radio_get(*(undefined2 *)(iVar9 + 0x12),
                                              *(undefined1 *)(iVar9 + 0x14),auStack_470);
                  if (iVar17 == 0) {
                    *(int *)(iVar9 + 0x18) = local_46c;
                    local_30 = 0;
                  }
                  else {
                    local_30 = 0;
                  }
                  do {
                    memcpy(&local_54c,__src,6);
                    iVar17 = stats_db_bssid_get(&local_54c);
                    if (iVar17 == 0) {
                      if (((local_30 != 0) || ((local_548 & 0xffff) != local_4d0)) ||
                         (local_544._0_2_ != local_4cc)) {
                        iVar17 = stats_db_ap_mac_get(local_548._2_2_,local_57c + 1);
                        if (iVar17 == 0) {
                          iVar17 = stats_db_radio_get(local_548 & 0xffff,local_544._0_1_,auStack_470
                                                     );
                          if (iVar17 == 0) {
                            if (local_46c == 1) {
                              iVar17 = (uint)*(byte *)(iVar9 + 0x1d) * 0x18 + 0x140;
                            }
                            else {
                              iVar17 = (uint)*(byte *)(iVar9 + 0x1c) * 0x18 + 0x20;
                            }
                            pvVar19 = (void *)(iVar9 + iVar17);
                            *(undefined2 *)((int)pvVar19 + 6) = local_548._2_2_;
                            memcpy(pvVar19,local_57c + 1,6);
                            *(undefined1 *)((int)pvVar19 + 8) = local_544._0_1_;
                            *(undefined1 *)((int)pvVar19 + 10) = local_468;
                            *(undefined1 *)((int)pvVar19 + 9) = local_45f;
                            *(undefined1 *)((int)pvVar19 + 0xb) = local_460;
                            bVar21 = *(byte *)((int)__src + 6);
                            if (uVar20 == 1) {
                              bVar21 = (bVar21 >> 1) + 0x92;
                            }
                            iVar10 = (int)(char)bVar21;
                            iVar17 = -0x5f;
                            if (-0x56 < iVar10) {
                              iVar17 = (int)(char)(bVar21 - 10);
                            }
                            bVar1 = wsta_roam_strategy_switch == '\0';
                            *(char *)((int)pvVar19 + 0xc) = (char)iVar17;
                            if (bVar1) {
                            }
                            else {
                              printf("[WSTA_ROAM_STRATEGY]%s()/%d bstm nbr [%02x:%02x:%02x:%02x:%02x:%02x] generate ok, rcpi[%u --> %d], rssi=%d.\n"
                                     ,"_bstm_ngr_generate",0x598,local_54c >> 0x18,
                                     local_54c >> 0x10 & 0xff,local_54c >> 8 & 0xff,local_54c & 0xff
                                     ,local_548 >> 0x18,local_548 >> 0x10 & 0xff,
                                     (uint)*(byte *)((int)__src + 6),iVar10,iVar17);
                            }
                            *(undefined1 *)((int)pvVar19 + 0xd) = local_544._1_1_;
                            memcpy((void *)((int)pvVar19 + 0xe),&local_54c,6);
                            iVar17 = wss_steer_candidate_rate_estimate
                                               (iVar9 + 0xc,pvVar19,auStack_470,iVar10);
                            *(int *)((int)pvVar19 + 0x14) = iVar17;
                            if (iVar17 == -1) {
                              if (wsta_roam_strategy_switch != '\0') {
                                printf("[WSTA_ROAM_STRATEGY]%s()/%d info of bstm nbr [%02x:%02x:%02x:%02x:%02x:%02x] calculate estimate rate failed, skip this bstm nbr.\n"
                                       ,"_bstm_ngr_generate",0x5a0,local_54c >> 0x18,
                                       local_54c >> 0x10 & 0xff,local_54c >> 8 & 0xff,
                                       local_54c & 0xff,local_548 >> 0x18,local_548 >> 0x10 & 0xff);
                              }
                              memset(pvVar19,0,0x18);
                            }
                            else if (local_46c == 1) {
                              *(char *)(iVar9 + 0x1d) = *(char *)(iVar9 + 0x1d) + '\x01';
                            }
                            else {
                              *(char *)(iVar9 + 0x1c) = *(char *)(iVar9 + 0x1c) + '\x01';
                            }
                            goto LAB_0048887c;
                          }
                        }
                        if (wsta_roam_strategy_switch != '\0') {
                          pcVar11 = 
                          "[WSTA_ROAM_STRATEGY]%s()/%d info of bstm nbr [%02x:%02x:%02x:%02x:%02x:%02x] not get correct, skip this bstm nbr.\n"
                          ;
                          uVar15 = 0x5b1;
                          goto LAB_004888fc;
                        }
                      }
                    }
                    else if (wsta_roam_strategy_switch != '\0') {
                      uVar15 = 0x5b7;
                      pcVar11 = 
                      "[WSTA_ROAM_STRATEGY]%s()/%d bssid [%02x:%02x:%02x:%02x:%02x:%02x] not found, skip this bstm nbr.\n"
                      ;
LAB_004888fc:
                      printf(pcVar11,"_bstm_ngr_generate",uVar15,(uint)local_54c._0_1_,
                             local_54c >> 0x10 & 0xff,local_54c >> 8 & 0xff,local_54c & 0xff,
                             local_548 >> 0x18,local_548 >> 0x10 & 0xff);
                    }
LAB_0048887c:
                    __src = (void *)((int)__src + 9);
                    local_30 = local_30 + 1;
                  } while ((int)local_30 < (int)local_2c);
                }
              }
              puVar12 = auStack_564;
            }
          }
          FUN_004086b0(puVar12,iVar9);
          uVar22 = uVar22 + 1;
        }
        else {
          if (wsta_roam_strategy_switch != '\0') {
            uVar15 = 0x5f2;
            pbVar18 = (byte *)(*(int *)(param_1 + 8) + iVar17);
            bVar21 = pbVar18[1];
            bVar2 = *pbVar18;
            bVar3 = pbVar18[2];
            bVar4 = pbVar18[3];
            bVar5 = pbVar18[4];
            bVar6 = pbVar18[5];
            pcVar11 = 
            "[WSTA_ROAM_STRATEGY]%s()/%d station[%02x:%02x:%02x:%02x:%02x:%02x] associated target mismatch, skip it...\n"
            ;
            goto LAB_0048864c;
          }
          uVar22 = uVar22 + 1;
        }
      }
      else if (wsta_roam_strategy_switch == '\0') {
        uVar22 = uVar22 + 1;
      }
      else {
        pcVar11 = 
        "[WSTA_ROAM_STRATEGY]%s()/%d station[%02x:%02x:%02x:%02x:%02x:%02x] not found, skip it...\n"
        ;
        pbVar18 = (byte *)(*(int *)(param_1 + 8) + iVar17);
        uVar15 = 0x5ea;
        bVar21 = pbVar18[1];
        bVar2 = *pbVar18;
        bVar3 = pbVar18[2];
        bVar4 = pbVar18[3];
        bVar5 = pbVar18[4];
        bVar6 = pbVar18[5];
LAB_0048864c:
        printf(pcVar11,"_wsta_roam_pkt_roaming_trigger_request",uVar15,(uint)bVar2,(uint)bVar21,
               (uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6);
        uVar22 = uVar22 + 1;
      }
    }
    iVar9 = FUN_00407fe0(auStack_558);
    if (iVar9 != 0) {
      if (wsta_roam_strategy_switch != '\0') {
        printf("[WSTA_ROAM_STRATEGY]%s()/%d get nbrs of station-list.\n",
               "_wsta_roam_pkt_roaming_trigger_request",0x616);
      }
      stats_db_sta_get_nbr_set(auStack_558);
    }
    iVar9 = FUN_00407fe0(auStack_564);
    if (iVar9 != 0) {
      FUN_004082c0(auStack_558,auStack_564);
    }
    iVar9 = FUN_00407fe0(auStack_558);
    if (iVar9 == 0) {
      uVar15 = 0;
      if (wsta_roam_strategy_switch != '\0') {
        pcVar11 = "[WSTA_ROAM_STRATEGY]%s()/%d No valid trigger stations, goto done.\n";
        pcVar13 = "_wsta_roam_pkt_roaming_trigger_request";
        uVar14 = 0x622;
LAB_004889c8:
        printf(pcVar11,pcVar13,uVar14);
      }
    }
    else {
      local_57c[0] = 0;
      iVar17 = 1;
      local_568 = CONCAT11(*param_1,(undefined1)local_568);
      local_570 = CONCAT22(local_2f8,local_2c0);
      local_56c = CONCAT22(local_2be,local_2bc);
      iVar9 = FUN_004081b0(auStack_558);
      while (uVar15 = 0, iVar9 != 0) {
        local_57c[0] = 0;
        if (wsta_roam_strategy_switch != '\0') {
          printf("[WSTA_ROAM_STRATEGY]%s()/%d \n\nsend No.%d packet.\n","_roaming_nbr_pkt_send_cb",
                 0x4c7,iVar17);
        }
        local_54c = 0;
        local_548 = 0;
        local_544 = 0;
        local_540 = 0;
        local_580 = 0;
        iVar10 = serv_wtp_address_arg_init(&local_54c);
        if (iVar10 == -1) {
          if (wsta_roam_err_switch != '\0') {
            printf("[WSTA_ROAM_ERROR]%s()/%d serv arg init failed\n","_roaming_nbr_packet_send",
                   0x493);
          }
LAB_00488a7c:
          uVar15 = 0;
          if (wsta_roam_err_switch != '\0') {
            pcVar11 = "[WSTA_ROAM_ERROR]%s()/%d send packet to AP failed\n";
            pcVar13 = "_roaming_nbr_pkt_send_cb";
            uVar14 = 0x4ca;
            goto LAB_004889c8;
          }
          break;
        }
        iVar16 = -1;
        iVar10 = cw_pkt_buf_create(0xfa);
        if (iVar10 != 0) {
          iVar9 = _roaming_nbr_packet_create
                            (&local_570,iVar10,&local_54c,&local_580,iVar9,local_57c);
          if (iVar9 == -1) {
            if (wsta_roam_err_switch != '\0') {
              pcVar11 = "[WSTA_ROAM_ERROR]%s()/%d create packet failed\n";
              uVar15 = 0x4a0;
              goto LAB_00488ba0;
            }
          }
          else if ((local_544 == 0) || (local_580 == 0)) {
            iVar16 = 0;
            if (wsta_roam_debug_switch != '\0') {
              pcVar11 = "[WSTA_ROAM_DEBUG]%s()/%d no AP need to send configure\n";
              uVar15 = 0x4a5;
              goto LAB_00488ba0;
            }
          }
          else {
            iVar9 = serv_packet_send(&local_54c,iVar10,0);
            iVar16 = 0;
            if ((iVar9 == -1) && (iVar16 = -1, wsta_roam_err_switch != '\0')) {
              pcVar11 = "[WSTA_ROAM_ERROR]%s()/%d send packet failed.\n";
              uVar15 = 0x4ab;
LAB_00488ba0:
              printf(pcVar11,"_roaming_nbr_packet_send",uVar15);
            }
          }
        }
        serv_wtp_address_arg_destroy(&local_54c);
        if (iVar10 != 0) {
          cw_pkt_buf_destroy(iVar10);
        }
        if (iVar16 != 0) goto LAB_00488a7c;
        iVar17 = iVar17 + 1;
        iVar9 = local_57c[0];
      }
    }
LAB_00488948:
    iVar9 = FUN_004081b0(auStack_558);
    while (iVar9 != 0) {
      iVar17 = FUN_00408680(iVar9);
      FUN_00407df0(iVar9);
      iVar9 = iVar17;
    }
  }
  else {
    uVar15 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
             "_wsta_roam_pkt_roaming_trigger_request",0x5d0);
    }
  }
  return uVar15;
}

