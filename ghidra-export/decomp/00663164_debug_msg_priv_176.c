// func debug_msg_priv_176 @ 00663164 size=1

/* WARNING: Removing unreachable block (ram,0x00662708) */
/* WARNING: Removing unreachable block (ram,0x00662718) */
/* WARNING: Removing unreachable block (ram,0x00662720) */
/* WARNING: Removing unreachable block (ram,0x00662728) */

undefined4 debug_msg_priv_176(undefined2 param_1,undefined1 param_2,undefined4 param_3)

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
      printf("[APUPD_ERROR]%32s() %05d: init serv argv failed.\r\n","apupd_sub_image_info_send",
             0x31b);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(param_1,&uStack_28,1,1,0x15f0000,1,0x51);
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_006626b8;
    __format = "[APUPD_ERROR]%32s() %05d: get addr from apmngr failed.\r\n";
    uVar3 = 800;
  }
  else {
    if (iStack_20 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(&uStack_28), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: AP not support large image update\r\n",
               "apupd_sub_image_info_send",0x325);
      }
      uVar4 = 0;
      serv_wtp_address_arg_destroy(&uStack_28);
      goto LAB_006626b8;
    }
    iVar1 = apupd_sub_image_info_create(param_2,param_3,&debug_md5);
    if (iVar1 != 0) {
      iVar2 = serv_packet_send(&uStack_28,iVar1,1);
      if (iVar2 != -1) {
        cw_pkt_buf_destroy(iVar1);
        serv_wtp_address_arg_destroy(&uStack_28);
        return 0;
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: send sub image info failed.\r\n",
               "apupd_sub_image_info_send",0x333);
      }
      cw_pkt_buf_destroy(iVar1);
      uVar4 = 0xffffffff;
      goto LAB_006626b8;
    }
    uVar4 = 0xffffffff;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_006626b8;
    __format = "[APUPD_ERROR]%32s() %05d: create sub image info failed.\r\n";
    uVar3 = 0x32d;
  }
  uVar4 = 0xffffffff;
  printf(__format,"apupd_sub_image_info_send",uVar3);
LAB_006626b8:
  serv_wtp_address_arg_destroy(&uStack_28);
  return uVar4;
}

