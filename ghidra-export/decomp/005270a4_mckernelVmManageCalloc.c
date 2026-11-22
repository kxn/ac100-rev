// func mckernelVmManageCalloc @ 005270a4 size=160

void * mckernelVmManageCalloc
                 (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  void *__s;
  
  if (DAT_007cca88 == '\0') {
    __s = (void *)uac_mem_malloc_my();
  }
  else {
    __s = (void *)mckernelVmManageMalloc(param_1 * param_2,param_3,param_4,param_5);
  }
  if (__s != (void *)0x0) {
    memset(__s,0,param_1 * param_2);
  }
  return __s;
}

