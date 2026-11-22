// func set_cloud_mngt_ap_nms_spupport @ 0049eed0 size=468

undefined4 set_cloud_mngt_ap_nms_spupport(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_300 [20];
  int local_2ec;
  int local_ac;
  
  uVar3 = 0xffffffff;
  memset(auStack_300,0,0x2d8);
  if (-1 < (int)param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (((int)param_1 < iVar1 + iVar2) ||
       ((49999 < (int)param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000))
       )) {
      memset(auStack_300,0,0x2d8);
      iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_300);
      uVar3 = 0xffffffff;
      if (iVar1 != -1) {
        uVar3 = 0xffffffff;
        FUN_004082d0(uac_nms_ap_entry_mutex,0xffffffff);
        if (((((*(int *)(g_cloud_mngt_ap_array + param_1 * 8 + 4) >> (param_2 & 0x1f) & 1U) == 0) &&
             (*(int *)(&g_cloud_mngt_nms_ap_cnt + param_2 * 4) < g_nms_aps_support_cnt)) &&
            (local_ac << 0xe < 0)) && (local_2ec != 7)) {
          if (cloud_mngt_debug_switch != '\0') {
            printf("[CLOUD_MNGT_DEBUG]%s()/%d ====set as nms ap:%d\n",
                   "set_cloud_mngt_ap_nms_spupport",0x508,param_1);
          }
          uVar3 = 0;
          iVar1 = g_cloud_mngt_ap_array + param_1 * 8;
          *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 1 << (param_2 & 0x1f);
          *(int *)(&g_cloud_mngt_nms_ap_cnt + param_2 * 4) =
               *(int *)(&g_cloud_mngt_nms_ap_cnt + param_2 * 4) + 1;
        }
        FUN_00407f30(uac_nms_ap_entry_mutex);
      }
    }
  }
  return uVar3;
}

