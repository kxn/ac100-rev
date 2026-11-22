// func apmngr_ap_role_update @ 0052f120 size=528

undefined4 apmngr_ap_role_update(uint param_1,uint param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_5c8 [20];
  uint local_5b4;
  undefined1 auStack_2f0 [732];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_5c8,0,0x5b0);
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if (((iVar1 + iVar2 <= (int)param_1) &&
      ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= (int)param_1)))) ||
     (8 < param_2)) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or role[%d].\n","apmngr_ap_role_update",0xa25,
           param_1,param_2);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_5c8);
  if (iVar1 == 0) {
    if (local_5b4 == param_2) {
      return 0;
    }
    iVar1 = apmngr_db_ap_role_update(param_1,param_2,param_3);
    if (iVar1 == 0) {
      apmngr_db_sync_ap_role(param_1,param_2,param_3);
      apmngr_db_datasync_ap_role(param_1,param_2,param_3);
      iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
      if (iVar1 == 0) {
        apmngr_evt_notify(10,auStack_5c8);
        return 0;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to find the entry(%d).\n";
      uVar3 = 0xa3d;
    }
    else {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Failed to update role for ap(%d).\n";
      uVar3 = 0xa34;
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
    __format = "[APMNGR_ERROR]%s()/%d Failed to find the entry(%d).\n";
    uVar3 = 0xa2b;
  }
  printf(__format,"apmngr_ap_role_update",uVar3,param_1);
  return 0xffffffff;
}

