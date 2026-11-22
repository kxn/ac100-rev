// func cw_packet_queue_push_tail @ 0059b708 size=384

undefined4 cw_packet_queue_push_tail(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_18 [12];
  
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d capwap packet queue is not inited.\n","cw_packet_queue_push_tail"
             ,0xe7);
    }
  }
  else {
    local_18[0] = 0x31;
    FUN_004082d0(*param_1,0xffffffff);
    iVar1 = param_1[3];
    if (*(int *)(iVar1 + 8) == *(int *)(iVar1 + 0x10)) {
      uVar4 = 0xffffffff;
      FUN_00407f30(*param_1);
      if (capwap_warning_switch != 0) {
        uVar4 = 0xffffffff;
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          puVar2 = (undefined4 *)param_1[3];
          printf("[CW_WARNING]%32s():%4d capwap packet queue is full, size is %d,capacity is %d,scale: %d-%d.\n"
                 ,"cw_packet_queue_push_tail",0x102,puVar2[2],puVar2[4],*puVar2,puVar2[1]);
        }
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 4) * 4) = param_2;
      iVar1 = param_1[3];
      if (*(int *)(iVar1 + 0x10) == 0) {
        trap(7);
      }
      *(int *)(iVar1 + 4) = (*(int *)(iVar1 + 4) + 1) % *(int *)(iVar1 + 0x10);
      *(int *)(param_1[3] + 8) = *(int *)(param_1[3] + 8) + 1;
      if (*(int *)(param_1[3] + 8) == 1) {
        write(param_1[2],local_18,1);
        uVar3 = *param_1;
      }
      else {
        uVar3 = *param_1;
      }
      uVar4 = 0;
      FUN_00407f30(uVar3);
    }
  }
  return uVar4;
}

