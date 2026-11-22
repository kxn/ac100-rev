// func apupd_db_wtp_delete_by_mac @ 0065aaf0 size=504

undefined4 apupd_db_wtp_delete_by_mac(byte *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_db_wtp_delete_by_mac, mac[%02X-%02X-%02X-%02X-%02X-%02X]\r\n"
           ,"apupd_db_wtp_delete_by_mac",0x2280,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
           (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  }
  if ((param_1 == (byte *)0x0) || (apupd_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_wtp_delete_by_mac",0x2286);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0065ab78;
    __format = "[APUPD_DEBUG]%32s() %05d: wtp isn\'t existent.\r\n";
    uVar2 = 0x2290;
  }
  else {
    iVar1 = apupd_wtp_entry_delete(iVar1);
    if (iVar1 == -1) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: delete wtp failed.\r\n","apupd_db_wtp_delete_by_mac",
               0x2298);
      }
      FUN_00407f30(apupd_db_mutex);
      return 0xffffffff;
    }
    if ((g_apupd_debug == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_0065ab78;
    __format = "[APUPD_DEBUG]%32s() %05d: delete wtp successed.\r\n";
    uVar2 = 0x229d;
  }
  printf(__format,"apupd_db_wtp_delete_by_mac",uVar2);
LAB_0065ab78:
  FUN_00407f30(apupd_db_mutex);
  return 0;
}

