// func cJSON_get_int_else_default @ 00674afc size=1

undefined4
cJSON_get_int_else_default(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int in_t9;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 3)) {
    if (**(int **)(in_t9 + 0xe4a1c) == 0) {
      *param_3 = param_2;
    }
    else {
      (**(code **)(in_t9 + 0xe4dd4))
                (*(int *)(in_t9 + 0xe48dc) + 0xff0,*(int *)(in_t9 + 0xe48dc) + 0x10d4,0x74,param_4,
                 in_t9 + 0xec604);
      *param_3 = param_2;
    }
  }
  else {
    *param_3 = *(undefined4 *)(param_1 + 0x14);
  }
  return 0;
}

