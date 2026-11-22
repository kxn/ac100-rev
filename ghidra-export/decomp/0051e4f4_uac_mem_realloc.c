// func uac_mem_realloc @ 0051e4f4 size=112

void * uac_mem_realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
  if (param_1 == (void *)0x0) {
    if (0 < (int)param_2) {
      pvVar1 = (void *)uac_mem_malloc_my(param_2,0x193);
      return pvVar1;
    }
  }
  else {
    if (0 < (int)param_2) {
      pvVar1 = realloc(param_1,param_2);
      return pvVar1;
    }
    uac_mem_free_my();
  }
  return (void *)0x0;
}

