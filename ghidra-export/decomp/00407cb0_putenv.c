// func putenv @ 00407cb0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putenv(char *__string)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_putenv_007590e8)();
  return iVar1;
}

