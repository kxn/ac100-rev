// func apmngr_template_add @ 0052ccd8 size=384

uint apmngr_template_add(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  uint local_10 [2];
  
  if (param_1 == 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Input template entry is NULL.\n";
    uVar2 = 0x664;
  }
  else {
    local_10[0] = apmngr_db_id_alloc(0);
    if (-1 < (int)local_10[0]) {
      *(short *)(param_1 + 0x10) = (short)local_10[0];
      *(undefined4 *)(param_1 + 0xc) = 0;
      iVar1 = apmngr_db_template_add(param_1);
      if (iVar1 != 0) {
        apmngr_db_id_free(0,local_10[0] & 0xffff);
        return 0xffff;
      }
      apmngr_db_sync_ap_entry(param_1,0,1,0);
      apmngr_db_datasync_ap_entry(param_1,0,1,0);
      iVar1 = apmngr_evt_notify(0,param_1);
      if ((iVar1 == 0) && (iVar1 = apmngr_evt_notify(2,param_1), iVar1 == 0)) {
        return local_10[0] & 0xffff;
      }
      apmngr_evt_notify(3,param_1);
      apmngr_db_template_delete(local_10[0] & 0xffff);
      apmngr_db_id_free(0,local_10[0] & 0xffff);
      apmngr_db_sync_ap_entry_del(local_10,1,1);
      apmngr_db_datasync_ap_entry_del(local_10,1,1);
      return 0xffff;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Failed to alloc id for ap entry.\n";
    uVar2 = 0x66b;
  }
  printf(__format,"apmngr_template_add",uVar2);
  return 0xffff;
}

