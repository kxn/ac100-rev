// func uac_thread_get_info @ 00523ecc size=136

undefined4 uac_thread_get_info(void *param_1)

{
  void *__src;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x4c);
    __src = uac_thread_get_tsd(tinfo_tsd_key);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_1,__src,0x4c);
    }
  }
  return uVar1;
}

