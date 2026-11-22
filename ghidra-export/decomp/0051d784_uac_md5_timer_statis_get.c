// func uac_md5_timer_statis_get @ 0051d784 size=276

void uac_md5_timer_statis_get(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = PTR_DAT_007591ac;
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
LAB_0051d7d4:
  do {
    if ((1 << (*(uint *)(puVar1 + 0x2044) & 0x1f)) + -1 + DAT_00783aec <= iVar3) {
      puts("   Waiting\tWorking\tTotal");
      puts("===========================");
      printf("%6d\t%6d\t%6d\n",iVar4,iVar5,iVar4 + iVar5);
      return;
    }
    iVar2 = WHEEL_MD5_TIMER_GET_BY_ID(iVar3);
    if ((*(byte *)(iVar2 + 0x54) & 1) != 0) {
      if ((*(byte *)(iVar2 + 0x54) & 4) == 0) {
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 1;
        goto LAB_0051d7d4;
      }
      iVar5 = iVar5 + 1;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

