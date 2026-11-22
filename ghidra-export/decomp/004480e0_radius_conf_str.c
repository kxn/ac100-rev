// func radius_conf_str @ 004480e0 size=68

undefined4 radius_conf_str(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _radius_find_option(param_1,param_2,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x48);
  }
  return uVar2;
}

