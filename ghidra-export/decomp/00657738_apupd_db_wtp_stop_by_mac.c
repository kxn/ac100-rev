// func apupd_db_wtp_stop_by_mac @ 00657738 size=1

undefined4 apupd_db_wtp_stop_by_mac(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_wtp_stop_by_mac",0x22b7);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto code_r0x00657814;
    __format = "[APUPD_ERROR]%32s() %05d: get update wtp failed.\r\n";
    uVar2 = 0x22c1;
  }
  else {
    if (*(int *)(*(int *)(iVar1 + 0x30) + 0x48) == 3) {
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto code_r0x00657814;
    __format = "[APUPD_ERROR]%32s() %05d: state of wtp is wrong.\r\n";
    uVar2 = 0x22c9;
  }
  printf(__format,"apupd_db_wtp_stop_by_mac",uVar2);
code_r0x00657814:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

