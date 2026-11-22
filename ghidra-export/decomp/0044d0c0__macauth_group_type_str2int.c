// func _macauth_group_type_str2int @ 0044d0c0 size=84

undefined4 _macauth_group_type_str2int(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_1,"whitelist");
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"blacklist");
    uVar2 = 1;
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

