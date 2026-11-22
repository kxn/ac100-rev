// func mcDebugHeapInit @ 005271cc size=408

ssize_t mcDebugHeapInit(undefined4 param_1)

{
  int __fd;
  int iVar1;
  char *__format;
  undefined4 uVar2;
  ssize_t sVar3;
  char acStack_38 [31];
  undefined1 local_19;
  
  memset(acStack_38,0,0x20);
  __fd = open("/proc/memory_check/new_malloc_syscall_num",0);
  if (__fd < 0) {
    if (2 < gMemCheckCtx) {
      return -1;
    }
    printf("[%s:%d]open syscall file failed!\n","mcDebugHeapInit",0x97);
    return -1;
  }
  iVar1 = read(__fd,acStack_38,0x20);
  sVar3 = iVar1;
  if (iVar1 < 0) {
    if (2 < gMemCheckCtx) goto LAB_00527298;
    uVar2 = 0x9d;
    __format = "[%s:%d]read new malloc syscall numm failed(%d)!\n";
  }
  else {
    local_19 = 0;
    iVar1 = atoi(acStack_38);
    if (0 < iVar1) {
      DAT_007cca90 = iVar1;
      printf("read new malloc syscall num :%d\n",iVar1);
      DAT_007cca88 = 1;
      DAT_007cca8c = param_1;
      goto LAB_00527298;
    }
    sVar3 = -1;
    if (2 < gMemCheckCtx) goto LAB_00527298;
    uVar2 = 0xa4;
    __format = "[%s:%d]invalid syscallNum(%d)!\n";
  }
  printf(__format,"mcDebugHeapInit",uVar2,iVar1);
LAB_00527298:
  close(__fd);
  return sVar3;
}

