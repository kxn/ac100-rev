// func wsta_db_print_list @ 00639e3c size=1

void wsta_db_print_list(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  puts("\n");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  if (param_1 != 0) {
    for (iVar2 = FUN_004081b0(&DAT_007cc6d8); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      wsta_db_print_entry(iVar2 + -0xc);
    }
  }
  uVar1 = FUN_00407fe0(&DAT_007cc6d8);
  printf("total num: %d\n",uVar1);
  uac_mutex_give(DAT_007cc6bc);
  return;
}

