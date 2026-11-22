// func del_and_reopen_db @ 00521c28 size=264

int del_and_reopen_db(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char acStack_110 [256];
  
  iVar2 = 1;
  memset(acStack_110,0,0x100);
  if (param_1 != 0) {
    memset(acStack_110,0,0x100);
    snprintf(acStack_110,0x100,"rm -rf %s",param_1);
    system(acStack_110);
    iVar2 = sqlite3_open(param_1,param_2);
    if (iVar2 != 0) {
      iVar2 = 1;
      iVar1 = uac_sqlite_err_switch_get();
      if (iVar1 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : sqlite3_open() fail, path=%s\n","del_and_reopen_db",
               0x41,param_1);
      }
    }
  }
  return iVar2;
}

