// func apupd_db_wtp_set @ 0065af30 size=240

undefined4 apupd_db_wtp_set(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_wtp_set",0x20b8);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    iVar1 = apupd_wtp_entry_update(param_1);
    if (iVar1 == -1) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: update wtp failed.\r\n","apupd_db_wtp_set",0x20c2);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(apupd_db_mutex);
    }
    else {
      uVar2 = 0;
      FUN_00407f30(apupd_db_mutex);
    }
  }
  return uVar2;
}

