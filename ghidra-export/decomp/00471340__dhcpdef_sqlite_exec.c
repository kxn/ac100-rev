// func _dhcpdef_sqlite_exec @ 00471340 size=204

undefined4 _dhcpdef_sqlite_exec(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "db";
    uVar1 = 0x19c;
  }
  else {
    if (param_2 != 0) {
      uVar1 = FUN_00407d60();
      return uVar1;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "cmd";
    uVar1 = 0x19d;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "_dhcpdef_sqlite_exec",uVar1,pcVar3);
  return 0xffffffff;
}

