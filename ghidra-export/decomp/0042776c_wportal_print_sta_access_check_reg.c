// func wportal_print_sta_access_check_reg @ 0042776c size=1

void wportal_print_sta_access_check_reg(void)

{
  int iVar1;
  undefined4 uVar2;
  
  puts("####################### WSTA ASSOC CHECK EVENT ########################");
  iVar1 = FUN_004081b0(&l_wportal_sta_access_check_reg);
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x2c);
    while( true ) {
      printf("name[%s], prio[%d], cb[%p], priv[%p]\n",iVar1 + 0xc,uVar2,
             *(undefined4 *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x34));
      iVar1 = FUN_00408680(iVar1);
      if (iVar1 == 0) break;
      uVar2 = *(undefined4 *)(iVar1 + 0x2c);
    }
  }
  putchar(10);
  return;
}

