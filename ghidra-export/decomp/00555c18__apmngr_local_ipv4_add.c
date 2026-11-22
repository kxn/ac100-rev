// func _apmngr_local_ipv4_add @ 00555c18 size=196

undefined4 _apmngr_local_ipv4_add(int param_1,undefined4 param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  if (param_1 == 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d inputs error.\n";
    uVar2 = 0x858;
  }
  else {
    local_10[0] = param_2;
    iVar1 = cw_service_msg_add(param_1,0x1e,local_10,0);
    if (iVar1 != -1) {
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d add local ipv4 failed.\n";
    uVar2 = 0x85f;
  }
  printf(__format,"_apmngr_local_ipv4_add",uVar2);
  return 0xffffffff;
}

