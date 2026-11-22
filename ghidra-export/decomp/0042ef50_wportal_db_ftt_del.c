// func wportal_db_ftt_del @ 0042ef50 size=92

undefined4 wportal_db_ftt_del(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_ftt_mutex,0xffffffff);
    FUN_00408690(ftt_tree,param_1);
    FUN_00407f30(wportal_ftt_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

