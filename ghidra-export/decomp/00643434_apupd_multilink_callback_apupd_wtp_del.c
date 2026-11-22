// func apupd_multilink_callback_apupd_wtp_del @ 00643434 size=284

undefined4 apupd_multilink_callback_apupd_wtp_del(uint param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [660];
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_multilink_callback_apupd_wtp_del, apid = %d\r\n",
           "apupd_multilink_callback_apupd_wtp_del",0x121c,param_1 & 0xffff);
  }
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get ap entry by id failed.\r\n";
    uVar2 = 0x1223;
  }
  else {
    iVar1 = apupd_db_wtp_delete_by_mac(auStack_2a0);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: delete wtp failed.\r\n";
    uVar2 = 0x122a;
  }
  printf(__format,"apupd_multilink_callback_apupd_wtp_del",uVar2);
  return 0xffffffff;
}

