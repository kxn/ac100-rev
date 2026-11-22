// func debug_msg_priv_175 @ 00663154 size=1

/* WARNING: Removing unreachable block (ram,0x006622a0) */
/* WARNING: Removing unreachable block (ram,0x006622b0) */
/* WARNING: Removing unreachable block (ram,0x006622b8) */
/* WARNING: Removing unreachable block (ram,0x006622c0) */

undefined4 debug_msg_priv_175(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  iVar1 = serv_wtp_address_arg_init(&uStack_28);
  if (iVar1 == -1) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n","apupd_large_image_info_send",
             0x2a1);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&uStack_28,1,1,0x15f0000,1,0x51);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00662250;
    __format = "[APUPD_ERROR]%32s() %05d: get addr from apmngr failed.\r\n";
    uVar3 = 0x2a6;
  }
  else {
    if (iStack_20 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(&uStack_28), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: AP not support large image update\r\n",
               "apupd_large_image_info_send",0x2ab);
      }
      uVar4 = 0;
      serv_wtp_address_arg_destroy(&uStack_28);
      goto LAB_00662250;
    }
    iVar1 = apupd_large_image_info_create(param_2,param_3,&debug_md5);
    if (iVar1 != 0) {
      iVar2 = serv_packet_send(&uStack_28,iVar1,1);
      if (iVar2 != -1) {
        cw_pkt_buf_destroy(iVar1);
        serv_wtp_address_arg_destroy(&uStack_28);
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: send large image info failed.\r\n",
               "apupd_large_image_info_send",0x2b9);
      }
      cw_pkt_buf_destroy(iVar1);
      uVar4 = 0xffffffff;
      goto LAB_00662250;
    }
    uVar4 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00662250;
    __format = "[APUPD_ERROR]%32s() %05d: create large image info failed.\r\n";
    uVar3 = 0x2b3;
  }
  uVar4 = 0xffffffff;
  printf(__format,"apupd_large_image_info_send",uVar3);
LAB_00662250:
  serv_wtp_address_arg_destroy(&uStack_28);
  return uVar4;
}

