// func apupd_result_code_add @ 006616bc size=196

undefined4 apupd_result_code_add(int param_1,undefined4 param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  if (param_1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0x11e;
  }
  else {
    local_10[0] = param_2;
    iVar1 = cw_service_msg_add(param_1,0x21,local_10,0);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: add result code failed.\r\n";
    uVar2 = 0x129;
  }
  printf(__format,"apupd_result_code_add",uVar2);
  return 0xffffffff;
}

