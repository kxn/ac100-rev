// func get_ap_nms_mask @ 0049ee08 size=200

undefined4 get_ap_nms_mask(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= param_1) {
      if (param_1 < 50000) {
        return 0;
      }
      iVar1 = apmngr_db_get_sensor_max();
      if (iVar1 + 50000 <= param_1) {
        return 0;
      }
    }
    if (g_nms_support_switch == 1) {
      FUN_004082d0(uac_nms_ap_entry_mutex,0xffffffff);
      uVar3 = *(undefined4 *)(g_cloud_mngt_ap_array + param_1 * 8 + 4);
      FUN_00407f30(uac_nms_ap_entry_mutex);
      return uVar3;
    }
  }
  return 0;
}

