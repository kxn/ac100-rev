// func cJSON_get_int_8 @ 00674970 size=132

undefined4 cJSON_get_int_8(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_t9;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    uVar1 = 0xffffffff;
    if (**(int **)(in_t9 + 0xe4ba8) != 0) {
      (**(code **)(in_t9 + 0xe4f60))
                (*(int *)(in_t9 + 0xe4a68) + 0xff0,*(int *)(in_t9 + 0xe4a68) + 0x10a0,0x44,param_4,
                 in_t9 + 0xec790);
    }
  }
  else {
    uVar1 = 0;
    *param_2 = (char)*(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}

