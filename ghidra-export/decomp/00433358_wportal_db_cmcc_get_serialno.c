// func wportal_db_cmcc_get_serialno @ 00433358 size=128

undefined4 wportal_db_cmcc_get_serialno(undefined2 param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined2 local_res0 [8];
  
  local_res0[0] = param_1;
  FUN_004082d0(wportal_cmcc_serialno_mutex,0xffffffff);
  __src = (void *)FUN_004080c0(cmcc_serialno_tree,local_res0);
  if (__src == (void *)0x0) {
    FUN_00407f30(wportal_cmcc_serialno_mutex);
    uVar1 = 0xffffffff;
  }
  else {
    memcpy(param_2,__src,0x20);
    FUN_00407f30(wportal_cmcc_serialno_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

