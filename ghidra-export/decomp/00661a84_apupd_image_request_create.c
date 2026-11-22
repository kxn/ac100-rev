// func apupd_image_request_create @ 00661a84 size=700

int apupd_image_request_create
              (int param_1,uint param_2,undefined4 param_3,int param_4,int param_5,char param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_2 < (uint)(param_5 + param_4))) ||
     (param_5 == 0)) {
    if (g_apupd_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    pcVar4 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x1b9;
LAB_00661c08:
    printf(pcVar4,"apupd_image_request_create",uVar5);
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
    pcVar4 = "[APUPD_ERROR]%32s() %05d: malloc pakcet buffer failed.\r\n";
    uVar5 = 0x1c0;
    goto LAB_00661c08;
  }
  iVar2 = cw_parsed_pkt_create(0xf);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00661bd8;
    pcVar4 = "[APUPD_ERROR]%32s() %05d: malloc parsed packet failed.\r\n";
    uVar5 = 0x1c7;
  }
  else {
    iVar6 = 2;
    if (param_5 + param_4 != param_2) {
      iVar6 = 1;
    }
    if (param_6 == '\x01') {
      iVar6 = 1;
    }
    iVar3 = apupd_image_data_add(iVar2,param_1 + param_4,param_5,iVar6);
    if (iVar3 == -1) {
      if ((g_apupd_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00661bd8;
      pcVar4 = "[APUPD_ERROR]%32s() %05d: add image data failed.\r\n";
      uVar5 = 0x1d4;
    }
    else if (((iVar6 == 2) && (param_6 == '\0')) &&
            (iVar6 = apupd_image_information_add(iVar2,param_2,param_3,0x10), iVar6 == -1)) {
      if ((g_apupd_error == 0) || (iVar6 = is_target_debug_ap(iVar1), iVar6 == 0))
      goto LAB_00661bd8;
      pcVar4 = "[APUPD_ERROR]%32s() %05d: add image information failed.\r\n";
      uVar5 = 0x1dd;
    }
    else {
      iVar6 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar6 != -1) {
        cw_parsed_pkt_destroy(iVar2);
        return iVar1;
      }
      if ((g_apupd_error == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) goto LAB_00661bd8;
      pcVar4 = "[APUPD_ERROR]%32s() %05d: assemble image request failed.\r\n";
      uVar5 = 0x1e5;
    }
  }
  printf(pcVar4,"apupd_image_request_create",uVar5);
LAB_00661bd8:
  cw_pkt_buf_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return 0;
}

