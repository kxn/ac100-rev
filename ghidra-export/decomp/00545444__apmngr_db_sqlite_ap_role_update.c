// func _apmngr_db_sqlite_ap_role_update @ 00545444 size=352

undefined4 _apmngr_db_sqlite_ap_role_update(ushort *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  char acStack_410 [1024];
  
  memset(acStack_410,0,0x400);
  uVar1 = param_1[5];
  uVar2 = apmngr_db_role_str(*(undefined4 *)(param_1 + 2));
  snprintf(acStack_410,0x400,"UPDATE %s SET group_id = \'%d\',ap_role = \'%s\' WHERE entry_id = %d;"
           ,"ApEntryRun_table",(uint)uVar1,uVar2,(uint)*param_1);
  iVar3 = FUN_00407d60(DAT_007c58e8,acStack_410);
  if (iVar3 == 0) {
    uVar1 = param_1[5];
    uVar2 = apmngr_db_role_str(*(undefined4 *)(param_1 + 2));
    snprintf(acStack_410,0x400,
             "UPDATE %s SET group_id = \'%d\',ap_role = \'%s\', cap_id = \'%d\' WHERE entry_id = %d;"
             ,"ApEntryCfg_table",(uint)uVar1,uVar2,(uint)param_1[4],(uint)*param_1);
    iVar3 = FUN_00407d60(g_apmngr_db,acStack_410);
    if (iVar3 == 0) {
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x2b2;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar2 = 0x2a5;
  }
  printf("[APMNGR_ERROR]%s()/%d Failed to update AP-entry table.\n",
         "_apmngr_db_sqlite_ap_role_update",uVar2);
  return 0xffffffff;
}

