// func mesh_set_web_pwd @ 004c00bc size=1

int mesh_set_web_pwd(char *param_1)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uStack_58;
  char *pcStack_54;
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
  
  if ((param_1 == (char *)0x0) || (sVar2 = strlen(param_1), 0x10 < sVar2)) {
    if (mesh_err_switch != '\0') {
      iVar1 = printf("[MESH_ERROR]%s()/%d web pwd is NULL or too long\n","mesh_set_web_pwd",0x849);
      return iVar1;
    }
    return 0;
  }
  mesh_db_web_password_set(param_1,sVar2);
  sVar2 = strlen(param_1);
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
  pcStack_54 = (char *)0x0;
  if ((param_1 == (char *)0x0) || ((short)sVar2 < 1)) {
    if (mesh_err_switch == '\0') {
      return -1;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar6 = 0x60f;
LAB_004c3e78:
    printf(pcVar5,"mesh_pkt_web_password_request_send_to_all",uVar6);
    return -1;
  }
  iVar1 = serv_wtp_address_arg_init(&uStack_44);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return -1;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar6 = 0x615;
    goto LAB_004c3e78;
  }
  FUN_0051ad88(&uStack_50);
  iVar1 = apmngr_db_get_all_addr_by_capacity(&uStack_44,1,1,0x15e0000,1,0x2c);
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
    if (iStack_3c == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n",
               "mesh_pkt_web_password_request_send_to_all",0x621);
      }
      serv_wtp_address_arg_destroy(&uStack_44);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      iVar7 = -1;
      iVar3 = cw_parsed_pkt_create(7);
      if (iVar3 != 0) {
        uStack_58 = CONCAT22((short)sVar2,uStack_58._2_2_);
        pcStack_54 = param_1;
        FUN_0051ad88(&uStack_2c);
        iVar4 = cw_priv_mesh_private_control_add(&uStack_50,0xf,&uStack_58);
        if (((iVar4 == 0) &&
            (iVar4 = cw_service_msg_add(iVar3,0x25,&uStack_34,1,0x76,&uStack_50), iVar4 == 0)) &&
           (iVar4 = capwap_packet_assemble(iVar1,iVar3), iVar4 != -1)) {
          mesh_pkt_dump(iVar3);
          iVar4 = serv_packet_send(&uStack_44,iVar1,1);
          if (iVar4 == -1) {
            if (mesh_err_switch == '\0') goto LAB_004c3f18;
            pcVar5 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar6 = 0x64a;
          }
          else {
            iVar7 = 0;
            if (mesh_debug_switch == '\0') goto LAB_004c3f18;
            pcVar5 = "[MESH_DEBUG]%s()/%d send web password configure to AP successfully.\n";
            uVar6 = 0x64e;
          }
          printf(pcVar5,"mesh_pkt_web_password_request_send_to_all",uVar6);
        }
      }
      goto LAB_004c3f18;
    }
  }
  iVar3 = 0;
  iVar7 = -1;
LAB_004c3f18:
  cw_priv_mesh_private_control_sub_ele_free(&uStack_50);
  if (iVar3 != 0) {
    cw_parsed_pkt_destroy(iVar3);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&uStack_44);
  return iVar7;
}

