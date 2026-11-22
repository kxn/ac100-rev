// func syscall @ 004079c0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long syscall(long __sysno,...)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_syscall_0075902c)();
  return lVar1;
}

