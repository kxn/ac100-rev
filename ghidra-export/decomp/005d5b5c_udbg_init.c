// func udbg_init @ 005d5b5c size=372

undefined4 udbg_init(void)

{
  int iVar1;
  undefined4 uVar2;
  pthread_mutexattr_t pStack_48;
  undefined1 auStack_44 [32];
  _union_1051 local_24;
  code *local_20;
  
  pthread_mutexattr_init(&pStack_48);
  pthread_mutexattr_settype(&pStack_48,1);
  pthread_mutex_init((pthread_mutex_t *)&udbg_trace_mutex,&pStack_48);
  pthread_mutexattr_destroy(&pStack_48);
  FUN_0051ad88(&udbg_help_list);
  udbg_help_register(&DAT_006f3354,"help()");
  iVar1 = udbg_init_process_var();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    local_20 = udbg_sigpipe;
    sigemptyset((sigset_t *)&stack0xffffffe4);
    local_24 = (_union_1051)0x8;
    sigaction(0xd,(sigaction *)&local_24,(sigaction *)(auStack_44 + 4));
    iVar1 = access("/tmp/uac_dump_core",0);
    if (iVar1 != 0) {
      local_20 = udbg_sigsegv;
      sigemptyset((sigset_t *)&stack0xffffffe4);
      local_24 = (_union_1051)0x8;
      sigaction(0xb,(sigaction *)&local_24,(sigaction *)(auStack_44 + 4));
      local_20 = udbg_sigbus;
      sigemptyset((sigset_t *)&stack0xffffffe4);
      local_24 = (_union_1051)0x8;
      sigaction(10,(sigaction *)&local_24,(sigaction *)(auStack_44 + 4));
      local_20 = udbg_sigusr1;
      sigemptyset((sigset_t *)&stack0xffffffe4);
      local_24 = (_union_1051)0x8;
      sigaction(0x10,(sigaction *)&local_24,(sigaction *)(auStack_44 + 4));
    }
    udbg_init_dl();
    FUN_004084d0(&DAT_006f336c,2,udbg_jcs_callback_set);
    FUN_004084e0(auStack_44,"udbg_deadlock_chk",udbg_deadlock_monitor,0);
    uVar2 = 0;
  }
  return uVar2;
}

