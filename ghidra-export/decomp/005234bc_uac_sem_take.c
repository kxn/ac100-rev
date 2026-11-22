// func uac_sem_take @ 005234bc size=240

undefined4 uac_sem_take(sem_t *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  timespec tStack_18;
  
  uVar3 = 0xffffffff;
  if (param_2 == -1) {
    do {
      iVar1 = sem_wait(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
    uVar3 = 0xffffffff;
  }
  else if (param_2 == 0) {
    iVar1 = sem_trywait(param_1);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
  }
  else {
    uac_compute_timeout_ms(&tStack_18);
    do {
      iVar1 = sem_timedwait(param_1,&tStack_18);
      if (iVar1 == 0) {
        return 0;
      }
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

