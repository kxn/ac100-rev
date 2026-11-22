// func wsta_roam_db_ap_stats_clear @ 00482780 size=116

undefined4 wsta_roam_db_ap_stats_clear(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = 0xffffffff;
  if ((int)(param_1 & 0xffff) < iVar1) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    memset((void *)(DAT_00767558 + (param_1 & 0xffff) * 0x28),0,0x28);
    FUN_00407f30(l_wsta_roam_data);
    uVar2 = 0;
  }
  return uVar2;
}

