// func acpdt_init @ 00665fd0 size=772

undefined4 acpdt_init(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  pcVar1 = (char *)FUN_00408450(0xb0,0x8a);
  g_acpdt_info = pcVar1;
  if (pcVar1 == (char *)0x0) {
    if (g_acpdt_error != 0) {
      printf("[ACPDT_ERROR] %32s() %05d: malloc failed.\r\n","acpdt_product_info_init",0x8c);
    }
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    printf("[ACPDT_ERROR] %32s() %05d: init product information failed.\r\n","acpdt_init",0x39e);
    return 0xffffffff;
  }
  memset(pcVar1,0,0xb0);
  iVar2 = FUN_00408040(pcVar1,0x80);
  if (iVar2 != 0) {
    if (g_acpdt_error != 0) {
      printf("[ACPDT_ERROR] %32s() %05d: get product name failed.\r\n","acpdt_product_infor_get",
             0x70);
    }
    strcpy(pcVar1,"TL-AC10000");
  }
  iVar2 = FUN_00407e30(pcVar1 + 0x80);
  if (iVar2 != 0) {
    if (g_acpdt_error != 0) {
      printf("[ACPDT_ERROR] %32s() %05d: read verison time failed.\r\n","acpdt_product_infor_get",
             0x76);
    }
    pcVar1[0x8c] = '\x01';
    pcVar1[0x8d] = '3';
    pcVar1[0x8e] = -0x62;
    pcVar1[0x8f] = 'p';
    pcVar1[0x90] = '\0';
    pcVar1[0x91] = '\0';
    pcVar1[0x92] = 'r';
    pcVar1[0x93] = 'h';
  }
  iVar2 = FUN_004085d0(pcVar1 + 0x94);
  if (iVar2 != 0) {
    if (g_acpdt_error != 0) {
      printf("[ACPDT_ERROR] %32s() %05d: get hardware ver failed.\r\n","acpdt_product_infor_get",
             0x7d);
    }
    pcVar1[0x98] = '\0';
    pcVar1[0x99] = '\0';
    pcVar1[0x9a] = '\0';
    pcVar1[0x9b] = '\0';
    pcVar1[0x94] = '\0';
    pcVar1[0x95] = '\0';
    pcVar1[0x96] = '\0';
    pcVar1[0x97] = '\x01';
  }
  pcVar1 = g_acpdt_info;
  if ((*(int *)(g_acpdt_info + 0x80) == 1) && (*(int *)(g_acpdt_info + 0x84) == 0)) {
    pcVar1[0x84] = '\0';
    pcVar1[0x85] = '\0';
    pcVar1[0x86] = '\0';
    pcVar1[0x87] = '\x01';
  }
  pcVar1[0x9c] = '\0';
  pcVar1[0x9d] = '\0';
  pcVar1[0x9e] = '\0';
  pcVar1[0x9f] = '\x01';
  pcVar1[0xa0] = '\0';
  pcVar1[0xa1] = '\0';
  pcVar1[0xa2] = '\0';
  pcVar1[0xa3] = '\x01';
  uVar3 = apmngr_db_get_ap_max();
  *(undefined4 *)(pcVar1 + 0xa4) = uVar3;
  pcVar1 = g_acpdt_info;
  uVar3 = wsta_profile_get_max_wstation();
  *(undefined4 *)(pcVar1 + 0xa8) = uVar3;
  builtin_strncpy(g_acpdt_info + 0xac,"\x02\x01\x04\x01",4);
  iVar2 = serv_msg_mngr_register(1,200,acpdt_capwap_callback_discovery_reqeust_listen);
  if (iVar2 == -1) {
    if (g_acpdt_error == 0) goto LAB_00666100;
    pcVar1 = "[ACPDT_ERROR] %32s() %05d: register callback to listen discovery reqeust failed.\r\n";
    uVar3 = 0x375;
  }
  else {
    iVar2 = serv_msg_mngr_register(3,200,acpdt_capwap_callback_join_reqeust_listen);
    if (iVar2 == -1) {
      if (g_acpdt_error == 0) goto LAB_00666100;
      pcVar1 = "[ACPDT_ERROR] %32s() %05d: register callback to listen join reqeust failed.\r\n";
      uVar3 = 0x37c;
    }
    else {
      iVar2 = serv_msg_mngr_register
                        (5,200,acpdt_capwap_callback_configuration_status_reqeust_listen);
      if (iVar2 != -1) {
        return 0;
      }
      if (g_acpdt_error == 0) goto LAB_00666100;
      pcVar1 = 
      "[ACPDT_ERROR] %32s() %05d: register callback to listen configuration status reqeust failed.\r\n"
      ;
      uVar3 = 899;
    }
  }
  printf(pcVar1,"acpdt_capwap_callback_init",uVar3);
LAB_00666100:
  if (g_acpdt_error != 0) {
    printf("[ACPDT_ERROR] %32s() %05d: resgister callback to capwap failed.\r\n","acpdt_init",0x3a5)
    ;
  }
  FUN_00407df0(g_acpdt_info);
  g_acpdt_info = (char *)0x0;
  return 0xffffffff;
}

