// func wportal_db_ftt_get_by_name @ 0042ee20 size=160

undefined4 wportal_db_ftt_get_by_name(int param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    FUN_004082d0(wportal_ftt_mutex,0xffffffff);
    __src = (void *)FUN_004080c0(ftt_tree,param_1);
    if (__src == (void *)0x0) {
      FUN_00407f30(wportal_ftt_mutex);
    }
    else {
      memcpy(param_2,__src,0x144);
      uVar1 = 0;
      FUN_00407f30(wportal_ftt_mutex);
    }
  }
  return uVar1;
}

