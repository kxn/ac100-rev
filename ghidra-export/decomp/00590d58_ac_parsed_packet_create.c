// func ac_parsed_packet_create @ 00590d58 size=380

undefined4 ac_parsed_packet_create(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_parsed_packet_create",0x173,"NULL != packet"
          );
    return 0;
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 1:
    uVar2 = 2;
    break;
  default:
    return 0;
  case 3:
    uVar2 = 4;
    break;
  case 5:
    uVar2 = 6;
    break;
  case 9:
    uVar2 = 10;
    break;
  case 0xb:
    uVar2 = 0xc;
    break;
  case 0xd:
    uVar2 = 0xe;
    break;
  case 0xf:
    uVar2 = 0x10;
  }
  uVar2 = cw_parsed_pkt_create(uVar2);
  iVar1 = cw_header_init(uVar2,*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
  if (iVar1 == -1) {
    if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00590e78;
    __format = "[CW_ERROR]%32s():%4d failed to set capwap header\n";
    uVar3 = 0x191;
  }
  else {
    iVar1 = cw_control_header_sequence_num_set(uVar2,*(undefined1 *)(param_1 + 0x14));
    if (iVar1 != -1) {
      return uVar2;
    }
    if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00590e78;
    __format = "[CW_ERROR]%32s():%4d failed to set capwap control header\n";
    uVar3 = 0x197;
  }
  printf(__format,"ac_parsed_packet_create",uVar3);
LAB_00590e78:
  cw_parsed_pkt_destroy(uVar2);
  return 0;
}

