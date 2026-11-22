// func stats_db_bssid_update @ 0066ff64 size=500

undefined4 stats_db_bssid_update(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 uVar6;
  
  if (param_1 == (void *)0x0) {
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d entry is null!\n","stats_db_bssid_update",0x10fe);
      return 0xffffffff;
    }
  }
  else {
    uVar2 = *(ushort *)((int)param_1 + 6);
    iVar3 = apmngr_db_get_ap_max();
    if (((((int)(uint)uVar2 < iVar3) && (bVar1 = *(byte *)((int)param_1 + 8), bVar1 != 0)) &&
        (uVar4 = rdmngr_profile_get_max_rd_per_ap(), bVar1 <= uVar4)) &&
       ((bVar1 = *(byte *)((int)param_1 + 9), bVar1 != 0 &&
        (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), bVar1 <= uVar4)))) {
      FUN_004082d0(l_stats_data,0xffffffff);
      pvVar5 = (void *)FUN_00407fa0(DAT_007cc8f4,param_1);
      if (pvVar5 == (void *)0x0) {
        pvVar5 = (void *)FUN_00408450(10,0x1111);
        if (pvVar5 == (void *)0x0) {
          uVar6 = 2;
          if (stats_warning_switch != '\0') {
            printf("[STATISTICS_WARNING]%s()/%d alloc memory fail!\n","stats_db_bssid_update",0x1114
                  );
          }
        }
        else {
          memcpy(pvVar5,param_1,10);
          uVar6 = 0;
          iVar3 = FUN_00408380(DAT_007cc8f4,pvVar5);
          if (iVar3 != 0) {
            if (stats_err_switch != '\0') {
              printf("[STATISTICS_ERROR]%s()/%d uac_hash_add() failed!\n","stats_db_bssid_update",
                     0x111c);
            }
            FUN_00407df0(pvVar5);
            uVar6 = 0xffffffff;
          }
        }
      }
      else {
        uVar6 = 0;
        memcpy(pvVar5,param_1,10);
      }
      FUN_00407f30(l_stats_data);
      return uVar6;
    }
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_bssid_update",0x1104,
             (uint)*(ushort *)((int)param_1 + 6),(uint)*(byte *)((int)param_1 + 8),
             (uint)*(byte *)((int)param_1 + 9));
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

