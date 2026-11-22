// func _apmngr_db_sqlite_set_errno @ 005472e8 size=180

undefined4 _apmngr_db_sqlite_set_errno(ushort *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  uVar2 = 0;
  snprintf(acStack_408,0x400,"UPDATE %s SET errno = %d WHERE entry_id = %d;","ApEntryRun_table",
           *(undefined4 *)(param_1 + 2),(uint)*param_1);
  iVar1 = FUN_00407d60(DAT_007c58e8,acStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
           "_apmngr_db_sqlite_set_errno",0x361);
  }
  return uVar2;
}

