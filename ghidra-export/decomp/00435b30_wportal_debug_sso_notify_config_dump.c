// func wportal_debug_sso_notify_config_dump @ 00435b30 size=1

void wportal_debug_sso_notify_config_dump(void)

{
  char *pcVar1;
  
  FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
  if (g_sso_type == 1) {
    pcVar1 = "sangfor";
  }
  else {
    pcVar1 = "none";
  }
  printf("sso_enable: %d\tsso_type:%d(%s)\n",g_sso_notify_enable,g_sso_type,pcVar1);
  if (g_sso_type == 1) {
    printf("sso_sangfor_server: %s\tsso_sangfor_port:%d\n",&g_sangfor_sso_config,DAT_0075a2d0);
  }
  uac_mutex_give(wportal_sso_notify_config_mutex);
  return;
}

