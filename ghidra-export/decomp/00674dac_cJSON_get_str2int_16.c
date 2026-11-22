// func cJSON_get_str2int_16 @ 00674dac size=1

undefined4 cJSON_get_str2int_16(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int in_t9;
  undefined1 auStack_50 [68];
  
  (**(code **)(in_t9 + 0xe49fc))(auStack_50,0,0x40);
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) != 4)) {
    uVar2 = 0xffffffff;
    if (**(int **)(in_t9 + 0xe476c) != 0) {
      (**(code **)(in_t9 + 0xe4b24))
                (*(int *)(in_t9 + 0xe462c) + 0xff0,*(int *)(in_t9 + 0xe462c) + 0x1130,0xb9);
    }
  }
  else {
    uVar2 = 0;
    (**(code **)(in_t9 + 0xe48e0))(auStack_50,*(undefined4 *)(param_1 + 0x10),0x40);
    uVar1 = (**(code **)(in_t9 + 0xe4968))(auStack_50);
    *param_2 = uVar1;
  }
  return uVar2;
}

