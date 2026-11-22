// func cw_parsed_pkt_msg_ele_add @ 00588588 size=1

short cw_parsed_pkt_msg_ele_add(int param_1,uint param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  param_2 = param_2 & 0xffff;
  if ((param_1 == 0) || (((0x35 < param_2 - 1 && (0x18 < param_2 - 0x400)) || (param_3 == 0)))) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_parsed_pkt_msg_ele_add",0x59f);
    return 0;
  }
  iVar1 = cw_msg_ele_mngr_get(param_2);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
    uVar2 = 0x5a7;
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x14))(param_3);
    if (iVar1 != 0) {
      FUN_004086b0(param_1 + 0x1c,iVar1);
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + *(short *)(iVar1 + 0xe) + 4;
      return *(short *)(iVar1 + 0xe) + 4;
    }
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d failed to create message element(%d)\n";
    uVar2 = 0x5af;
  }
  printf(__format,"cw_parsed_pkt_msg_ele_add",uVar2,param_2);
  return 0;
}

