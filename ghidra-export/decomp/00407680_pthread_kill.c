// func pthread_kill @ 00407680 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_kill(pthread_t __threadid,int __signo)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_kill_00758f5c)();
  return iVar1;
}

