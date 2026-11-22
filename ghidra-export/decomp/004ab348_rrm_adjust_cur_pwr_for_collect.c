// func rrm_adjust_cur_pwr_for_collect @ 004ab348 size=188

void rrm_adjust_cur_pwr_for_collect(uint param_1,undefined1 param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 & 0xff;
  iVar1 = rrm_transfer_pwr_to_level(param_1,param_2,param_3);
  uVar2 = rrm_transfer_level_to_power(iVar1,param_2,param_3);
  if (param_4 == 0) {
    if (uVar2 <= param_1) {
      return;
    }
    uVar3 = iVar1 - 1;
  }
  else {
    uVar3 = iVar1 + 1;
    if (param_1 <= uVar2) {
      return;
    }
  }
  rrm_transfer_level_to_power(uVar3 & 0xff,param_2,param_3);
  return;
}

