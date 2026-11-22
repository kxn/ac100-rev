// func uac_cond_signal @ 00523868 size=24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uac_cond_signal(pthread_cond_t *__cond)

{
  int iVar1;
  
  iVar1 = pthread_cond_signal(__cond);
  return iVar1;
}

