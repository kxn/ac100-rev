// func uac_thread_get_info_by_tid @ 00523f54 size=252

undefined4 uac_thread_get_info_by_tid(undefined4 param_1,void *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *__src;
  
  uVar2 = 0xffffffff;
  if (param_2 != (void *)0x0) {
    memset(param_2,0,0x4c);
    pthread_mutex_lock((pthread_mutex_t *)&uac_thread_mutex);
    iVar3 = uac_list_first(&uac_thread_list);
    do {
      if (iVar3 == 0) {
        uVar2 = 0xffffffff;
        goto LAB_00524024;
      }
      __src = (void *)(iVar3 + -0x40);
      iVar4 = uac_list_next(iVar3);
      piVar1 = (int *)(iVar3 + -0x14);
      iVar3 = iVar4;
    } while (*(int *)((int)param_2 + 0x2c) != *piVar1);
    memcpy(param_2,__src,0x4c);
    uVar2 = 0;
LAB_00524024:
    pthread_mutex_unlock((pthread_mutex_t *)&uac_thread_mutex);
  }
  return uVar2;
}

