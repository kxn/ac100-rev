// func sso_sangfor_config_set @ 0043a9c4 size=116

undefined4 sso_sangfor_config_set(char *param_1,undefined4 param_2)

{
  FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
  strncpy(&g_sangfor_sso_config,param_1,0x100);
  DAT_0075a2d0 = param_2;
  FUN_00407f30(wportal_sso_notify_config_mutex);
  return 0;
}

