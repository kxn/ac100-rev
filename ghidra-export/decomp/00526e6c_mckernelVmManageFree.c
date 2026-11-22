// func mckernelVmManageFree @ 00526e6c size=196

void mckernelVmManageFree(int param_1)

{
  long lVar1;
  
  if (DAT_007cca88 != '\0') {
    if (((param_1 != 0) && (lVar1 = syscall(DAT_007cca90,param_1,0,0,1,0), lVar1 != 0)) &&
       (gMemCheckCtx < 3)) {
      printf("[%s:%d]syscall: failed(ret:%d, addr:%p)!\n","mckernelVmManageFree",0x3d,lVar1,param_1)
      ;
    }
    return;
  }
  uac_mem_free_my();
  return;
}

