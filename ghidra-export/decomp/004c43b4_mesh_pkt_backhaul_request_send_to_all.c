// func mesh_pkt_backhaul_request_send_to_all @ 004c43b4 size=804

undefined4 mesh_pkt_backhaul_request_send_to_all(char *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  char acStack_50 [32];
  undefined2 local_30;
  char *local_2c;
  undefined2 local_28;
  char *local_24;
  
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  memset(acStack_50,0,0x30);
  if (((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) || (param_3 == (char *)0x0)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar7 = 0x6c9;
LAB_004c4534:
    printf(pcVar5,"mesh_pkt_backhaul_request_send_to_all",uVar7);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_74);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar7 = 0x6cf;
    goto LAB_004c4534;
  }
  FUN_0051ad88(&local_80);
  iVar1 = apmngr_db_get_all_addr_by_capacity(&local_74,1,1,0xe0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n",
             "mesh_pkt_backhaul_request_send_to_all",0x6d6);
      iVar1 = 0;
    }
  }
  else {
    if (local_6c == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d No AP support mesh\n","mesh_pkt_backhaul_request_send_to_all",
               0x6db);
      }
      serv_wtp_address_arg_destroy(&local_74);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar7 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        strncpy(acStack_50,param_1,0x20);
        sVar3 = strlen(param_2);
        local_30 = (undefined2)sVar3;
        local_2c = param_2;
        sVar3 = strlen(param_3);
        local_28 = (undefined2)sVar3;
        local_24 = param_3;
        FUN_0051ad88(&local_5c);
        iVar4 = cw_priv_mesh_private_control_add(&local_80,10,acStack_50);
        if (((iVar4 == 0) &&
            (iVar4 = cw_service_msg_add(iVar2,0x25,&local_64,1,0x76,&local_80), iVar4 == 0)) &&
           (iVar4 = capwap_packet_assemble(iVar1,iVar2), iVar4 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar4 = serv_packet_send(&local_74,iVar1,1);
          if (iVar4 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c455c;
            pcVar5 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar6 = 0x707;
          }
          else {
            uVar7 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c455c;
            pcVar5 = "[MESH_DEBUG]%s()/%d send backhaul configure to AP successfully.\n";
            uVar6 = 0x70b;
          }
          printf(pcVar5,"mesh_pkt_backhaul_request_send_to_all",uVar6);
        }
      }
      goto LAB_004c455c;
    }
  }
  iVar2 = 0;
  uVar7 = 0xffffffff;
LAB_004c455c:
  cw_priv_mesh_private_control_sub_ele_free(&local_80);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&local_74);
  return uVar7;
}

