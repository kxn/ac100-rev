// func _uac_dhcpdef_recover_firm_aps @ 00466100 size=220

undefined4 _uac_dhcpdef_recover_firm_aps(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  iVar1 = apmngr_db_foreach_proc(0xff7fffff,recover_ap_config_cb,local_10);
  if (iVar1 == 1) {
    uVar3 = 1;
    if (g_dhcpdef_error == 0) {
      return 1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 1;
    }
    uVar4 = 1;
    __format = "\x1b[31;49m[%s]<%s():%d> apmngr_db_foreach_proc() fail, ret=%d!\x1b[0m\r\n";
    uVar2 = 0x973;
  }
  else {
    uVar3 = 0;
    if (g_dhcpdef_info == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "[%s]<%s():%d> ##########recover %d ap entries!##########\r\n";
    uVar2 = 0x977;
    uVar4 = local_10[0];
  }
  printf(__format,"dhcp_defend","_uac_dhcpdef_recover_firm_aps",uVar2,uVar4);
  return uVar3;
}

