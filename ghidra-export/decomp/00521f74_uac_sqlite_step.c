// func uac_sqlite_step @ 00521f74 size=36

undefined4 uac_sqlite_step(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = sqlite3_step();
    return uVar1;
  }
  return 0xffffffff;
}

