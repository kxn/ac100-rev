// func FUN_006270b4 @ 006270b4 size=1944

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_006270b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *******pppppppbVar1;
  byte *******pppppppbVar2;
  undefined2 uVar8;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte bVar9;
  char *__format;
  char *pcVar10;
  byte *pbVar11;
  byte *******pppppppbVar12;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  uint local_c60 [17];
  byte *local_c1c;
  byte *******local_c18;
  byte *******local_c14;
  byte *local_c10;
  byte *local_c0c;
  undefined4 *local_c08;
  byte local_bf8 [4];
  undefined4 local_bf4;
  int local_bf0;
  byte ******local_bec;
  byte *******local_be8;
  undefined4 local_be4;
  undefined4 local_be0;
  undefined4 local_bdc;
  undefined4 local_bd8;
  byte local_bd4 [68];
  undefined2 local_b90 [52];
  undefined1 auStack_b28 [672];
  byte ******appppppbStack_888 [168];
  undefined1 auStack_5e8 [728];
  byte abStack_310 [728];
  byte *******local_38;
  int local_34;
  byte *******local_30;
  int local_2c;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_linked_modify ENTER\n","_uac_rdmngr_linked_modify",
           0x57a);
  }
  memset(abStack_310,0,0x2d8);
  local_bf8[0] = 0;
  local_be8 = (byte *******)0x0;
  uVar8 = rdmngr_db_generate_ap_id(param_1);
  iVar3 = apmngr_db_entry_get_by_id(uVar8,abStack_310);
  if (iVar3 == -1) {
    if (rdmngr_warning_switch == 0) {
      return 0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0;
    }
    pcVar10 = "[RDMNGR_WARNING]%s()/%d apmngr_db_entry_get_by_id failed.\n";
    uVar5 = 0x588;
  }
  else {
    local_c18 = appppppbStack_888;
    local_c14 = (byte *******)&local_be8;
    local_c1c = abStack_310;
    for (uVar4 = 0; uVar4 < 0x44; uVar4 = uVar4 + 1) {
      *(undefined1 *)((int)local_c60 + uVar4) = (&stack0x00000010)[uVar4];
    }
    local_res0 = param_1;
    iVar3 = rdmngr_db_get_same_freq_type_peer_radio(param_1,local_res4,local_res8,local_resc);
    if (iVar3 == -1) {
      if (rdmngr_warning_switch == 0) {
        return 0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      pcVar10 = "[RDMNGR_WARNING]%s()/%d rdmngr_db_get_same_freq_type_peer_radio failed \n";
      uVar5 = 0x58f;
    }
    else {
      local_c18 = appppppbStack_888;
      local_c1c = (byte *)0x0;
      local_c14 = local_be8;
      local_c10 = abStack_310;
      local_c0c = local_bf8;
      for (uVar4 = 0; uVar4 < 0x44; uVar4 = uVar4 + 1) {
        *(undefined1 *)((int)local_c60 + uVar4) = (&stack0x00000010)[uVar4];
      }
      local_38 = (byte *******)
                 rdmngr_db_get_radio_cfg_linked_strategy
                           (local_res0,local_res4,local_res8,local_resc);
      pppppppbVar1 = local_be8;
      if (local_38 != (byte *******)0x0) {
        uVar4 = (uint)local_bf8[0];
        memcpy(&local_be4,&local_res0,0x54);
        local_34 = (int)local_resc._0_2_;
        local_bec = (byte ******)appppppbStack_888;
        if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array ENTER\n"
                 ,"_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array",0x543);
        }
        local_bf0 = 0;
        memset(local_b90,0,0x66);
        local_bf4 = 0;
        memset(auStack_b28,0,0x2a0);
        if (((int)pppppppbVar1 < 1) || (uVar4 == 0)) {
          if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            local_c60[0] = uVar4;
            printf("[RDMNGR_DEBUG]%s()/%d peer_rd_entry_cnt=%d, rrar_array_num=%d\n",
                   "_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array",0x553,pppppppbVar1);
          }
LAB_00627264:
          rdmngr_db_free_radio_cfg_linked_strategy(local_38);
          return 0;
        }
        local_b90[0] = (undefined2)local_34;
        memcpy(auStack_b28,&local_bec,(int)pppppppbVar1 * 0x54);
        if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d rrar_array_num=%d\n",
                 "_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array",0x55b,uVar4);
        }
        pppppppbVar12 = (byte *******)0x0;
        do {
          iVar3 = 0;
          local_2c = (int)pppppppbVar12 * 0x54;
          local_30 = local_38;
          while( true ) {
            if ((int)uVar4 <= iVar3) goto LAB_0062748c;
            pbVar11 = (byte *)((int)local_bec + local_2c);
            uVar5 = rdmngr_db_generate_ap_id(*(int *)pbVar11);
            pppppppbVar2 = local_30;
            iVar6 = rdmngr_db_generate_rd_id(uVar5,*(byte *)local_30);
            local_30 = (byte *******)((int)pppppppbVar2 + 0xda);
            if (iVar6 == *(int *)pbVar11) break;
            iVar3 = iVar3 + 1;
          }
          if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            local_c60[0] = (uint)*(byte *)pppppppbVar2;
            printf("[RDMNGR_DEBUG]%s()/%d find link strategy for radio_id=%d, radio_unit_number=%d\n"
                   ,"_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array",0x564,*(int *)pbVar11);
          }
          local_c10 = (byte *)&local_bf0;
          local_bf0 = 0;
          local_c0c = (byte *)local_b90;
          local_bd8 = CONCAT22((short)local_34,local_bd8._2_2_);
          local_c08 = &local_bf4;
          local_c14 = pppppppbVar2;
          local_c1c = pbVar11;
          for (uVar7 = 0; uVar7 < 0x44; uVar7 = uVar7 + 1) {
            *(byte *)((int)local_c60 + uVar7) = local_bd4[uVar7];
          }
          local_c18 = pppppppbVar12;
          iVar3 = rdmngr_db_check_and_do_peer_radio_linked_modify
                            (local_be4,local_be0,local_bdc,local_bd8);
          if (iVar3 == -1) {
            if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              iVar3 = *(int *)pbVar11;
              __format = "[RDMNGR_ERROR]%s()/%d fail to linked modify peer radio,radioId=%d\n";
              pcVar10 = "_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array";
              uVar5 = 0x568;
LAB_00627594:
              printf(__format,pcVar10,uVar5,iVar3);
            }
          }
          else if (local_bf0 == 1) {
            if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d radio(%d) modified.\n",
                     "_uac_rdmngr_do_peer_radios_linked_modify_by_rrar_array",0x56d,*(int *)pbVar11)
              ;
            }
            memset(auStack_5e8,0,0x2d8);
            memset(auStack_5e8,0,0x2d8);
            iVar3 = *(int *)pbVar11;
            iVar6 = rdmngr_db_rd_entry_set(pbVar11);
            if (iVar6 == 0) {
              rdmngr_db_rd_update(iVar3,1);
              rdmngr_callback_proc(2,iVar3,auStack_b28 + (int)pppppppbVar12 * 0x54,pbVar11);
              if (pbVar11[0x48] == 0) {
                bVar9 = pbVar11[0x49];
LAB_006276b8:
                if (bVar9 != 0) {
                  rdmngr_db_rd_entry_channel_reselect_reset(iVar3);
                }
              }
              else {
                iVar6 = rdmngr_db_update_reinit_state(iVar3);
                if (iVar6 == 0) {
                  uVar8 = rdmngr_db_generate_ap_id(iVar3);
                  iVar6 = apmngr_db_entry_get_by_id(uVar8,auStack_5e8);
                  if ((iVar6 == 0) && (iVar6 = apmngr_checksum_update(auStack_5e8,0), iVar6 == 0)) {
                    uVar5 = rdmngr_db_generate_ap_id(iVar3);
                    iVar6 = rdmngr_wtp_pkt_send(uVar5,pbVar11);
                    if (iVar6 == 0) {
                      if ((rdmngr_debug_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0))
                      {
                        printf("[RDMNGR_DEBUG]%s()/%d shutdown radio %d OK.\n",
                               "_uac_rdmngr_linked_set_and_send",0x514,iVar3);
                      }
                      rdmngr_callback_proc(0,iVar3,0,0);
                      uVar5 = rdmngr_db_generate_ap_id(iVar3);
                      iVar6 = rdmngr_wtp_pkt_send(uVar5,pbVar11);
                      if (iVar6 == 0) {
                        if ((rdmngr_debug_switch != 0) &&
                           (iVar6 = is_target_debug_ap(1), iVar6 != 0)) {
                          printf("[RDMNGR_DEBUG]%s()/%d open radio %d OK.\n",
                                 "_uac_rdmngr_linked_set_and_send",0x518,iVar3);
                        }
                        rdmngr_callback_proc(1,iVar3,0,0);
                        bVar9 = pbVar11[0x49];
                      }
                      else {
                        bVar9 = pbVar11[0x49];
                      }
                    }
                    else {
                      bVar9 = pbVar11[0x49];
                    }
                    goto LAB_006276b8;
                  }
                  if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                    pcVar10 = "[RDMNGR_ERROR]%s()/%d update md5 failed.\n";
                    uVar5 = 0x50e;
                    goto LAB_00627708;
                  }
                }
                else if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  uVar5 = 0x507;
                  pcVar10 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_update_reinit_state() failed.\n";
LAB_00627708:
                  printf(pcVar10,"_uac_rdmngr_linked_set_and_send",uVar5);
                }
              }
            }
            else if ((rdmngr_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
              uVar5 = 0x4fe;
              __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_set(%d) failed.\n";
              pcVar10 = "_uac_rdmngr_linked_set_and_send";
              goto LAB_00627594;
            }
          }
LAB_0062748c:
          pppppppbVar12 = (byte *******)((int)pppppppbVar12 + 1);
          if (pppppppbVar12 == pppppppbVar1) goto LAB_00627264;
        } while( true );
      }
      if (rdmngr_warning_switch == 0) {
        return 0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      pcVar10 = "[RDMNGR_WARNING]%s()/%d get radio attribute linked cfg startegy failed\n";
      uVar5 = 0x597;
    }
  }
  printf(pcVar10,"_uac_rdmngr_linked_modify",uVar5);
  return 0;
}

