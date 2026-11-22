// func _apmngr_pkt_lag_config_update_pkt_create @ 005598f8 size=420

undefined4
_apmngr_pkt_lag_config_update_pkt_create
          (undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
          undefined1 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_38 = 0;
  local_34 = 0;
  iVar1 = cw_parsed_pkt_create(7);
  if (iVar1 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_apmngr_pkt_lag_config_update_pkt_create",0x8ce);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_28);
  local_34 = param_6;
  local_38 = CONCAT22(CONCAT11(param_3,param_4),CONCAT11(param_5,(undefined1)local_38));
  iVar2 = cw_service_msg_add(iVar1,0x25,&local_30,1,0xa3,&local_38);
  if (iVar2 == 0) {
    iVar2 = capwap_packet_assemble(param_2,iVar1);
    if (iVar2 != -1) {
      cw_parsed_pkt_destroy(iVar1);
      return 0;
    }
    if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005599a4;
    __format = "[RDMNGR_ERROR]%s()/%d capwap_packet_assemble() fail!\n";
    uVar3 = 0x8e9;
  }
  else {
    if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005599a4;
    __format = "[RDMNGR_ERROR]%s()/%d cw_service_msg_add() fail!\n";
    uVar3 = 0x8e2;
  }
  printf(__format,"_apmngr_pkt_lag_config_update_pkt_create",uVar3);
LAB_005599a4:
  cw_parsed_pkt_destroy(iVar1);
  return 0xffffffff;
}

