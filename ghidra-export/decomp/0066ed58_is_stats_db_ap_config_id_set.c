// func is_stats_db_ap_config_id_set @ 0066ed58 size=184

undefined4 is_stats_db_ap_config_id_set(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0xffff;
  iVar1 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar1) {
    FUN_004082d0(l_stats_data,0xffffffff);
    iVar1 = DAT_007cc8ec + param_1 * 0x1e0;
    uVar2 = 0xffffffff;
    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x16) == '\x01')) {
      uVar2 = 0;
    }
    FUN_00407f30(l_stats_data);
  }
  else {
    uVar2 = 0xffffffff;
    if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","is_stats_db_ap_config_id_set",0xdd7,
             param_1);
    }
  }
  return uVar2;
}

