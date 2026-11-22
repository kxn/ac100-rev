// func wportal_db_rds_srv_add @ 0042f010 size=96

undefined4 wportal_db_rds_srv_add(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
    uVar1 = FUN_00407e20(rds_srv_tree_index,param_1);
    FUN_00407f30(wportal_rds_srv_mutex);
  }
  return uVar1;
}

