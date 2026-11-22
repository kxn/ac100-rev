// func _stats_pkt_wtp_event_listener @ 006740f0 size=340

undefined4 _stats_pkt_wtp_event_listener(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  
  uVar2 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  stats_db_ctl_get(&local_28);
  if ((local_28._0_1_ != '\0') &&
     (iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x52), iVar1 != 0)) {
    uVar2 = _stats_pkt_sta_request(iVar1,param_1,param_2,param_3);
  }
  if ((local_28._0_1_ != '\0') &&
     (iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x56), iVar1 != 0)) {
    uVar2 = _stats_pkt_fail_sta_request(iVar1,param_1,param_2,param_3);
  }
  if ((local_28._2_1_ != '\0') &&
     (iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x54), iVar1 != 0)) {
    uVar2 = _stats_pkt_ap_request(iVar1,param_1,param_2,param_3);
  }
  if ((local_28._1_1_ != '\0') &&
     (iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x53), iVar1 != 0)) {
    uVar2 = _stats_pkt_rssi_request(iVar1,param_1,param_2,param_3);
  }
  if (stats_debug_switch != '\0') {
    printf("[STATISTICS_DEBUG]%s()/%d _stats_pkt_wtp_event_listener() finish.\n",
           "_stats_pkt_wtp_event_listener",0x18d);
  }
  return uVar2;
}

