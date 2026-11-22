// func _dhcpdef_sqlite_do_update @ 00471b38 size=616

undefined4 _dhcpdef_sqlite_do_update(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  char *__s;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined1 local_420;
  char acStack_41c [1028];
  
  __s = acStack_41c;
  memset(__s,0,0x400);
  local_430 = 0;
  local_42c = 0;
  iVar5 = (int)param_1 + 0x11;
  local_428 = 0;
  local_424 = 0;
  local_420 = 0;
  memcpy(&local_430,param_1,0x11);
  local_424._1_3_ = (undefined3)((uint)iVar5 >> 8);
  local_420 = (undefined1)iVar5;
  iVar1 = dhcpdef_db_get_max_svr_per_ap();
  iVar1 = FUN_00408450(iVar1 * 6 + 1,0x29a);
  if (iVar1 == 0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
           "_dhcpdef_sqlite_do_update",0x29d);
    return 0xffffffff;
  }
  uVar2 = dhcpdef_db_get_max_svr_per_ap();
  iVar3 = dhcpdef_db_get_max_svr_per_ap();
  iVar5 = _dhcpdef_sqlite_svrids2str(iVar5,uVar2,iVar1,iVar3 * 6);
  if (iVar5 < 0) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_svrids2str() fail\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_sqlite_do_update",0x2a4);
    }
  }
  else {
    snprintf(__s,0x400,"UPDATE %s SET %s = %d, %s = \'%s\' WHERE %s = %d;","bind_tbl","enable",
             (int)local_428._0_1_,"svr_ids",iVar1,"ap_id",local_430);
    if (l_db_handle == 0) {
      uVar2 = 0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00471cc4;
      __s = "l_db_handle";
      __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      uVar4 = 0x2ac;
    }
    else {
      iVar5 = _dhcpdef_sqlite_exec(l_db_handle,__s);
      uVar2 = 0;
      if (((iVar5 == 0) || (uVar2 = 0xffffffff, g_dhcpdef_error == 0)) ||
         (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00471cc4;
      __format = "\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_exec() fail, cmd=%s\x1b[0m\r\n";
      uVar4 = 0x2af;
    }
    uVar2 = 0xffffffff;
    printf(__format,"dhcp_defend","_dhcpdef_sqlite_do_update",uVar4,__s);
  }
LAB_00471cc4:
  FUN_00407df0(iVar1);
  return uVar2;
}

