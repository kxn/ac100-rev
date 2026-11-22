// func dhcpdef_sqlite_svr_entry_load @ 00472514 size=412

int dhcpdef_sqlite_svr_entry_load(void)

{
  char *pcVar1;
  int iVar2;
  char *__format;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *__s;
  char *pcVar7;
  int local_418;
  char acStack_414 [1028];
  
  __s = acStack_414;
  local_418 = 0;
  memset(__s,0,0x400);
  pcVar1 = (char *)_dhcpdef_sqlite_try_create_tbl();
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)_dhcpdef_sqlite_open("/etc/nouci_config/dbs/dhcpdef_svr.db",&local_418);
    if (pcVar1 == (char *)0x0) {
      snprintf(__s,0x400,"select * from svr_tbl");
      iVar5 = FUN_00407fb0(local_418,__s,_dhcpdef_sqlite_svr_entry_load_one,0);
      if ((iVar5 == 0) || (iVar6 = FUN_00408410(), iVar6 == 0)) goto LAB_00472574;
      pcVar7 = "svr_tbl";
      __format = "[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"select \'%s\' fail\"\n";
      pcVar3 = "dhcpdef_sqlite_svr_entry_load";
      pcVar4 = (char *)0x320;
      iVar6 = iVar5;
    }
    else {
      iVar6 = -1;
      iVar5 = iVar6;
      if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00472574;
      __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
      pcVar3 = "dhcp_defend";
      pcVar7 = "_dhcpdef_sqlite_open((int8_t *)DHCPDEF_SVR_DB_PATH, &db)";
      pcVar4 = "dhcpdef_sqlite_svr_entry_load";
      iVar5 = 0x31b;
      __s = pcVar1;
    }
  }
  else {
    iVar6 = -1;
    iVar5 = iVar6;
    if ((g_dhcpdef_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00472574;
    pcVar7 = "_dhcpdef_sqlite_try_create_tbl()";
    __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
    pcVar3 = "dhcp_defend";
    pcVar4 = "dhcpdef_sqlite_svr_entry_load";
    iVar5 = 0x319;
    __s = pcVar1;
  }
  printf(__format,pcVar3,pcVar4,iVar5,__s,pcVar7);
  iVar5 = iVar6;
LAB_00472574:
  if (local_418 != 0) {
    FUN_004080b0();
  }
  return iVar5;
}

