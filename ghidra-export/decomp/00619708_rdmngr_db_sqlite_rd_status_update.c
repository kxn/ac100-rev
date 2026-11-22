// func rdmngr_db_sqlite_rd_status_update @ 00619708 size=408

undefined4 rdmngr_db_sqlite_rd_status_update(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char acStack_610 [1536];
  
  memset(acStack_610,0,0x600);
  iVar2 = g_rdmngr_db_ptr;
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d Wrong value, failed to update rd table in memory.\n",
             "rdmngr_db_sqlite_rd_status_update",0x32a);
    }
  }
  else {
    if (g_rdmngr_db_ptr == 0) {
      iVar2 = -1;
      if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[RDMNGR_ERROR]%s()/%d open db failed.\n","rdmngr_db_sqlite_rd_status_update",0x330);
      }
    }
    else {
      if (param_1[1] == 0) {
        pcVar1 = "Led off";
      }
      else {
        pcVar1 = "Led on";
      }
      snprintf(acStack_610,0x600,"UPDATE %s SET %s = \'%s\' WHERE %s = \'%d\';","rdmngrTable",
               "rf_state",pcVar1 + 4,"rf_id",*param_1);
      iVar2 = FUN_00407d60(iVar2,acStack_610);
      if ((iVar2 != 0) && (iVar4 = FUN_00408410(), iVar4 != 0)) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "rdmngr_db_sqlite_rd_status_update",0x33c,iVar2,acStack_610,
               "Failed to update rd table in memory.");
      }
    }
    FUN_00407df0(param_1);
    uVar3 = 0xffffffff;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

