// func apmngr_db_capacity_support @ 005364bc size=876

undefined4 apmngr_db_capacity_support(uint param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  uint local_res8;
  undefined4 local_resc;
  uint *local_20;
  
  param_1 = param_1 & 0xffff;
  local_res8 = param_3;
  local_resc = param_4;
  if ((((apmngr_ap_num_max <= (int)param_1) &&
       ((param_1 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)param_1)))) || (param_2 < 0)) ||
     (0x80 < param_2)) {
    if (apmngr_debug_switch == '\0') {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_capacity_support",0x27e);
    return 0;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar2 = param_1;
  if (49999 < param_1) {
    uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) != 0) {
    uVar2 = param_1;
    if (49999 < param_1) {
      uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0xc) != 0) {
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x14) == 5) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        param_1 = (uint)*(short *)(g_apmngr_entry_array + param_1 * 0x2d8 + 0x18);
        if (((int)param_1 < 0) || (apmngr_ap_num_max <= (int)param_1)) {
          if ((apmngr_debug_switch != '\0') &&
             (iVar1 = is_target_debug_ap(apmngr_db_mutex), iVar1 != 0)) {
            printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_capacity_support",0x28e);
          }
          goto LAB_0053670c;
        }
      }
      uVar2 = param_1;
      if (49999 < (int)param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      local_20 = &local_res8;
      do {
        if (param_2 == 0) {
          FUN_00407f30(apmngr_db_mutex);
          return 1;
        }
        param_1 = *local_20;
        if (0x5f < param_1) {
          if ((apmngr_err_switch != '\0') &&
             (iVar1 = is_target_debug_ap(apmngr_db_mutex), iVar1 != 0)) {
            __format = "[APMNGR_ERROR]%s()/%d cap(%d) is illegal\n";
            uVar3 = 0x29b;
            goto LAB_00536740;
          }
          break;
        }
        param_2 = param_2 + -1;
        local_20 = local_20 + 1;
      } while ((1 << (param_1 & 0x1f) &
               *(uint *)(g_apmngr_entry_array + uVar2 * 0x2d8 + (((int)param_1 >> 5) + 0x94) * 4))
               != 0);
      goto LAB_0053670c;
    }
  }
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not used\n";
    uVar3 = 0x286;
LAB_00536740:
    printf(__format,"apmngr_db_capacity_support",uVar3,param_1);
  }
LAB_0053670c:
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

