// func uac_schedule_container_data_handle @ 0052078c size=400

undefined4 uac_schedule_container_data_handle(int param_1,int param_2,undefined4 param_3)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (__s = (void *)uac_mem_malloc_my(0x14,0x1da), __s != (void *)0x0)) {
    memset(__s,0,0x14);
    uac_mutex_take(*(undefined4 *)(param_1 + 0x30),0xffffffff);
    if ((*(int *)(param_1 + 0x7c) == 1) &&
       ((*(int *)(param_1 + 0x4c) == -1 &&
        (iVar1 = uac_thread_create(param_1 + 0x4c,param_1 + 0xc,uac_schedule_container_async_send,
                                   param_1), iVar1 != 0)))) {
      puts("Failed to create uac_schedule_container_async_send thread");
      uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
      uac_mem_free_my(__s);
      if (param_2 != 0) {
        uac_mem_free_my(param_2);
      }
    }
    else {
      uVar2 = 0;
      uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
      *(int *)((int)__s + 0x10) = param_2;
      *(undefined4 *)((int)__s + 0xc) = param_3;
      uac_mutex_take(*(undefined4 *)(param_1 + 0x50),0xffffffff);
      uac_list_insert_last(param_1 + 0x40,__s);
      uac_cond_signal(*(pthread_cond_t **)(param_1 + 0x54));
      uac_mutex_give(*(undefined4 *)(param_1 + 0x50));
    }
  }
  return uVar2;
}

