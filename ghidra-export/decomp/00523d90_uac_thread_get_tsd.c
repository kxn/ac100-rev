// func uac_thread_get_tsd @ 00523d90 size=24

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * uac_thread_get_tsd(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = pthread_getspecific(__key);
  return pvVar1;
}

