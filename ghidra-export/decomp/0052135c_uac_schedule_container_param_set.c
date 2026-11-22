// func uac_schedule_container_param_set @ 0052135c size=204

undefined4
uac_schedule_container_param_set(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
    param_1[1] = param_3;
    if (param_1[2] != -1) {
      uac_timer_remove();
      param_1[2] = 0xffffffff;
    }
    uVar2 = 0;
    iVar1 = _uac_timer_add(*param_1,0,uac_schedule_container_timer_callback,param_1,0,
                           "uac_schedule_container_param_set",0x1cc);
    param_1[2] = iVar1;
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
      printf("add timer for schedule container failed");
    }
  }
  return uVar2;
}

