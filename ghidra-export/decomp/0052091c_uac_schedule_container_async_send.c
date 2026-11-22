// func uac_schedule_container_async_send @ 0052091c size=344

undefined4 uac_schedule_container_async_send(int param_1)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uac_list_init(&local_28);
  if (param_1 != 0) {
    do {
      uac_mutex_take(*(undefined4 *)(param_1 + 0x50),0xffffffff);
      while (iVar1 = uac_list_first(param_1 + 0x40), iVar1 == 0) {
        uac_cond_wait(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x50),0xffffffff);
      }
      uac_list_move(&local_28,param_1 + 0x40);
      uac_mutex_give(*(undefined4 *)(param_1 + 0x50));
      while (iVar1 = uac_list_first(&local_28), iVar1 != 0) {
        uac_list_remove(iVar1);
        if (*(code **)(iVar1 + 0xc) == (code *)0x0) {
          if ((*(int *)(iVar1 + 0x10) != 0) && (*(code **)(param_1 + 0x60) != (code *)0x0)) {
            (**(code **)(param_1 + 0x60))(*(int *)(iVar1 + 0x10));
            *(undefined4 *)(iVar1 + 0x10) = 0;
          }
        }
        else {
          (**(code **)(iVar1 + 0xc))(param_1);
        }
        uac_mem_free_my(iVar1);
      }
    } while( true );
  }
  return 0;
}

