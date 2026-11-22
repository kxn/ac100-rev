// func wsta_print_mem_record @ 0063a208 size=288

void wsta_print_mem_record(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  if (param_1 != 0) {
    iVar2 = FUN_004081b0(&wsta_mem_record);
    while (iVar2 != 0) {
      iVar3 = FUN_00408680(iVar2);
      puts("##################################");
      printf("func   [%s]\n",iVar2 + 0x14);
      printf("line   [%d]\n",*(undefined4 *)(iVar2 + 0x54));
      printf("ptr    [%p]\n",*(undefined4 *)(iVar2 + 0xc));
      printf("size   [%d]\n",*(undefined4 *)(iVar2 + 0x10));
      iVar2 = iVar3;
    }
  }
  uVar1 = FUN_00407fe0(&wsta_mem_record);
  printf("mem_record_num=%d\n",uVar1);
  FUN_00407f30(DAT_007cc6bc);
  return;
}

