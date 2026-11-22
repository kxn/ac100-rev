// func mesh_pkt_enable_request_send @ 004c2278 size=680

undefined4 mesh_pkt_enable_request_send(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort local_50 [2];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_50[0] = 0;
  iVar1 = serv_wtp_address_arg_init(&local_40);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d init serv argv failed.\n","mesh_pkt_enable_request_send",0x45e);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_4c);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_40,1,1,0xe0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n","mesh_pkt_enable_request_send",
             0x465);
      iVar1 = 0;
    }
  }
  else {
    if (local_38 == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n","mesh_pkt_enable_request_send",0x46a);
      }
      serv_wtp_address_arg_destroy(&local_40);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        local_50[0] = (ushort)(param_2 != 0);
        FUN_0051ad88(&local_28);
        iVar3 = cw_priv_mesh_private_control_add(&local_4c,0x15,local_50);
        if (((iVar3 == 0) &&
            (iVar3 = cw_service_msg_add(iVar2,0x25,&local_30,1,0x76,&local_4c), iVar3 == 0)) &&
           (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar3 = serv_packet_send(&local_40,iVar1,1);
          if (iVar3 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c23b0;
            __format = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar4 = 0x492;
          }
          else {
            uVar5 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c23b0;
            __format = "[MESH_DEBUG]%s()/%d send mesh switch configure to AP successfully.\n";
            uVar4 = 0x496;
          }
          printf(__format,"mesh_pkt_enable_request_send",uVar4);
        }
      }
      goto LAB_004c23b0;
    }
  }
  iVar2 = 0;
  uVar5 = 0xffffffff;
LAB_004c23b0:
  cw_priv_mesh_private_control_sub_ele_free(&local_4c);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&local_40);
  return uVar5;
}

