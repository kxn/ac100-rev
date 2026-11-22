// func balance_db_wtp_array_dump @ 0045e5b4 size=248

void balance_db_wtp_array_dump(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((balance_wtp_array != 0) && (balance_com != (uint *)0x0)) {
    iVar2 = 1;
    uVar1 = 0;
    puts("wtp array used:");
    while (uVar1 < *balance_com) {
      iVar3 = uVar1 * 0x14;
      if (*(int *)(balance_wtp_array + iVar3 + 4) == 1) {
        printf("=====>array index[%d], number[%d]\n",uVar1,iVar2);
        iVar2 = iVar2 + 1;
        uVar1 = uVar1 + 1;
        balance_wtp_entry_dump(balance_wtp_array + iVar3);
      }
      else {
        uVar1 = uVar1 + 1;
      }
    }
  }
  return;
}

