// func gettimeofday @ 004078c0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int gettimeofday(timeval *__tv,__timezone_ptr_t __tz)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_gettimeofday_00758fec)();
  return iVar1;
}

