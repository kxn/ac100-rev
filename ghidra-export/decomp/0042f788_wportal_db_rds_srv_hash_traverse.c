// func wportal_db_rds_srv_hash_traverse @ 0042f788 size=96

undefined4
wportal_db_rds_srv_hash_traverse
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
  FUN_004080d0(rds_srv_hash_addr,&local_res0,param_6,param_7);
  FUN_00407f30(wportal_rds_srv_mutex);
  return 0;
}

