// func uac_schedule_container_clear @ 005216d8 size=236

undefined4 uac_schedule_container_clear(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uac_mutex_take(*(undefined4 *)(param_1 + 0x30),0xffffffff);
    while (iVar2 = uac_list_first(param_1 + 0x34), iVar2 != 0) {
      uac_list_remove(iVar2);
      if (*(int *)(param_1 + 100) != 0) {
        uac_hash_remove(*(undefined4 *)(param_1 + 0x68),iVar2);
      }
      if (*(int *)(iVar2 + 0xc) != 0) {
        (**(code **)(param_1 + 0x60))();
        *(undefined4 *)(iVar2 + 0xc) = 0;
      }
      uac_mem_free_my(iVar2);
    }
    uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
    uVar1 = 0;
  }
  return uVar1;
}

