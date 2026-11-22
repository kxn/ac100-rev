// func dhcpdef_db_apbind_entry_del_not_firmed @ 00469038 size=112

void dhcpdef_db_apbind_entry_del_not_firmed(undefined4 param_1)

{
  int iVar1;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_del_not_firmed",
           0x386,"dhcpdef_db_apbind_entry_del_not_firmed");
  }
  _dhcpdef_db_apbind_entry_del_inner(param_1,1);
  return;
}

