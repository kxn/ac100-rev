// func apmngr_sql_show_callback @ 00543f1c size=1

undefined4 apmngr_sql_show_callback(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    if (iVar2 < 1) {
      uVar1 = *param_3;
    }
    else {
      putchar(0x7c);
      uVar1 = *param_3;
    }
    param_3 = param_3 + 1;
    printf("%s",uVar1);
  }
  putchar(10);
  return 0;
}

