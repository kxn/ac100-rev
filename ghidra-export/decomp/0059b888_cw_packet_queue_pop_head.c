// func cw_packet_queue_pop_head @ 0059b888 size=1

undefined4 cw_packet_queue_pop_head(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [12];
  
  auStack_18[0] = 0;
  if (param_1 == (undefined4 *)0x0) {
    if (capwap_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      printf("[CW_ERROR]%32s():%4d capwap packet queue is not inited.\n","cw_packet_queue_pop_head",
             0x116);
      return 0;
    }
  }
  else {
    FUN_004082d0(*param_1,0xffffffff);
    if (*(int *)(param_1[3] + 8) != 0) {
      if (*(int *)(param_1[3] + 8) == 1) {
        read(param_1[1],auStack_18,1);
        piVar2 = (int *)param_1[3];
      }
      else {
        piVar2 = (int *)param_1[3];
      }
      uVar3 = *(undefined4 *)(piVar2[5] + *piVar2 * 4);
      if (piVar2[4] == 0) {
        trap(7);
      }
      *piVar2 = (*piVar2 + 1) % piVar2[4];
      *(int *)(param_1[3] + 8) = *(int *)(param_1[3] + 8) + -1;
      iVar1 = param_1[3];
      if (*(int *)(iVar1 + 0xc) == -1) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      else {
        *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
      }
      FUN_00407f30(*param_1);
      return uVar3;
    }
    FUN_00407f30(*param_1);
  }
  return 0;
}

