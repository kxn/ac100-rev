// func _apmngr_db_sqlite_ap_run_state_update @ 00544a14 size=208

undefined4 _apmngr_db_sqlite_ap_run_state_update(ushort *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  if (*(int *)(param_1 + 2) == 0) {
    pcVar1 = ", software_ver = NULL ";
  }
  else {
    pcVar1 = "";
  }
  uVar3 = 0;
  snprintf(acStack_408,0x400,"UPDATE %s SET status = %d %s WHERE entry_id = %d;","ApEntryRun_table",
           *(int *)(param_1 + 2),pcVar1,(uint)*param_1);
  iVar2 = FUN_00407d60(DAT_007c58e8,acStack_408);
  if (((iVar2 != 0) && (uVar3 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
           "_apmngr_db_sqlite_ap_run_state_update",0x375);
  }
  return uVar3;
}

