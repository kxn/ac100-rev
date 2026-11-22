// func _dhcpdef_sqlite_do_delete @ 0047140c size=384

undefined4 _dhcpdef_sqlite_do_delete(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  if (param_1 == (undefined4 *)0x0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "ap_id";
    uVar3 = 0x248;
  }
  else {
    snprintf(acStack_408,0x400,"DELETE FROM %s WHERE %s=%d;","bind_tbl","ap_id",*param_1);
    if (l_db_handle != 0) {
      iVar1 = _dhcpdef_sqlite_exec(l_db_handle,acStack_408);
      if (iVar1 == 0) {
        return 0;
      }
      if (g_dhcpdef_error == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_sqlite_do_delete",0x24e,iVar1,"_dhcpdef_sqlite_exec(l_db_handle, cmd)");
      return 0xffffffff;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "l_db_handle";
    uVar3 = 0x24d;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "_dhcpdef_sqlite_do_delete",uVar3,pcVar4);
  return 0xffffffff;
}

