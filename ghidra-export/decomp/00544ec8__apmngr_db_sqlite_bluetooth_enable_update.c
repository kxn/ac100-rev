// func _apmngr_db_sqlite_bluetooth_enable_update @ 00544ec8 size=244

undefined4 _apmngr_db_sqlite_bluetooth_enable_update(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  snprintf(acStack_408,0x400,"UPDATE %s SET bluetooth_enable = %d WHERE entry_id = %d;",
           "ApEntryCfg_table",(int)*(char *)(param_1 + 1),(uint)*param_1);
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d msg->bluetooth_enable:%d.\n",
           "_apmngr_db_sqlite_bluetooth_enable_update",0x461,(int)*(char *)(param_1 + 1));
  }
  uVar2 = 0;
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
           "_apmngr_db_sqlite_bluetooth_enable_update",0x464);
  }
  return uVar2;
}

