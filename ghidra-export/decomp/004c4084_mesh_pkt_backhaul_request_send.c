// func mesh_pkt_backhaul_request_send @ 004c4084 size=1

undefined4
mesh_pkt_backhaul_request_send(undefined2 param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  char acStack_50 [32];
  undefined2 uStack_30;
  char *pcStack_2c;
  undefined2 uStack_28;
  char *pcStack_24;
  
  uStack_74 = 0;
  uStack_70 = 0;
  iStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  memset(acStack_50,0,0x30);
  if (((param_2 == (char *)0x0) || (param_3 == (char *)0x0)) || (param_4 == (char *)0x0)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d Input error.\n";
    uVar7 = 0x66b;
code_r0x004c4210:
    printf(pcVar5,"mesh_pkt_backhaul_request_send",uVar7);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&uStack_74);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
    uVar7 = 0x671;
    goto code_r0x004c4210;
  }
  FUN_0051ad88(&uStack_80);
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&uStack_74,1,1,0xe0000,1,0x2c);
  if (iVar1 == -1) {
    if (mesh_err_switch == '\0') {
      iVar1 = 0;
    }
    else {
      printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n","mesh_pkt_backhaul_request_send",
             0x678);
      iVar1 = 0;
    }
  }
  else {
    if (iStack_6c == 0) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d AP not support to AP mesh\n","mesh_pkt_backhaul_request_send",
               0x67d);
      }
      serv_wtp_address_arg_destroy(&uStack_74);
      return 0;
    }
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      uVar7 = 0xffffffff;
      iVar2 = cw_parsed_pkt_create(7);
      if (iVar2 != 0) {
        strncpy(acStack_50,param_2,0x20);
        sVar3 = strlen(param_3);
        uStack_30 = (undefined2)sVar3;
        pcStack_2c = param_3;
        sVar3 = strlen(param_4);
        uStack_28 = (undefined2)sVar3;
        pcStack_24 = param_4;
        FUN_0051ad88(&uStack_5c);
        iVar4 = cw_priv_mesh_private_control_add(&uStack_80,10,acStack_50);
        if (((iVar4 == 0) &&
            (iVar4 = cw_service_msg_add(iVar2,0x25,&uStack_64,1,0x76,&uStack_80), iVar4 == 0)) &&
           (iVar4 = capwap_packet_assemble(iVar1,iVar2), iVar4 != -1)) {
          mesh_pkt_dump(iVar2);
          iVar4 = serv_packet_send(&uStack_74,iVar1,1);
          if (iVar4 == -1) {
            if (mesh_err_switch == '\0') goto code_r0x004c4238;
            pcVar5 = "[MESH_ERROR]%s()/%d send packet failed.\n";
            uVar6 = 0x6a9;
          }
          else {
            uVar7 = 0;
            if (mesh_debug_switch == '\0') goto code_r0x004c4238;
            pcVar5 = "[MESH_DEBUG]%s()/%d send backhaul configure to AP successfully.\n";
            uVar6 = 0x6ad;
          }
          printf(pcVar5,"mesh_pkt_backhaul_request_send",uVar6);
        }
      }
      goto code_r0x004c4238;
    }
  }
  iVar2 = 0;
  uVar7 = 0xffffffff;
code_r0x004c4238:
  cw_priv_mesh_private_control_sub_ele_free(&uStack_80);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  serv_wtp_address_arg_destroy(&uStack_74);
  return uVar7;
}

