// func uac_sync_init @ 00522cac size=160

void uac_sync_init(void)

{
  pthread_mutexattr_t apStack_10 [2];
  
  if (DAT_007c3b70 == 0) {
    pthread_mutexattr_init(apStack_10);
    pthread_mutexattr_settype(apStack_10,1);
    pthread_mutex_init((pthread_mutex_t *)&uac_sync_mutex,apStack_10);
    pthread_mutexattr_destroy(apStack_10);
    uac_list_init(&uac_mutex_list);
    DAT_007c3b70 = 1;
  }
  return;
}

