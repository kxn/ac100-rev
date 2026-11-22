// func uac_mutex_create @ 00522d4c size=380

pthread_mutex_t * uac_mutex_create(char *param_1,uint param_2)

{
  size_t __n;
  size_t sVar1;
  char *__dest;
  pthread_mutex_t *__mutex;
  pthread_mutexattr_t apStack_20 [3];
  
  __mutex = (pthread_mutex_t *)0x0;
  if ((param_2 < 2) && (param_1 != (char *)0x0)) {
    __n = strlen(param_1);
    __mutex = (pthread_mutex_t *)uac_mem_calloc_my(1,0x34,0x7b);
    if (__mutex != (pthread_mutex_t *)0x0) {
      __mutex[1].__data.__lock = 0;
      sVar1 = strlen(param_1);
      __dest = (char *)uac_mem_calloc_my(1,sVar1 + 1,0x7f);
      __mutex[1].__data.__lock = (int)__dest;
      if (__dest == (char *)0x0) {
        uac_mem_free_my(__mutex);
        __mutex = (pthread_mutex_t *)0x0;
      }
      else {
        strncpy(__dest,param_1,__n);
        *(uint *)((int)__mutex + 0x1c) = param_2;
        pthread_mutexattr_init(apStack_20);
        pthread_mutexattr_settype(apStack_20,param_2);
        pthread_mutex_init(__mutex,apStack_20);
        pthread_mutexattr_destroy(apStack_20);
        pthread_mutex_lock((pthread_mutex_t *)&uac_sync_mutex);
        uac_list_insert_last(&uac_mutex_list,(int)__mutex + 0x28);
        pthread_mutex_unlock((pthread_mutex_t *)&uac_sync_mutex);
      }
    }
  }
  return __mutex;
}

