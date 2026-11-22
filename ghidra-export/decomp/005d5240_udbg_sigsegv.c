// func udbg_sigsegv @ 005d5240 size=256

void udbg_sigsegv(undefined4 param_1,undefined4 param_2,int param_3)

{
  pthread_t pVar1;
  long lVar2;
  undefined1 auStack_38 [36];
  
  memset(auStack_38,0,0x20);
  puts("\n====================Segment Fault======================");
  prctl(0x10,auStack_38,0,0,0);
  pVar1 = pthread_self();
  lVar2 = syscall(0x107e);
  printf("Thread name: [%s], tid: [%p], real pid: [%d]\n",auStack_38,pVar1,lVar2);
  printf("PC: 0x%lx\n",*(undefined4 *)(param_3 + 0x24));
  udbgGetStack(param_3);
  if (udbg_trace_file != 0) {
    udbg_trace_to_file();
    puts("\n====================Segment Fault======================");
    prctl(0x10,auStack_38,0,0,0);
    lVar2 = syscall(0x107e);
    printf("Thread name: [%s], tid: [%p], real pid: [%d]\n",auStack_38,pVar1,lVar2);
    udbgGetStack(param_3);
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}

