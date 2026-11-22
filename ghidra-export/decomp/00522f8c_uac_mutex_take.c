// func uac_mutex_take @ 00522f8c size=276

undefined4 uac_mutex_take(pthread_mutex_t *param_1,int param_2)

{
  pthread_t pVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  timespec tStack_20;
  
  pVar1 = pthread_self();
  if (param_1 == (pthread_mutex_t *)0x0) {
    return 0xffffffff;
  }
  uac_thread_set_cookie(param_1);
  if (param_2 == -1) {
    pcVar4 = pthread_mutex_lock;
  }
  else {
    pcVar4 = pthread_mutex_trylock;
    if (param_2 != 0) {
      uac_compute_timeout_ms(&tStack_20,param_2);
      iVar2 = pthread_mutex_timedlock(param_1,&tStack_20);
      goto LAB_00523018;
    }
  }
  iVar2 = (*pcVar4)(param_1);
LAB_00523018:
  uVar3 = 0xffffffff;
  uac_thread_set_cookie(0);
  if (iVar2 == 0) {
    if (*(pthread_t *)((int)param_1 + 0x20) == pVar1) {
      uVar3 = 0;
      *(int *)((int)param_1 + 0x24) = *(int *)((int)param_1 + 0x24) + 1;
    }
    else {
      *(pthread_t *)((int)param_1 + 0x20) = pVar1;
      uVar3 = 0;
      *(undefined4 *)((int)param_1 + 0x24) = 1;
    }
  }
  return uVar3;
}

