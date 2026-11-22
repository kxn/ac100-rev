// func send @ 00407d00 size=16

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_send_007590fc)();
  return sVar1;
}

