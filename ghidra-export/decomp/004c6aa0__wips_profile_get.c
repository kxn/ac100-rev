// func _wips_profile_get @ 004c6aa0 size=60

undefined4 _wips_profile_get(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  iVar1 = FUN_0051eb48("sensor",param_1,local_10);
  if (iVar1 != 0) {
    local_10[0] = 0xffffffff;
  }
  return local_10[0];
}

