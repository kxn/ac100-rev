// func _rrm_pkt_wtp_event_listener @ 004ae470 size=108

void _rrm_pkt_wtp_event_listener(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x5d);
  if (iVar1 != 0) {
    _rrm_pkt_rssi_request(iVar1,param_1,param_2,param_3);
    return;
  }
  return;
}

