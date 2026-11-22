// func apupd_db_wtp_get_by_mac @ 006547f4 size=296

undefined4 apupd_db_wtp_get_by_mac(int param_1,void *param_2)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == (void *)0x0)) || (apupd_wtp_hash == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_wtp_get_by_mac",0x20fa);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    __src = (void *)FUN_00407fa0(apupd_wtp_hash,param_1);
    if (__src == (void *)0x0) {
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: get wtp from hash by mac failed.\r\n",
               "apupd_db_wtp_get_by_mac",0x2104);
      }
      uVar2 = 0xffffffff;
      FUN_00407f30(apupd_db_mutex);
    }
    else {
      memcpy(param_2,__src,0xa0);
      uVar2 = 0;
      FUN_00407f30(apupd_db_mutex);
    }
  }
  return uVar2;
}

