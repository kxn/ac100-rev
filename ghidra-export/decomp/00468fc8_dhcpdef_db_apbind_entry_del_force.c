// func dhcpdef_db_apbind_entry_del_force @ 00468fc8 size=112

void dhcpdef_db_apbind_entry_del_force(undefined4 param_1)

{
  int iVar1;
  
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","dhcpdef_db_apbind_entry_del_force",0x37f,
           "dhcpdef_db_apbind_entry_del_force");
  }
  _dhcpdef_db_apbind_entry_del_inner(param_1,0);
  return;
}

