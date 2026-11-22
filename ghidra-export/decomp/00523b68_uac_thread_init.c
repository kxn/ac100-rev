// func uac_thread_init @ 00523b68 size=184

void uac_thread_init(void)

{
  pthread_mutexattr_t apStack_10 [2];
  
  if (DAT_007c3ba0 == 0) {
    pthread_mutexattr_init(apStack_10);
    pthread_mutexattr_settype(apStack_10,1);
    pthread_mutex_init((pthread_mutex_t *)&uac_thread_mutex,apStack_10);
    pthread_mutexattr_destroy(apStack_10);
    uac_thread_key_create(&tinfo_tsd_key,(__destr_function *)0x0);
    uac_list_init(&uac_thread_list);
    DAT_007c3ba0 = 1;
  }
  return;
}

