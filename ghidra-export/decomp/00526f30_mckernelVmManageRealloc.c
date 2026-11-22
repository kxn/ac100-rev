// func mckernelVmManageRealloc @ 00526f30 size=372

void * mckernelVmManageRealloc
                 (void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  size_t sVar1;
  void *pvVar2;
  
  if (DAT_007cca88 != '\0') {
    pvVar2 = (void *)0x0;
    if (param_1 != (void *)0x0) {
      sVar1 = syscall(DAT_007cca90,param_1,0,0,2,0);
      if ((int)sVar1 < 0) {
        if (gMemCheckCtx < 3) {
          printf("[%s:%d]get old block size failed!\n","mckernelVmManageRealloc",0x50);
        }
      }
      else {
        pvVar2 = (void *)mckernelVmManageMalloc(param_2,param_3,param_4,param_5);
        if (pvVar2 != (void *)0x0) {
          if ((int)sVar1 <= (int)param_2) {
            param_2 = sVar1;
          }
          memcpy(pvVar2,param_1,param_2);
          mckernelVmManageFree(param_1);
        }
      }
    }
    return pvVar2;
  }
  pvVar2 = realloc(param_1,param_2);
  return pvVar2;
}

