// func uac_cond_create @ 005235e8 size=244

pthread_cond_t * uac_cond_create(char *param_1)

{
  size_t __n;
  size_t sVar1;
  char *__dest;
  pthread_cond_t *__cond;
  
  __cond = (pthread_cond_t *)0x0;
  if (param_1 != (char *)0x0) {
    __n = strlen(param_1);
    __cond = (pthread_cond_t *)uac_mem_calloc_my(1,0x38,0x1c7);
    if (__cond != (pthread_cond_t *)0x0) {
      __cond[1].__data.__lock = 0;
      sVar1 = strlen(param_1);
      __dest = (char *)uac_mem_calloc_my(1,sVar1 + 1,0x1ce);
      __cond[1].__data.__lock = (int)__dest;
      if (__dest == (char *)0x0) {
        uac_mem_free_my(__cond);
        __cond = (pthread_cond_t *)0x0;
      }
      else {
        strncpy(__dest,param_1,__n);
        pthread_cond_init(__cond,(pthread_condattr_t *)0x0);
      }
    }
  }
  return __cond;
}

