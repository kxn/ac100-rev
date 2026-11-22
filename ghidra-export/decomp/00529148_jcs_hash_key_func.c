// func jcs_hash_key_func @ 00529148 size=152

undefined4 jcs_hash_key_func(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_t9;
  
  if (param_1 == 0) {
    if (**(int **)(in_t9 + 0x2300a8) != 0) {
      (**(code **)(in_t9 + 0x230788))
                (*(int *)(in_t9 + 0x22ffe0) + 0x5004,*(int *)(in_t9 + 0x22ffe0) + 0x53a8,0x6f,
                 param_4,in_t9 + 0x237fb8);
    }
    return 0;
  }
  uVar1 = (**(code **)(in_t9 + 0x2304d4))();
  uVar1 = uac_hash_update(param_1,uVar1,0);
  return uVar1;
}

