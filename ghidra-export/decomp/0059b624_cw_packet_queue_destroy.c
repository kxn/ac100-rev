// func cw_packet_queue_destroy @ 0059b624 size=1

void cw_packet_queue_destroy(undefined4 *param_1)

{
  int *piVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (*(int *)(param_1[3] + 8) != 0) {
    piVar1 = (int *)param_1[3];
    while (*piVar1 != piVar1[1]) {
      FUN_00407df0(*(undefined4 *)(piVar1[5] + *piVar1 * 4));
      *(undefined4 *)(((int *)param_1[3])[5] + *(int *)param_1[3] * 4) = 0;
      piVar1 = (int *)param_1[3];
      if (piVar1[4] == 0) {
        trap(7);
      }
      *piVar1 = (*piVar1 + 1) % piVar1[4];
      *(int *)(param_1[3] + 8) = *(int *)(param_1[3] + 8) + -1;
      piVar1 = (int *)param_1[3];
    }
  }
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  FUN_00407df0(*(undefined4 *)(param_1[3] + 0x14));
  FUN_00407df0(param_1[3]);
  FUN_00408360(*param_1);
  uac_mem_free_my(param_1);
  return;
}

