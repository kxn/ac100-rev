// func uac_cond_wait @ 00523754 size=276

undefined4 uac_cond_wait(pthread_cond_t *param_1,pthread_mutex_t *param_2,int param_3)

{
  pthread_t pVar1;
  int iVar2;
  char *__format;
  timespec local_20;
  
  local_20.tv_sec = 0;
  local_20.tv_nsec = 0;
  pVar1 = pthread_self();
  if (*(int *)((int)param_2 + 0x1c) == 0) {
    if (*(pthread_t *)((int)param_2 + 0x20) == pVar1) {
      *(undefined4 *)((int)param_2 + 0x20) = 0;
      *(undefined4 *)((int)param_2 + 0x24) = 0;
      if (param_3 == -1) {
        iVar2 = pthread_cond_wait(param_1,param_2);
      }
      else {
        uac_compute_timeout_ms(&local_20,param_3);
        iVar2 = pthread_cond_timedwait(param_1,param_2,&local_20);
      }
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      *(pthread_t *)((int)param_2 + 0x20) = pVar1;
      *(int *)((int)param_2 + 0x24) = *(int *)((int)param_2 + 0x24) + 1;
      return 0;
    }
    __format = "Error: cond_wait \"%s\" use mutex \"%s\" that has not been taken before.\n";
  }
  else {
    __format = "Error: cond \"%s\" use INCORRECT type of mutex \"%s\".\n";
  }
  printf(__format,param_1[1].__data.__lock,param_2[1].__data.__lock);
  return 0xffffffff;
}

