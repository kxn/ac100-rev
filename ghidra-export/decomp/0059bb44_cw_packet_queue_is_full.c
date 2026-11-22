// func cw_packet_queue_is_full @ 0059bb44 size=1

bool cw_packet_queue_is_full(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    bVar2 = false;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d capwap packet queue is not inited.\n","cw_packet_queue_is_full",
             0x17b);
    }
  }
  else {
    FUN_004082d0(*param_1,0xffffffff);
    bVar2 = *(int *)(param_1[3] + 8) == *(int *)(param_1[3] + 0x10);
    FUN_00407f30(*param_1);
  }
  return bVar2;
}

