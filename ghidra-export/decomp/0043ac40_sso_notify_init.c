// func sso_notify_init @ 0043ac40 size=540

undefined4 sso_notify_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  char acStack_40 [32];
  undefined4 local_20;
  undefined4 local_1c;
  code *local_18;
  undefined4 local_14;
  
  wportal_sso_notify_config_mutex = FUN_00407f00("wportal_sso_notify_config_mutex",1);
  if (wportal_sso_notify_config_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d Create config mutex failed.\n";
    uVar2 = 0x122;
    goto LAB_0043add0;
  }
  iVar1 = sso_notify_read_uci_config();
  if (iVar1 == -1) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d read uci config error.\n";
    uVar2 = 0x128;
    goto LAB_0043add0;
  }
  memset(acStack_40,0,0x30);
  snprintf(acStack_40,0x20,"sso_notify");
  local_20 = 10;
  local_1c = 0;
  local_14 = 0;
  local_18 = _sso_notify_auth_join;
  iVar1 = wportal_db_event_register(acStack_40);
  if (iVar1 == -1) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = 0x10a;
      goto LAB_0043ad54;
    }
  }
  else {
    memset(acStack_40,0,0x30);
    snprintf(acStack_40,0x20,"sso_notify");
    local_20 = 10;
    local_1c = 1;
    local_14 = 0;
    local_18 = _sso_notify_auth_leave;
    iVar1 = wportal_db_event_register(acStack_40);
    if (iVar1 != -1) {
      return 0;
    }
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar2 = 0x116;
LAB_0043ad54:
      printf("[WPORTAL_ERR]%s()/%d sso notify register to wportal failed.\n",
             "sso_notify_register_to_wportal",uVar2);
    }
  }
  if (wportal_err_switch == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  __format = "[WPORTAL_ERR]%s()/%d sso notify register to wportal failed.\n";
  uVar2 = 0x12e;
LAB_0043add0:
  printf(__format,"sso_notify_init",uVar2);
  return 0xffffffff;
}

