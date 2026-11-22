// func wportal_db_cmcc_get_wq_by_ip @ 00433478 size=148

undefined4 wportal_db_cmcc_get_wq_by_ip(undefined4 param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  
  memset(auStack_48,0,0x34);
  local_28 = param_1;
  FUN_004082d0(wportal_cmcc_waitque_mutex,0xffffffff);
  __src = (void *)FUN_004080c0(cmcc_wq_tree,auStack_48);
  if (__src == (void *)0x0) {
    FUN_00407f30(wportal_cmcc_waitque_mutex);
    uVar1 = 0xffffffff;
  }
  else {
    memcpy(param_2,__src,0x34);
    FUN_00407f30(wportal_cmcc_waitque_mutex);
    uVar1 = 0;
  }
  return uVar1;
}

