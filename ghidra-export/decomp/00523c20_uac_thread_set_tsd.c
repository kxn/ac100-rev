// func uac_thread_set_tsd @ 00523c20 size=24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int uac_thread_set_tsd(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = pthread_setspecific(__key,__pointer);
  return iVar1;
}

