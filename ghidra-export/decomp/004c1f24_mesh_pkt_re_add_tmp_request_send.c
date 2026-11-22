// func mesh_pkt_re_add_tmp_request_send @ 004c1f24 size=852

undefined4
mesh_pkt_re_add_tmp_request_send(undefined2 param_1,int param_2,void *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_60;
  void *local_5c;
  undefined4 local_58;
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
  local_60 = 0;
  local_5c = (void *)0x0;
  local_58 = 0;
  if ((param_2 < 0) || ((param_2 != 0 && (param_3 == (void *)0x0)))) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar6 = 0x3f4;
LAB_004c2094:
    printf(pcVar4,"mesh_pkt_re_add_tmp_request_send",uVar6);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_48);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar6 = 0x3fa;
    goto LAB_004c2094;
  }
  FUN_0051ad88(&local_54);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_48,1,1,0x15e0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n","mesh_pkt_re_add_tmp_request_send"
             ,0x401);
      iVar1 = 0;
    }
  }
  else {
    if (local_40 == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n","mesh_pkt_re_add_tmp_request_send",
               0x406);
      }
      serv_wtp_address_arg_destroy(&local_48);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar6 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        local_60 = CONCAT22((short)param_2,local_60._2_2_);
        if (param_2 != 0) {
          uVar6 = 0xffffffff;
          local_5c = (void *)FUN_00408450(param_2 * 6,0x419);
          if (local_5c == (void *)0x0) goto LAB_004c21cc;
          memcpy(local_5c,param_3,param_2 * 6);
        }
        local_58 = param_4;
        FUN_0051ad88(&local_30);
        iVar3 = cw_priv_mesh_private_control_add(&local_54,0x14,&local_60);
        uVar6 = 0xffffffff;
        if (((iVar3 == 0) &&
            (iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x76,&local_54), iVar3 == 0)) &&
           (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar3 = serv_packet_send(&local_48,iVar1,1);
          if (iVar3 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c21cc;
            pcVar4 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar5 = 0x438;
          }
          else {
            uVar6 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c21cc;
            pcVar4 = "[MESH_DEBUG]%s()/%d send add tmp re request configure to AP successfully.\n";
            uVar5 = 0x43c;
          }
          printf(pcVar4,"mesh_pkt_re_add_tmp_request_send",uVar5);
        }
      }
      goto LAB_004c21cc;
    }
  }
  iVar2 = 0;
  uVar6 = 0xffffffff;
LAB_004c21cc:
  cw_priv_mesh_private_control_sub_ele_free(&local_54);
  if (local_5c != (void *)0x0) {
    FUN_00407df0();
  }
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&local_48);
  return uVar6;
}

