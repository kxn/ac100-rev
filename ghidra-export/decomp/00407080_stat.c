// func stat @ 00407080 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = stat(__file,__buf);
  return iVar1;
}

