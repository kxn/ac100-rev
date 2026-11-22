// func uac_sqlite_delete_int32_key_in_db @ 005226ec size=68

undefined4 uac_sqlite_delete_int32_key_in_db(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _delete_int32_key_in_db();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

