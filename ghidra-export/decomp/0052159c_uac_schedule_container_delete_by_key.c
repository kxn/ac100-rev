// func uac_schedule_container_delete_by_key @ 0052159c size=1

int uac_schedule_container_delete_by_key
              (int param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_t9;
  
  iVar4 = 0;
  if ((param_1 != 0) && (param_2 != (code *)0x0)) {
    uac_mutex_take(*(undefined4 *)(param_1 + 0x30),0xffffffff,param_3,param_4,in_t9 + 0x23fb64);
    iVar2 = uac_list_first(param_1 + 0x34);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar2 = uac_list_next(iVar1);
      iVar3 = (*param_2)(*(undefined4 *)(iVar1 + 0xc),param_3);
      if (iVar3 != 0) {
        uac_list_remove(iVar1);
        if (*(int *)(param_1 + 100) != 0) {
          uac_hash_remove(*(undefined4 *)(param_1 + 0x68),iVar1);
        }
        if (*(int *)(iVar1 + 0xc) != 0) {
          (**(code **)(param_1 + 0x60))();
        }
        iVar4 = iVar4 + 1;
        uac_mem_free_my(iVar1);
      }
    }
    uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
  }
  return iVar4;
}

