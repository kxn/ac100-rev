// func __errno_location @ 00407ce0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * __errno_location(void)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___errno_location_007590f4)();
  return piVar1;
}

