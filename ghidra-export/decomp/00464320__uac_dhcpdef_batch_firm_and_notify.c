// func _uac_dhcpdef_batch_firm_and_notify @ 00464320 size=308

undefined4
_uac_dhcpdef_batch_firm_and_notify(undefined4 param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((param_2 == (undefined4 *)0x0) || (param_3 == 0)) || (param_4 == (int *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_batch_firm_and_notify",0x326,"aps && ap_num && batch_apconf_chg");
    }
  }
  else {
    uVar2 = 0;
    for (iVar3 = 0; iVar3 < param_3; iVar3 = iVar3 + 1) {
      if (*param_4 == 1) {
        iVar1 = dhcpdef_db_apbind_entry_is_firm(*param_2);
        if ((iVar1 == 1) && (iVar1 = dhcpdef_db_apbind_entry_firm_update(*param_2), iVar1 != 0)) {
          uVar2 = 0xffffffff;
        }
        iVar1 = _uac_dhcpdef_notify_ap(*param_2,param_1);
        if (iVar1 != 0) {
          uVar2 = 0xffffffff;
        }
      }
      param_4 = param_4 + 1;
      param_2 = param_2 + 1;
    }
  }
  return uVar2;
}

