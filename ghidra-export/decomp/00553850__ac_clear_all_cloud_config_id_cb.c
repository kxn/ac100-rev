// func _ac_clear_all_cloud_config_id_cb @ 00553850 size=176

undefined4 _ac_clear_all_cloud_config_id_cb(int param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    if (apmngr_err_switch == '\0') {
      return 1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 1;
    }
    __format = "[APMNGR_ERROR]%s()/%d Input params invalid.\n";
    uVar2 = 0x9f6;
  }
  else {
    iVar1 = reset_ap_cloud_config_id_in_mem_db(*(undefined2 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      return 0;
    }
    if (rdmngr_err_switch == 0) {
      return 1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 1;
    }
    __format = "[RDMNGR_ERROR]%s()/%d reset ap cloud_config_id error in mem or db\n";
    uVar2 = 0x9fb;
  }
  printf(__format,"_ac_clear_all_cloud_config_id_cb",uVar2);
  return 1;
}

