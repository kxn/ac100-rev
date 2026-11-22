// func wsta_db_free_ap_sta @ 0063c4fc size=228

uint wsta_db_free_ap_sta(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= param_1)) {
    uVar4 = 0xffffffff;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n","wsta_db_free_ap_sta",0xa81,
             param_1);
    }
  }
  else {
    uVar4 = 0;
    for (uVar3 = 1; uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar3 <= uVar2;
        uVar3 = uVar3 + 1 & 0xff) {
      uVar2 = wsta_db_free_rd_sta(param_1,uVar3,param_2,param_3);
      uVar4 = uVar4 | uVar2;
    }
  }
  return uVar4;
}

