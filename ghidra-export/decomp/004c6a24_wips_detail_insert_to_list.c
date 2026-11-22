// func wips_detail_insert_to_list @ 004c6a24 size=124

void wips_detail_insert_to_list(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004081b0();
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x24);
    while( true ) {
      if (iVar2 < *(int *)(param_2 + 0x24)) {
        FUN_00408170(iVar1,param_2);
        return;
      }
      iVar1 = FUN_00408680();
      if (iVar1 == 0) break;
      iVar2 = *(int *)(iVar1 + 0x24);
    }
  }
  FUN_004086b0(param_1,param_2);
  return;
}

