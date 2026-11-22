// func FUN_004c7c60 @ 004c7c60 size=212

void FUN_004c7c60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_004081b0(&g_wips_list);
  while( true ) {
    if (iVar1 == 0) {
      FUN_004086b0(&g_wips_list,param_1);
      return;
    }
    iVar4 = -1;
    iVar2 = FUN_004081b0(iVar1 + 0x9c);
    if (iVar2 != 0) {
      iVar4 = *(int *)(iVar2 + 0x24);
    }
    iVar2 = FUN_004081b0(param_1 + 0x9c);
    iVar3 = -1;
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0x24);
    }
    if (iVar4 < iVar3) break;
    iVar1 = FUN_00408680();
  }
  FUN_00408170(iVar1,param_1);
  return;
}

