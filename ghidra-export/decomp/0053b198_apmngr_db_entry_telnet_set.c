// func apmngr_db_entry_telnet_set @ 0053b198 size=388

void apmngr_db_entry_telnet_set(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar1 = param_1;
    if (49999 < param_1) {
      uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar1 * 0x2d8 + 0x1c) == 1) {
      if (49999 < param_1) {
        param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined1 *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x206) = param_2;
    }
    FUN_00407f30(apmngr_db_mutex);
    return;
  }
  if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] is NULL.\n","apmngr_db_entry_telnet_set",0x7fd,
           param_1);
    return;
  }
  return;
}

