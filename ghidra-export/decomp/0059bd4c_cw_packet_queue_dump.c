// func cw_packet_queue_dump @ 0059bd4c size=232

void cw_packet_queue_dump(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_004082d0(*param_1,0xffffffff);
    puts("******************print capwap packet queue info**************");
    printf("capwap packet queue capacity : %d.\n",*(undefined4 *)(param_1[3] + 0x10));
    printf("capwap packet queue size: %d.\n",*(undefined4 *)(param_1[3] + 8));
    printf("capwap packet queue header: %d.\n",*(undefined4 *)param_1[3]);
    printf("capwap packet queue tail: %d.\n",*(undefined4 *)(param_1[3] + 4));
    puts("**************************************************************");
    FUN_00407f30(*param_1);
    return;
  }
  if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_ERROR]%32s():%4d capwap packet queue is not inited.\n","cw_packet_queue_dump",0x1dc)
    ;
    return;
  }
  return;
}

