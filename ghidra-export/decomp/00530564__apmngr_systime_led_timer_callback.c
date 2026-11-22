// func _apmngr_systime_led_timer_callback @ 00530564 size=144

undefined4 _apmngr_systime_led_timer_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_18 [2];
  int local_14 [2];
  
  local_14[0] = 0;
  local_18[0] = *(undefined2 *)(param_1 + 0x10);
  iVar1 = multi_link_status_get();
  if (((iVar1 == 1) && (*(int *)(param_1 + 0x2ac) != 0)) && (*(char *)(param_1 + 0x1bc) != '\0')) {
    apmngr_led_timer_start(*(undefined2 *)(param_1 + 0x10),local_14);
    uVar2 = 1;
    if (local_14[0] == 0) {
      uVar2 = 2;
    }
    apmngr_ap_led_update(local_18,1,uVar2);
  }
  return 0;
}

