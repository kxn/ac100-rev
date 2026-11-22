// func uac_schedule_container_timer_callback @ 00520a74 size=752

void uac_schedule_container_timer_callback(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_t9;
  
  if (param_1 != (undefined4 *)0x0) {
    param_1[2] = 0xffffffff;
    iVar1 = uac_mem_malloc_my(0xc,0x9d);
    if (iVar1 != 0) {
      (**(code **)(in_t9 + 0x238d34))(iVar1,0,0xc);
      uac_list_init(iVar1);
      uac_mutex_take(param_1[0xc],0xffffffff);
      while (iVar3 = uac_list_first(param_1 + 0xd), iVar3 != 0) {
        uac_list_remove(iVar3);
        if (param_1[0x19] != 0) {
          uac_hash_remove(param_1[0x1a],iVar3);
        }
        if (*(int *)(iVar3 + 0xc) != 0) {
          iVar2 = uac_mem_malloc_my(0x10,0xae);
          if (iVar2 == 0) {
            (*(code *)param_1[0x18])(*(undefined4 *)(iVar3 + 0xc));
            *(undefined4 *)(iVar3 + 0xc) = 0;
            uac_mem_free_my(iVar3);
            break;
          }
          *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
          *(undefined4 *)(iVar3 + 0xc) = 0;
          uac_list_insert_last(iVar1,iVar2);
        }
        uac_mem_free_my(iVar3);
      }
      uac_mutex_give(param_1[0xc]);
      iVar3 = uac_list_size(iVar1);
      if (iVar3 == 0) {
        iVar3 = uac_list_size(iVar1);
        if (iVar3 != 0) {
          while (iVar3 = uac_list_first(iVar1), iVar3 != 0) {
            uac_list_remove(iVar3);
            if (*(int *)(iVar3 + 0xc) != 0) {
              (*(code *)param_1[0x18])();
              *(undefined4 *)(iVar3 + 0xc) = 0;
            }
            uac_mem_free_my(iVar3);
          }
        }
      }
      else {
        (*(code *)param_1[0x16])(iVar1);
        while (iVar3 = uac_list_first(iVar1), iVar3 != 0) {
          uac_list_remove(iVar3);
          if (*(int *)(iVar3 + 0xc) != 0) {
            (*(code *)param_1[0x18])();
            *(undefined4 *)(iVar3 + 0xc) = 0;
          }
          uac_mem_free_my(iVar3);
        }
      }
      uac_mem_free_my(iVar1);
    }
    iVar1 = _uac_timer_add(*param_1,0,*(int *)(in_t9 + 0x238984) + 0xa74,param_1,0,
                           *(int *)(in_t9 + 0x2386b4) + 0x3784,0xe8);
    param_1[2] = iVar1;
    if (iVar1 == -1) {
                    /* WARNING: Could not recover jumptable at 0x00520d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(in_t9 + 0x238e5c))(*(int *)(in_t9 + 0x2386b4) + 0x3658);
      return;
    }
  }
  return;
}

