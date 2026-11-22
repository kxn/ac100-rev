// func cloud_mngt_nms_spupport_ap_cnt @ 0049e964 size=108

undefined4 cloud_mngt_nms_spupport_ap_cnt(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x20) {
    FUN_004082d0(uac_nms_ap_entry_mutex,0xffffffff);
    uVar1 = *(undefined4 *)(&g_cloud_mngt_nms_ap_cnt + param_1 * 4);
    FUN_00407f30(uac_nms_ap_entry_mutex);
  }
  return uVar1;
}

