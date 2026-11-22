// func wsta_roam_db_ap_stats_active @ 004827f4 size=112

undefined4 wsta_roam_db_ap_stats_active(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = 0xffffffff;
  if ((int)(param_1 & 0xffff) < iVar1) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    uVar2 = l_wsta_roam_data;
    *(undefined1 *)(DAT_00767558 + (param_1 & 0xffff) * 0x28) = 1;
    FUN_00407f30(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

