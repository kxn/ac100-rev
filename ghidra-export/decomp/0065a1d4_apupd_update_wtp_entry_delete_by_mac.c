// func apupd_update_wtp_entry_delete_by_mac @ 0065a1d4 size=196

undefined4 apupd_update_wtp_entry_delete_by_mac(undefined4 param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: get update wtp from hash by mac failed.\r\n";
    uVar2 = 0x531;
  }
  else {
    iVar1 = apupd_update_wtp_entry_delete(iVar1);
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
    __format = "[APUPD_ERROR]%32s() %05d: delete update wtp failed.\r\n";
    uVar2 = 0x538;
  }
  printf(__format,"apupd_update_wtp_entry_delete_by_mac",uVar2);
  return 0xffffffff;
}

