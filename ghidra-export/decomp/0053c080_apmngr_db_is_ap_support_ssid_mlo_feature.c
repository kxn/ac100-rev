// func apmngr_db_is_ap_support_ssid_mlo_feature @ 0053c080 size=368

bool apmngr_db_is_ap_support_ssid_mlo_feature(uint param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  param_1 = param_1 & 0xffff;
  if ((int)param_1 < apmngr_ap_num_max) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    bVar3 = false;
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) != 0) {
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      bVar3 = false;
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0xc) != 0) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        bVar3 = *(char *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x2d2) == '\x01';
      }
    }
    FUN_00407f30(apmngr_db_mutex);
  }
  else {
    bVar3 = false;
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_is_ap_support_ssid_mlo_feature",0x8e1)
      ;
    }
  }
  return bVar3;
}

