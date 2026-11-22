// func wportal_db_rds_srv_traverse @ 0042f604 size=1

undefined4 wportal_db_rds_srv_traverse(undefined4 param_1,undefined4 param_2)

{
  FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
  FUN_004083c0(rds_srv_tree_index,param_1,param_2);
  FUN_00407f30(wportal_rds_srv_mutex);
  return 0;
}

