// func wportal_db_rds_srv_set @ 0042f4ec size=144

undefined4 wportal_db_rds_srv_set(void *param_1)

{
  void *__dest;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
    __dest = (void *)FUN_004080c0(rds_srv_tree_index,(int)param_1 + 0x108);
    if (__dest == (void *)0x0) {
      FUN_00407f30(wportal_rds_srv_mutex);
    }
    else {
      memcpy(__dest,param_1,0x134);
      uVar1 = 0;
      FUN_00407f30(wportal_rds_srv_mutex);
    }
  }
  return uVar1;
}

