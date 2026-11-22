// func rrm_adjust_cur_pwr @ 004ab300 size=72

void rrm_adjust_cur_pwr(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = rrm_transfer_pwr_to_level(param_1,param_2,param_3);
  rrm_transfer_level_to_power(uVar1,param_2,param_3);
  return;
}

