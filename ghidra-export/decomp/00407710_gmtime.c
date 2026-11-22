// func gmtime @ 00407710 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * gmtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_gmtime_00758f80)();
  return ptVar1;
}

