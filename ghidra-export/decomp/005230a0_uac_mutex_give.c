// func uac_mutex_give @ 005230a0 size=160

undefined4 uac_mutex_give(pthread_mutex_t *param_1)

{
  pthread_t pVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  pVar1 = pthread_self();
  if (param_1 != (pthread_mutex_t *)0x0) {
    if (*(pthread_t *)((int)param_1 + 0x20) == pVar1) {
      iVar2 = *(int *)((int)param_1 + 0x24) + -1;
      *(int *)((int)param_1 + 0x24) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)((int)param_1 + 0x20) = 0;
      }
      uVar3 = 0xffffffff;
      iVar2 = pthread_mutex_unlock(param_1);
      if (iVar2 == 0) {
        uVar3 = 0;
      }
    }
    else {
      printf("WARNING: Try to give mutex \"%s\" not owned by thread itself.\n",
             param_1[1].__data.__lock);
    }
  }
  return uVar3;
}

