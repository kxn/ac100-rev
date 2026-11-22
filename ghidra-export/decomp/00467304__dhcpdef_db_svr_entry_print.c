// func _dhcpdef_db_svr_entry_print @ 00467304 size=260

void _dhcpdef_db_svr_entry_print(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [40];
  
  memset(auStack_30,0,0x28);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  if (param_1 == (undefined4 *)0x0) {
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_db_svr_entry_print",0x260,"entry");
    }
  }
  else {
    puts("############################################\r");
    printf("  server id    = %d\r\n",*param_1);
    printf("  server name  = %s\r\n",param_1 + 1);
    dhcpdef_addrtype2str((int)*(char *)((int)param_1 + 0x9b),&local_40);
    printf("  addr type    = %s\r\n",&local_40);
    dhcpdef_addr2str((int)*(char *)((int)param_1 + 0x9b),param_1 + 0x27,auStack_30);
    printf("  server addr  = %s\r\n",auStack_30);
  }
  return;
}

