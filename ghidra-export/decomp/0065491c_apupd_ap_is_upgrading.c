// func apupd_ap_is_upgrading @ 0065491c size=204

bool apupd_ap_is_upgrading(undefined2 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_380 [72];
  int local_338;
  undefined1 auStack_2e0 [72];
  undefined1 auStack_298 [656];
  
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e0);
  if (iVar1 == -1) {
    if (g_apupd_error == 0) {
      return false;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return false;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get ap entry by id error\r\n";
    uVar2 = 0xf94;
  }
  else {
    iVar1 = apupd_db_wtp_get_by_mac(auStack_298,auStack_380);
    if (iVar1 != -1) {
      return local_338 - 3U < 5;
    }
    if (g_apupd_debug == 0) {
      return false;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return false;
    }
    __format = "[APUPD_DEBUG]%32s() %05d: get wtp by mac error\r\n";
    uVar2 = 0xf9a;
  }
  printf(__format,"apupd_ap_is_upgrading",uVar2);
  return false;
}

