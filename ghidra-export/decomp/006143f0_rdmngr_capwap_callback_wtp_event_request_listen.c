// func rdmngr_capwap_callback_wtp_event_request_listen @ 006143f0 size=1432

undefined4 rdmngr_capwap_callback_wtp_event_request_listen(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte *pbVar2;
  byte bVar6;
  uint uVar3;
  char cVar7;
  short *psVar4;
  short sVar5;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 local_4b8;
  undefined1 auStack_4b4 [60];
  ushort local_478;
  undefined1 auStack_460 [8];
  char local_458;
  byte local_426;
  ushort local_424;
  undefined1 local_420;
  undefined1 auStack_40c [32];
  short local_3ec;
  undefined1 auStack_2f8 [16];
  undefined2 local_2e8;
  undefined4 local_2b8;
  undefined2 local_2b4;
  undefined2 local_2b2;
  undefined1 auStack_e0 [196];
  
  memset(auStack_460,0,0x54);
  memset(auStack_4b4,0,0x54);
  memset(auStack_2f8,0,0x2d8);
  local_4b8 = 0;
  memset(auStack_40c,0,0x114);
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    uVar12 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[RDMNGR_ERROR]%s()/%d Invalid params.\n";
    uVar13 = 0x6da;
    goto LAB_00614530;
  }
  pbVar2 = (byte *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x25);
  if (pbVar2 == (byte *)0x0) {
    return 0xffffffff;
  }
  rdmngr_pkt_dump(param_1);
  if (rdmngr_debug_switch == 0) {
    bVar6 = pbVar2[1];
  }
  else {
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      bVar6 = pbVar2[1];
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, chnl:%d, rd_mode:%d, tx_pwr:%d\n",
             "rdmngr_capwap_callback_wtp_event_request_listen",0x6e5,(uint)*pbVar2,(uint)pbVar2[2],
             (uint)pbVar2[1],(uint)*(ushort *)(pbVar2 + 4));
      bVar6 = pbVar2[1];
    }
  }
  if (bVar6 < 0xe) {
    uVar3 = (uint)pbVar2[2];
    if (uVar3 == 0xff) {
      uVar3 = 0;
    }
    pbVar2[2] = (byte)uVar3;
    if (uVar3 == 0) {
LAB_006145e4:
      iVar8 = apmngr_db_entry_get_by_mac(param_2,auStack_2f8);
      if (iVar8 == 0) {
        local_4b8 = CONCAT22(local_2b4,local_2b2);
        if ((*pbVar2 == 0) ||
           (iVar8 = rdmngr_db_get_ap_radio_cnt(local_2b8,auStack_e0,&local_4b8),
           iVar8 < (int)(uint)*pbVar2)) {
          if (rdmngr_warning_switch == 0) {
            return 0xffffffff;
          }
          iVar8 = is_target_debug_ap();
          if (iVar8 == 0) {
            return 0xffffffff;
          }
          uVar3 = (uint)*pbVar2;
          pcVar9 = "[RDMNGR_WARNING]%s()/%d Invalid rd_id:%d.\n";
          uVar12 = 0x715;
          goto LAB_00614640;
        }
        uVar12 = rdmngr_db_generate_rd_id(local_2e8);
        iVar8 = rdmngr_db_rd_entry_get(uVar12,auStack_460);
        if (iVar8 == 0) {
          memset(auStack_4b4,0,0x54);
          memcpy(auStack_4b4,auStack_460,0x54);
          iVar8 = apdb_get_radio_by_id(local_2b8,auStack_e0,*pbVar2,auStack_40c,(int)local_458);
          if (iVar8 == -1) {
            uVar12 = 0xffffffff;
            if (rdmngr_err_switch == 0) {
              return 0xffffffff;
            }
            iVar8 = is_target_debug_ap();
            if (iVar8 == 0) {
              return 0xffffffff;
            }
            pcVar9 = "[RDMNGR_ERROR]%s()/%d apdb_get_radio_by_id() failed.\n";
            uVar13 = 0x725;
          }
          else {
            if ((int)local_3ec < (int)(uint)*(ushort *)(pbVar2 + 4)) {
              if (rdmngr_warning_switch == 0) {
                return 0xffffffff;
              }
              iVar8 = is_target_debug_ap();
              if (iVar8 == 0) {
                return 0xffffffff;
              }
              uVar3 = (uint)local_3ec;
              uVar1 = *(ushort *)(pbVar2 + 4);
              pcVar9 = "[RDMNGR_WARNING]%s()/%d tx_pwr(%d) is higher than radio maxTxPwr(%d).\n";
              uVar12 = 0x72b;
LAB_00614728:
              printf(pcVar9,"rdmngr_capwap_callback_wtp_event_request_listen",uVar12,(uint)uVar1,
                     uVar3);
              return 0xffffffff;
            }
            rdmngr_pkt_dump_one(param_1,uVar12);
            local_424 = (ushort)pbVar2[2];
            if (pbVar2[2] == 0) {
              local_424 = 0xffff;
            }
            local_420 = (undefined1)*(undefined2 *)(pbVar2 + 4);
            local_426 = pbVar2[1];
            iVar8 = rdmngr_db_rd_entry_set(auStack_460);
            if (iVar8 == 0) {
              cVar7 = rdmngr_db_get_band_by_channel((int)(short)local_478);
              psVar4 = (short *)get_high_per_ap_chn_info();
              if (local_458 == '\0') {
                sVar5 = *psVar4;
              }
              else if (cVar7 == '\x02') {
                sVar5 = psVar4[1];
              }
              else {
                sVar5 = psVar4[2];
              }
              if (((local_424 != local_478) || (pbVar2[2] == 0)) || (sVar5 == 0)) {
                rdmngr_callback_proc(4,uVar12,auStack_4b4,auStack_460);
              }
              uVar12 = 0;
              if (rdmngr_debug_switch == 0) {
                return 0;
              }
              iVar8 = is_target_debug_ap();
              if (iVar8 == 0) {
                return 0;
              }
              pcVar9 = 
              "[RDMNGR_DEBUG]%s()/%d rdmngr_capwap_callback_wtp_event_request_listen() done.\n";
              uVar13 = 0x756;
            }
            else {
              uVar12 = 0xffffffff;
              if (rdmngr_err_switch == 0) {
                return 0xffffffff;
              }
              iVar8 = is_target_debug_ap();
              if (iVar8 == 0) {
                return 0xffffffff;
              }
              pcVar9 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_set() failed.\n";
              uVar13 = 0x744;
            }
          }
        }
        else {
          uVar12 = 0xffffffff;
          if (rdmngr_err_switch == 0) {
            return 0xffffffff;
          }
          iVar8 = is_target_debug_ap();
          if (iVar8 == 0) {
            return 0xffffffff;
          }
          pcVar9 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rd_entry_get() failed.\n";
          uVar13 = 0x71c;
        }
      }
      else {
        uVar12 = 0xffffffff;
        if (rdmngr_debug_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[RDMNGR_DEBUG]%s()/%d apmngr_db_entry_get_by_mac() failed.\n";
        uVar13 = 0x70a;
      }
LAB_00614530:
      printf(pcVar9,"rdmngr_capwap_callback_wtp_event_request_listen",uVar13);
      return uVar12;
    }
    iVar8 = 0;
    iVar10 = 0;
    do {
      uVar11 = *(uint *)(DAT_007598ec + iVar10 + 0x17c8);
      if ((uVar11 != 0) && (uVar3 == uVar11)) {
        uVar3 = (uint)*(ushort *)(DAT_007598ec + (iVar8 + 4) * 8 + 0x17ae);
        if (*(ushort *)(pbVar2 + 4) <= uVar3) goto LAB_006145e4;
        if (rdmngr_warning_switch == 0) {
          return 0xffffffff;
        }
        iVar8 = is_target_debug_ap();
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar1 = *(ushort *)(pbVar2 + 4);
        pcVar9 = "[RDMNGR_WARNING]%s()/%d tx_pwr(%d) is higher than maxTxPwr(%d)\n";
        uVar12 = 0x704;
        goto LAB_00614728;
      }
      iVar8 = iVar8 + 1;
      iVar10 = iVar8 * 8;
    } while (iVar8 != 0x28);
    if (rdmngr_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar3 = (uint)pbVar2[2];
    pcVar9 = "[RDMNGR_WARNING]%s()/%d Invalid rd_chnl:%d.\n";
    uVar12 = 0x6fd;
  }
  else {
    if (rdmngr_warning_switch == 0) {
      return 0xffffffff;
    }
    iVar8 = is_target_debug_ap();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    uVar3 = (uint)pbVar2[1];
    pcVar9 = "[RDMNGR_WARNING]%s()/%d Invalid rd_mode:%d.\n";
    uVar12 = 0x6ea;
  }
LAB_00614640:
  printf(pcVar9,"rdmngr_capwap_callback_wtp_event_request_listen",uVar12,uVar3);
  return 0xffffffff;
}

