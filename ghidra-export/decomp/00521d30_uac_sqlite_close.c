// func uac_sqlite_close @ 00521d30 size=60

undefined4 uac_sqlite_close(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    sqlite3_close();
    uVar1 = 0;
  }
  return uVar1;
}

