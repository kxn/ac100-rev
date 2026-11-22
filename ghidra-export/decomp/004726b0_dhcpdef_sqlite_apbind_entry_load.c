// func dhcpdef_sqlite_apbind_entry_load @ 004726b0 size=508

undefined4 dhcpdef_sqlite_apbind_entry_load(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *__s;
  int local_420;
  char acStack_41c [1032];
  
  __s = acStack_41c;
  local_420 = 0;
  memset(__s,0,0x400);
  iVar1 = _dhcpdef_sqlite_try_create_tbl();
  if (iVar1 == 0) {
    iVar1 = _dhcpdef_sqlite_open("/etc/nouci_config/dbs/dhcpdef_bind.db",&local_420);
    if (iVar1 == 0) {
      uVar5 = dhcpdef_db_get_max_ap();
      FUN_00408300(&g_invalid_ap_id,&g_invalid_ap_id_pos,uVar5);
      snprintf(__s,0x400,"select * from bind_tbl");
      iVar1 = FUN_00407fb0(local_420,__s,_dhcpdef_sqlite_apbind_entry_load_one,0);
      if (iVar1 == 0) {
        iVar1 = FUN_00408490(g_invalid_ap_id,g_invalid_ap_id_pos,local_420,"bind_tbl","ap_id");
        if (iVar1 == 0) {
          uVar5 = 0;
          FUN_00407de0(&g_invalid_ap_id,&g_invalid_ap_id_pos);
          goto LAB_00472714;
        }
      }
      else {
        iVar2 = FUN_00408410();
        if (iVar2 != 0) {
          __format = "[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"select \'%s\' fail\"\n";
          pcVar3 = "dhcpdef_sqlite_apbind_entry_load";
          pcVar4 = (char *)0x341;
          goto LAB_0047285c;
        }
      }
    }
    else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(&g_invalid_ap_id), iVar1 != 0)) {
      __s = "/etc/nouci_config/dbs/dhcpdef_bind.db";
      __format = "\x1b[31;49m[%s]<%s():%d> sqlite3_open() fail, path=%s\x1b[0m\r\n";
      pcVar3 = "dhcp_defend";
      pcVar4 = "dhcpdef_sqlite_apbind_entry_load";
      iVar1 = 0x338;
LAB_0047285c:
      printf(__format,pcVar3,pcVar4,iVar1,__s);
    }
  }
  else if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(&g_invalid_ap_id), iVar1 != 0)) {
    printf("\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_try_create_tbl() fail.\x1b[0m\r\n",
           "dhcp_defend","dhcpdef_sqlite_apbind_entry_load",0x331);
  }
  uVar5 = 0xffffffff;
  FUN_00407de0(&g_invalid_ap_id,&g_invalid_ap_id_pos);
LAB_00472714:
  if (local_420 != 0) {
    FUN_004080b0();
  }
  return uVar5;
}

