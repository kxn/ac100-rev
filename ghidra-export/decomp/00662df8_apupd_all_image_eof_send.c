// func apupd_all_image_eof_send @ 00662df8 size=860

undefined4 apupd_all_image_eof_send(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_all_image_eof_send\r\n","apupd_all_image_eof_send",0x3dd
          );
  }
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_24);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n","apupd_all_image_eof_send",1000);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_24,1,1,0x15f0000,1,0x51);
  if (iVar1 == -1) {
    uVar6 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00662e90;
    pcVar4 = "[APUPD_ERROR]%32s() %05d: get addr from apmngr failed.\r\n";
    uVar5 = 0x3ed;
  }
  else if (local_1c == 0) {
    uVar6 = 0;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00662e90;
    pcVar4 = "[APUPD_ERROR]%32s() %05d: AP not support large image update\r\n";
    uVar5 = 0x3f2;
  }
  else {
    iVar1 = cw_pkt_buf_create(0xfa);
    if (iVar1 != 0) {
      iVar2 = cw_parsed_pkt_create(0xf);
      if (iVar2 == 0) {
        uVar6 = 0xffffffff;
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: malloc parsed packet failed.\r\n",
                 "apupd_all_image_eof_send",0x3ff);
        }
        if (iVar1 == 0) goto LAB_00662e90;
      }
      else {
        iVar3 = apupd_image_data_add(iVar2,&local_28,4,2);
        if (iVar3 == -1) {
          if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
            pcVar4 = "[APUPD_ERROR]%32s() %05d: add image data failed.\r\n";
            uVar6 = 0x408;
            goto LAB_00663024;
          }
        }
        else {
          iVar3 = capwap_packet_assemble(iVar1,iVar2);
          if (iVar3 == -1) {
            if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
              pcVar4 = "[APUPD_ERROR]%32s() %05d: assemble image request failed.\r\n";
              uVar6 = 0x40f;
LAB_00663024:
              printf(pcVar4,"apupd_all_image_eof_send",uVar6);
            }
          }
          else {
            apupd_pkt_dump(iVar2);
            iVar3 = serv_packet_send(&local_24,iVar1,1);
            if (iVar3 != -1) {
              cw_parsed_pkt_destroy(iVar2);
              cw_pkt_buf_destroy(iVar1);
              return 0;
            }
            if ((g_apupd_error != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
              pcVar4 = "[APUPD_ERROR]%32s() %05d: send sub image action failed.\r\n";
              uVar6 = 0x416;
              goto LAB_00663024;
            }
          }
        }
        cw_parsed_pkt_destroy(iVar2);
      }
      uVar6 = 0xffffffff;
      cw_pkt_buf_destroy(iVar1);
      goto LAB_00662e90;
    }
    uVar6 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00662e90;
    pcVar4 = "[APUPD_ERROR]%32s() %05d: malloc pakcet buffer failed.\r\n";
    uVar5 = 0x3f9;
  }
  printf(pcVar4,"apupd_all_image_eof_send",uVar5);
LAB_00662e90:
  serv_wtp_address_arg_destroy(&local_24);
  return uVar6;
}

