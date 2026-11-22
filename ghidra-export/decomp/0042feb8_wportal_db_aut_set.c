// func wportal_db_aut_set @ 0042feb8 size=184

undefined4 wportal_db_aut_set(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_1 != 0) &&
     ((iVar1 = wportal_get_mode(), iVar1 != 0 ||
      ((-1 < *(int *)(param_1 + 0x14) &&
       (uVar2 = wserv_profile_get_max_wservice(), *(uint *)(param_1 + 0x14) < uVar2)))))) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar1 = FUN_004080c0(aut_tree,param_1);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      FUN_00407f30(wportal_aut_mutex);
    }
    else {
      _wportal_db_aut_copy(iVar1,param_1);
      uVar3 = 0;
      FUN_00407f30(wportal_aut_mutex);
    }
  }
  return uVar3;
}

