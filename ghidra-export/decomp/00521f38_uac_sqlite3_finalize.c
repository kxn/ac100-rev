// func uac_sqlite3_finalize @ 00521f38 size=60

undefined4 uac_sqlite3_finalize(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    sqlite3_finalize();
    uVar1 = 0;
  }
  return uVar1;
}

