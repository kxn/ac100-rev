// func _radius_auth_type_str2int @ 004404f4 size=180

undefined4 _radius_auth_type_str2int(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strcmp(param_1,"pap");
  uVar2 = 1;
  if (iVar1 != 0) {
    iVar1 = strcmp(param_1,"chap");
    uVar2 = 2;
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"mschap");
      uVar2 = 3;
      if (iVar1 != 0) {
        iVar1 = strcmp(param_1,"mschapv2");
        uVar2 = 4;
        if (iVar1 != 0) {
          uVar2 = 0xffffffff;
        }
      }
    }
  }
  return uVar2;
}

