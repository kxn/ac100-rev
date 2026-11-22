// func uac_thread_traverse_list @ 00523e00 size=204

void uac_thread_traverse_list(code *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (code *)0x0) {
    return;
  }
  pthread_mutex_lock((pthread_mutex_t *)&uac_thread_mutex);
  iVar1 = uac_list_first(&uac_thread_list);
  while (iVar1 != 0) {
    iVar2 = iVar1 + -0x40;
    iVar1 = uac_list_next(iVar1);
    (*param_1)(iVar2);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&uac_thread_mutex);
  return;
}

