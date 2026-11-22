// func apupd_db_config_get_without_lock @ 00652c88 size=128

undefined4 apupd_db_config_get_without_lock(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (void *)0x0) || (apupd_config == (void *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_config_get_without_lock",0x1b86
            );
    }
  }
  else {
    uVar2 = 0;
    memcpy(param_1,apupd_config,4);
  }
  return uVar2;
}

