// func stats_db_print_ap_all @ 00672930 size=152

void stats_db_print_ap_all(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  FUN_004082d0(l_stats_data,0xffffffff);
  while( true ) {
    iVar1 = apmngr_db_get_ap_max();
    if (iVar1 <= (int)uVar2) break;
    if ((*(byte *)(DAT_007cc8ec + uVar2 * 0x1e0) & 3) == 0) {
      uVar2 = uVar2 + 1 & 0xffff;
    }
    else {
      _stats_db_print_ap_by_id(uVar2,0);
      uVar2 = uVar2 + 1 & 0xffff;
    }
  }
  FUN_00407f30(l_stats_data);
  return;
}

