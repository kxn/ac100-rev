// func uac_sem_destroy @ 00523444 size=120

void uac_sem_destroy(sem_t *param_1)

{
  if (param_1 != (sem_t *)0x0) {
    sem_destroy(param_1);
    if (param_1[1].__align != 0) {
      uac_mem_free_my();
      param_1[1].__align = 0;
    }
    uac_mem_free_my(param_1);
    return;
  }
  return;
}

