// func mckernelVmManageMalloc @ 00526d50 size=284

long mckernelVmManageMalloc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  memset(&local_50,0,0x2c);
  if (DAT_007cca88 == '\0') {
    lVar1 = uac_mem_malloc_my(param_1,param_2);
  }
  else {
    local_50 = 2;
    local_4c = param_3;
    local_48 = param_4;
    lVar1 = syscall(DAT_007cca90,0,param_1,DAT_007cca8c,0,&local_50);
    if ((lVar1 == 0) && (gMemCheckCtx < 3)) {
      printf("[%s:%d]syscall: failed(size:%d)!\n","mckernelVmManageMalloc",0x2b,param_1);
    }
  }
  return lVar1;
}

