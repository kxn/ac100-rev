// func wsta_db_print_tmp_list @ 00639b58 size=184

void wsta_db_print_tmp_list(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  puts("\n");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  if (param_1 != 0) {
    for (iVar2 = FUN_004081b0(&DAT_007cc71c); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      wsta_db_print_entry(iVar2 + -0xc);
    }
  }
  uVar1 = FUN_00407fe0(&DAT_007cc71c);
  printf("total num: %d\n",uVar1);
  FUN_00407f30(DAT_007cc6bc);
  return;
}

