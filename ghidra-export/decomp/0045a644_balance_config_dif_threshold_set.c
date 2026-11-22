// func balance_config_dif_threshold_set @ 0045a644 size=24

undefined4 balance_config_dif_threshold_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0xc) = param_2;
  }
  return uVar1;
}

