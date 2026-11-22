// func _uac_lldp_pkt_echo_req_listen @ 004a4348 size=212

undefined4 _uac_lldp_pkt_echo_req_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d Get echo request packet.\n","_uac_lldp_pkt_echo_req_listen",
           0x1fd);
  }
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x68);
  if (iVar1 != 0) {
    uVar2 = _uac_lldp_request(iVar1,param_1,param_2,param_3);
    return uVar2;
  }
  if (uac_lldp_debug_switch != '\0') {
    printf("[UAC_LLDP_DEBUG]%s()/%d Get echo request packet.\n","_uac_lldp_pkt_echo_req_listen",
           0x201);
  }
  return 0;
}

