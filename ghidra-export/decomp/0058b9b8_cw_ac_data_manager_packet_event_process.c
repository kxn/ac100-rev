// func cw_ac_data_manager_packet_event_process @ 0058b9b8 size=1340

void cw_ac_data_manager_packet_event_process(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  ushort *puVar5;
  char cVar6;
  undefined4 uVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  undefined4 local_d8;
  int local_d4;
  undefined1 auStack_d0 [16];
  undefined1 auStack_c0 [20];
  undefined2 local_ac;
  undefined1 auStack_9c [6];
  undefined1 auStack_96 [6];
  undefined1 local_90;
  undefined1 auStack_8c [20];
  undefined2 local_78;
  undefined1 auStack_68 [28];
  undefined1 auStack_4c [28];
  undefined1 *local_30;
  int local_2c;
  
  if (param_2 == 0) {
    uVar7 = 0x4db;
    pcVar8 = "pkt";
LAB_0058bc80:
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_manager_packet_event_process",uVar7,
           pcVar8);
    return;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar7 = 0x4dc;
    pcVar8 = "pkt->packet_buf.buf";
    goto LAB_0058bc80;
  }
  if (param_1 == 0) {
    uVar7 = 0x4dd;
    pcVar8 = "session";
    goto LAB_0058bc80;
  }
  iVar11 = param_1 + 0xf8;
  memcpy((void *)(*(int *)(param_1 + 0xc) + 0x7c),(void *)(param_1 + 0x2c),0x14);
  *(undefined2 *)(*(int *)(param_1 + 0xc) + 0x90) = *(undefined2 *)(param_1 + 0x40);
  iVar2 = FUN_00407fe0(iVar11);
  if (iVar2 != 0) {
    pvVar4 = (void *)FUN_00408450(0x18,0x55e);
    if (pvVar4 != (void *)0x0) {
      memset(pvVar4,0,0x18);
      *(int *)((int)pvVar4 + 0x10) = param_2;
      FUN_004086b0(iVar11,pvVar4);
      return;
    }
LAB_0058bad0:
    iVar2 = *(int *)(param_2 + 8);
    goto LAB_0058bad4;
  }
  bVar1 = false;
  iVar2 = cw_control_header_msg_type_get(*(undefined4 *)(param_2 + 0x10));
  if ((*(char *)(param_2 + 0x38) != '\0') && ((iVar2 == 0x11 || (iVar2 == 0xf)))) {
    bVar1 = iVar2 == 0x11;
    iVar2 = 7;
  }
  local_d8 = 0xb;
  local_d4 = iVar2;
  iVar3 = cw_fsm_ac_process_event(param_1,&local_d8);
  if (iVar3 == 0) {
    cVar6 = '\x01';
    if (*(char *)(param_1 + 0xa4) != -1) {
      cVar6 = *(char *)(param_1 + 0xa4) + '\x01';
    }
    *(char *)(param_1 + 0xa4) = cVar6;
    iVar10 = param_2 + 0x10;
    cw_control_header_seq_num_set(*(undefined4 *)(param_2 + 0x10));
    iVar3 = ac_packet_buf_send(param_1,iVar10);
    if (iVar3 == 0) {
      uVar12 = FUN_00524078();
      if (open_store_snapshot != 0) {
        local_2c = *(int *)(param_2 + 0x44);
        iVar3 = create_new_pkt_snapshot(3,*(undefined4 *)(param_1 + 0xc));
        get_pkt_info_by_buf(iVar3,iVar10,param_1 + 0xdc);
        if (iVar3 != 0) {
          if (*(undefined4 **)(iVar3 + 0x58) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar3 + 0x58) = 0;
            *(undefined1 *)(*(int *)(iVar3 + 0x58) + 4) = 0;
            *(int *)(*(int *)(iVar3 + 0x58) + 8) = (int)uVar12 - local_2c;
          }
          *(undefined8 *)(iVar3 + 0x10) = uVar12;
          memcpy((void *)(iVar3 + 0x2c),(void *)(param_1 + 0x14),6);
        }
      }
      *(undefined8 *)(param_2 + 0x40) = uVar12;
      if ((iVar2 == 0x11) && (iVar3 = ac_send_packet_response_need(param_2), iVar3 == 0))
      goto LAB_0058bb94;
      if (bVar1) {
        memset(auStack_68,0,0x38);
        local_30 = auStack_9c;
        memset(local_30,0,0x34);
        *(undefined2 *)(param_2 + 0x16) = 0;
        FUN_0051ad88(auStack_4c);
        iVar3 = capwap_packet_parse(iVar10,auStack_68,0,0,param_1 + 0xdc);
        if (iVar3 == 0) {
          uVar9 = 0;
          puVar5 = (ushort *)cw_msg_ele_priv_val_get_from_pkt(auStack_68,0x75);
          if (puVar5 != (ushort *)0x0) {
            for (; uVar9 < *puVar5; uVar9 = uVar9 + 1) {
              memcpy(auStack_8c,(void *)(param_1 + 0x2c),0x14);
              local_78 = *(undefined2 *)(param_1 + 0x40);
              local_90 = 1;
              memcpy(auStack_96,(void *)(param_1 + 0x14),6);
              memcpy(auStack_9c,(void *)(*(int *)(puVar5 + 2) + uVar9 * 6),6);
              serv_ent_handle(2,auStack_9c,0,0);
            }
          }
        }
        *(undefined2 *)(param_2 + 0x16) = 0;
        capwap_parsed_packet_free(auStack_68);
      }
      local_d8 = 0xc;
      local_d4 = iVar2;
      iVar2 = cw_fsm_ac_process_event(param_1,&local_d8);
      if (iVar2 != -1) {
        iVar2 = ac_send_packet_response_need(param_2);
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_2 + 8);
          goto LAB_0058bad4;
        }
        pvVar4 = (void *)FUN_00408450(0x18,0x536);
        if (pvVar4 != (void *)0x0) {
          memset(pvVar4,0,0x18);
          *(int *)((int)pvVar4 + 0x10) = param_2;
          iVar2 = cw_ac_pkt_retransmit_para_fixed(param_2,param_1);
          if ((iVar2 == 0) &&
             (iVar2 = cw_ac_retransmit_timer_start(param_1,*(undefined4 *)(param_2 + 4)), iVar2 == 0
             )) {
            FUN_004086b0(iVar11,pvVar4);
            *(undefined1 *)(param_1 + 0xa8) = *(undefined1 *)(param_1 + 0xa4);
            return;
          }
          FUN_00407df0(pvVar4);
          iVar2 = *(int *)(param_2 + 8);
          goto LAB_0058bad4;
        }
        goto LAB_0058bad0;
      }
      if (capwap_warning_switch == 0) {
        iVar2 = *(int *)(param_2 + 8);
        goto LAB_0058bad4;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_2 + 8);
        goto LAB_0058bad4;
      }
      pcVar8 = "[CW_WARNING]%32s():%4d session[%p] process fsm failed\n";
      uVar7 = 0x530;
    }
    else {
      if (capwap_warning_switch == 0) goto LAB_0058bad0;
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_2 + 8);
        goto LAB_0058bad4;
      }
      pcVar8 = "[CW_WARNING]%32s():%4d session[%p] sends packet failed\n";
      uVar7 = 0x4fc;
    }
    printf(pcVar8,"cw_ac_data_manager_packet_event_process",uVar7,param_1);
    iVar2 = *(int *)(param_2 + 8);
  }
  else {
    if (iVar2 != 0x11) {
      iVar2 = *(int *)(param_2 + 8);
      goto LAB_0058bad4;
    }
    memset(auStack_d0,0,0x34);
    memcpy(auStack_c0,(void *)(param_1 + 0x2c),0x14);
    local_ac = *(undefined2 *)(param_1 + 0x40);
    memcpy(auStack_d0,(void *)(param_1 + 0x14),6);
    serv_ent_handle(2,auStack_d0,0,0);
LAB_0058bb94:
    cw_fsm_ac_teardown(param_1);
    iVar2 = *(int *)(param_2 + 8);
  }
LAB_0058bad4:
  *(int *)(param_2 + 8) = iVar2 + -1;
  return;
}

