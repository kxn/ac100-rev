// func _dhcpdef_sqlite_open @ 00471f68 size=224

undefined4 _dhcpdef_sqlite_open(char *param_1,int param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    param_1 = "path && db";
    uVar2 = 0x18d;
  }
  else {
    iVar1 = FUN_00408130(param_1,param_2,0);
    if (iVar1 == 0) {
      return 0;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "\x1b[31;49m[%s]<%s():%d> sqlite3_open() fail, path=%s\x1b[0m\r\n";
    uVar2 = 0x192;
  }
  printf(__format,"dhcp_defend","_dhcpdef_sqlite_open",uVar2,param_1);
  return 0xffffffff;
}

