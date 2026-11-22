// func apupd_db_config_set @ 00652b20 size=180

undefined4 apupd_db_config_set(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (void *)0x0) || (apupd_config == (void *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_config_set",0x1b4a);
    }
  }
  else {
    FUN_004082d0(apupd_db_mutex,0xffffffff);
    uVar2 = 0;
    memcpy(apupd_config,param_1,4);
    FUN_00407f30(apupd_db_mutex);
  }
  return uVar2;
}

