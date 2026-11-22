// func uac_sem_create @ 00523340 size=260

sem_t * uac_sem_create(char *param_1,uint param_2)

{
  size_t __n;
  size_t sVar1;
  char *__dest;
  sem_t *__sem;
  
  __sem = (sem_t *)0x0;
  if (param_1 != (char *)0x0) {
    __n = strlen(param_1);
    __sem = (sem_t *)uac_mem_calloc_my(1,0x14,0x15f);
    if (__sem != (sem_t *)0x0) {
      __sem[1].__align = 0;
      sVar1 = strlen(param_1);
      __dest = (char *)uac_mem_calloc_my(1,sVar1 + 1,0x166);
      __sem[1].__align = (long)__dest;
      if (__dest == (char *)0x0) {
        uac_mem_free_my(__sem);
        __sem = (sem_t *)0x0;
      }
      else {
        strncpy(__dest,param_1,__n);
        sem_init(__sem,0,param_2);
      }
    }
  }
  return __sem;
}

