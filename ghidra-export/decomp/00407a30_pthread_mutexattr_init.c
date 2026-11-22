// func pthread_mutexattr_init @ 00407a30 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutexattr_init(pthread_mutexattr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_mutexattr_init_00759048)();
  return iVar1;
}

