// func localtime_r @ 00407c80 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_r_007590dc)();
  return ptVar1;
}

