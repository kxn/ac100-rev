// func cw_protocol_msg_ele_create @ 0057250c size=228

int cw_protocol_msg_ele_create(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_3 == 0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d input parameter is wrong\n";
    uVar2 = 500;
  }
  else {
    iVar1 = FUN_00408450(0x18,0x1f8);
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0xc) = param_1;
      *(undefined2 *)(iVar1 + 0xe) = param_2;
      *(int *)(iVar1 + 0x10) = param_3;
      return iVar1;
    }
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[CW_ERROR]%32s():%4d out of memory\n";
    uVar2 = 0x1fb;
  }
  printf(__format,"cw_protocol_msg_ele_create",uVar2);
  return 0;
}

