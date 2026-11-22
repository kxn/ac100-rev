// func get_pkt_info @ 00594874 size=136

undefined4 get_pkt_info(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d get_pkt_info\n","get_pkt_info",0xa8);
  }
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x10);
    *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(param_2 + 0x14);
    cw_msg_eles_get_type(param_1 + 0x48,param_1 + 0x3c,param_2);
    uVar1 = 0;
  }
  return uVar1;
}

