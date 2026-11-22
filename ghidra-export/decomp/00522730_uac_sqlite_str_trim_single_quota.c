// func uac_sqlite_str_trim_single_quota @ 00522730 size=252

undefined4 uac_sqlite_str_trim_single_quota(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  iVar1 = 0;
  iVar2 = 0;
  while( true ) {
    while( true ) {
      if (param_2 <= iVar2) {
        return 0;
      }
      pcVar4 = (char *)(param_1 + iVar2);
      if (*pcVar4 == '\'') break;
      if (param_4 <= iVar1) {
        iVar1 = uac_sqlite_err_switch_get();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        uVar3 = 0x1ba;
        goto LAB_005227f0;
      }
      pcVar6 = (char *)(param_3 + iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 1;
      *pcVar6 = *pcVar4;
    }
    if (param_4 + -1 <= iVar1) break;
    puVar5 = (undefined1 *)(param_3 + iVar1);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 2;
    *puVar5 = 0x27;
    puVar5[1] = 0x27;
  }
  iVar1 = uac_sqlite_err_switch_get();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  uVar3 = 0x1af;
LAB_005227f0:
  printf("[UAC_QLITE_ERROR]%s()/line %d : out of range db_str_size.\n",
         "uac_sqlite_str_trim_single_quota",uVar3);
  return 0xffffffff;
}

