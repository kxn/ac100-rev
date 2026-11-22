// func uac_sqlite_free @ 0052201c size=60

undefined4 uac_sqlite_free(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    sqlite3_free();
    uVar1 = 0;
  }
  return uVar1;
}

