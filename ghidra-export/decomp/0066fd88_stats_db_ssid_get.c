// func stats_db_ssid_get @ 0066fd88 size=476

uint stats_db_ssid_get(uint param_1,uint param_2,uint param_3,void *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  void *__src;
  
  param_1 = param_1 & 0xffff;
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xff;
  if (param_4 == (void *)0x0) {
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ssid_get",0x105e);
      return 0xffffffff;
    }
  }
  else {
    iVar2 = apmngr_db_get_ap_max();
    if (((((int)param_1 < iVar2) && (param_2 != 0)) &&
        (uVar3 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar3)) &&
       ((param_3 != 0 && (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), param_3 <= uVar3)))) {
      FUN_004082d0(l_stats_data,0xffffffff);
      iVar2 = *(int *)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + (param_2 - 1) * 8 + 4);
      if (iVar2 == 0) {
        if (stats_warning_switch != '\0') {
          printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_get",0x106c,
                 param_1,param_2,param_3);
        }
        FUN_00407f30(l_stats_data);
        return 0xffffffff;
      }
      __src = (void *)(*(int *)(iVar2 + 0x160) + (param_3 - 1) * 0x100);
      bVar1 = (*(byte *)((int)__src + 8) & 2) != 0;
      if (bVar1) {
        memcpy(param_4,__src,0x100);
      }
      FUN_00407f30(l_stats_data);
      return (uint)!bVar1;
    }
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_ssid_get",0x1064,
             param_1,param_2,param_3);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

