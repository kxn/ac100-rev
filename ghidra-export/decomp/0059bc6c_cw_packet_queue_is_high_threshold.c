// func cw_packet_queue_is_high_threshold @ 0059bc6c size=112

undefined4 cw_packet_queue_is_high_threshold(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    FUN_004082d0(*param_1,0xffffffff);
    iVar1 = *(int *)(param_1[3] + 0x10);
    if (iVar1 == 0) {
      trap(7);
    }
    if (0x4f < (*(int *)(param_1[3] + 8) * 100) / iVar1) {
      uVar2 = 0;
    }
    FUN_00407f30(*param_1);
  }
  return uVar2;
}

