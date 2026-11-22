// func wsta_roam_db_print_ap_stats_all @ 004834c0 size=64

void wsta_roam_db_print_ap_stats_all(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    iVar1 = apmngr_db_get_ap_max();
    uVar2 = uVar3 & 0xffff;
    if (iVar1 <= (int)uVar3) break;
    uVar3 = uVar3 + 1;
    wsta_roam_db_print_ap_stats_by_id(uVar2);
  }
  return;
}

