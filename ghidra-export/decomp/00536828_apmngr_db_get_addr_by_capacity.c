// func apmngr_db_get_addr_by_capacity @ 00536828 size=1752

undefined4
apmngr_db_get_addr_by_capacity
          (uint param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint *local_30;
  
  param_1 = param_1 & 0xffff;
  if ((((apmngr_ap_num_max <= (int)param_1) &&
       ((param_1 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)param_1)))) || (param_6 < 0)) ||
     ((0x80 < param_6 || (param_2 == 0)))) {
    if (apmngr_debug_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_get_addr_by_capacity",0x2b3);
    return 0xffffffff;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar3 = param_1;
  if (49999 < param_1) {
    uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 0) {
LAB_00536ae0:
    if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_00536af0;
    pcVar5 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not used\n";
    uVar7 = 0x2b9;
  }
  else {
    uVar3 = param_1;
    if (49999 < param_1) {
      uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0xc) == 0) goto LAB_00536ae0;
    uVar3 = param_1;
    if (49999 < param_1) {
      uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(uint *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x2ac) < 2) {
LAB_00536b2c:
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_00536af0;
      pcVar5 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in right state\n";
      uVar7 = 0x2be;
    }
    else {
      uVar3 = param_1;
      if (49999 < param_1) {
        uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (3 < *(uint *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x2ac)) goto LAB_00536b2c;
      if ((param_4 == 0) || (iVar2 = multi_link_status_get(param_1), iVar2 != 0)) {
        uVar3 = param_1;
        if (49999 < param_1) {
          uVar3 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        if ((param_5 & 1 << (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x14) + 0x10U & 0x1f))
            != 0) {
          iVar6 = param_1 - 50000;
          iVar4 = param_1 * 0x2d8;
          iVar2 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
          if (param_1 < 50000) {
            iVar2 = iVar4;
          }
          local_30 = (uint *)&stack0x00000018;
LAB_00536bf4:
          do {
            if (param_6 == 0) {
              iVar2 = iVar4;
              if (49999 < param_1) {
                iVar2 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
              }
              if (*(int *)(g_apmngr_entry_array + iVar2 + 0x14) == 5) {
                iVar2 = iVar4;
                if (49999 < param_1) {
                  iVar2 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar3 = (uint)*(short *)(g_apmngr_entry_array + iVar2 + 0x18);
                if (((int)uVar3 < 0) || (apmngr_ap_num_max <= (int)uVar3)) {
                  FUN_00407f30(apmngr_db_mutex);
                  if (apmngr_err_switch == '\0') {
                    return 0xffffffff;
                  }
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    return 0xffffffff;
                  }
                  pcVar5 = "[APMNGR_ERROR]%s()/%d cap id(%d) is illegal\n";
                  uVar7 = 0x2e7;
                  goto LAB_00536c94;
                }
                iVar2 = g_apmngr_entry_array + uVar3 * 0x2d8;
                if ((*(int *)(iVar2 + 0x1c) == 0) || (*(int *)(iVar2 + 0xc) == 0)) {
                  if ((apmngr_debug_switch != '\0') &&
                     (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 != 0)) {
                    pcVar5 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not used\n";
                    uVar7 = 0x2ec;
                    param_1 = uVar3;
                    goto LAB_00536ab4;
                  }
                  break;
                }
                if ((*(uint *)(iVar2 + 0x2ac) < 2) || (3 < *(uint *)(iVar2 + 0x2ac))) {
                  if ((apmngr_debug_switch != '\0') &&
                     (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 != 0)) {
                    pcVar5 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not in right state\n";
                    uVar7 = 0x2f1;
                    param_1 = uVar3;
                    goto LAB_00536ab4;
                  }
                  break;
                }
                uVar1 = *(undefined2 *)(iVar2 + 0x280);
                if (49999 < param_1) {
                  iVar4 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar7 = 1;
              }
              else {
                iVar2 = iVar4;
                if (49999 < param_1) {
                  iVar2 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                iVar2 = g_apmngr_entry_array + iVar2;
                iVar8 = iVar4;
                if (49999 < param_1) {
                  iVar8 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar1 = *(undefined2 *)(g_apmngr_entry_array + iVar8 + 0x280);
                if (49999 < param_1) {
                  iVar4 = (iVar6 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar7 = 0;
              }
              serv_wtp_address_arg_add
                        (param_2,*(undefined4 *)(iVar2 + 0x26c),*(undefined4 *)(iVar2 + 0x270),
                         *(undefined4 *)(iVar2 + 0x274),*(undefined4 *)(iVar2 + 0x278),
                         *(undefined4 *)(iVar2 + 0x27c),uVar1,g_apmngr_entry_array + iVar4 + 0x48,
                         uVar7);
              break;
            }
            uVar3 = *local_30;
            if (0x5f < uVar3) {
              FUN_00407f30(apmngr_db_mutex);
              if (apmngr_err_switch == '\0') {
                return 0xffffffff;
              }
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                return 0xffffffff;
              }
              pcVar5 = "[APMNGR_ERROR]%s()/%d cap(%d) is illegal\n";
              uVar7 = 0x2d3;
LAB_00536c94:
              printf(pcVar5,"apmngr_db_get_addr_by_capacity",uVar7,uVar3);
              return 0xffffffff;
            }
            uVar3 = 1 << (uVar3 & 0x1f) &
                    *(uint *)(g_apmngr_entry_array + iVar2 + (((int)uVar3 >> 5) + 0x94) * 4);
            if (param_3 != 0) {
              if (uVar3 == 0) break;
              param_6 = param_6 + -1;
              local_30 = local_30 + 1;
              goto LAB_00536bf4;
            }
            param_6 = param_6 + -1;
            local_30 = local_30 + 1;
          } while (uVar3 == 0);
          goto LAB_00536af0;
        }
        if ((apmngr_debug_switch == '\0') ||
           (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_00536af0;
        pcVar5 = "[APMNGR_DEBUG]%s()/%d ap(%d) role is not matched\n";
        uVar7 = 0x2c8;
      }
      else {
        if ((apmngr_debug_switch == '\0') ||
           (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_00536af0;
        pcVar5 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
        uVar7 = 0x2c3;
      }
    }
  }
LAB_00536ab4:
  printf(pcVar5,"apmngr_db_get_addr_by_capacity",uVar7,param_1);
LAB_00536af0:
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

