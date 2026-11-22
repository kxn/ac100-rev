// func FUN_005f7e84 @ 005f7e84 size=184

undefined4 FUN_005f7e84(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_808 [2048];
  
  memset(acStack_808,0,0x800);
  uVar2 = 0;
  snprintf(acStack_808,0x800,"DELETE FROM %s WHERE %s=%d;","igmp_ip_tbl","id",param_1);
  iVar1 = FUN_00407d60(l_wserv_ip_handle,acStack_808);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, cmd=%s\r\n",
           "_wserv_sqlite_do_delete_ip",0x33c,acStack_808);
  }
  return uVar2;
}

