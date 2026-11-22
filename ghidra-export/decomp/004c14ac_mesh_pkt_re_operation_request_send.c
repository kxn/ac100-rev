// func mesh_pkt_re_operation_request_send @ 004c14ac size=908

undefined4
mesh_pkt_re_operation_request_send(undefined2 param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_70;
  void *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 auStack_4c [5];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_70 = 0;
  local_6c = (void *)0x0;
  memcpy(auStack_4c,&DAT_006a5f10,0x14);
  if ((param_2 < 0) || (((param_2 != 0 && (param_3 == (void *)0x0)) || (4 < param_4)))) {
    if (mesh_err_switch != '\0') {
      __format = "[MESH_ERROR]%s()/%d Input error.\n";
      uVar4 = 0x38d;
LAB_004c1598:
      printf(__format,"mesh_pkt_re_operation_request_send",uVar4);
      return 0xffffffff;
    }
  }
  else {
    iVar1 = serv_wtp_address_arg_init(&local_5c);
    if (iVar1 != -1) {
      FUN_0051ad88(&local_68);
      iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_5c,1,1,0xe0000,1,0x2c);
      if (iVar1 == -1) {
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d get addr from apmngr failed.\n",
                 "mesh_pkt_re_operation_request_send",0x39a);
        }
        iVar1 = 0;
        iVar2 = 0;
        uVar4 = 0xffffffff;
      }
      else {
        if (local_54 == 0) {
          if (mesh_debug_switch != '\0') {
            printf("[MESH_DEBUG]%s()/%d AP not support to mesh\n",
                   "mesh_pkt_re_operation_request_send",0x39f);
          }
          serv_wtp_address_arg_destroy(&local_5c);
          return 0;
        }
        iVar1 = cw_pkt_buf_create(0xfa);
        if (iVar1 == 0) {
          iVar2 = 0;
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = 0xffffffff;
          iVar2 = cw_parsed_pkt_create(7);
          if (iVar2 != 0) {
            local_70 = CONCAT22((short)param_2,local_70._2_2_);
            if (param_2 != 0) {
              uVar4 = 0xffffffff;
              local_6c = (void *)FUN_00408450(param_2 * 6,0x3b2);
              if (local_6c == (void *)0x0) goto LAB_004c16f4;
              memcpy(local_6c,param_3,param_2 * 6);
            }
            FUN_0051ad88(&local_30);
            uVar5 = auStack_4c[param_4];
            uVar4 = 0xffffffff;
            iVar3 = cw_priv_mesh_private_control_add(&local_68,uVar5,&local_70);
            if (((iVar3 == 0) &&
                (iVar3 = cw_service_msg_add(iVar2,0x25,&local_38,1,0x76,&local_68), iVar3 == 0)) &&
               (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
              mesh_pkt_dump(iVar2);
              iVar3 = serv_packet_send(&local_5c,iVar1,1);
              if (iVar3 == -1) {
                if (mesh_err_switch != '\0') {
                  printf("[MESH_ERROR]%s()/%d send packet failed.\n",
                         "mesh_pkt_re_operation_request_send",0x3d0);
                }
              }
              else {
                uVar4 = 0;
                if (mesh_debug_switch != '\0') {
                  printf("[MESH_DEBUG]%s()/%d send pair/unpair/add/delete/re_list(%d) configure to AP successfully.\n"
                         ,"mesh_pkt_re_operation_request_send",0x3d4,uVar5);
                }
              }
            }
          }
        }
      }
LAB_004c16f4:
      cw_priv_mesh_private_control_sub_ele_free(&local_68);
      if (local_6c != (void *)0x0) {
        FUN_00407df0();
      }
      if (iVar2 != 0) {
        cw_parsed_pkt_destroy(iVar2);
      }
      if (iVar1 != 0) {
        cw_pkt_buf_destroy(iVar1);
      }
      serv_wtp_address_arg_destroy(&local_5c);
      return uVar4;
    }
    if (mesh_err_switch != '\0') {
      __format = "[MESH_ERROR]%s()/%d init serv argv failed.\n";
      uVar4 = 0x393;
      goto LAB_004c1598;
    }
  }
  return 0xffffffff;
}

