// func _apmngr_db_sqlite_template_delete @ 00544cc0 size=168

undefined4 _apmngr_db_sqlite_template_delete(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  uVar2 = 0;
  snprintf(acStack_408,0x400,"DELETE FROM %s WHERE entry_id = %d;","ApTemplate_table",param_1);
  iVar1 = FUN_00407d60(g_apmngr_db,acStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to delete template.\n","_apmngr_db_sqlite_template_delete",
           0x10a);
  }
  return uVar2;
}

