// func wportal_db_cmcc_get_wq @ 004333d8 size=160

undefined4 wportal_db_cmcc_get_wq(void *param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined1 auStack_48 [40];
  undefined1 auStack_20 [20];
  
  memset(auStack_48,0,0x34);
  memcpy(auStack_20,param_1,6);
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

