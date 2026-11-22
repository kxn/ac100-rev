// func _audit_client_pkt_wtp_event_listener @ 0050aab8 size=124

undefined4
_audit_client_pkt_wtp_event_listener(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = audit_client_db_is_server_enable();
  if ((iVar1 != 0) && (iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x6e), iVar1 != 0)) {
    uVar2 = _audit_client_sniffing_statistics_request(iVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 0;
}

