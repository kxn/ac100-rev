// func _uac_thread_boot @ 00523c38 size=1

void _uac_thread_boot(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  code *pcVar4;
  
  uVar1 = (**(code **)(in_t9 + 0x235c40))();
  (**(code **)(in_t9 + 0x235c9c))(uVar1);
  (**(code **)(in_t9 + 0x235b88))(0xf,param_1 + 1,0,0,0);
  uVar2 = (**(code **)(in_t9 + 0x235a3c))(0x107e);
  param_1[0xb] = uVar1;
  pcVar4 = *(code **)(in_t9 + 0x235b6c);
  param_1[10] = uVar2;
  (*pcVar4)(1,0);
  (**(code **)(in_t9 + 0x2359d8))(0,0);
  iVar3 = *(int *)(in_t9 + 0x235830);
  (**(code **)(in_t9 + 0x235c74))(iVar3 + 0x3ba4);
  uac_list_insert_last(*(int *)(in_t9 + 0x235830) + 0x3bc0,param_1 + 0x10);
  (**(code **)(in_t9 + 0x235b94))(iVar3 + 0x3ba4);
  uac_thread_set_tsd(*(pthread_key_t *)(*(int *)(in_t9 + 0x235830) + 0x3bbc),param_1);
  (*(code *)*param_1)(param_1[9]);
  (**(code **)(in_t9 + 0x235c74))(iVar3 + 0x3ba4);
  uac_list_remove(param_1 + 0x10);
  (**(code **)(in_t9 + 0x235b94))(iVar3 + 0x3ba4);
  uac_mem_free_my(param_1);
  pcVar4 = *(code **)(in_t9 + 0x235bd4);
  (*pcVar4)(0);
                    /* WARNING: Could not recover jumptable at 0x00523da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(pcVar4 + 0x235a64))();
  return;
}

