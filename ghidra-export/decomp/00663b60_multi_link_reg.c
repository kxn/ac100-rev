// func multi_link_reg @ 00663b60 size=176

undefined4 multi_link_reg(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  iVar1 = FUN_00408450(0x1c,0xb6);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    memcpy((void *)(iVar1 + 0xc),param_1,0x10);
    iVar3 = FUN_004081b0(&g_multi_link_reg_list);
    if (iVar3 == 0) {
LAB_00663bdc:
      FUN_004086b0(&g_multi_link_reg_list,iVar1);
      uVar2 = 0;
    }
    else {
      cVar4 = *(char *)(iVar3 + 0x10);
      while (*(char *)((int)param_1 + 4) <= cVar4) {
        iVar3 = FUN_00408680();
        if (iVar3 == 0) goto LAB_00663bdc;
        cVar4 = *(char *)(iVar3 + 0x10);
      }
      FUN_00408170(iVar3,iVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

