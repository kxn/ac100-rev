// func apupd_sub_image_info_send @ 00662610 size=644

undefined4
apupd_sub_image_info_send(undefined2 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (param_4 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x315;
LAB_0066273c:
    printf(pcVar3,"apupd_sub_image_info_send",uVar5);
    return 0xffffffff;
  }
  iVar1 = serv_wtp_address_arg_init(&local_28);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n";
    uVar5 = 0x31b;
    goto LAB_0066273c;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_28,1,1,0x15f0000,1,0x51);
  if (iVar1 == -1) {
    uVar5 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_006626b8;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: get addr from apmngr failed.\r\n";
    uVar4 = 800;
  }
  else {
    if (local_20 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(&local_28), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: AP not support large image update\r\n",
               "apupd_sub_image_info_send",0x325);
      }
      uVar5 = 0;
      serv_wtp_address_arg_destroy(&local_28);
      goto LAB_006626b8;
    }
    iVar1 = apupd_sub_image_info_create(param_2,param_3,param_4);
    if (iVar1 != 0) {
      iVar2 = serv_packet_send(&local_28,iVar1,1);
      if (iVar2 != -1) {
        cw_pkt_buf_destroy(iVar1);
        serv_wtp_address_arg_destroy(&local_28);
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: send sub image info failed.\r\n",
               "apupd_sub_image_info_send",0x333);
      }
      cw_pkt_buf_destroy(iVar1);
      uVar5 = 0xffffffff;
      goto LAB_006626b8;
    }
    uVar5 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_006626b8;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: create sub image info failed.\r\n";
    uVar4 = 0x32d;
  }
  uVar5 = 0xffffffff;
  printf(pcVar3,"apupd_sub_image_info_send",uVar4);
LAB_006626b8:
  serv_wtp_address_arg_destroy(&local_28);
  return uVar5;
}

