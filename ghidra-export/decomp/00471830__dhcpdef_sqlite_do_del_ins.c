// func _dhcpdef_sqlite_do_del_ins @ 00471830 size=776

int _dhcpdef_sqlite_do_del_ins(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *__format;
  int iVar5;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined1 local_428;
  char acStack_424 [1032];
  
  memset(acStack_424,0,0x400);
  local_438 = 0;
  local_434 = 0;
  iVar5 = (int)param_1 + 0x11;
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  memcpy(&local_438,param_1,0x11);
  local_42c._1_3_ = (undefined3)((uint)iVar5 >> 8);
  local_428 = (undefined1)iVar5;
  iVar1 = dhcpdef_db_get_max_svr_per_ap();
  iVar1 = FUN_00408450(iVar1 * 6 + 1,0x264);
  if (iVar1 == 0) {
    if (g_dhcpdef_error == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
           "_dhcpdef_sqlite_do_del_ins",0x267);
    return -1;
  }
  uVar2 = dhcpdef_db_get_max_svr_per_ap();
  iVar3 = dhcpdef_db_get_max_svr_per_ap();
  iVar5 = _dhcpdef_sqlite_svrids2str(iVar5,uVar2,iVar1,iVar3 * 6);
  uVar2 = local_438;
  if (iVar5 < 0) {
    iVar5 = -1;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> _dhcpdef_sqlite_svrids2str() fail\x1b[0m\r\n","dhcp_defend",
             "_dhcpdef_sqlite_do_del_ins",0x26e);
    }
    goto LAB_00471954;
  }
  if (l_db_handle == 0) {
    iVar5 = -1;
    if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00471954;
    pcVar4 = "l_db_handle";
    __format = "\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n";
    uVar2 = 0x273;
  }
  else {
    snprintf(acStack_424,0x400,"DELETE FROM %s WHERE %s=%d;","bind_tbl","ap_id",local_438);
    pcVar4 = (char *)_dhcpdef_sqlite_exec(l_db_handle,acStack_424);
    if (pcVar4 == (char *)0x0) {
      snprintf(acStack_424,0x400,"INSERT INTO %s (%s, %s, %s) VALUES(%d, %d, \'%s\');","bind_tbl",
               "ap_id","enable","svr_ids",uVar2,(int)local_430._0_1_,iVar1);
      iVar5 = _dhcpdef_sqlite_exec(l_db_handle,acStack_424);
      if (iVar5 != 0) {
        if (g_dhcpdef_error == 0) {
          iVar5 = -1;
        }
        else {
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            iVar5 = -1;
          }
          else {
            printf("\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n","dhcp_defend",
                   "_dhcpdef_sqlite_do_del_ins",0x27d,iVar5,"_dhcpdef_sqlite_exec(l_db_handle, cmd)"
                  );
            iVar5 = -1;
          }
        }
      }
      goto LAB_00471954;
    }
    iVar5 = -1;
    if ((g_dhcpdef_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00471954;
    __format = "\x1b[31;49m[%s]<%s():%d> E - %d call %s failed.\x1b[0m\r\n";
    uVar2 = 0x277;
  }
  iVar5 = -1;
  printf(__format,"dhcp_defend","_dhcpdef_sqlite_do_del_ins",uVar2,pcVar4);
LAB_00471954:
  FUN_00407df0(iVar1);
  return iVar5;
}

