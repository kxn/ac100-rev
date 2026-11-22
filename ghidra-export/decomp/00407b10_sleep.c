// func sleep @ 00407b10 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_sleep_00759080)();
  return uVar1;
}

