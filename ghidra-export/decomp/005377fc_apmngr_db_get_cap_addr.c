// func apmngr_db_get_cap_addr @ 005377fc size=1152

undefined4 apmngr_db_get_cap_addr(uint param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  
  param_1 = param_1 & 0xffff;
  if (((apmngr_ap_num_max <= (int)param_1) &&
      ((param_1 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)param_1)))) || (param_2 == 0)) {
    if (apmngr_debug_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_get_cap_addr",0x370);
    return 0xffffffff;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar3 = param_1;
  if (49999 < param_1) {
    uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 0) {
LAB_00537960:
    if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0))
    goto LAB_0053796c;
    __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not used\n";
    uVar4 = 0x376;
    uVar3 = param_1;
  }
  else {
    uVar3 = param_1;
    if (49999 < param_1) {
      uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) != 5) goto LAB_00537960;
    uVar3 = param_1;
    if (49999 < param_1) {
      uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0xc) == 0) goto LAB_00537960;
    uVar3 = param_1;
    if (49999 < param_1) {
      uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    sVar1 = *(short *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x18);
    uVar3 = (uint)sVar1;
    if (((int)uVar3 < 0) || (apmngr_ap_num_max <= (int)uVar3)) {
      FUN_00407f30(apmngr_db_mutex);
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_ERROR]%s()/%d cap id(%d) is illegal\n","apmngr_db_get_cap_addr",0x37d,uVar3);
      return 0xffffffff;
    }
    iVar2 = g_apmngr_entry_array + uVar3 * 0x2d8;
    if ((*(int *)(iVar2 + 0x1c) == 0) || (*(int *)(iVar2 + 0xc) == 0)) {
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_0053796c;
      __format = "[APMNGR_DEBUG]%s()/%d cap(%d) is not used\n";
      uVar4 = 0x382;
    }
    else if ((*(uint *)(iVar2 + 0x2ac) < 2) || (3 < *(uint *)(iVar2 + 0x2ac))) {
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_0053796c;
      __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in right state\n";
      uVar4 = 0x387;
    }
    else if ((param_3 == 0) || (iVar2 = multi_link_status_get(sVar1), iVar2 != 0)) {
      iVar2 = g_apmngr_entry_array + uVar3 * 0x2d8;
      if ((1 < *(uint *)(iVar2 + 0x2ac)) && (*(uint *)(iVar2 + 0x2ac) < 4)) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        serv_wtp_address_arg_add
                  (param_2,*(undefined4 *)(iVar2 + 0x26c),*(undefined4 *)(iVar2 + 0x270),
                   *(undefined4 *)(iVar2 + 0x274),*(undefined4 *)(iVar2 + 0x278),
                   *(undefined4 *)(iVar2 + 0x27c),*(undefined2 *)(iVar2 + 0x280),
                   g_apmngr_entry_array + param_1 * 0x2d8 + 0x48,1);
        goto LAB_0053796c;
      }
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_0053796c;
      __format = "[APMNGR_DEBUG]%s()/%d cap(%d) is not in right state\n";
      uVar4 = 0x392;
    }
    else {
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_0053796c;
      __format = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
      uVar4 = 0x38c;
    }
  }
  printf(__format,"apmngr_db_get_cap_addr",uVar4,uVar3);
LAB_0053796c:
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

