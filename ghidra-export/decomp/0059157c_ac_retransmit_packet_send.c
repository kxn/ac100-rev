// func ac_retransmit_packet_send @ 0059157c size=684

undefined4 ac_retransmit_packet_send(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_v1;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_retransmit_packet_send",0x253,
           "NULL != session");
  }
  else {
    iVar1 = FUN_00407fe0(param_1 + 0xf8);
    if (iVar1 != 0) {
      iVar1 = FUN_004081b0(param_1 + 0xf8);
      if (iVar1 == 0) {
        uVar2 = 0x265;
        pcVar4 = "pkt_node";
      }
      else {
        if (**(int **)(iVar1 + 0x10) != 0) {
          uVar2 = cw_control_header_msg_type_get((*(int **)(iVar1 + 0x10))[4]);
          local_30 = 0xb;
          local_2c = uVar2;
          iVar3 = cw_fsm_ac_process_event(param_1,&local_30);
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          cw_control_header_seq_num_set
                    (*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x10),*(undefined1 *)(param_1 + 0xa8))
          ;
          iVar3 = ac_packet_buf_send(param_1,*(int *)(iVar1 + 0x10) + 0x10);
          if (iVar3 == -1) {
            if (capwap_warning_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            pcVar4 = "[CW_WARNING]%32s():%4d send retransmit packet failed\n";
            uVar2 = 0x272;
          }
          else {
            uVar6 = FUN_00524078();
            iVar3 = is_store_snapshot();
            if (iVar3 == 0) {
              iVar1 = *(int *)(iVar1 + 0x10);
            }
            else {
              FUN_00524078();
              iVar5 = *(int *)(*(int *)(iVar1 + 0x10) + 0x44);
              iVar3 = create_new_pkt_snapshot(3,*(undefined4 *)(param_1 + 0xc));
              get_pkt_info_by_buf(iVar3,*(int *)(iVar1 + 0x10) + 0x10,param_1 + 0xdc);
              if (iVar3 == 0) {
                iVar1 = *(int *)(iVar1 + 0x10);
              }
              else {
                if (*(int **)(iVar3 + 0x58) != (int *)0x0) {
                  **(int **)(iVar3 + 0x58) = (int)*(short *)(param_1 + 0xf4);
                  *(undefined1 *)(*(int *)(iVar3 + 0x58) + 4) = *(undefined1 *)(param_1 + 0xf6);
                  *(int *)(*(int *)(iVar3 + 0x58) + 8) = extraout_v1 - iVar5;
                }
                *(undefined8 *)(iVar3 + 0x10) = uVar6;
                memcpy((void *)(iVar3 + 0x2c),(void *)(param_1 + 0x14),6);
                iVar1 = *(int *)(iVar1 + 0x10);
              }
            }
            *(undefined8 *)(iVar1 + 0x40) = uVar6;
            local_30 = 0xc;
            local_2c = uVar2;
            iVar1 = cw_fsm_ac_process_event(param_1,&local_30);
            if (iVar1 != -1) {
              return 0;
            }
            if (capwap_warning_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            pcVar4 = "[CW_WARNING]%32s():%4d handle fsm event failed.\n";
            uVar2 = 0x28a;
          }
          printf(pcVar4,"ac_retransmit_packet_send",uVar2);
          return 0xffffffff;
        }
        uVar2 = 0x266;
        pcVar4 = "pkt_node->packet_info->retransmit != CW_NOT_RETRANS";
      }
      printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_retransmit_packet_send",uVar2,pcVar4);
    }
  }
  return 0xffffffff;
}

