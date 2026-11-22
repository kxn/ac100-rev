// func rdmngr_ele_set_adm_state @ 00612f50 size=184

undefined4 rdmngr_ele_set_adm_state(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_10;
  undefined1 local_f;
  
  local_10 = param_1;
  local_f = param_3;
  iVar1 = cw_service_msg_add(param_2,0x1f,&local_10,0);
  if (iVar1 == 0) {
    uVar3 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[RDMNGR_DEBUG]%s()/%d rdmngr_ele_set_adm_state() OK.\n";
    uVar2 = 0x1c2;
  }
  else {
    uVar3 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d admin state cw_service_msg_add() failed.\n";
    uVar2 = 0x1bd;
  }
  printf(__format,"rdmngr_ele_set_adm_state",uVar2);
  return uVar3;
}

