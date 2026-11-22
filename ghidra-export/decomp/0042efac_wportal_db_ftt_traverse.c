// func wportal_db_ftt_traverse @ 0042efac size=100

undefined4 wportal_db_ftt_traverse(undefined4 param_1,undefined4 param_2)

{
  FUN_004082d0(wportal_ftt_mutex,0xffffffff);
  FUN_004083c0(ftt_tree,param_1,param_2);
  FUN_00407f30(wportal_ftt_mutex);
  return 0;
}

