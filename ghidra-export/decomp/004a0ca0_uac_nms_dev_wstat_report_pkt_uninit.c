// func uac_nms_dev_wstat_report_pkt_uninit @ 004a0ca0 size=108

undefined4 uac_nms_dev_wstat_report_pkt_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = unregister_sub_device_report_handle(_uac_nms_dev_wstat_report_request,3);
  if ((iVar1 == -1) && (uVar2 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d unregister callback to listen join-req capwap message event failed.\n"
           ,"uac_nms_dev_wstat_report_pkt_uninit",0x12d);
  }
  return uVar2;
}

