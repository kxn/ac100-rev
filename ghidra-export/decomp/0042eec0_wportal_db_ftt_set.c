// func wportal_db_ftt_set @ 0042eec0 size=144

undefined4 wportal_db_ftt_set(void *param_1)

{
  void *__dest;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    FUN_004082d0(wportal_ftt_mutex,0xffffffff);
    __dest = (void *)FUN_004080c0(ftt_tree,param_1);
    if (__dest == (void *)0x0) {
      FUN_00407f30(wportal_ftt_mutex);
    }
    else {
      memcpy(__dest,param_1,0x144);
      uVar1 = 0;
      FUN_00407f30(wportal_ftt_mutex);
    }
  }
  return uVar1;
}

