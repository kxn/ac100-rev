// func sso_notify_deInit @ 0043a864 size=44

void sso_notify_deInit(void)

{
  FUN_00408360(wportal_sso_notify_config_mutex);
  wportal_sso_notify_config_mutex = 0;
  return;
}

