// func cw_packet_queue_proc_num_get @ 0059be34 size=24

undefined4 cw_packet_queue_proc_num_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
  }
  return uVar1;
}

