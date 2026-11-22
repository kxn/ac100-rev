// func uac_mutex_destroy @ 00522ec8 size=196

void uac_mutex_destroy(pthread_mutex_t *param_1)

{
  if (param_1 != (pthread_mutex_t *)0x0) {
    pthread_mutex_destroy(param_1);
    pthread_mutex_lock((pthread_mutex_t *)&uac_sync_mutex);
    uac_list_remove((int)param_1 + 0x28);
    pthread_mutex_unlock((pthread_mutex_t *)&uac_sync_mutex);
    if (param_1[1].__data.__lock != 0) {
      uac_mem_free_my();
      param_1[1].__data.__lock = 0;
    }
    uac_mem_free_my(param_1);
    return;
  }
  puts("WARNING: Try to destroy NULL mutex.");
  return;
}

