// func wportal_db_ftt_add @ 0042e09c size=96

undefined4 wportal_db_ftt_add(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_ftt_mutex,0xffffffff);
    uVar1 = FUN_00407e20(ftt_tree,param_1);
    FUN_00407f30(wportal_ftt_mutex);
  }
  return uVar1;
}

