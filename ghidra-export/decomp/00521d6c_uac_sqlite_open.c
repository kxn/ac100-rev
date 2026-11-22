// func uac_sqlite_open @ 00521d6c size=460

undefined4 uac_sqlite_open(int param_1,int *param_2,code *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 local_20 [2];
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == (int *)0x0) {
    return 0xffffffff;
  }
  local_20[0] = 0;
  iVar2 = sqlite3_open();
  if (iVar2 == 0) {
    iVar2 = sqlite3_prepare_v2(*param_2,"PRAGMA quick_check;",0xffffffff,local_20,0);
    if (iVar2 == 0) {
      do {
        iVar2 = sqlite3_step(local_20[0]);
        if (iVar2 != 100) {
          bVar1 = true;
          goto LAB_00521ec4;
        }
        pcVar4 = (char *)sqlite3_column_text(local_20[0],0);
      } while ((pcVar4 == (char *)0x0) || (iVar2 = strcmp(pcVar4,"ok"), iVar2 != 0));
      bVar1 = false;
LAB_00521ec4:
      sqlite3_finalize(local_20[0]);
      if (!bVar1) {
        return 0;
      }
    }
    iVar2 = uac_sqlite_err_switch_get();
    if (iVar2 == 0) goto LAB_00521dd8;
    uVar3 = 0x6c;
    pcVar4 = "[UAC_QLITE_ERROR]%s()/line %d : open_db_and_integrity_check() fail, path=%s\n";
  }
  else {
    iVar2 = uac_sqlite_err_switch_get();
    if (iVar2 == 0) goto LAB_00521dd8;
    uVar3 = 0x57;
    pcVar4 = "[UAC_QLITE_ERROR]%s()/line %d : sqlite3_open() fail, path=%s\n";
  }
  printf(pcVar4,"open_db_and_integrity_check",uVar3,param_1);
LAB_00521dd8:
  if (*param_2 != 0) {
    uac_sqlite_close();
    *param_2 = 0;
  }
  if (param_3 != (code *)0x0) {
    (*param_3)();
  }
  iVar2 = del_and_reopen_db(param_1,param_2);
  uVar3 = 0xffffffff;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  return uVar3;
}

