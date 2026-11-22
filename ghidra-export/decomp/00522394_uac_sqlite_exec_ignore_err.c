// func uac_sqlite_exec_ignore_err @ 00522394 size=192

undefined4 uac_sqlite_exec_ignore_err(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = sqlite3_exec();
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = uac_sqlite_dbg_switch_get();
      if (iVar1 != 0) {
        printf("[UAC_SQLITE_DEBUG]%s()/line %d : err_msg:%s, cmd:%s failed.\n",
               "uac_sqlite_exec_ignore_err",0xec,&DAT_00688af8,param_2);
      }
      uac_sqlite_free(0);
      uVar2 = 0;
    }
  }
  return uVar2;
}

