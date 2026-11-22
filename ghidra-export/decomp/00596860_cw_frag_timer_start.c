// func cw_frag_timer_start @ 00596860 size=168

undefined4 cw_frag_timer_start(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0xee;
    pcVar3 = "NULL != session";
  }
  else {
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar1 = cw_timer_add(*(int *)(param_1 + 0x24),10,cw_frag_timer_callback,param_1,
                           cw_frag_timer_arg_free_callback);
      *(int *)(param_1 + 0x20) = iVar1;
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      return 0;
    }
    uVar2 = 0xef;
    pcVar3 = "NULL != session->timer";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_timer_start",uVar2,pcVar3);
  return 0xffffffff;
}

