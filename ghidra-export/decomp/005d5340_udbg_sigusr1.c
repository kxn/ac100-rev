// func udbg_sigusr1 @ 005d5340 size=268

void udbg_sigusr1(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  pthread_t pVar1;
  long lVar2;
  undefined1 auStack_38 [32];
  
  memset(auStack_38,0,0x20);
  prctl(0x10,auStack_38,0,0,0);
  pthread_mutex_lock((pthread_mutex_t *)&udbg_trace_mutex);
  puts("\n*********************************************************************");
  pVar1 = pthread_self();
  lVar2 = syscall(0x107e);
  printf("Thread name: [%s], tid: [%p], real pid: [%d]\n",auStack_38,pVar1,lVar2);
  udbgGetStack(param_3);
  if (udbg_trace_file != 0) {
    udbg_trace_to_file();
    puts("\n*********************************************************************");
    lVar2 = syscall(0x107e);
    printf("Thread name: [%s], tid: [%p], real pid: [%d]\n",auStack_38,pVar1,lVar2);
    udbgGetStack(param_3);
    udbg_dup_stdout("/dev/console");
  }
  pthread_mutex_unlock((pthread_mutex_t *)&udbg_trace_mutex);
  return;
}

