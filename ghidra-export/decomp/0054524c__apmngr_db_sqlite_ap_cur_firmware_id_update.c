// func _apmngr_db_sqlite_ap_cur_firmware_id_update @ 0054524c size=260

undefined4 _apmngr_db_sqlite_ap_cur_firmware_id_update(ushort *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char acStack_408 [1024];
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d _apmngr_db_sqlite_ap_cur_firmware_id_update ENTER\n",
           "_apmngr_db_sqlite_ap_cur_firmware_id_update",0x444);
  }
  memset(acStack_408,0,0x400);
  if (*(char *)(param_1 + 1) == '\0') {
    pcVar2 = "ApTemplate_table";
  }
  else {
    pcVar2 = "ApEntryCfg_table";
  }
  uVar3 = 0;
  snprintf(acStack_408,0x400,"UPDATE %s SET firmware_id = \'%s\' WHERE entry_id = %d;",pcVar2,
           (int)param_1 + 3,(uint)*param_1);
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_408);
  if (((iVar1 != 0) && (uVar3 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to update entry table.\n",
           "_apmngr_db_sqlite_ap_cur_firmware_id_update",0x451);
  }
  return uVar3;
}

