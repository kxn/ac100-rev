// func get_pkt_info_by_buf @ 005948fc size=224

undefined4 get_pkt_info_by_buf(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_48 [16];
  undefined4 local_38;
  undefined1 local_34;
  undefined1 auStack_2c [28];
  
  memset(auStack_48,0,0x38);
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d get_pkt_info_by_buf\n","get_pkt_info_by_buf",0xbd);
  }
  uVar1 = 0xffffffff;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_0051ad88(auStack_2c);
    *(undefined2 *)(param_2 + 6) = 0;
    capwap_packet_parse(param_2,auStack_48,0,0,param_3);
    *(undefined2 *)(param_2 + 6) = 0;
    *(undefined4 *)(param_1 + 0x34) = local_38;
    *(undefined1 *)(param_1 + 0x32) = local_34;
    cw_msg_eles_get_type(param_1 + 0x48,param_1 + 0x3c,auStack_48);
    capwap_parsed_packet_free(auStack_48);
    uVar1 = 0;
  }
  return uVar1;
}

