// func uac_mem_free_my @ 0051dfd4 size=472

void uac_mem_free_my(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 != 0) {
    uVar2 = *(uint *)(param_1 + -0xc);
    iVar3 = *(int *)(param_1 + -8);
    iVar4 = *(int *)(param_1 + -4);
    piVar1 = (int *)(param_1 + *(int *)(param_1 + -0x10));
    iVar5 = *piVar1;
    iVar6 = piVar1[1];
    if (uVar2 < 0xffff) {
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      (&g_lines)[uVar2] = (&g_lines)[uVar2] + -1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
    }
    if (mem_debug_switch != 0) {
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      mem_count = mem_count + -1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
    }
    if ((mem_check_debug_switch == 1) &&
       ((((iVar3 != -0x55555556 || (iVar4 != -0x44444445)) || (iVar5 != -0x55555556)) ||
        (iVar6 != -0x44444445)))) {
      printf("free line:%d err_ptr:%p\r\n",uVar2,(void *)(param_1 + -0x10));
      printf("free head1:%x head2:%x\r\n",iVar3,iVar4);
      printf("free tail1:%x tail2:%x\r\n",iVar5,iVar6);
    }
    free((void *)(param_1 + -0x10));
    return;
  }
  return;
}

