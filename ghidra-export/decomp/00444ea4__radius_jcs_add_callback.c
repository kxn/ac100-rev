// func _radius_jcs_add_callback @ 00444ea4 size=100

void _radius_jcs_add_callback(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_t9;
  
  uVar1 = _radius_message_process();
  uVar1 = (**(code **)(in_t9 + 0x3148d4))(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00444f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_t9 + 0x314894))(param_2,*(int *)(in_t9 + 0x314274) + 0x6a24,uVar1);
  return;
}

