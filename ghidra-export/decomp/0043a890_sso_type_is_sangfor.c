// func sso_type_is_sangfor @ 0043a890 size=80

bool sso_type_is_sangfor(void)

{
  int iVar1;
  
  FUN_004082d0(wportal_sso_notify_config_mutex,0xffffffff);
  iVar1 = g_sso_type;
  FUN_00407f30(wportal_sso_notify_config_mutex);
  return iVar1 == 1;
}

