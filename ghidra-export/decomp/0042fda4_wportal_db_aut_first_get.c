// func wportal_db_aut_first_get @ 0042fda4 size=1

undefined4 wportal_db_aut_first_get(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar1 = FUN_004081b0(aut_list);
    if (iVar1 == 0) {
      FUN_00407f30(wportal_aut_mutex);
    }
    else {
      _wportal_db_aut_copy(param_1,iVar1);
      uVar2 = 0;
      FUN_00407f30(wportal_aut_mutex);
    }
  }
  return uVar2;
}

