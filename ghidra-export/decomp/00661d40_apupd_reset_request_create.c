// func apupd_reset_request_create @ 00661d40 size=648

int apupd_reset_request_create(undefined4 param_1,int param_2,short param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    if (g_apupd_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x214;
LAB_00661e50:
    printf(pcVar4,"apupd_reset_request_create",uVar5);
    return 0;
  }
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[APUPD_ERROR]%32s() %05d: create packet buffer failed.\r\n";
    uVar5 = 0x21b;
    goto LAB_00661e50;
  }
  iVar2 = cw_parsed_pkt_create(0x11);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00661e20;
    pcVar4 = "[APUPD_ERROR]%32s() %05d: create parsed packet failed.\r\n";
    uVar5 = 0x222;
  }
  else {
    if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: apupd_image_identifier_add\r\n","apupd_reset_request_create"
             ,0x227);
    }
    iVar3 = apupd_image_identifier_add(iVar2,param_1,param_2,param_3);
    if (iVar3 == -1) {
      if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00661e20;
      pcVar4 = "[APUPD_ERROR]%32s() %05d: add image identifier failed.\r\n";
      uVar5 = 0x22a;
    }
    else {
      iVar3 = apupd_vendor_specific_payload_with_reset_mask_add(iVar2,param_1,0x23,param_4);
      if (iVar3 == -1) {
        if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00661e20;
        pcVar4 = "[APUPD_ERROR]%32s() %05d: add vendor specific payload with reset mask failed.\r\n"
        ;
        uVar5 = 0x231;
      }
      else {
        iVar3 = capwap_packet_assemble(iVar1,iVar2);
        if (iVar3 != -1) {
          cw_parsed_pkt_destroy(iVar2);
          return iVar1;
        }
        if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00661e20;
        pcVar4 = "[APUPD_ERROR]%32s() %05d: assemble reset packet failed.\r\n";
        uVar5 = 0x238;
      }
    }
  }
  printf(pcVar4,"apupd_reset_request_create",uVar5);
LAB_00661e20:
  cw_pkt_buf_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return 0;
}

