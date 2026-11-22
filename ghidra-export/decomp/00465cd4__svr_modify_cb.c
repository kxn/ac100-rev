// func _svr_modify_cb @ 00465cd4 size=196

undefined4 _svr_modify_cb(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_svr_modify_cb",
             0x456,"entry");
    }
  }
  else {
    uVar2 = *param_1;
    iVar1 = dhcpdef_db_apbind_entry_is_firm(uVar2);
    if ((iVar1 == 1) && (iVar1 = dhcpdef_db_apbind_entry_firm_update(uVar2,1), iVar1 != 0)) {
      return 0xffffffff;
    }
    uVar3 = 0xffffffff;
    iVar1 = _uac_dhcpdef_notify_ap(uVar2,1);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

