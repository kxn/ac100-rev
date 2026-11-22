// func cloud_mngt_ap_is_nms_spupport @ 0049e9d0 size=208

uint cloud_mngt_ap_is_nms_spupport(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((param_2 < 0x20) && (-1 < param_1)) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      FUN_004082d0(uac_nms_ap_entry_mutex,0xffffffff);
      iVar1 = *(int *)(g_cloud_mngt_ap_array + param_1 * 8 + 4);
      FUN_00407f30(uac_nms_ap_entry_mutex);
      uVar3 = iVar1 >> (param_2 & 0x1f) & 1;
    }
  }
  return uVar3;
}

