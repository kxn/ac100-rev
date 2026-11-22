// func _dhcpdef_sqlite_do_insert @ 0047158c size=676

undefined4 _dhcpdef_sqlite_do_insert(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined1 local_420;
  char acStack_41c [1028];
  
  pcVar4 = acStack_41c;
  memset(pcVar4,0,0x400);
  local_430 = 0;
  local_42c = 0;
  iVar6 = (int)param_1 + 0x11;
  local_428 = 0;
  local_424 = 0;
  local_420 = 0;
  memcpy(&local_430,param_1,0x11);
  local_424._1_3_ = (undefined3)((uint)iVar6 >> 8);
  local_420 = (undefined1)iVar6;
  iVar1 = dhcpdef_db_get_max_svr_per_ap();
  iVar1 = FUN_00408450(iVar1 * 6 + 1,0x21b);
  if (iVar1 == 0) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
           "_dhcpdef_sqlite_do_insert",0x21e);
    return 0xffffffff;
  }
  uVar2 = dhcpdef_db_get_max_svr_per_ap();
  iVar3 = dhcpdef_db_get_max_svr_per_ap();
  iVar6 = _dhcpdef_sqlite_svrids2str(iVar6,uVar2,iVar1,iVar3 * 6);
  if (iVar6 < 0) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00471718;
    pcVar4 = "\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_svrids2str() fail\x1b[0m\r\n";
    uVar5 = 0x225;
LAB_00471820:
    printf(pcVar4,"dhcp_defend","_dhcpdef_sqlite_do_insert",uVar5);
  }
  else {
    snprintf(pcVar4,0x400,"INSERT INTO %s (%s, %s, %s) VALUES(%d, %d, \'%s\');","bind_tbl","ap_id",
             "enable","svr_ids",local_430,(int)local_428._0_1_,iVar1);
    if (l_db_handle == 0) {
      uVar2 = 0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00471718;
      pcVar4 = "l_db_handle";
      __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
      uVar5 = 0x22d;
    }
    else {
      iVar6 = _dhcpdef_sqlite_exec(l_db_handle,pcVar4);
      if (iVar6 == 0) {
        uVar2 = 0;
        if ((g_dhcpdef_info == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00471718;
        pcVar4 = "[%s]<%s():%d> succeed to insert bind entry in database.\r\n";
        uVar5 = 0x235;
        goto LAB_00471820;
      }
      uVar2 = 0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00471718;
      __format = "\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_exec() fail, cmd=%s\x1b[0m\r\n";
      uVar5 = 0x230;
    }
    uVar2 = 0xffffffff;
    printf(__format,"dhcp_defend","_dhcpdef_sqlite_do_insert",uVar5,pcVar4);
  }
LAB_00471718:
  FUN_00407df0(iVar1);
  return uVar2;
}

