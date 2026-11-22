// func _sso_notify_auth_leave @ 0043a8e0 size=64

undefined4 _sso_notify_auth_leave(int param_1)

{
  int iVar1;
  
  iVar1 = sso_type_is_sangfor();
  if (iVar1 != 0) {
    _sso_notify_sangfor_server(0,param_1 + 0xa3,param_1 + 0x58);
  }
  return 0;
}

