// func _apmngr_db_sqlite_ap_update @ 0054635c size=200

undefined4 _apmngr_db_sqlite_ap_update(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_410 [1028];
  
  memset(auStack_410,0,0x400);
  uVar3 = (uint)(param_1[1] == 0);
  if (*param_1 != 0) {
    uVar3 = 0;
  }
  uVar2 = 0;
  _apmngr_ap_cfg_update_sql_gene
            (auStack_410,0x400,*param_1,param_1[1],*(undefined2 *)(param_1 + 2),param_1 + 3);
  iVar1 = FUN_00407d60((&g_apmngr_db)[uVar3],auStack_410);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to update to AP-entry table.\n",
           "_apmngr_db_sqlite_ap_update",0x234);
  }
  return uVar2;
}

