// func uac_thread_set_cookie @ 00523da8 size=88

void uac_thread_set_cookie(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = uac_thread_get_tsd(tinfo_tsd_key);
  if (pvVar1 != (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x30) = param_1;
    *(int *)((int)pvVar1 + 0x34) = *(int *)((int)pvVar1 + 0x34) + 1;
  }
  return;
}

