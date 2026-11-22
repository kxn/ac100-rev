// func wportal_db_rds_srv_hash_del @ 0042f714 size=116

undefined4 wportal_db_rds_srv_hash_del(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
  iVar1 = FUN_004080c0(rds_srv_tree_index,local_res0);
  if (iVar1 == 0) {
    FUN_00407f30(wportal_rds_srv_mutex);
    uVar2 = 0xffffffff;
  }
  else {
    FUN_00407f40(rds_srv_hash_addr,iVar1);
    FUN_00407f30(wportal_rds_srv_mutex);
    uVar2 = 0;
  }
  return uVar2;
}

