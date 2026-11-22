// func _radius_result_check_timer @ 004464b0 size=188

void _radius_result_check_timer(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = uac_time_usecs();
  if (param_1 == 0) {
    if (radius_err_switch != 0) {
      printf("[RADIUS_ERR]%s()/%d Para is invalid.\n","_radius_result_check_timer",0x82f);
      return;
    }
  }
  else {
    uVar1 = (uint)uVar2 - *(int *)(param_1 + 0x2c);
    if (((int)((ulonglong)uVar2 >> 0x20) - *(int *)(param_1 + 0x28) != (uint)((uint)uVar2 < uVar1))
       || (999999 < uVar1)) {
      *(undefined8 *)(param_1 + 0x28) = uVar2;
      radius_result_check_foreach(param_1);
      return;
    }
  }
  return;
}

