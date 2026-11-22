// func apupd_db_models_get @ 00653504 size=1

undefined4 apupd_db_models_get(int param_1)

{
  void *__src;
  void *__dest;
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (apupd_model_list == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_models_get",0x1cea);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    for (__src = (void *)FUN_004081b0(apupd_model_list); __src != (void *)0x0;
        __src = (void *)FUN_00408680(__src)) {
      __dest = (void *)FUN_00408450(0x800,0x1cf4);
      if (__dest == (void *)0x0) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: malloc model failed.\r\n","apupd_db_models_get",0x1cf7);
        }
        FUN_00407f30(apupd_db_mutex);
        return 0xffffffff;
      }
      memcpy(__dest,__src,0x800);
      FUN_004086b0(param_1,__dest);
    }
    uVar2 = 0;
    FUN_00407f30(apupd_db_mutex);
  }
  return uVar2;
}

