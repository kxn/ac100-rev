// func _sso_notify_auth_join @ 0043a920 size=64

undefined4 _sso_notify_auth_join(int param_1)

{
  int iVar1;
  
  iVar1 = sso_type_is_sangfor();
  if (iVar1 != 0) {
    _sso_notify_sangfor_server(1,param_1 + 0xa3,param_1 + 0x58);
  }
  return 0;
}

