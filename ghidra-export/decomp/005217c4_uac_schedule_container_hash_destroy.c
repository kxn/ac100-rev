// func uac_schedule_container_hash_destroy @ 005217c4 size=448

void uac_schedule_container_hash_destroy(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  while (iVar1 = uac_list_first(param_1 + 0x34), iVar1 != 0) {
    uac_list_remove(iVar1);
    uac_hash_remove(*(undefined4 *)(param_1 + 0x68),iVar1);
    if (*(int *)(iVar1 + 0xc) != 0) {
      (**(code **)(param_1 + 0x60))();
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    uac_mem_free_my(iVar1);
  }
  while (iVar1 = uac_list_first(param_1 + 0x40), iVar1 != 0) {
    uac_list_remove(iVar1);
    if (*(int *)(iVar1 + 0x10) != 0) {
      (**(code **)(param_1 + 0x60))();
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
    uac_mem_free_my(iVar1);
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    uac_hash_delete();
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 8) != -1) {
    uac_timer_remove();
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    uac_mutex_destroy();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    uac_mutex_destroy();
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    uac_cond_destroy();
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  uac_mem_free_my(param_1);
  return;
}

