// func uac_thread_create @ 00523990 size=448

undefined4 uac_thread_create(pthread_t *param_1,char *param_2,int param_3,int param_4)

{
  int iVar1;
  int *__s;
  char *__format;
  undefined4 uVar2;
  pthread_attr_t pStack_40;
  
  if (((param_1 == (pthread_t *)0x0) || (param_3 == 0)) || (param_2 == (char *)0x0)) {
    uVar2 = 0xaf;
    __format = "[THREAD_ERR]%s %d: inputs error.\r\n";
  }
  else {
    iVar1 = pthread_attr_init(&pStack_40);
    if (iVar1 == 0) {
      pthread_attr_setstacksize(&pStack_40,0x10000);
      __s = (int *)uac_mem_malloc_my(0x4c,0xba);
      if (__s == (int *)0x0) {
        pthread_attr_destroy(&pStack_40);
        uVar2 = 0xbe;
        __format = "[THREAD_ERR]%s %d: malloc failed.\r\n";
      }
      else {
        memset(__s,0,0x4c);
        *__s = param_3;
        __s[9] = param_4;
        strncpy((char *)(__s + 1),param_2,0x1f);
        iVar1 = pthread_create(param_1,&pStack_40,_uac_thread_boot,__s);
        if (iVar1 == 0) {
          pthread_attr_destroy(&pStack_40);
          return 0;
        }
        pthread_attr_destroy(&pStack_40);
        uac_mem_free_my(__s);
        uVar2 = 0xcb;
        __format = "[THREAD_ERR]%s %d: create thread failed.\r\n";
      }
    }
    else {
      uVar2 = 0xb5;
      __format = "[THREAD_ERR]%s %d: pthread_attr_init error.\r\n";
    }
  }
  printf(__format,"uac_thread_create",uVar2);
  return 0xffffffff;
}

