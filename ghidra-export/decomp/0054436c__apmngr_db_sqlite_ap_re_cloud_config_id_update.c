// func _apmngr_db_sqlite_ap_re_cloud_config_id_update @ 0054436c size=180

undefined4 _apmngr_db_sqlite_ap_re_cloud_config_id_update(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  uVar2 = 0;
  snprintf(acStack_408,0x400,"UPDATE %s SET cloud_config_id = \'%s\' WHERE entry_id = %d;",
           "ApEntryCfg_table",param_1 + 0x191,(uint)*(ushort *)(param_1 + 8));
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to update AP-entry table when update re data\n",
           "_apmngr_db_sqlite_ap_re_cloud_config_id_update",0x293);
  }
  return uVar2;
}

