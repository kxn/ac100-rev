// func dhcpdef_db_apbind_entry_print_by_id @ 0046b674 size=1

undefined4 dhcpdef_db_apbind_entry_print_by_id(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      FUN_004082d0(DAT_00767094,0xffffffff);
      iVar1 = DAT_007670a8;
      iVar2 = param_1 * 0x11;
      if (49999 < param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x11;
      }
      _dhcpdef_db_apbind_entry_print(iVar1 + iVar2);
      FUN_00407f30(DAT_00767094);
      return 0;
    }
  }
  if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("\x1b[31;49m[%s]<%s():%d> Invalid ap_id[%d]!\x1b[0m\r\n","dhcp_defend",
           "dhcpdef_db_apbind_entry_print_by_id",0x4ff,param_1);
  }
  return 0xffffffff;
}

