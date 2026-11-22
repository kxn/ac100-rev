// func apmngr_db_is_led_timer_cfg_changed @ 00541534 size=52

bool apmngr_db_is_led_timer_cfg_changed(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = memcmp((void *)(param_1 + 0x17c),(void *)(param_2 + 0x17c),9);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}

