// func rdmngr_packet_create @ 00614988 size=7232

undefined4 rdmngr_packet_create(uint *param_1,int param_2,int param_3)

{
  undefined3 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar6;
  ushort uVar7;
  undefined1 uVar8;
  int iVar5;
  byte bVar10;
  char cVar11;
  short *psVar9;
  char *pcVar12;
  byte bVar13;
  undefined4 uVar14;
  undefined *puVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined1 uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int local_a70;
  int local_a6c;
  undefined4 local_a68;
  uint local_a64;
  uint local_a60;
  uint local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  undefined4 local_a4c;
  undefined4 local_a48;
  undefined4 local_a44;
  undefined4 local_a40;
  undefined4 local_a3c;
  undefined4 local_a38;
  undefined4 local_a34;
  undefined4 local_a30;
  undefined4 local_a2c;
  undefined1 auStack_a28 [36];
  undefined1 auStack_a04 [52];
  undefined1 local_9d0;
  byte local_9cf [8];
  byte local_9c7 [8];
  byte local_9bf;
  byte local_9be [4];
  byte local_9ba [10];
  short local_9b0;
  short local_9ae;
  byte local_9a9 [12];
  byte local_99d;
  undefined1 local_99c;
  undefined1 local_99b;
  undefined1 local_99a;
  undefined1 auStack_8b8 [64];
  undefined4 local_878;
  undefined1 auStack_6a0 [192];
  undefined1 auStack_5e0 [64];
  undefined4 local_5a0;
  undefined1 auStack_3c8 [192];
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined1 auStack_f0 [60];
  uint local_b4;
  uint local_30;
  
  memset(auStack_308,0,0x2d8);
  if ((param_1 == (uint *)0x0) || (param_2 == 0)) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar12 = "[RDMNGR_ERROR]%s()/%d Invalid params.\n";
    uVar17 = 0x505;
LAB_00614b00:
    printf(pcVar12,"rdmngr_packet_create",uVar17);
    return 0xffffffff;
  }
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar12 = "[RDMNGR_ERROR]%s()/%d no memory\n";
    uVar17 = 0x50b;
    goto LAB_00614b00;
  }
  uVar16 = *param_1;
  if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, cfg:%d, info:%d\n","rdmngr_packet_create",0x511,*param_1
           ,(int)*(char *)(param_1 + 0x11),(uint)*(byte *)(param_2 + 2));
  }
  uVar3 = rdmngr_db_generate_ap_id(*param_1);
  iVar4 = apmngr_db_entry_get_by_id(uVar3 & 0xffff,auStack_308);
  if (iVar4 != 0) {
    uVar17 = 0xffffffff;
    if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00614a40;
    pcVar12 = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() fail:%d.\n";
    uVar14 = 0x516;
LAB_00614b64:
    uVar17 = 0xffffffff;
    printf(pcVar12,"rdmngr_packet_create",uVar14,uVar3);
    goto LAB_00614a40;
  }
  uVar16 = uVar16 & 0xf;
  if (*(char *)(param_2 + 2) != '\x01') {
    if (*(char *)(param_2 + 2) != '\x02') {
      uVar17 = 0xffffffff;
      if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00614a40;
      uVar3 = (uint)*(byte *)(param_2 + 2);
      pcVar12 = "[RDMNGR_ERROR]%s()/%d current operation(%d) is wrong\n";
      uVar14 = 0x581;
      goto LAB_00614b64;
    }
    iVar4 = rdmngr_ele_set_adm_state(uVar16,iVar2,2);
    if (iVar4 != 0) {
      uVar17 = 0xffffffff;
      if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00614a40;
      pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_adm_state() failed.\n";
      uVar14 = 0x57b;
      goto LAB_00614bec;
    }
    goto LAB_00614c70;
  }
  iVar4 = rdmngr_ele_set_adm_state(uVar16,iVar2,1);
  if (iVar4 == 0) {
    bVar10 = (byte)*(short *)(param_1 + 2);
    local_a54 = (undefined4 *)0x0;
    local_a50 = 0;
    if (*(short *)(param_1 + 2) == -1) {
      bVar10 = 0;
    }
    local_a4c = 0;
    local_a48 = 0;
    local_a58._1_3_ = (uint3)bVar10 << 8;
    uVar18 = (undefined1)uVar16;
    local_a58 = CONCAT13(uVar18,local_a58._1_3_);
    local_a58 = CONCAT31(local_a58._0_3_,2);
    uVar6 = rdmngr_db_generate_ap_id(*param_1);
    iVar4 = apmngr_db_capacity_support(uVar6,1,9);
    if (iVar4 == 0) {
      local_a50 = CONCAT13(0xff,local_a50._1_3_);
      uVar8 = 0xff;
      uVar1 = 0xffffff;
      local_a50 = CONCAT22(local_a50._0_2_,0xffff);
      local_a4c = 0xffffffff;
    }
    else {
      local_a50 = CONCAT13(*(char *)((int)param_1 + 10) == '\0',local_a50._1_3_);
      uVar1 = *(undefined3 *)((int)param_1 + 0x12);
      local_a50 = CONCAT22(local_a50._0_2_,*(undefined2 *)(param_1 + 3));
      local_a4c = CONCAT22(*(undefined2 *)((int)param_1 + 0xe),100);
      uVar8 = *(undefined1 *)((int)param_1 + 0x45);
    }
    local_a48 = CONCAT31(uVar1,uVar8);
    iVar4 = cw_service_msg_add(iVar2,0x404,&local_a58,0);
    if (iVar4 == 0) {
      if (rdmngr_debug_switch == 0) {
        uVar7 = *(ushort *)(param_1 + 8);
      }
      else {
        iVar4 = is_target_debug_ap();
        if (iVar4 == 0) {
          uVar7 = *(ushort *)(param_1 + 8);
        }
        else {
          printf("[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_80211_drt_seq_ctrl() OK.\n",
                 "rdmngr_ele_set_80211_drt_seq_ctrl",0x1f1);
          uVar7 = *(ushort *)(param_1 + 8);
        }
      }
      local_a60 = 0;
      local_a5c = 0;
      local_a68 = CONCAT13(uVar18,(uint3)uVar7);
      local_a64 = (uint)*(ushort *)((int)param_1 + 0x1a);
      iVar4 = cw_service_msg_add(iVar2,0x406,&local_a68,0);
      if (iVar4 == 0) {
        if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_80211_mac_op() OK.\n",
                 "rdmngr_ele_set_80211_mac_op",0x20f);
        }
        local_a58 = 0;
        memset(auStack_5e0,0,0x2d8);
        memset(&local_9d0,0,0x114);
        uVar6 = rdmngr_db_generate_ap_id(*param_1);
        iVar4 = apmngr_db_entry_get_by_id(uVar6,auStack_5e0);
        if ((iVar4 == 0) &&
           (iVar4 = apdb_get_radio_by_id
                              (local_5a0,auStack_3c8,uVar16,&local_9d0,(int)*(char *)(param_1 + 1)),
           iVar4 == 0)) {
          local_a58 = CONCAT13(uVar18,local_a58._1_3_);
          uVar6 = rdmngr_db_get_pwr_by_level
                            ((int)*(char *)((int)param_1 + 0x15),(int)local_9b0,(int)local_9ae,
                             (int)*(short *)(param_1 + 2),(int)*(char *)(param_1 + 1));
          local_a58 = CONCAT22(local_a58._0_2_,uVar6);
          iVar4 = cw_service_msg_add(iVar2,0x411,&local_a58,0);
          if (iVar4 == 0) {
            if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_80211_tx_pwr() OK.\n",
                     "rdmngr_ele_set_80211_tx_pwr",0x22f);
            }
            local_a64 = 0;
            local_a60 = 0;
            local_a5c = 0;
            local_a68 = CONCAT13(uVar18,0x10000);
            uVar8 = rdmngr_profile_get_max_wlan_per_rd();
            local_a64 = 0;
            local_a68 = CONCAT31(CONCAT21(local_a68._0_2_,uVar8),
                                 *(undefined1 *)((int)param_1 + 0x22));
            local_a60 = (uint)*(ushort *)(param_1 + 7);
            memcpy(&local_a5c,(void *)(DAT_007598ec + 0x17a4),4);
            iVar4 = cw_service_msg_add(iVar2,0x416,&local_a68,0);
            if (iVar4 != 0) {
              if (rdmngr_err_switch == 0) {
                uVar17 = 0xffffffff;
                goto LAB_00614a40;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 != 0) {
                printf("[RDMNGR_ERROR]%s()/%d WTP radio config cw_service_msg_add() failed.\n",
                       "rdmngr_ele_set_80211_radio_cfg",0x248);
              }
              uVar17 = 0xffffffff;
              if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_00614a40;
              pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_80211_radio_cfg failed.\n";
              uVar14 = 0x53e;
              goto LAB_00614bec;
            }
            if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_80211_radio_cfg() OK.\n",
                     "rdmngr_ele_set_80211_radio_cfg",0x24c);
            }
            local_a44 = 0;
            local_a40 = 0;
            local_a3c = 0;
            local_a38 = 0;
            local_a34 = 0;
            local_a30 = 0;
            local_a2c = 0;
            local_a58 = 0;
            local_a54 = (undefined4 *)0x0;
            local_a50 = 0;
            local_a4c = 0;
            local_a48 = 0;
            memset(auStack_8b8,0,0x2d8);
            local_a68 = 0;
            local_a64 = 0;
            local_a60 = 0;
            local_a5c = 0;
            FUN_0051ad88(&local_a50);
            local_a34 = local_a34 & 0xffffff;
            local_a44 = CONCAT31(CONCAT21(CONCAT11(uVar18,*(undefined1 *)((int)param_1 + 5)),
                                          *(undefined1 *)((int)param_1 + 6)),
                                 *(undefined1 *)(param_1 + 9));
            local_a40 = CONCAT31(*(undefined3 *)((int)param_1 + 0x16),
                                 *(undefined1 *)((int)param_1 + 0x26));
            local_a3c = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)param_1 + 0x23),
                                                   *(undefined1 *)((int)param_1 + 0x3d)),
                                          *(undefined1 *)((int)param_1 + 0x3e)),
                                 *(undefined1 *)((int)param_1 + 0x3f));
            local_a38 = CONCAT13(*(undefined1 *)(param_1 + 0x10),local_a38._1_3_);
            local_a38 = CONCAT22(local_a38._0_2_,*(undefined2 *)((int)param_1 + 0x42));
            uVar6 = rdmngr_db_generate_ap_id(*param_1);
            iVar4 = apmngr_db_capacity_support(uVar6,1,1);
            if (iVar4 == 0) {
              if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d not support rssi set.\n",
                       "rdmngr_ele_set_pirv_adv_radio_cfg",0x289);
              }
              uVar8 = 1;
              local_a34 = CONCAT13(local_a34._0_1_,0xff0000);
              local_a34 = CONCAT22(local_a34._0_2_,0x100);
              local_a34 = CONCAT31(local_a34._0_3_,0xff);
            }
            else {
              if (rdmngr_debug_switch == 0) {
                uVar8 = *(undefined1 *)((int)param_1 + 0x27);
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  uVar8 = *(undefined1 *)((int)param_1 + 0x27);
                }
                else {
                  printf("[RDMNGR_DEBUG]%s()/%d support rssi set.\n",
                         "rdmngr_ele_set_pirv_adv_radio_cfg",0x281);
                  uVar8 = *(undefined1 *)((int)param_1 + 0x27);
                }
              }
              local_a34 = CONCAT31(CONCAT21(CONCAT11(local_a34._0_1_,uVar8),
                                            *(undefined1 *)(param_1 + 10)),
                                   *(undefined1 *)((int)param_1 + 0x29));
              uVar8 = *(undefined1 *)((int)param_1 + 0x2a);
            }
            local_a30 = CONCAT13(uVar8,local_a30._1_3_);
            uVar6 = rdmngr_db_generate_ap_id(*param_1);
            iVar4 = apmngr_db_capacity_support(uVar6,1,10);
            uVar8 = 0xff;
            if (iVar4 != 0) {
              uVar8 = (undefined1)*(undefined2 *)((int)param_1 + 0x1e);
            }
            local_a30._1_3_ = CONCAT12(uVar8,local_a30._2_2_);
            uVar6 = rdmngr_db_generate_ap_id(*param_1);
            iVar4 = apmngr_db_entry_get_by_id(uVar6,auStack_8b8);
            if ((iVar4 == 0) &&
               (iVar4 = apdb_get_radio_extend_capability
                                  (local_878,auStack_6a0,1,0xffffffff,&local_a68,0x10), iVar4 == 0))
            {
              uVar6 = rdmngr_db_generate_ap_id(*param_1);
              iVar4 = apmngr_db_capacity_support(uVar6,1,0x46);
              uVar3 = local_a30;
              if (iVar4 == 0) goto LAB_00615308;
              local_a30 = local_a30 & 0xffff0000;
              local_a2c = 0;
              if ((local_a5c & 0x100) != 0) {
                local_a30._0_2_ = SUB42(uVar3,2);
                local_a30 = (uint)CONCAT21(local_a30._0_2_,*(char *)((int)param_1 + 0x2e) == '\x01')
                            << 8;
              }
              if ((local_a5c & 0x200) != 0) {
                bVar10 = 2;
                if (*(char *)((int)param_1 + 0x2f) != '\x01') {
                  bVar10 = 0;
                }
                local_a30 = (uint)CONCAT21(local_a30._0_2_,bVar10 | local_a30._2_1_) << 8;
              }
              if ((local_a5c & 0x400) != 0) {
                bVar10 = 4;
                if (*(char *)(param_1 + 0xc) != '\x01') {
                  bVar10 = 0;
                }
                local_a30 = (uint)CONCAT21(local_a30._0_2_,bVar10 | local_a30._2_1_) << 8;
              }
              if ((local_a5c & 0x800) != 0) {
                bVar10 = 8;
                if (*(char *)((int)param_1 + 0x31) != '\x01') {
                  bVar10 = 0;
                }
                local_a30 = (uint)CONCAT21(local_a30._0_2_,bVar10 | local_a30._2_1_) << 8;
              }
              if ((local_a5c & 0x1000) != 0) {
                bVar10 = 0x10;
                if (*(char *)((int)param_1 + 0x32) != '\x01') {
                  bVar10 = 0;
                }
                bVar13 = 0;
                if (0 < *(char *)((int)param_1 + 0x33)) {
                  bVar13 = (byte)((int)*(char *)((int)param_1 + 0x33) << 5);
                }
                local_a30 = (uint)CONCAT21(local_a30._0_2_,bVar10 | local_a30._2_1_ | bVar13) << 8;
              }
              if ((local_a5c & 0x2000) != 0) {
                bVar10 = 0x80;
                if (*(char *)(param_1 + 0xd) != '\x01') {
                  bVar10 = 0;
                }
                local_a30 = CONCAT31(CONCAT21(local_a30._0_2_,bVar10 | local_a30._2_1_),
                                     *(char *)((int)param_1 + 0x35) == '\x01');
              }
              if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d i:%d,val.wifi6_feature_bitmap:\n",
                       "rdmngr_ele_set_pirv_adv_radio_cfg",0x2c6,9);
              }
              iVar4 = 0;
              do {
                if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
                  printf("[RDMNGR_DEBUG]%s()/%d %d \n","rdmngr_ele_set_pirv_adv_radio_cfg",0x2c7,
                         (uint)*(byte *)((int)&local_a30 + iVar4 + 2));
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 != 6);
            }
            else {
LAB_00615308:
              local_a30 = CONCAT22(local_a30._0_2_,0xffff);
              local_a2c = 0xffffffff;
            }
            iVar4 = cw_service_msg_add(iVar2,0x25,&local_a58,1,8,&local_a44);
            if (iVar4 == 0) {
              if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_pirv_adv_radio_cfg() OK.\n",
                       "rdmngr_ele_set_pirv_adv_radio_cfg",0x2d7);
              }
              local_30 = (uint)g_multi_rate;
              uVar3 = (uint)g_multi_rate_5g;
              memset(auStack_a28,0,0x24);
              local_a58 = 0;
              local_a54 = (undefined4 *)0x0;
              local_a50 = 0;
              local_a4c = 0;
              local_a48 = 0;
              memset(auStack_a04,0,0x34);
              local_a6c = 0;
              local_a70 = 0;
              memset(&local_9d0,0,0x37);
              local_a44 = 0;
              local_a40 = 0;
              local_a3c = 0;
              local_a38 = 0;
              local_a34 = 0;
              local_a68 = 0;
              local_a64 = 0;
              local_a60 = 0;
              FUN_0051ad88(&local_a3c);
              local_9d0 = uVar18;
              memset(auStack_a28,0,0x24);
              local_a70 = 0;
              iVar4 = rate_db_11a_mandatory_rate_get(auStack_a28,9,&local_a70);
              if (iVar4 == -1) {
                if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                  pcVar12 = 
                  "[RDMNGR_ERROR]%s()/%d rate_db_11a_mandatory_rate_get() failed, rate_count:%d\n";
                  uVar17 = 0x30a;
LAB_00615530:
                  printf(pcVar12,"rdmngr_ele_set_priv_ap_rate",uVar17,local_a70);
                }
              }
              else {
                _rdmngr_db_priv_ap_rate_set(local_9cf,auStack_a28,local_a70);
                iVar4 = local_a70;
                memset(auStack_a28,0,0x24);
                local_a70 = 0;
                iVar5 = rate_db_11a_supported_rate_get(auStack_a28,9,&local_a70);
                if (iVar5 == -1) {
                  if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                    pcVar12 = 
                    "[RDMNGR_ERROR]%s()/%d rate_db_11a_supported_rate_get() failed, rate_count:%d\n"
                    ;
                    uVar17 = 0x315;
                    goto LAB_00615530;
                  }
                }
                else {
                  _rdmngr_db_priv_ap_rate_set(local_9c7,auStack_a28,local_a70);
                  local_a6c = 0;
                  iVar5 = rate_db_11a_multicast_rate_get(&local_a6c);
                  if (iVar5 == -1) {
                    if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                      pcVar12 = "[RDMNGR_ERROR]%s()/%d rate_db_11a_multicast_rate_get() failed.\n";
                      uVar17 = 0x31d;
                      goto LAB_00615a8c;
                    }
                  }
                  else {
                    uVar21 = local_b4 & 0x800;
                    if (uVar21 == 0) {
                      if (local_a6c == -1) {
                        local_9bf = 0;
                      }
                      else {
                        local_9bf = (byte)local_a6c;
                      }
                    }
                    else {
                      uVar20 = (uVar3 & 0x7f) << 1;
                      local_9bf = (byte)uVar20;
                      for (uVar3 = 0; (int)uVar3 < iVar4; uVar3 = uVar3 + 1 & 0xff) {
                        if (local_9cf[uVar3] == uVar20) goto LAB_006155b0;
                      }
                      uVar3 = 0;
                      local_9cf[iVar4] = (byte)uVar20;
                      do {
                        uVar19 = uVar3 & 0xff;
                        if (local_9c7[uVar3] == uVar20) {
                          if (uVar19 == 7) {
                            local_9c7[uVar3] = 0;
                          }
                          else {
                            local_a68 = 0;
                            local_a64 = 0;
                            local_a60 = 0;
                            memcpy(&local_a68,local_9c7 + uVar19 + 1,7 - uVar3);
                            memcpy(local_9c7 + uVar19,&local_a68,8 - uVar3);
                          }
                          break;
                        }
                        uVar3 = uVar3 + 1;
                      } while (uVar3 != 8);
                    }
LAB_006155b0:
                    local_a58 = 0;
                    local_a54 = (undefined4 *)0x0;
                    local_a50 = 0;
                    local_a4c = 0;
                    local_a48 = 0;
                    local_a70 = 0;
                    iVar4 = rate_db_11b_mandatory_rate_get(&local_a58,5,&local_a70);
                    if (iVar4 == -1) {
                      if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                        pcVar12 = 
                        "[RDMNGR_ERROR]%s()/%d rate_db_11a_mandatory_rate_get() failed, rate_count:%d\n"
                        ;
                        uVar17 = 0x354;
                        goto LAB_00615530;
                      }
                    }
                    else {
                      _rdmngr_db_priv_ap_rate_set(local_9be,&local_a58,local_a70);
                      iVar4 = local_a70;
                      local_a58 = 0;
                      local_a54 = (undefined4 *)0x0;
                      local_a50 = 0;
                      local_a4c = 0;
                      local_a48 = 0;
                      local_a70 = 0;
                      iVar5 = rate_db_11b_supported_rate_get(&local_a58,5,&local_a70);
                      if (iVar5 == -1) {
                        if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0))
                        {
                          pcVar12 = 
                          "[RDMNGR_ERROR]%s()/%d rate_db_11b_supported_rate_get() failed, rate_count:%d\n"
                          ;
                          uVar17 = 0x35e;
                          goto LAB_00615530;
                        }
                      }
                      else {
                        _rdmngr_db_priv_ap_rate_set(local_9ba,&local_a58,local_a70);
                        local_a6c = 0;
                        iVar5 = rate_db_11b_multicast_rate_get(&local_a6c);
                        if (iVar5 == -1) {
                          if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)
                             ) {
                            pcVar12 = 
                            "[RDMNGR_ERROR]%s()/%d rate_db_11b_multicast_rate_get() failed.\n";
                            uVar17 = 0x366;
                            goto LAB_00615a8c;
                          }
                        }
                        else {
                          uVar3 = (local_30 & 0x7f) << 1;
                          bVar10 = (byte)uVar3;
                          if (uVar21 == 0) {
                            if (local_a6c == -1) {
                              local_9ba[4] = 0;
                            }
                            else {
                              local_9ba[4] = (byte)local_a6c;
                            }
                          }
                          else {
                            local_9ba[4] = bVar10;
                            for (uVar20 = 0; (int)uVar20 < iVar4; uVar20 = uVar20 + 1 & 0xff) {
                              if (local_9be[uVar20] == uVar3) goto LAB_006159c4;
                            }
                            uVar20 = 0;
                            local_9be[iVar4] = bVar10;
                            do {
                              uVar19 = uVar20 & 0xff;
                              if (local_9ba[uVar20] == uVar3) {
                                if (uVar19 == 3) {
                                  local_9ba[uVar20] = 0;
                                }
                                else {
                                  local_a68 = 0;
                                  local_a64 = 0;
                                  local_a60 = 0;
                                  memcpy(&local_a68,local_9ba + uVar19 + 1,3 - uVar20);
                                  memcpy(local_9ba + uVar19,&local_a68,4 - uVar20);
                                }
                                break;
                              }
                              uVar20 = uVar20 + 1;
                            } while (uVar20 != 4);
                          }
LAB_006159c4:
                          memset(auStack_a04,0,0x34);
                          local_a70 = 0;
                          iVar4 = rate_db_11g_mandatory_rate_get(auStack_a04,0xd,&local_a70);
                          if (iVar4 == -1) {
                            if ((rdmngr_err_switch != 0) &&
                               (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                              pcVar12 = 
                              "[RDMNGR_ERROR]%s()/%d rate_db_11a_mandatory_rate_get() failed, rate_count:%d\n"
                              ;
                              uVar17 = 0x39d;
                              goto LAB_00615530;
                            }
                          }
                          else {
                            _rdmngr_db_priv_ap_rate_set(local_9ba + 5,auStack_a04,local_a70);
                            iVar4 = local_a70;
                            memset(auStack_a04,0,0x34);
                            local_a70 = 0;
                            iVar5 = rate_db_11g_supported_rate_get(auStack_a04,0xd,&local_a70);
                            if (iVar5 == -1) {
                              if ((rdmngr_err_switch != 0) &&
                                 (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                pcVar12 = 
                                "[RDMNGR_ERROR]%s()/%d rate_db_11a_mandatory_rate_get() failed, rate_count:%d\n"
                                ;
                                uVar17 = 0x3a7;
                                goto LAB_00615530;
                              }
                            }
                            else {
                              _rdmngr_db_priv_ap_rate_set(local_9a9,auStack_a04,local_a70);
                              local_a6c = 0;
                              iVar5 = rate_db_11g_multicast_rate_get(&local_a6c);
                              if (iVar5 == -1) {
                                if ((rdmngr_err_switch != 0) &&
                                   (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                  pcVar12 = 
                                  "[RDMNGR_ERROR]%s()/%d rate_db_11g_multicast_rate_get() failed.\n"
                                  ;
                                  uVar17 = 0x3af;
LAB_00615a8c:
                                  printf(pcVar12,"rdmngr_ele_set_priv_ap_rate",uVar17);
                                }
                              }
                              else {
                                uVar20 = 0;
                                if (uVar21 == 0) {
                                  if (local_a6c == -1) {
                                    local_99d = 0;
                                  }
                                  else {
                                    local_99d = (byte)local_a6c;
                                  }
                                }
                                else {
                                  local_99d = bVar10;
                                  for (; (int)uVar20 < iVar4; uVar20 = uVar20 + 1 & 0xff) {
                                    if (local_9ba[uVar20 + 5] == uVar3) goto LAB_00615be0;
                                  }
                                  local_9ba[iVar4 + 5] = bVar10;
                                  uVar21 = 0;
                                  do {
                                    uVar20 = uVar21 & 0xff;
                                    if (local_9a9[uVar21] == uVar3) {
                                      if (uVar20 == 0xb) {
                                        local_9a9[uVar21] = 0;
                                      }
                                      else {
                                        local_a68 = 0;
                                        local_a64 = 0;
                                        local_a60 = 0;
                                        memcpy(&local_a68,local_9a9 + uVar20 + 1,0xb - uVar21);
                                        memcpy(local_9a9 + uVar20,&local_a68,0xc - uVar21);
                                      }
                                      break;
                                    }
                                    uVar21 = uVar21 + 1;
                                  } while (uVar21 != 0xc);
                                }
LAB_00615be0:
                                local_a6c = 0;
                                iVar5 = rate_db_11n_mandatory_mcs_get(&local_a6c);
                                iVar4 = local_a6c;
                                if (iVar5 == -1) {
                                  if ((rdmngr_err_switch != 0) &&
                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                    pcVar12 = 
                                    "[RDMNGR_ERROR]%s()/%d rate_db_11n_mandatory_mcs_get() failed.\n"
                                    ;
                                    uVar17 = 0x3e5;
                                    goto LAB_00615a8c;
                                  }
                                }
                                else {
                                  local_a6c = 0;
                                  local_99c = (undefined1)iVar4;
                                  iVar5 = rate_db_11n_supported_mcs_get(&local_a6c);
                                  iVar4 = local_a6c;
                                  if (iVar5 == -1) {
                                    if ((rdmngr_err_switch != 0) &&
                                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                      pcVar12 = 
                                      "[RDMNGR_ERROR]%s()/%d rate_db_11n_supported_mcs_get() failed.\n"
                                      ;
                                      uVar17 = 0x3f4;
                                      goto LAB_00615a8c;
                                    }
                                  }
                                  else {
                                    local_a6c = 0;
                                    local_99b = (undefined1)iVar4;
                                    iVar4 = rate_db_11n_multicast_mcs_get(&local_a6c);
                                    if (iVar4 == -1) {
                                      if ((rdmngr_err_switch != 0) &&
                                         (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                        pcVar12 = 
                                        "[RDMNGR_ERROR]%s()/%d rate_db_11n_multicast_mcs_get() failed.\n"
                                        ;
                                        uVar17 = 0x3fc;
                                        goto LAB_00615a8c;
                                      }
                                    }
                                    else {
                                      local_99a = (undefined1)local_a6c;
                                      iVar4 = cw_service_msg_add(iVar2,0x25,&local_a44,1,10,
                                                                 &local_9d0);
                                      if (iVar4 == 0) {
                                        if (rdmngr_debug_switch == 0) {
                                          cVar11 = *(char *)(param_1 + 1);
                                        }
                                        else {
                                          iVar4 = is_target_debug_ap();
                                          if (iVar4 == 0) {
                                            cVar11 = *(char *)(param_1 + 1);
                                          }
                                          else {
                                            printf(
                                                  "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_priv_ap_rate() OK.\n"
                                                  ,"rdmngr_ele_set_priv_ap_rate",0x411);
                                            cVar11 = *(char *)(param_1 + 1);
                                          }
                                        }
                                        if (cVar11 == '\x01') {
                                          uVar6 = rdmngr_db_generate_ap_id(*param_1);
                                          iVar4 = apmngr_db_entry_get_by_id(uVar6,auStack_308);
                                          if (iVar4 == 0) {
                                            iVar4 = apdb_support_11ac_by_id
                                                              (local_2c8,auStack_f0,uVar16,
                                                               (int)*(char *)(param_1 + 1));
                                            if (iVar4 != 0) {
                                              local_a58 = 0;
                                              local_a44 = 0;
                                              local_a40 = 0;
                                              local_a3c = 0;
                                              local_a38 = 0;
                                              local_a34 = 0;
                                              local_a70 = 0;
                                              FUN_0051ad88(&local_a3c);
                                              local_a58 = CONCAT13(uVar18,local_a58._1_3_);
                                              iVar4 = rate_db_11ac_mandatory_nss_get(&local_a70);
                                              if (iVar4 == 0) {
                                                if (local_a70 == -1) {
                                                  local_a58._1_3_ = (uint3)local_a58._2_2_;
                                                }
                                                else {
                                                  local_a58._1_3_ =
                                                       CONCAT12((char)local_a70,local_a58._2_2_);
                                                }
                                                local_a70 = 0;
                                                iVar5 = rate_db_11ac_supported_nss_get(&local_a70);
                                                iVar4 = local_a70;
                                                if (iVar5 == 0) {
                                                  local_a70 = 0;
                                                  local_a58._2_2_ =
                                                       CONCAT11((char)iVar4,(undefined1)local_a58);
                                                  iVar4 = rate_db_11ac_multicast_nss_get(&local_a70)
                                                  ;
                                                  if (iVar4 == 0) {
                                                    local_a58 = CONCAT31(local_a58._0_3_,
                                                                         (char)local_a70);
                                                    iVar4 = cw_service_msg_add(iVar2,0x25,&local_a44
                                                                               ,1,0x2b,&local_a58);
                                                    if (iVar4 == 0) {
                                                      if ((rdmngr_debug_switch != 0) &&
                                                         (iVar4 = is_target_debug_ap(), iVar4 != 0))
                                                      {
                                                        printf(
                                                  "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_priv_ap_11ac_rate() OK.\n"
                                                  ,"rdmngr_ele_set_priv_ap_11ac_rate",0x45b);
                                                  }
                                                  goto LAB_00615d8c;
                                                  }
                                                  if ((rdmngr_err_switch != 0) &&
                                                     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                    pcVar12 = 
                                                  "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                                                  ;
                                                  uVar17 = 0x457;
                                                  goto LAB_006161b4;
                                                  }
                                                  }
                                                  else if ((rdmngr_err_switch != 0) &&
                                                          (iVar4 = is_target_debug_ap(), iVar4 != 0)
                                                          ) {
                                                    pcVar12 = 
                                                  "[RDMNGR_ERROR]%s()/%d rate_db_11ac_multicast_nss_get() failed.\n"
                                                  ;
                                                  uVar17 = 0x446;
                                                  goto LAB_006161b4;
                                                  }
                                                }
                                                else if ((rdmngr_err_switch != 0) &&
                                                        (iVar4 = is_target_debug_ap(), iVar4 != 0))
                                                {
                                                  pcVar12 = 
                                                  "[RDMNGR_ERROR]%s()/%d rate_db_11ac_supported_nss_get() failed.\n"
                                                  ;
                                                  uVar17 = 0x43e;
                                                  goto LAB_006161b4;
                                                }
                                              }
                                              else if ((rdmngr_err_switch != 0) &&
                                                      (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                pcVar12 = 
                                                "[RDMNGR_ERROR]%s()/%d rate_db_11ac_mandatory_nss_get() failed.\n"
                                                ;
                                                uVar17 = 0x42f;
LAB_006161b4:
                                                printf(pcVar12,"rdmngr_ele_set_priv_ap_11ac_rate",
                                                       uVar17);
                                              }
                                              uVar17 = 0xffffffff;
                                              if ((rdmngr_err_switch == 0) ||
                                                 (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                              goto LAB_00614a40;
                                              pcVar12 = 
                                              "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_priv_ap_11ac_rate() failed.\n"
                                              ;
                                              uVar14 = 0x556;
                                              goto LAB_00614bec;
                                            }
                                          }
                                        }
LAB_00615d8c:
                                        uVar6 = rdmngr_db_generate_ap_id(*param_1);
                                        iVar4 = apmngr_db_capacity_support(uVar6,1,0x46);
                                        if (iVar4 == 0) {
LAB_00615ec4:
                                          uVar6 = rdmngr_db_generate_ap_id(*param_1);
                                          iVar4 = apmngr_db_capacity_support(uVar6,1,0x15);
                                          if (iVar4 != 0) {
                                            local_a58 = 0;
                                            local_a54 = (undefined4 *)0x0;
                                            local_a44 = 0;
                                            local_a40 = 0;
                                            local_a3c = 0;
                                            local_a38 = 0;
                                            local_a34 = 0;
                                            FUN_0051ad88(&local_a3c);
                                            local_a58 = (uint)*(char *)((int)param_1 + 0x2b);
                                            local_a54._0_2_ = (undefined2)uVar16;
                                            local_a54 = (undefined4 *)
                                                        CONCAT31(CONCAT21(local_a54._0_2_,
                                                                          *(undefined1 *)
                                                                           (param_1 + 0xb)),
                                                                 *(undefined1 *)
                                                                  ((int)param_1 + 0x2d));
                                            iVar4 = cw_service_msg_add(iVar2,0x25,&local_a44,1,0x4c,
                                                                       &local_a58);
                                            if (iVar4 != 0) {
                                              if (rdmngr_err_switch == 0) {
                                                uVar17 = 0xffffffff;
                                                goto LAB_00614a40;
                                              }
                                              iVar4 = is_target_debug_ap();
                                              if (iVar4 != 0) {
                                                printf(
                                                  "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                                                  ,"rdmngr_ele_set_priv_wlan_rssi_orient",0x4c3);
                                              }
                                              uVar17 = 0xffffffff;
                                              if ((rdmngr_err_switch == 0) ||
                                                 (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                              goto LAB_00614a40;
                                              pcVar12 = 
                                              "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_priv_wlan_rssi_orient() failed.\n"
                                              ;
                                              uVar14 = 0x569;
                                              goto LAB_00614bec;
                                            }
                                            if ((rdmngr_debug_switch != 0) &&
                                               (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                              printf(
                                                  "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_priv_wlan_rssi_orient() OK.\n"
                                                  ,"rdmngr_ele_set_priv_wlan_rssi_orient",0x4c7);
                                            }
                                          }
                                          uVar6 = rdmngr_db_generate_ap_id(*param_1);
                                          iVar4 = apmngr_db_capacity_support(uVar6,1,0x39);
                                          if (iVar4 != 0) {
                                            local_a58 = 0;
                                            local_a54 = (undefined4 *)0x0;
                                            local_a68 = 0;
                                            local_a64 = 0;
                                            local_a60 = 0;
                                            local_a44 = 0;
                                            local_a40 = 0;
                                            local_a3c = 0;
                                            local_a38 = 0;
                                            local_a34 = 0;
                                            FUN_0051ad88(&local_a3c);
                                            local_a58 = CONCAT13(uVar18,local_a58._1_3_) &
                                                        0xff00ffff;
                                            uVar16 = 3;
                                            if (frame_rate_num < 4) {
                                              uVar16 = frame_rate_num;
                                            }
                                            psVar9 = (short *)((int)&local_a68 + 2);
                                            local_a58._2_2_ =
                                                 CONCAT11((char)uVar16,(undefined1)local_a58);
                                            for (uVar16 = 0; uVar16 != frame_rate_num;
                                                uVar16 = uVar16 + 1) {
                                              *psVar9 = (short)*(char *)((int)param_1 + 0x25);
                                              psVar9 = psVar9 + 2;
                                            }
                                            local_a54 = &local_a68;
                                            iVar4 = cw_service_msg_add(iVar2,0x25,&local_a44,1,0x8e,
                                                                       &local_a58);
                                            if (iVar4 != 0) {
                                              if (rdmngr_err_switch == 0) {
                                                uVar17 = 0xffffffff;
                                                goto LAB_00614a40;
                                              }
                                              iVar4 = is_target_debug_ap();
                                              if (iVar4 != 0) {
                                                printf(
                                                  "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                                                  ,"rdmngr_ele_set_priv_frame_rate_ctrl",0x4ed);
                                              }
                                              uVar17 = 0xffffffff;
                                              if ((rdmngr_err_switch == 0) ||
                                                 (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                              goto LAB_00614a40;
                                              pcVar12 = 
                                              "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_priv_frame_rate_ctrl() failed.\n"
                                              ;
                                              uVar14 = 0x572;
                                              goto LAB_00614bec;
                                            }
                                            if ((rdmngr_debug_switch != 0) &&
                                               (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                              printf(
                                                  "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_priv_frame_rate_ctrl() OK.\n"
                                                  ,"rdmngr_ele_set_priv_frame_rate_ctrl",0x4f1);
                                            }
                                          }
LAB_00614c70:
                                          rdmngr_pkt_dump(iVar2);
                                          rdmngr_pkt_dump_one(iVar2,*param_1);
                                          iVar4 = capwap_packet_assemble(param_3,iVar2);
                                          if (iVar4 == 0) {
                                            uVar17 = 0;
                                            if (rdmngr_debug_switch != 0) {
                                              iVar4 = is_target_debug_ap();
                                              uVar17 = 0;
                                              if (iVar4 != 0) {
                                                if (param_3 == 0) {
                                                  puVar15 = &DAT_006a2b04;
                                                }
                                                else {
                                                  puVar15 = &DAT_00691368;
                                                }
                                                uVar17 = 0;
                                                printf(
                                                  "[RDMNGR_DEBUG]%s()/%d pkt_buf is null : %s\n",
                                                  "rdmngr_packet_create",0x590,puVar15);
                                              }
                                            }
                                            goto LAB_00614a40;
                                          }
                                          uVar17 = 0xffffffff;
                                          if ((rdmngr_err_switch == 0) ||
                                             (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                          goto LAB_00614a40;
                                          pcVar12 = 
                                          "[RDMNGR_ERROR]%s()/%d rdmngr capwap_packet_assemble() failed.\n"
                                          ;
                                          uVar14 = 0x58a;
                                          goto LAB_00614bec;
                                        }
                                        local_a58 = 0;
                                        local_a70 = 0;
                                        local_a44 = 0;
                                        local_a40 = 0;
                                        local_a3c = 0;
                                        local_a38 = 0;
                                        local_a34 = 0;
                                        FUN_0051ad88(&local_a3c);
                                        local_a58 = CONCAT13(uVar18,local_a58._1_3_);
                                        iVar4 = rate_db_11ax_mandatory_nss_get(&local_a70);
                                        if (iVar4 == 0) {
                                          if (local_a70 == -1) {
                                            local_a58._1_3_ = (uint3)local_a58._2_2_;
                                          }
                                          else {
                                            local_a58._1_3_ =
                                                 CONCAT12((char)local_a70,local_a58._2_2_);
                                          }
                                          local_a70 = 0;
                                          iVar5 = rate_db_11ax_supported_nss_get(&local_a70);
                                          iVar4 = local_a70;
                                          if (iVar5 == 0) {
                                            local_a70 = 0;
                                            local_a58._2_2_ =
                                                 CONCAT11((char)iVar4,(undefined1)local_a58);
                                            iVar4 = rate_db_11ax_multicast_nss_get(&local_a70);
                                            if (iVar4 == 0) {
                                              local_a58 = CONCAT31(local_a58._0_3_,(char)local_a70);
                                              iVar4 = cw_service_msg_add(iVar2,0x25,&local_a44,1,
                                                                         0xa0,&local_a58);
                                              if (iVar4 == 0) {
                                                if ((rdmngr_debug_switch != 0) &&
                                                   (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                  printf(
                                                  "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_priv_ap_11ax_rate() OK.\n"
                                                  ,"rdmngr_ele_set_priv_ap_11ax_rate",0x4a4);
                                                }
                                                goto LAB_00615ec4;
                                              }
                                              if ((rdmngr_err_switch != 0) &&
                                                 (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                                pcVar12 = 
                                                "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                                                ;
                                                uVar17 = 0x4a0;
                                                goto LAB_00615e88;
                                              }
                                            }
                                            else if ((rdmngr_err_switch != 0) &&
                                                    (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                              pcVar12 = 
                                              "[RDMNGR_ERROR]%s()/%d rate_db_11ac_multicast_nss_get() failed.\n"
                                              ;
                                              uVar17 = 0x48f;
                                              goto LAB_00615e88;
                                            }
                                          }
                                          else if ((rdmngr_err_switch != 0) &&
                                                  (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                            pcVar12 = 
                                            "[RDMNGR_ERROR]%s()/%d rate_db_11ac_supported_nss_get() failed.\n"
                                            ;
                                            uVar17 = 0x487;
                                            goto LAB_00615e88;
                                          }
                                        }
                                        else if ((rdmngr_err_switch != 0) &&
                                                (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                          pcVar12 = 
                                          "[RDMNGR_ERROR]%s()/%d rate_db_11ac_mandatory_nss_get() failed.\n"
                                          ;
                                          uVar17 = 0x478;
LAB_00615e88:
                                          printf(pcVar12,"rdmngr_ele_set_priv_ap_11ax_rate",uVar17);
                                        }
                                        uVar17 = 0xffffffff;
                                        if ((rdmngr_err_switch == 0) ||
                                           (iVar4 = is_target_debug_ap(), iVar4 == 0))
                                        goto LAB_00614a40;
                                        pcVar12 = 
                                        "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_priv_ap_11ax_rate() failed.\n"
                                        ;
                                        uVar14 = 0x55f;
                                        goto LAB_00614bec;
                                      }
                                      if ((rdmngr_err_switch != 0) &&
                                         (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                                        pcVar12 = 
                                        "[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                                        ;
                                        uVar17 = 0x40d;
                                        goto LAB_00615a8c;
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
              uVar17 = 0xffffffff;
              if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_00614a40;
              pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_priv_ap_rate() failed.\n";
              uVar14 = 0x54d;
            }
            else {
              if (rdmngr_err_switch == 0) {
                uVar17 = 0xffffffff;
                goto LAB_00614a40;
              }
              iVar4 = is_target_debug_ap();
              if (iVar4 != 0) {
                printf("[RDMNGR_ERROR]%s()/%d vendor specific payload cw_service_msg_add() failed.\n"
                       ,"rdmngr_ele_set_pirv_adv_radio_cfg",0x2d3);
              }
              uVar17 = 0xffffffff;
              if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_00614a40;
              pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_adv_radio_cfg() faield.\n";
              uVar14 = 0x546;
            }
            goto LAB_00614bec;
          }
          if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d Tx Power cw_service_msg_add() failed.\n",
                   "rdmngr_ele_set_80211_tx_pwr",0x22a);
          }
        }
        else if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id or apdb_get_radio_by_id failed:%d.\n"
                 ,"rdmngr_ele_set_80211_tx_pwr",0x220,*param_1);
        }
        uVar17 = 0xffffffff;
        if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00614a40;
        pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_80211_tx_pwr() failed.\n";
        uVar14 = 0x536;
      }
      else {
        if (rdmngr_err_switch == 0) {
          uVar17 = 0xffffffff;
          goto LAB_00614a40;
        }
        iVar4 = is_target_debug_ap();
        if (iVar4 != 0) {
          printf("[RDMNGR_ERROR]%s()/%d MAC Operation cw_service_msg_add() failed.\n",
                 "rdmngr_ele_set_80211_mac_op",0x20a);
        }
        uVar17 = 0xffffffff;
        if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_00614a40;
        pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_80211_mac_op() failed.\n";
        uVar14 = 0x52f;
      }
    }
    else {
      if (rdmngr_err_switch == 0) {
        uVar17 = 0xffffffff;
        goto LAB_00614a40;
      }
      iVar4 = is_target_debug_ap();
      if (iVar4 != 0) {
        printf("[RDMNGR_ERROR]%s()/%d Direct Sequence Control cw_msg_ele_add() failed.\n",
               "rdmngr_ele_set_80211_drt_seq_ctrl",0x1ec);
      }
      uVar17 = 0xffffffff;
      if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00614a40;
      pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_80211_drt_seq_ctrl() failed.\n";
      uVar14 = 0x527;
    }
  }
  else {
    uVar17 = 0xffffffff;
    if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_00614a40;
    pcVar12 = "[RDMNGR_ERROR]%s()/%d rdmngr_ele_set_adm_state() failed.\n";
    uVar14 = 0x520;
  }
LAB_00614bec:
  uVar17 = 0xffffffff;
  printf(pcVar12,"rdmngr_packet_create",uVar14);
LAB_00614a40:
  cw_parsed_pkt_destroy(iVar2);
  return uVar17;
}

