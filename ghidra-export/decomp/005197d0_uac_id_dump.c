// func uac_id_dump @ 005197d0 size=364

void uac_id_dump(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    puts("=======================ID dump==============================");
    printf("put=%d,get=%d,allocated=%d\n",param_1[3],param_1[2],param_1[5]);
    printf("bitmap: ");
    for (uVar1 = 0; uVar1 < param_1[4] + 0x1fU >> 5; uVar1 = uVar1 + 1) {
      printf("0x%x ",*(undefined4 *)(param_1[1] + uVar1 * 4));
    }
    putchar(10);
    printf("array data: ");
    for (iVar2 = 0; iVar2 < param_1[4]; iVar2 = iVar2 + 1) {
      printf("%d ",*(undefined4 *)(*param_1 + iVar2 * 4));
    }
    putchar(10);
    puts("=======================Dump End=============================\n");
    return;
  }
  return;
}

