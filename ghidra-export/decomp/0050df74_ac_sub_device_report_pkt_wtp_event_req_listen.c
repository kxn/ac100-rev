// func ac_sub_device_report_pkt_wtp_event_req_listen @ 0050df74 size=148

undefined4 ac_sub_device_report_pkt_wtp_event_req_listen(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x80);
  if (iVar1 == 0) {
    iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x83);
    if (iVar1 == 0) {
      iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xa5);
      if (iVar1 != 0) {
        tdcp_handle_from_ap(iVar1,param_1,param_2);
      }
    }
    else {
      FUN_0050d4ec(iVar1,param_2);
    }
  }
  else {
    FUN_0050c0e0(iVar1,param_2);
  }
  return 0;
}

