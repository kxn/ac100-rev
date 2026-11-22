// func uac_nms_report_get_fit_ap_nms_support @ 0049e30c size=136

undefined4 uac_nms_report_get_fit_ap_nms_support(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [40];
  
  uVar2 = 0;
  memcpy(auStack_30,&DAT_0069ca20,0x24);
  iVar1 = FUN_00408120("intelligent_ops_data_report","apmng_set",auStack_30,1);
  if ((iVar1 != 0) && (uVar2 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d uci req parse failed.\n",
           "uac_nms_report_get_fit_ap_nms_support",0x41a);
  }
  return uVar2;
}

