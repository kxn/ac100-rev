// func wips_entry_clear_interval @ 004cad64 size=200

/* WARNING: Removing unreachable block (ram,0x004cad84) */

void wips_entry_clear_interval(void)

{
  int iVar1;
  
  wips_entry_clear();
  if ((uint)wips_online_hours % 0x18 == 0) {
    wips_whitelist_reset_send(0xffff);
  }
  iVar1 = FUN_00408340(0xe10,0,wips_entry_clear_interval,0,0,"wips_entry_clear_interval",0x9e);
  if ((iVar1 == -1) && (sensor_err_switch != '\0')) {
    printf("[SENSOR_ERROR]%s()/%d start timer error\n","wips_entry_clear_interval",0xa1);
  }
  wips_online_hours = wips_online_hours + 1;
  return;
}

