// func uac_sqlite3_prepare_v2 @ 00521f98 size=132

undefined4 uac_sqlite3_prepare_v2(void)

{
  int iVar1;
  undefined4 in_a3;
  undefined4 uVar2;
  undefined4 in_stack_00000010;
  
  uVar2 = 0;
  iVar1 = sqlite3_prepare_v2();
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
    iVar1 = uac_sqlite_err_switch_get();
    if (iVar1 != 0) {
      printf("[UAC_QLITE_ERROR]%s()/line %d : uac_sqlite3_prepare_v2 fail\n",
             "uac_sqlite3_prepare_v2",0x111,in_a3,in_stack_00000010);
    }
  }
  return uVar2;
}

