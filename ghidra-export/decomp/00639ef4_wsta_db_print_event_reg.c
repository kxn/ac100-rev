// func wsta_db_print_event_reg @ 00639ef4 size=1

void wsta_db_print_event_reg(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 3;
  iVar3 = 0;
  do {
    if (iVar3 == 1) {
      puts("######################## WSTA DEASSOC EVENT ##########################");
      puVar2 = &DAT_007cc6f4;
    }
    else if (iVar3 == 2) {
      puts("######################## IP UPDATE EVENT ##########################");
      puVar2 = &DAT_007cc700;
    }
    else {
      puts("######################## WSTA ASSOC EVENT ############################");
      puVar2 = &DAT_007cc6e8;
    }
    for (iVar1 = FUN_004081b0(puVar2); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      printf("name[%s], prio[%d], cb[%p], priv[%p]\n",iVar1 + 0xc,*(undefined4 *)(iVar1 + 0x2c),
             *(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
    }
    iVar4 = iVar4 + -1;
    putchar(10);
    iVar3 = iVar3 + 1;
  } while (iVar4 != 0);
  return;
}

