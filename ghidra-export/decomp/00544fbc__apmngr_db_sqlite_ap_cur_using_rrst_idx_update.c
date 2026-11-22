// func _apmngr_db_sqlite_ap_cur_using_rrst_idx_update @ 00544fbc size=328

undefined4 _apmngr_db_sqlite_ap_cur_using_rrst_idx_update(ushort *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char acStack_410 [1028];
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d _apmngr_db_sqlite_ap_cur_using_rrst_idx_update ENTER\n",
           "_apmngr_db_sqlite_ap_cur_using_rrst_idx_update",0x42d);
  }
  memset(acStack_410,0,0x400);
  if (*(char *)(param_1 + 1) == '\0') {
    pcVar2 = "ApTemplate_table";
  }
  else {
    pcVar2 = "ApEntryCfg_table";
  }
  snprintf(acStack_410,0x400,"UPDATE %s SET radio_role_table_idx = %d WHERE entry_id = %d;",pcVar2,
           (uint)*(byte *)((int)param_1 + 3),(uint)*param_1);
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d msg->type=%d\n","_apmngr_db_sqlite_ap_cur_using_rrst_idx_update",
           0x436,(uint)*(byte *)(param_1 + 1));
  }
  uVar3 = 0;
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_410);
  if (((iVar1 != 0) && (uVar3 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to update entry table.\n",
           "_apmngr_db_sqlite_ap_cur_using_rrst_idx_update",0x43b);
  }
  return uVar3;
}

