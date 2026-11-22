// func cw_ac_recieve_queue_low_threshold_cb @ 0058f428 size=148

undefined4 cw_ac_recieve_queue_low_threshold_cb(int param_1)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (((param_1 != 0) && (ac != 0)) && (__s = (void *)FUN_00408450(0x10,0xc9c), __s != (void *)0x0))
  {
    memset(__s,0,0x10);
    iVar1 = ac;
    uVar2 = 0;
    *(int *)((int)__s + 0xc) = param_1;
    FUN_004086b0(iVar1 + 0xcc3c,__s);
  }
  return uVar2;
}

