// func sso_enable_set @ 0043a960 size=100

undefined4 sso_enable_set(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    param_2 = 0;
  }
  FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
  g_sso_type = param_2;
  g_sso_notify_enable = param_1;
  FUN_00407f30(wportal_sso_notify_config_mutex);
  return 0;
}

