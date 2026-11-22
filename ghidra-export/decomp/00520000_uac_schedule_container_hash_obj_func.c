// func uac_schedule_container_hash_obj_func @ 00520000 size=32

undefined4 uac_schedule_container_hash_obj_func(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00520010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)(param_1 + 0x10) + 0x6c))(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  }
  return 0;
}

