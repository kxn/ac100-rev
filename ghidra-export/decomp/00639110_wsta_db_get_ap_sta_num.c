// func wsta_db_get_ap_sta_num @ 00639110 size=336

int wsta_db_get_ap_sta_num(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) {
    iVar1 = -1;
    if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n","wsta_db_get_ap_sta_num",0xb36,
             param_1);
    }
  }
  else {
    uVar5 = 1;
    iVar1 = 0;
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    while( true ) {
      uVar3 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar3 < uVar5) break;
      for (uVar3 = 1; uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 <= uVar4;
          uVar3 = uVar3 + 1 & 0xff) {
        iVar1 = iVar1 + *(int *)(*(int *)(*(int *)(DAT_007cc6e4 + param_1 * 4) + (uVar5 - 1) * 4) +
                                 (uVar3 - 1) * 0xc + 8);
      }
      uVar5 = uVar5 + 1 & 0xff;
    }
    FUN_00407f30(DAT_007cc6bc);
  }
  return iVar1;
}

