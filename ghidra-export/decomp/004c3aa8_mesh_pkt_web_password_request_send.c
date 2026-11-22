// func mesh_pkt_web_password_request_send @ 004c3aa8 size=1

undefined4 mesh_pkt_web_password_request_send(undefined2 param_1,int param_2,short param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_44 = 0;
  uStack_40 = 0;
  iStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_58 = 0;
  iStack_54 = 0;
  if ((param_2 == 0) || (param_3 < 1)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar5 = 0x5b3;
code_r0x004c3b88:
    printf(pcVar4,"mesh_pkt_web_password_request_send",uVar5);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&uStack_44);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar5 = 0x5b9;
    goto code_r0x004c3b88;
  }
  FUN_0051ad88(&uStack_50);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&uStack_44,1,1,0x15e0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n",
             "mesh_pkt_web_password_request_send",0x5c0);
      iVar1 = 0;
    }
  }
  else {
    if (iStack_3c == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n","mesh_pkt_web_password_request_send",
               0x5c5);
      }
      serv_wtp_address_arg_destroy(&uStack_44);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        uStack_58 = CONCAT22(param_3,uStack_58._2_2_);
        iStack_54 = param_2;
        FUN_0051ad88(&uStack_2c);
        iVar3 = cw_priv_mesh_private_control_add(&uStack_50,0xf,&uStack_58);
        if (((iVar3 == 0) &&
            (iVar3 = cw_service_msg_add(iVar2,0x25,&uStack_34,1,0x76,&uStack_50), iVar3 == 0)) &&
           (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar3 = serv_packet_send(&uStack_44,iVar1,1);
          if (iVar3 == -1) {
            if (mesh_err_switch == '\0') goto code_r0x004c3c30;
            pcVar4 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar6 = 0x5ee;
          }
          else {
            uVar5 = 0;
            if (mesh_debug_switch == '\0') goto code_r0x004c3c30;
            pcVar4 = "[MESH_DEBUG]%s()/%d send web password configure to AP successfully.\n";
            uVar6 = 0x5f2;
          }
          printf(pcVar4,"mesh_pkt_web_password_request_send",uVar6);
        }
      }
      goto code_r0x004c3c30;
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
code_r0x004c3c30:
  cw_priv_mesh_private_control_sub_ele_free(&uStack_50);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&uStack_44);
  return uVar5;
}

