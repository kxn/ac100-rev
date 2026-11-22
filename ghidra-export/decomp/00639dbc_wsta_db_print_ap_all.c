// func wsta_db_print_ap_all @ 00639dbc size=128

void wsta_db_print_ap_all(void)

{
  int iVar1;
  int iVar2;
  
  puts("\n");
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  for (iVar2 = 0; iVar1 = apmngr_db_get_ap_max(), iVar2 < iVar1; iVar2 = iVar2 + 1) {
    wsta_db_print_ap_entry(DAT_007cc6e4 + iVar2 * 4,iVar2);
  }
  FUN_00407f30(DAT_007cc6bc);
  return;
}

