// func wsta_db_free_rd_sta @ 0063c3ac size=336

uint wsta_db_free_rd_sta(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  
  param_2 = param_2 & 0xff;
  if (((int)param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= (int)param_1)) {
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
      uVar4 = 0xa5e;
      param_2 = param_1;
      goto LAB_0063c490;
    }
  }
  else {
    if ((param_2 != 0) && (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
      uVar2 = 0;
      for (uVar5 = 1; uVar3 = rdmngr_profile_get_max_wlan_per_rd(), uVar5 <= uVar3;
          uVar5 = uVar5 + 1 & 0xff) {
        uVar3 = wsta_db_free_wlan_sta(param_1,param_2,uVar5,param_3,param_4);
        uVar2 = uVar2 | uVar3;
      }
      return uVar2;
    }
    if (g_wsta_warning != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
      uVar4 = 0xa63;
LAB_0063c490:
      printf(__format,"wsta_db_free_rd_sta",uVar4,param_2);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

