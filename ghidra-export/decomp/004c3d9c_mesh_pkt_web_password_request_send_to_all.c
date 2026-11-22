// func mesh_pkt_web_password_request_send_to_all @ 004c3d9c size=744

undefined4 mesh_pkt_web_password_request_send_to_all(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_58 = 0;
  local_54 = 0;
  if ((param_1 == 0) || (param_2 < 1)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar5 = 0x60f;
LAB_004c3e78:
    printf(pcVar4,"mesh_pkt_web_password_request_send_to_all",uVar5);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_44);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar5 = 0x615;
    goto LAB_004c3e78;
  }
  FUN_0051ad88(&local_50);
  iVar1 = apmngr_db_get_all_addr_by_capacity(&local_44,1,1,0x15e0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n",
             "mesh_pkt_web_password_request_send_to_all",0x61c);
      iVar1 = 0;
    }
  }
  else {
    if (local_3c == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n",
               "mesh_pkt_web_password_request_send_to_all",0x621);
      }
      serv_wtp_address_arg_destroy(&local_44);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        local_58 = CONCAT22(param_2,local_58._2_2_);
        local_54 = param_1;
        FUN_0051ad88(&local_2c);
        iVar3 = cw_priv_mesh_private_control_add(&local_50,0xf,&local_58);
        if (((iVar3 == 0) &&
            (iVar3 = cw_service_msg_add(iVar2,0x25,&local_34,1,0x76,&local_50), iVar3 == 0)) &&
           (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar3 = serv_packet_send(&local_44,iVar1,1);
          if (iVar3 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c3f18;
            pcVar4 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar6 = 0x64a;
          }
          else {
            uVar5 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c3f18;
            pcVar4 = "[MESH_DEBUG]%s()/%d send web password configure to AP successfully.\n";
            uVar6 = 0x64e;
          }
          printf(pcVar4,"mesh_pkt_web_password_request_send_to_all",uVar6);
        }
      }
      goto LAB_004c3f18;
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
LAB_004c3f18:
  cw_priv_mesh_private_control_sub_ele_free(&local_50);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&local_44);
  return uVar5;
}

