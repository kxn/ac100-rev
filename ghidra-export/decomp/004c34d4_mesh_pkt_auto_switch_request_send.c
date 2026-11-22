// func mesh_pkt_auto_switch_request_send @ 004c34d4 size=700

undefined4 mesh_pkt_auto_switch_request_send(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_58 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_48);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d init serv argv failed.\n","mesh_pkt_auto_switch_request_send",0x508)
    ;
    return 0xffffffff;
  }
  FUN_0051ad88(&local_54);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_48,1,1,0x15e0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n",
             "mesh_pkt_auto_switch_request_send",0x50f);
      iVar1 = 0;
    }
  }
  else {
    if (local_40 == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n","mesh_pkt_auto_switch_request_send",
               0x514);
      }
      serv_wtp_address_arg_destroy(&local_48);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        local_58 = CONCAT11(param_2 != 0,param_3 != 0);
        FUN_0051ad88(&local_30);
        iVar3 = cw_priv_mesh_private_control_add(&local_54,0xe,&local_58);
        if (((iVar3 == 0) &&
            (iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x76,&local_54), iVar3 == 0)) &&
           (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar3 = serv_packet_send(&local_48,iVar1,1);
          if (iVar3 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c3618;
            __format = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar4 = 0x53d;
          }
          else {
            uVar5 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c3618;
            __format = "[MESH_DEBUG]%s()/%d send auto switch configure to AP successfully.\n";
            uVar4 = 0x541;
          }
          printf(__format,"mesh_pkt_auto_switch_request_send",uVar4);
        }
      }
      goto LAB_004c3618;
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
LAB_004c3618:
  cw_priv_mesh_private_control_sub_ele_free(&local_54);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&local_48);
  return uVar5;
}

