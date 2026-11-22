// func cw_ac_manager_data_destroy @ 00589b30 size=104

void cw_ac_manager_data_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  while (iVar1 = FUN_004081b0(param_1), iVar1 != 0) {
    FUN_00408500(iVar1);
    FUN_00407df0(iVar1);
  }
  FUN_00407df0(param_1);
  return;
}

