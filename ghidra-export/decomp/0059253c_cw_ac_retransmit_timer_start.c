// func cw_ac_retransmit_timer_start @ 0059253c size=268

undefined4 cw_ac_retransmit_timer_start(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_retransmit_timer_start",0x6db,"session");
    uVar4 = 0xffffffff;
  }
  else {
    if (capwap_debug_switch == 0) {
      uVar3 = *(uint *)(param_1 + 0xd0);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        uVar3 = *(uint *)(param_1 + 0xd0);
      }
      else {
        printf("[CW_DEBUG]%32s():%4d session[%p] start the retransmit timer\n",
               "cw_ac_retransmit_timer_start",0x6dc,param_1);
        uVar3 = *(uint *)(param_1 + 0xd0);
      }
    }
    *(short *)(param_1 + 0xf4) = (short)param_2;
    uVar1 = 0x3c;
    if (0x3b < (int)uVar3) {
      uVar1 = uVar3;
    }
    if (uVar1 < param_2) {
      *(short *)(param_1 + 0xf4) = (short)uVar1;
    }
    *(undefined1 *)(param_1 + 0xf6) = 0;
    if ((*(int *)(param_1 + 0xec) != 0) &&
       (iVar2 = cw_timer_remove(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44)), iVar2 != 0)) {
      return 0xffffffff;
    }
    iVar2 = cw_timer_add(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44),
                         (int)*(short *)(param_1 + 0xf4),cw_ac_retransmit_timeout_handler,param_1,0)
    ;
    uVar4 = 0xffffffff;
    *(int *)(param_1 + 0xec) = iVar2;
    if (iVar2 != 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

