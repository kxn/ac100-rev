// func _apmngr_db_sqlite_template_insert @ 00545dc0 size=152

undefined4 _apmngr_db_sqlite_template_insert(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_408 [1024];
  
  memset(auStack_408,0,0x400);
  _apmngr_template_cfg_insert_sql_gene(auStack_408,0x400,param_1);
  uVar2 = 0;
  iVar1 = FUN_00407d60(g_apmngr_db,auStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to insert to template-entry table.\n",
           "_apmngr_db_sqlite_template_insert",0x225);
  }
  return uVar2;
}

