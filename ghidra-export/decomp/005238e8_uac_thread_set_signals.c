// func uac_thread_set_signals @ 005238e8 size=168

void uac_thread_set_signals(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int local_res8;
  undefined4 local_resc;
  int *local_28;
  
  local_res8 = param_3;
  local_resc = param_4;
  sigemptyset((sigset_t *)&stack0xffffffdc);
  local_28 = &local_res8;
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      sigaddset((sigset_t *)&stack0xffffffdc,*local_28);
      local_28 = local_28 + 1;
    } while (0 < param_2);
  }
  pthread_sigmask(param_1,(sigset_t *)&stack0xffffffdc,(__sigset_t *)0x0);
  return;
}

