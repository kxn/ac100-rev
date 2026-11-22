// func cw_ac_retransmit_timeout_handler @ 00591828 size=700

void cw_ac_retransmit_timeout_handler(int param_1)

{
  int iVar1;
  char cVar5;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_50 [64];
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_retransmit_timeout_handler",0x2a2,
           "session");
    return;
  }
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d Retransmit timeout %d/%d\n","cw_ac_retransmit_timeout_handler",
           0x2a4,(int)*(char *)(param_1 + 0xf6),(int)*(char *)(param_1 + 0xf7));
  }
  iVar1 = FUN_004081b0(param_1 + 0xf8);
  cVar5 = *(char *)(param_1 + 0xf6) + '\x01';
  *(char *)(param_1 + 0xf6) = cVar5;
  if (cVar5 <= *(char *)(param_1 + 0xf7)) {
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0xf6) = 0;
      goto LAB_005918a0;
    }
    iVar2 = ac_send_packet_retrans_need(param_1,*(undefined4 *)(iVar1 + 0x10));
    if (iVar2 != 0) {
      iVar2 = ac_retransmit_packet_send(param_1);
      if (iVar2 == -1) {
        if (capwap_warning_switch == 0) {
          piVar3 = *(int **)(iVar1 + 0x10);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            piVar3 = *(int **)(iVar1 + 0x10);
          }
          else {
            printf("[CW_WARNING]%32s():%4d ac_retransmit_packet_send failed\n",
                   "cw_ac_retransmit_timeout_handler",0x2b6);
            piVar3 = *(int **)(iVar1 + 0x10);
          }
        }
      }
      else {
        piVar3 = *(int **)(iVar1 + 0x10);
      }
      if (*piVar3 - 1U < 2) {
        iVar2 = *(int *)(param_1 + 0xd0);
        iVar6 = (int)*(short *)(param_1 + 0xf4);
        iVar1 = 0x3c;
        if (0x3b < iVar2) {
          iVar1 = iVar2;
        }
        if (iVar1 < iVar6 << 1) {
          if (iVar6 < 0x3c) {
            *(short *)(param_1 + 0xf4) = (short)iVar1;
          }
          else if (iVar6 < iVar2) {
            *(short *)(param_1 + 0xf4) = (short)iVar1;
          }
        }
        else {
          *(short *)(param_1 + 0xf4) = (short)(iVar6 << 1);
        }
      }
      if (capwap_debug_switch == 0) {
        iVar1 = *(int *)(param_1 + 0xc);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0xc);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d start retransmit timer: %ds\n",
                 "cw_ac_retransmit_timeout_handler",0x2c7,(int)*(short *)(param_1 + 0xf4));
          iVar1 = *(int *)(param_1 + 0xc);
        }
      }
      uVar4 = cw_timer_add(*(undefined4 *)(iVar1 + 0x44),(int)*(short *)(param_1 + 0xf4),
                           cw_ac_retransmit_timeout_handler,param_1,0);
      *(undefined4 *)(param_1 + 0xec) = uVar4;
      return;
    }
  }
  *(undefined1 *)(param_1 + 0xf6) = 0;
LAB_005918a0:
  memset(auStack_50,0,0x40);
  FUN_00408190(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
               *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
               *(undefined4 *)(param_1 + 0x3c),auStack_50,0x40,"---");
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d [%p]Retransmit[%ds] count exceeds max count or AP not support retransmit[%s:%d]\n"
           ,"cw_ac_retransmit_timeout_handler",0x2ad,*(undefined4 *)(param_1 + 0xc),
           (int)*(short *)(param_1 + 0xf4),auStack_50,(uint)*(ushort *)(param_1 + 0x40));
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  local_58 = 5;
  local_54 = 10;
  cw_fsm_ac_process_event(param_1,&local_58);
  return;
}

