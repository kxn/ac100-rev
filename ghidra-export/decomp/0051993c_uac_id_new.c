// func uac_id_new @ 0051993c size=292

int * uac_id_new(int param_1)

{
  int iVar1;
  void *__s;
  int iVar2;
  int *__s_00;
  size_t __n;
  
  __s_00 = (int *)0x0;
  if ((0 < param_1) && (__s_00 = (int *)uac_mem_malloc_my(0x18,0x56), __s_00 != (int *)0x0)) {
    memset(__s_00,0,0x18);
    __s_00[4] = param_1;
    iVar1 = uac_mem_malloc_my(param_1 << 2,0x5f);
    *__s_00 = iVar1;
    if (iVar1 != 0) {
      __n = (param_1 + 0x1fU >> 5) << 2;
      __s = (void *)uac_mem_malloc_my(__n,0x67);
      __s_00[1] = (int)__s;
      if (__s != (void *)0x0) {
        memset(__s,0,__n);
        iVar1 = 0;
        iVar2 = *__s_00;
        while( true ) {
          *(int *)(iVar2 + iVar1 * 4) = iVar1;
          iVar1 = iVar1 + 1;
          if (iVar1 == param_1) break;
          iVar2 = *__s_00;
        }
        return __s_00;
      }
      uac_mem_free_my(*__s_00);
    }
    uac_mem_free_my(__s_00);
    __s_00 = (int *)0x0;
  }
  return __s_00;
}

