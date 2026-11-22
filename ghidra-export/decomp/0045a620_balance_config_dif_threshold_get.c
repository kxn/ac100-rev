// func balance_config_dif_threshold_get @ 0045a620 size=1

undefined4 balance_config_dif_threshold_get(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    uVar1 = 0;
  }
  return uVar1;
}

