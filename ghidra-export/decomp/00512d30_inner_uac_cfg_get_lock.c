// func inner_uac_cfg_get_lock @ 00512d30 size=656

void inner_uac_cfg_get_lock(undefined4 param_1)

{
  pthread_key_t __key;
  void *__pointer;
  int iVar1;
  pthread_t pVar2;
  
  __pointer = uac_thread_get_tsd(cfg_tsd_key);
  if (uac_cfg_dbg_switch != 0) {
    printf("[UAC_CFG_DEBUG]%s()/line %d : [%s()]Get lock\n","inner_uac_cfg_get_lock",0x154,param_1);
  }
  if (__pointer == (void *)0x0) {
    __pointer = (void *)uac_mem_calloc_my(1,0x18,0x158);
    if (__pointer == (void *)0x0) {
      return;
    }
    pVar2 = pthread_self();
    __key = cfg_tsd_key;
    *(pthread_t *)((int)__pointer + 0xc) = pVar2;
    *(undefined4 *)((int)__pointer + 0x10) = 0;
    *(undefined4 *)((int)__pointer + 0x14) = 0;
    iVar1 = uac_thread_set_tsd(__key,__pointer);
    if (iVar1 != 0) {
      if (uac_cfg_err_switch != 0) {
        printf("[UAC_CFG_ERROR]%s()/line %d : Set tsd failed, Tid: %p\n","inner_uac_cfg_get_lock",
               0x167,*(undefined4 *)((int)__pointer + 0xc));
      }
      uac_mem_free_my(__pointer);
      return;
    }
    pthread_mutex_lock((pthread_mutex_t *)&cfg_mutex);
    uac_list_insert_last(&cfg_tsd_list,__pointer);
    pthread_mutex_unlock((pthread_mutex_t *)&cfg_mutex);
    if (uac_cfg_dbg_switch != 0) {
      printf("[UAC_CFG_DEBUG]%s()/line %d : Alloc new tsd data, Tid: %p\n","inner_uac_cfg_get_lock",
             0x163,*(undefined4 *)((int)__pointer + 0xc));
    }
  }
  if (*(int *)((int)__pointer + 0x10) == 0) {
    if (uac_cfg_dbg_switch != 0) {
      printf("[UAC_CFG_DEBUG]%s()/line %d : Try first lock. Tid: %p\n","inner_uac_cfg_get_lock",
             0x174,*(undefined4 *)((int)__pointer + 0xc));
    }
    while (iVar1 = 1, l_cfg_lock == 1) {
      usleep(25000);
    }
    *(undefined4 *)((int)__pointer + 0x10) = 1;
  }
  else {
    if (uac_cfg_dbg_switch != 0) {
      printf("[UAC_CFG_DEBUG]%s()/line %d : Recursive lock, increase count. Tid: %p\n",
             "inner_uac_cfg_get_lock",0x16f,*(undefined4 *)((int)__pointer + 0xc));
    }
    iVar1 = *(int *)((int)__pointer + 0x14) + 1;
  }
  *(int *)((int)__pointer + 0x14) = iVar1;
  if (uac_cfg_dbg_switch != 0) {
    printf("[UAC_CFG_DEBUG]%s()/line %d : Tid: %p, Lock state: %d, count: %d\n",
           "inner_uac_cfg_get_lock",0x17a,*(undefined4 *)((int)__pointer + 0xc),
           *(undefined4 *)((int)__pointer + 0x10),*(undefined4 *)((int)__pointer + 0x14));
  }
  return;
}

