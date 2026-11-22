// func time @ 004078e0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_00758ff4)();
  return tVar1;
}

