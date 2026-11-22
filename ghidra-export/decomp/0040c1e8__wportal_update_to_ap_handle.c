// func _wportal_update_to_ap_handle @ 0040c1e8 size=292

undefined4
_wportal_update_to_ap_handle
          (undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_40 = 0;
  local_3c = 0;
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 != 0) {
    FUN_0051ad88(&local_30);
    local_40 = CONCAT22(param_2,local_40._2_2_);
    local_3c = param_1;
    iVar2 = cw_parsed_pkt_create(7);
    if (((iVar2 != 0) &&
        (iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x2a,&local_40), iVar3 != -1)) &&
       (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
      serv_packet_send(param_3,iVar1,param_4);
      cw_parsed_pkt_destroy(iVar2);
      cw_pkt_buf_destroy(iVar1);
      return 0;
    }
    cw_pkt_buf_destroy(iVar1);
    if (iVar2 != 0) {
      cw_parsed_pkt_destroy(iVar2);
    }
  }
  return 0xffffffff;
}

