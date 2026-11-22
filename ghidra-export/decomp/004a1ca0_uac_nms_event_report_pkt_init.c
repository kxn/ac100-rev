// func uac_nms_event_report_pkt_init @ 004a1ca0 size=108

undefined4 uac_nms_event_report_pkt_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = register_sub_device_report_handle(_uac_nms_event_report_request,1);
  if ((iVar1 == -1) && (uVar2 = 0xffffffff, cloud_mngt_err_switch != '\0')) {
    printf("[CLOUD_MNGT_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n"
           ,"uac_nms_event_report_pkt_init",0x131);
  }
  return uVar2;
}

