// func apmngr_db_is_led_wifi_close @ 00537c7c size=888

undefined4 apmngr_db_is_led_wifi_close(uint param_1)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  if ((apmngr_ap_num_max <= (int)param_1) &&
     ((param_1 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)param_1)))) {
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_is_led_wifi_close",0x4a0);
    return 0;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar2 = param_1;
  if (49999 < param_1) {
    uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 0) {
LAB_00537e64:
    if ((apmngr_debug_switch == '\0') || (iVar1 = is_target_debug_ap(apmngr_db_mutex), iVar1 == 0))
    goto LAB_00537e70;
    __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not used\n";
    uVar3 = 0x4a6;
  }
  else {
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0xc) == 0) goto LAB_00537e64;
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(uint *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x2ac) < 2) {
LAB_00537dfc:
      if ((apmngr_debug_switch == '\0') || (iVar1 = is_target_debug_ap(apmngr_db_mutex), iVar1 == 0)
         ) goto LAB_00537e70;
      __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in right state\n";
      uVar3 = 0x4ab;
    }
    else {
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (3 < *(uint *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x2ac)) goto LAB_00537dfc;
      iVar1 = multi_link_status_get(param_1);
      if (iVar1 != 0) {
        uVar2 = param_1;
        if (49999 < param_1) {
          uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if ((*(uint *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x254) & 0x400) != 0) {
          uVar2 = param_1;
          if (49999 < param_1) {
            uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
          }
          if (*(char *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x130) != '\0') {
            if (49999 < param_1) {
              param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
            }
            if (*(int *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x288) == 2) {
              FUN_00407f30(apmngr_db_mutex);
              return 1;
            }
          }
        }
        goto LAB_00537e70;
      }
      if ((apmngr_debug_switch == '\0') || (iVar1 = is_target_debug_ap(apmngr_db_mutex), iVar1 == 0)
         ) goto LAB_00537e70;
      __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
      uVar3 = 0x4b0;
    }
  }
  printf(__format,"apmngr_db_is_led_wifi_close",uVar3,param_1);
LAB_00537e70:
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

