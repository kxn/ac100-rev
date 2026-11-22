// func apmngr_ap_capid_update @ 0052ef80 size=416

undefined4 apmngr_ap_capid_update(uint param_1,short param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  short local_2f8 [4];
  undefined1 auStack_2f0 [24];
  short local_2d8;
  
  param_1 = param_1 & 0xffff;
  memset(local_2f8,0,0x2e0);
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if (((int)param_1 < iVar1 + iVar2) ||
     ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), (int)param_1 < iVar1 + 50000)))) {
    iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
    if (iVar1 == 0) {
      if (local_2d8 == param_2) {
        return 0;
      }
      iVar1 = apmngr_db_ap_capid_update(param_1,param_2);
      if (iVar1 == 0) {
        apmngr_db_sync_ap_capid(param_1,param_2);
        apmngr_db_datasync_ap_capid(param_1,param_2);
        local_2f8[0] = local_2d8;
        local_2d8 = param_2;
        apmngr_evt_notify(9,local_2f8);
        return 0;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to update cap id for ap(%d).\n";
      uVar3 = 0xa11;
    }
    else {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to find the entry(%d).\n";
      uVar3 = 0xa07;
    }
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n";
    uVar3 = 0xa01;
  }
  printf(__format,"apmngr_ap_capid_update",uVar3,param_1);
  return 0xffffffff;
}

