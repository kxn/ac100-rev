// func dup2 @ 004071c0 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
  int iVar1;
  
  iVar1 = dup2(__fd,__fd2);
  return iVar1;
}

