// func _wportal_auth_server_type_str2int @ 00411728 size=108

undefined4 _wportal_auth_server_type_str2int(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_1,"local");
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"remote");
    uVar2 = 1;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"tmp");
      uVar2 = 99;
      if (iVar1 != 0) {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}

