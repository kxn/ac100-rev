// func wips_counter_setting_send @ 004c68f0 size=256

void wips_counter_setting_send(undefined4 param_1)

{
  int iVar1;
  char *__s;
  undefined1 auStack_2e8 [20];
  int local_2d4;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if ((iVar1 != -1) && (local_2d4 == 7)) {
    __s = (char *)FUN_00408450(0x8000,0x44d);
    if (__s == (char *)0x0) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d out of memory.\n","wips_counter_setting_send",0x450);
      }
    }
    else {
      sprintf(__s,
              "{\"method\": \"do\",\"wireless_counter\": {\"set_global_params\": {\"radio_id\":\"1\",\"single_duration\":\"5\",\"interval\":\"1000\",\"duration\":\"%d\"}}}"
              ,600);
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d wips_counter_setting_send[ap_id=%d]: %s\n",
               "wips_counter_setting_send",0x455,param_1,__s);
      }
      sensor_pkt_tdcp_send(param_1,__s);
      FUN_00407df0(__s);
    }
  }
  return;
}

