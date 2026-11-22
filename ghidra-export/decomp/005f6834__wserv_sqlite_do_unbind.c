// func _wserv_sqlite_do_unbind @ 005f6834 size=200

undefined4 _wserv_sqlite_do_unbind(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_808 [2048];
  
  memset(acStack_808,0,0x800);
  uVar2 = 0;
  snprintf(acStack_808,0x800,"UPDATE %s SET WSERV%d=-1,VLAN%d=-1 WHERE %s=%d;","bind_tbl",
           (uint)*(byte *)(param_1 + 1),(uint)*(byte *)(param_1 + 1),"radio_id",*param_1);
  iVar1 = FUN_00407d60(l_wserv_rf_handle,acStack_808);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, cmd=%s\r\n",
           "_wserv_sqlite_do_unbind",0x377,acStack_808);
  }
  return uVar2;
}

