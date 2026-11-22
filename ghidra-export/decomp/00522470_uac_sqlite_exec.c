// func uac_sqlite_exec @ 00522470 size=208

undefined4 uac_sqlite_exec(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = sqlite3_exec();
    uVar1 = 0;
    if (iVar2 != 0) {
      iVar3 = uac_sqlite_err_switch_get();
      if (iVar3 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : result:%d err_msg:%s, cmd:%s failed.\n",
               "uac_sqlite_exec",0xd8,iVar2,&DAT_00688af8,param_2);
      }
      uac_sqlite_free(0);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

