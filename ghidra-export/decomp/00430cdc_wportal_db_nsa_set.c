// func wportal_db_nsa_set @ 00430cdc size=140

undefined4 wportal_db_nsa_set(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_nsa_mutex,0xffffffff);
    iVar1 = FUN_004080c0(nsa_tree,param_1);
    if (iVar1 == 0) {
      FUN_00407f30(wportal_nsa_mutex);
    }
    else {
      _wportal_db_nsa_copy(iVar1,param_1);
      uVar2 = 0;
      FUN_00407f30(wportal_nsa_mutex);
    }
  }
  return uVar2;
}

