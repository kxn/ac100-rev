// func _wsta_roam_pkt_wtp_event_listener @ 00489380 size=228

undefined4
_wsta_roam_pkt_wtp_event_listener(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x49);
  if (iVar1 != 0) {
    uVar2 = _wsta_roam_pkt_pmk_request(iVar1,param_1,param_2,param_3);
  }
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x58);
  if (iVar1 != 0) {
    uVar2 = _wsta_roam_pkt_roaming_trigger_request(iVar1,param_1,param_2,param_3);
  }
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x9c);
  if (iVar1 != 0) {
    uVar2 = _wsta_roam_pkt_chnl_scan_report(iVar1,param_1,param_2,param_3);
  }
  if (wsta_roam_debug_switch != '\0') {
    printf("[WSTA_ROAM_DEBUG]%s()/%d _wsta_roam_pkt_wtp_event_listener() finish.\n",
           "_wsta_roam_pkt_wtp_event_listener",0x976);
  }
  return uVar2;
}

