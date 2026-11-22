// func wserv_db_print_event_reg @ 005f58e4 size=1

void wserv_db_print_event_reg(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 6;
  iVar3 = 0;
  do {
    switch(iVar3) {
    case 0:
      puts("######################## WSERV BIND EVENT ############################");
      puVar2 = &DAT_007cbf18;
      break;
    case 1:
      puts("######################## WSERV UNBIND EVENT ##########################");
      puVar2 = &DAT_007cbf24;
      break;
    case 2:
      puts("######################## WSERV ENABLE EVENT ##########################");
      puVar2 = &DAT_007cbf30;
      break;
    case 3:
      puts("######################## WSERV DISABLE EVENT #########################");
      puVar2 = &DAT_007cbf3c;
      break;
    case 4:
      puts("######################## WSERV DELETE EVENT #########################");
      puVar2 = &DAT_007cbf48;
      break;
    default:
      goto LAB_005f5944;
    }
    for (iVar1 = FUN_004081b0(puVar2); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
      printf("name[%s], prio[%d], cb[%p], priv[%p]\n",iVar1 + 0xc,*(undefined4 *)(iVar1 + 0x2c),
             *(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
    }
    iVar4 = iVar4 + -1;
    putchar(10);
    iVar3 = iVar3 + 1;
  } while (iVar4 != 0);
LAB_005f5944:
  return;
}

