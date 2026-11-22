// func cJSON_get_int_else_keep @ 00674b8c size=1

undefined4
cJSON_get_int_else_keep(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_t9;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    uVar1 = 0xffffffff;
    if (**(int **)(in_t9 + 0xe498c) != 0) {
      (**(code **)(in_t9 + 0xe4d44))
                (*(int *)(in_t9 + 0xe484c) + 0xff0,*(int *)(in_t9 + 0xe484c) + 0x10f0,0x84,param_4,
                 in_t9 + 0xec574);
    }
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}

