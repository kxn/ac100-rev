// func unset_cloud_mngt_ap_nms_support @ 0049f0a4 size=336

void unset_cloud_mngt_ap_nms_support(uint param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  FUN_004082d0(uac_nms_ap_entry_mutex,0xffffffff);
  if (-1 < (int)param_1) {
    iVar2 = apmngr_db_get_ap_max(uac_nms_ap_entry_mutex);
    iVar3 = apmngr_db_get_template_max();
    if ((((int)param_1 < iVar2 + iVar3) ||
        ((49999 < (int)param_1 &&
         (iVar2 = apmngr_db_get_sensor_max(uac_nms_ap_entry_mutex), (int)param_1 < iVar2 + 50000))))
       && ((param_3 == 1 || (iVar2 = multi_link_status_get(param_1 & 0xffff), iVar2 == 1)))) {
      iVar2 = *(int *)(&g_cloud_mngt_nms_ap_cnt + param_2 * 4);
      if (0 < iVar2) {
        iVar3 = g_cloud_mngt_ap_array + param_1 * 8;
        uVar4 = *(uint *)(iVar3 + 4);
        if (((int)uVar4 >> (param_2 & 0x1f) & 1U) != 0) {
          *(int *)(&g_cloud_mngt_nms_ap_cnt + param_2 * 4) = iVar2 + -1;
          bVar1 = cloud_mngt_debug_switch != '\0';
          *(uint *)(iVar3 + 4) = ~(1 << (param_2 & 0x1f)) & uVar4;
          if (bVar1) {
            printf("[CLOUD_MNGT_DEBUG]%s()/%d ====unset  nms ap:%d\n",
                   "unset_cloud_mngt_ap_nms_support",0x51e,param_1);
          }
        }
      }
    }
  }
  FUN_00407f30(uac_nms_ap_entry_mutex);
  return;
}

