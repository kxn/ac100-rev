// func wportal_rds_srv_get_by_index @ 004208c0 size=8

undefined4 wportal_rds_srv_get_by_index(undefined4 param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined4 auStackX_0 [4];
  
  uVar1 = 0xffffffff;
  if (param_2 != (void *)0x0) {
    auStackX_0[0] = param_1;
    FUN_004082d0(wportal_rds_srv_mutex,0xffffffff);
    __src = (void *)FUN_004080c0(rds_srv_tree_index,auStackX_0);
    if (__src == (void *)0x0) {
      FUN_00407f30(wportal_rds_srv_mutex);
    }
    else {
      memcpy(param_2,__src,0x134);
      uVar1 = 0;
      FUN_00407f30(wportal_rds_srv_mutex);
    }
  }
  return uVar1;
}

