// func _apmngr_local_ipv6_add @ 00558fd8 size=232

undefined4 _apmngr_local_ipv6_add(int param_1,void *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d inputs error.\n";
    uVar2 = 0x86d;
  }
  else {
    memcpy(&local_18,param_2,0x10);
    iVar1 = cw_service_msg_add(param_1,0x36,&local_18,0);
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
    __format = "[APMNGR_ERROR]%s()/%d add local ipv6 failed.\n";
    uVar2 = 0x874;
  }
  printf(__format,"_apmngr_local_ipv6_add",uVar2);
  return 0xffffffff;
}

