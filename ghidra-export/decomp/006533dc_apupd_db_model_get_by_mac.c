// func apupd_db_model_get_by_mac @ 006533dc size=1

void * apupd_db_model_get_by_mac(int param_1,void *param_2)

{
  int iVar1;
  void *__src;
  
  if (((param_1 == 0) || (param_2 == (void *)0x0)) || (apupd_wtp_hash == 0)) {
    __src = (void *)0x0;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_get_by_mac",0x1cc1);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    iVar1 = FUN_00407fa0(apupd_wtp_hash,param_1);
    if (iVar1 == 0) {
      if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get wtp by mac failed.\r\n","apupd_db_model_get_by_mac",
               0x1ccb);
      }
      __src = (void *)0x0;
      FUN_00407f30(apupd_db_mutex);
    }
    else {
      __src = *(void **)(iVar1 + 0x50);
      memcpy(param_2,__src,0x800);
      FUN_00407f30(apupd_db_mutex);
    }
  }
  return __src;
}

