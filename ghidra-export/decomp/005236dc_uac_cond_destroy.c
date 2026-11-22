// func uac_cond_destroy @ 005236dc size=120

void uac_cond_destroy(pthread_cond_t *param_1)

{
  if (param_1 != (pthread_cond_t *)0x0) {
    pthread_cond_destroy(param_1);
    if (param_1[1].__data.__lock != 0) {
      uac_mem_free_my();
      param_1[1].__data.__lock = 0;
    }
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

