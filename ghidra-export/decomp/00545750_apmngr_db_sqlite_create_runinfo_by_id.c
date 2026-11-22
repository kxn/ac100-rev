// func apmngr_db_sqlite_create_runinfo_by_id @ 00545750 size=236

undefined4
apmngr_db_sqlite_create_runinfo_by_id(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  uVar2 = 0;
  snprintf(acStack_408,0x400,
           "INSERT OR IGNORE INTO ApEntryRun_table (%s, %s, %s, %s, %s) VALUES(%s, %s, \'%s\', 1, 0);"
           ,"entry_id","group_id","ap_role",&DAT_006cb294,"status",*param_3,param_3[1],param_3[2]);
  iVar1 = FUN_00407d60(DAT_007c58e8,acStack_408);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to create a runinfo entry.\n",
           "apmngr_db_sqlite_create_runinfo_by_id",0x549);
  }
  return uVar2;
}

