// func cw_ac_retransmit_timer_stop @ 00592648 size=196

undefined4 cw_ac_retransmit_timer_stop(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_retransmit_timer_stop",0x6ff,"session");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    *(undefined1 *)(param_1 + 0xf6) = 0;
    if (*(int *)(param_1 + 0xec) != 0) {
      if (capwap_debug_switch == 0) {
        iVar1 = *(int *)(param_1 + 0xc);
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_1 + 0xc);
        }
        else {
          printf("[CW_DEBUG]%32s():%4d session[%p] stop the retransmit timer\n",
                 "cw_ac_retransmit_timer_stop",0x703,param_1);
          iVar1 = *(int *)(param_1 + 0xc);
        }
      }
      iVar1 = cw_timer_remove(*(undefined4 *)(iVar1 + 0x44),*(undefined4 *)(param_1 + 0xec));
      uVar2 = 0xffffffff;
      if (iVar1 == 0) {
        uVar2 = 0;
        *(undefined4 *)(param_1 + 0xec) = 0;
      }
    }
  }
  return uVar2;
}

