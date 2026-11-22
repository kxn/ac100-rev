// func radius_dict_getattr_by_value @ 00448124 size=56

void radius_dict_getattr_by_value(int param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  uac_hash_get(*(undefined4 *)(param_1 + 0x10),local_res4);
  return;
}

