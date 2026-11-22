// func uac_sqlite_init_int32_key_array @ 005225d8 size=192

undefined4 uac_sqlite_init_int32_key_array(undefined4 *param_1,undefined4 *param_2,size_t param_3)

{
  void *pvVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    pvVar1 = (void *)*param_1;
    if ((param_2 == (undefined4 *)0x0) || (pvVar1 != (void *)0x0)) {
      if (pvVar1 != (void *)0x0) {
        memset(pvVar1,-1,param_3);
      }
    }
    else if (0 < (int)param_3) {
      pvVar1 = (void *)uac_mem_malloc_my(param_3 << 2,0x176);
      *param_1 = pvVar1;
      if (pvVar1 == (void *)0x0) {
        return 0xffffffff;
      }
      memset(pvVar1,-1,param_3);
      *param_2 = 0;
      return 0;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  return 0xffffffff;
}

