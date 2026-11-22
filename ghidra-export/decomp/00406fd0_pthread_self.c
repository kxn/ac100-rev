// func pthread_self @ 00406fd0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
  pthread_t pVar1;
  
  pVar1 = pthread_self();
  return pVar1;
}

