// func uac_schedule_container_sync_add @ 00520434 size=856

undefined4 uac_schedule_container_sync_add(int param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  uac_mutex_take(*(undefined4 *)(param_1 + 0x30),0xffffffff);
  if (*(int *)(param_1 + 100) == 0) {
    pvVar1 = (void *)uac_mem_malloc_my(0x14,0x241);
    if (pvVar1 == (void *)0x0) goto LAB_005206c4;
    memset(pvVar1,0,0x14);
    *(int *)((int)pvVar1 + 0xc) = param_2;
    *(int *)((int)pvVar1 + 0x10) = param_1;
  }
  else {
    uVar5 = (**(code **)(param_1 + 0x78))(param_2);
    iVar4 = uac_hash_get(*(undefined4 *)(param_1 + 0x68),uVar5);
    if (iVar4 != 0) {
      puts("Already exsist, add failed!");
      goto LAB_005206c4;
    }
    pvVar1 = (void *)uac_mem_malloc_my(0x14,0x22e);
    if (pvVar1 == (void *)0x0) goto LAB_005206c4;
    memset(pvVar1,0,0x14);
    *(int *)((int)pvVar1 + 0xc) = param_2;
    *(int *)((int)pvVar1 + 0x10) = param_1;
    iVar4 = uac_hash_add(*(undefined4 *)(param_1 + 0x68),pvVar1);
    if (iVar4 != 0) {
      uac_mem_free_my(pvVar1);
      goto LAB_005206c4;
    }
  }
  uac_list_insert_last(param_1 + 0x34,pvVar1);
  uVar2 = uac_list_size(param_1 + 0x34);
  if (uVar2 < *(uint *)(param_1 + 4)) {
    uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
    return 0;
  }
  pvVar1 = (void *)uac_mem_malloc_my(0xc,0x253);
  if (pvVar1 != (void *)0x0) {
    memset(pvVar1,0,0xc);
    pcVar6 = uac_list_init;
    pvVar3 = pvVar1;
    do {
      (*pcVar6)(pvVar3);
      pvVar3 = (void *)uac_list_first(param_1 + 0x34);
      if (pvVar3 == (void *)0x0) {
LAB_005205e8:
        uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
        iVar4 = uac_list_size(pvVar1);
        if (iVar4 != 0) {
          (**(code **)(param_1 + 0x58))(pvVar1);
          while (iVar4 = uac_list_first(pvVar1), iVar4 != 0) {
            uac_list_remove(iVar4);
            if (*(int *)(iVar4 + 0xc) != 0) {
              (**(code **)(param_1 + 0x60))();
              *(undefined4 *)(iVar4 + 0xc) = 0;
            }
            uac_mem_free_my(iVar4);
          }
        }
        uac_mem_free_my(pvVar1);
        return 0;
      }
      uac_list_remove(pvVar3);
      if (*(int *)(param_1 + 100) != 0) {
        uac_hash_remove(*(undefined4 *)(param_1 + 0x68),pvVar3);
      }
      if (*(int *)((int)pvVar3 + 0xc) != 0) {
        iVar4 = uac_mem_malloc_my(0x10,0x263);
        if (iVar4 == 0) {
          (**(code **)(param_1 + 0x60))(*(undefined4 *)((int)pvVar3 + 0xc));
          *(undefined4 *)((int)pvVar3 + 0xc) = 0;
          uac_mem_free_my(pvVar3);
          goto LAB_005205e8;
        }
        *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)((int)pvVar3 + 0xc);
        *(undefined4 *)((int)pvVar3 + 0xc) = 0;
        uac_list_insert_last(pvVar1,iVar4);
      }
      pcVar6 = uac_mem_free_my;
    } while( true );
  }
LAB_005206c4:
  uac_mutex_give(*(undefined4 *)(param_1 + 0x30));
  return 0xffffffff;
}

