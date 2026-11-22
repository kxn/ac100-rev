// func rrm_callback_register @ 004b00b4 size=168

undefined4 rrm_callback_register(void *param_1)

{
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  __dest = (void *)FUN_00408450(0x1c,0xbbe);
  uVar1 = 0xffffffff;
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_1,0x1c);
    iVar2 = FUN_004081b0(&g_rrm_cb_list);
    if (iVar2 == 0) {
LAB_004b012c:
      FUN_004086b0(&g_rrm_cb_list,__dest);
      uVar1 = 0;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x18);
      while (*(int *)((int)__dest + 0x18) <= iVar3) {
        iVar2 = FUN_00408680();
        if (iVar2 == 0) goto LAB_004b012c;
        iVar3 = *(int *)(iVar2 + 0x18);
      }
      FUN_00408170(iVar2,__dest);
      uVar1 = 0;
    }
  }
  return uVar1;
}

