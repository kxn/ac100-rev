// func cw_send_pkt_create @ 00588090 size=144

void * cw_send_pkt_create(int param_1,undefined1 param_2)

{
  int iVar1;
  void *__s;
  
  __s = (void *)0x0;
  if ((0 < param_1) && (__s = (void *)FUN_00408450(0x48,0x4c0), __s != (void *)0x0)) {
    memset(__s,0,0x48);
    iVar1 = FUN_00408450(param_1,0x4c4);
    *(int *)((int)__s + 0x10) = iVar1;
    if (iVar1 == 0) {
      FUN_00407df0(__s);
    }
    else {
      *(int *)((int)__s + 0x18) = param_1;
      *(undefined1 *)((int)__s + 0x38) = param_2;
    }
  }
  return __s;
}

