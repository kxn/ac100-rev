// func _uac_dhcpdef_batch_able_inner @ 00464d38 size=308

undefined4 _uac_dhcpdef_batch_able_inner(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_batch_able_inner",0x5c9,
           "_uac_dhcpdef_batch_able_inner");
  }
  if (((param_2 == 0) || (param_3 == 0)) || (param_4 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_batch_able_inner",0x5ca,"aps && ap_num && batch_apconf_chg");
    }
  }
  else {
    iVar1 = dhcpdef_db_apbind_entry_batch_able(param_1,param_2,param_3,param_4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
    iVar1 = _uac_dhcpdef_batch_firm_and_notify(0,param_2,param_3,param_4);
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

