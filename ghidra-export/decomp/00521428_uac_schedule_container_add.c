// func uac_schedule_container_add @ 00521428 size=68

undefined4 uac_schedule_container_add(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x7c) != 1) {
    uVar1 = uac_schedule_container_sync_add();
    return uVar1;
  }
  uVar1 = uac_schedule_container_data_handle(param_1,param_2,uac_schedule_container_sync_add);
  return uVar1;
}

