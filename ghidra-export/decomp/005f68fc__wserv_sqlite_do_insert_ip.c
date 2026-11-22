// func _wserv_sqlite_do_insert_ip @ 005f68fc size=308

undefined4 _wserv_sqlite_do_insert_ip(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_850 [64];
  char acStack_810 [2052];
  
  memset(acStack_810,0,0x800);
  memset(auStack_850,0,0x40);
  FUN_00408190(param_1[1],param_1[2],param_1[3],param_1[4],param_1[5],auStack_850,0x40,"---");
  if (*(char *)((int)param_1 + 0x19) == '\x01') {
    pcVar1 = "Led on";
  }
  else {
    pcVar1 = "Led off";
  }
  uVar3 = 0;
  snprintf(acStack_810,0x800,
           "INSERT INTO %s (id,ip_addr,relay,enable) VALUES(\'%d\', \'%s\', \'%d\', \'%s\');",
           "igmp_ip_tbl",*param_1,auStack_850,(uint)*(byte *)(param_1 + 6),pcVar1 + 4);
  iVar2 = FUN_00407d60(l_wserv_ip_handle,acStack_810);
  if (((iVar2 != 0) && (uVar3 = 0xffffffff, g_wserv_error != 0)) &&
     (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[error]%s(): %d  -> uac_sqlite_exec_no_cb() fail, cmd=%s\r\n",
           "_wserv_sqlite_do_insert_ip",800,acStack_810);
  }
  return uVar3;
}

