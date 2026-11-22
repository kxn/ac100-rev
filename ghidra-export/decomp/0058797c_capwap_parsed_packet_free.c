// func capwap_parsed_packet_free @ 0058797c size=280

int capwap_parsed_packet_free(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *__format;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    iVar1 = 0;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","capwap_parsed_packet_free",0x71e);
    }
  }
  else {
    iVar1 = cw_msg_eles_free();
    if (iVar1 == 0) {
      iVar1 = 0;
      if (capwap_debug_switch == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = cw_control_msg_name(*(undefined4 *)(param_1 + 0x10));
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      __format = "[CW_DEBUG]%32s():%4d success to free %s(%d)\n";
      uVar5 = 0x728;
    }
    else {
      if (capwap_err_switch == 0) {
        return iVar1;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return iVar1;
      }
      uVar3 = cw_control_msg_name(*(undefined4 *)(param_1 + 0x10));
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      __format = "[CW_ERROR]%32s():%4d failed to free %s(%d)\n";
      uVar5 = 0x72c;
    }
    printf(__format,"capwap_parsed_packet_free",uVar5,uVar3,uVar4);
  }
  return iVar1;
}

