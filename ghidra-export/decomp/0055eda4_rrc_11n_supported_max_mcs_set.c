// func rrc_11n_supported_max_mcs_set @ 0055eda4 size=24

undefined4 rrc_11n_supported_max_mcs_set(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x194) = param_2;
  }
  return uVar1;
}

