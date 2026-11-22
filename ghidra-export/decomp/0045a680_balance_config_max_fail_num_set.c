// func balance_config_max_fail_num_set @ 0045a680 size=24

undefined4 balance_config_max_fail_num_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  return uVar1;
}

