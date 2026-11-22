// func stats_db_radio_get_total @ 0066f360 size=416

undefined4 stats_db_radio_get_total(uint param_1,uint param_2,void *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  byte *__src;
  undefined4 uVar3;
  int iVar4;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (param_2 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    if (param_3 != (void *)0x0) {
      iVar1 = rdmngr_profile_get_max_wlan_per_rd();
      iVar4 = (param_2 - 1) * 8;
      FUN_004082d0(l_stats_data,0xffffffff);
      __src = *(byte **)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar4 + 4);
      uVar3 = 1;
      if ((__src != (byte *)0x0) && (((*__src & 2) != 0 || (param_4 == 1)))) {
        memcpy(param_3,__src,0x160);
        uVar3 = 0;
        if (*(void **)((int)param_3 + 0x160) != (void *)0x0) {
          memcpy(*(void **)((int)param_3 + 0x160),
                 *(void **)(*(int *)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar4 + 4) +
                           0x160),iVar1 << 8);
        }
      }
      FUN_00407f30(l_stats_data);
      return uVar3;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_radio_get_total",0xef9);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_get_total",0xef3,
           param_1,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

