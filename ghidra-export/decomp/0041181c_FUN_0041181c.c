// func FUN_0041181c @ 0041181c size=248

int FUN_0041181c(undefined4 param_1,undefined1 param_2,undefined1 param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = (uint)CONCAT11(param_2,param_3);
  local_20 = 0;
  local_18 = param_1;
  memcpy(&local_20,param_4,6);
  iVar1 = FUN_004081b0(&l_wportal_sta_access_check_reg);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(int **)(iVar1 + 0x34) == (int *)0x0) || (iVar3 = **(int **)(iVar1 + 0x34), iVar3 == 0)) {
      iVar3 = 0;
    }
    iVar3 = (**(code **)(iVar1 + 0x30))(&local_20,iVar3);
    if (iVar3 != 0) break;
    iVar1 = FUN_00408680(iVar1);
  }
  if (wportal_info_switch == 0) {
    return iVar3;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return iVar3;
  }
  printf("[WPORTAL_INFO]%s()/%d _wportal_sta_access_do_check() OK, reg[%s].\n",
         "_wportal_sta_access_do_check",0x2619,iVar1 + 0xc);
  return iVar3;
}

