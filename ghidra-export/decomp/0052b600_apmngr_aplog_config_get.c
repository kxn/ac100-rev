// func apmngr_aplog_config_get @ 0052b600 size=168

undefined4
apmngr_aplog_config_get
          (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          void *param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) &&
      (param_3 != (undefined4 *)0x0)) &&
     (((param_4 != (undefined4 *)0x0 && (param_5 != (void *)0x0)) && (param_6 != (undefined4 *)0x0))
     )) {
    *param_1 = g_apmngr_ac_log_switch;
    *param_2 = g_apmngr_ac_log_level;
    *param_3 = g_apmngr_remote_server_switch;
    *param_4 = g_apmngr_remote_log_level;
    memcpy(param_5,&g_apmngr_remote_server,0x14);
    *param_6 = g_apmngr_remote_report_interval;
    uVar1 = 0;
  }
  return uVar1;
}

