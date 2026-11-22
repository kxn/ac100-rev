// func uac_md5_timer_print @ 0051d898 size=336

void uac_md5_timer_print(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  uac_mutex_take(g_wheel_md5_timer_base,0xffffffff);
  puVar1 = PTR_DAT_007591ac;
  printf("Pre alloc: %d\tExtend alloc:%d\n",
         (1 << (*(uint *)(PTR_DAT_007591ac + 0x2044) & 0x1f)) + -1,DAT_00783aec);
  puts("============timer list===============");
  while (iVar4 < (1 << (*(uint *)(puVar1 + 0x2044) & 0x1f)) + -1 + DAT_00783aec) {
    iVar2 = WHEEL_MD5_TIMER_GET_BY_ID(iVar4);
    if ((*(byte *)(iVar2 + 0x54) & 1) == 0) {
      iVar4 = iVar4 + 1;
    }
    else {
      uVar3 = *(uint *)(iVar2 + 0xc);
      iVar4 = iVar4 + 1;
      printf("Timer<%d>: id=<%d>, seq=<%d>, interval=<%lu ms>, bit:%d\n",uVar3,uVar3 & 0xfffff,
             uVar3 >> 0x14,*(int *)(iVar2 + 0x58) * 500,(uint)*(byte *)(iVar2 + 0x54));
    }
  }
  uac_mutex_give(g_wheel_md5_timer_base);
  return;
}

