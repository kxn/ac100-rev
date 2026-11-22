// func _macauth_enable_str2int @ 0044c1b8 size=36

bool _macauth_enable_str2int(char *param_1)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,"on");
  return iVar1 == 0;
}

