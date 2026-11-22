// func apmngr_db_get_addr_by_sub_capacity @ 00536f00 size=2300

/* WARNING: Removing unreachable block (ram,0x00537468) */
/* WARNING: Removing unreachable block (ram,0x005374f4) */

undefined4
apmngr_db_get_addr_by_sub_capacity
          (uint param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,int param_7)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *local_38;
  
  if ((((int)param_1 < 0) || (apmngr_ap_num_max <= (int)param_1)) || (param_2 == 0)) {
    if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d input error\n","apmngr_db_get_addr_by_sub_capacity",0x305);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  iVar2 = param_1 * 0x2d8;
  if (49999 < (int)param_1) {
    iVar2 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
  }
  uVar4 = param_1;
  if (*(int *)(g_apmngr_entry_array + iVar2 + 0x1c) == 0) {
LAB_00537198:
    if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0))
    goto LAB_005371a4;
    pcVar6 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not used\n";
    uVar7 = 0x30c;
  }
  else {
    iVar2 = param_1 * 0x2d8;
    if (49999 < (int)param_1) {
      iVar2 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
    }
    if (*(int *)(g_apmngr_entry_array + iVar2 + 0xc) == 0) goto LAB_00537198;
    iVar2 = param_1 * 0x2d8;
    if (49999 < (int)param_1) {
      iVar2 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
    }
    if (*(uint *)(g_apmngr_entry_array + iVar2 + 0x2ac) < 2) {
LAB_005371e0:
      if ((apmngr_debug_switch == '\0') || (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)
         ) goto LAB_005371a4;
      pcVar6 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in right state\n";
      uVar7 = 0x311;
    }
    else {
      iVar2 = param_1 * 0x2d8;
      if (49999 < (int)param_1) {
        iVar2 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
      }
      if (3 < *(uint *)(g_apmngr_entry_array + iVar2 + 0x2ac)) goto LAB_005371e0;
      if ((param_4 == 0) || (iVar2 = multi_link_status_get(param_1 & 0xffff), iVar2 != 0)) {
        iVar2 = g_apmngr_entry_array;
        iVar3 = param_1 * 0x2d8;
        if (49999 < (int)param_1) {
          iVar3 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
        }
        if ((param_5 & 1 << (*(int *)(g_apmngr_entry_array + iVar3 + 0x14) + 0x10U & 0x1f)) != 0) {
          if (0x5f < param_6) {
            FUN_00407f30(apmngr_db_mutex);
            if (apmngr_err_switch == '\0') {
              return 0xffffffff;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 != 0) {
              printf("[APMNGR_ERROR]%s()/%d main_cap(%d) is illegal\n",
                     "apmngr_db_get_addr_by_sub_capacity",0x322,param_6);
              return 0xffffffff;
            }
            return 0xffffffff;
          }
          if (param_3 == 0) {
            iVar3 = param_1 * 0x2d8;
            if (49999 < (int)param_1) {
              iVar3 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
            }
            uVar4 = 1 << (param_6 & 0x1f) &
                    *(uint *)(g_apmngr_entry_array + iVar3 + (((int)param_6 >> 5) + 0x94) * 4);
          }
          else {
            iVar3 = param_1 * 0x2d8;
            if (49999 < (int)param_1) {
              iVar3 = ((param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
            }
            uVar4 = 1 << (param_6 & 0x1f) &
                    *(uint *)(g_apmngr_entry_array + iVar3 + (((int)param_6 >> 5) + 0x94) * 4);
          }
          if (uVar4 == 0) {
            uVar4 = apmngr_db_get_sub_capability_idx(param_6);
            if (uVar4 < 3) {
              iVar10 = param_1 - 50000;
              iVar9 = param_1 * 0x2d8;
              iVar3 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
              if ((int)param_1 < 50000) {
                iVar3 = iVar9;
              }
              iVar3 = iVar2 + iVar3 + uVar4 * 4;
              local_38 = (int *)&stack0x0000001c;
              for (; 0 < param_7; param_7 = param_7 + -1) {
                iVar8 = *local_38;
                iVar5 = apmngr_db_check_sub_capability_valid(param_6,iVar8);
                if (iVar5 == 0) {
                  if ((apmngr_err_switch == '\0') ||
                     (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
                  pcVar6 = 
                  "[APMNGR_ERROR]%s()/%d ap_id(%d), main_cap(%d) sub_capability(%d) invalid\n";
                  uVar7 = 0x33d;
                  goto LAB_005372b4;
                }
                if (param_3 == 0) {
                  iVar5 = iVar8 + 7;
                  if (-1 < iVar8) {
                    iVar5 = iVar8;
                  }
                  if (((int)(uint)*(byte *)((iVar3 - (iVar5 >> 3)) + 0x263) >> (iVar8 % 8 & 0x1fU) &
                      1U) != 0) {
LAB_00537518:
                    if ((apmngr_warning_switch == '\0') ||
                       (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
                    pcVar6 = 
                    "[APMNGR_WARNING]%s()/%d ap_id(%d), main_cap(%d) sub_capability(%d) not support\n"
                    ;
                    uVar7 = 0x345;
                    goto LAB_005372b4;
                  }
                }
                else {
                  iVar5 = iVar8 + 7;
                  if (-1 < iVar8) {
                    iVar5 = iVar8;
                  }
                  if (((int)(uint)*(byte *)((iVar3 - (iVar5 >> 3)) + 0x263) >> (iVar8 % 8 & 0x1fU) &
                      1U) == 0) goto LAB_00537518;
                }
                local_38 = local_38 + 1;
              }
              iVar3 = iVar9;
              if (49999 < (int)param_1) {
                iVar3 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
              }
              if (*(int *)(iVar2 + iVar3 + 0x14) != 5) {
                iVar3 = iVar9;
                if (49999 < (int)param_1) {
                  iVar3 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                iVar3 = iVar2 + iVar3;
                iVar5 = iVar9;
                if (49999 < (int)param_1) {
                  iVar5 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar1 = *(undefined2 *)(iVar2 + iVar5 + 0x280);
                if (49999 < (int)param_1) {
                  iVar9 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                }
                uVar7 = 0;
LAB_0053761c:
                serv_wtp_address_arg_add
                          (param_2,*(undefined4 *)(iVar3 + 0x26c),*(undefined4 *)(iVar3 + 0x270),
                           *(undefined4 *)(iVar3 + 0x274),*(undefined4 *)(iVar3 + 0x278),
                           *(undefined4 *)(iVar3 + 0x27c),uVar1,iVar2 + iVar9 + 0x48,uVar7);
                goto LAB_005371a4;
              }
              iVar3 = iVar9;
              if (49999 < (int)param_1) {
                iVar3 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
              }
              uVar4 = (uint)*(short *)(iVar2 + iVar3 + 0x18);
              if (((int)uVar4 < 0) || (apmngr_ap_num_max <= (int)uVar4)) {
                FUN_00407f30(apmngr_db_mutex);
                if (apmngr_err_switch == '\0') {
                  return 0xffffffff;
                }
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  return 0xffffffff;
                }
                printf("[APMNGR_ERROR]%s()/%d cap id(%d) is illegal\n",
                       "apmngr_db_get_addr_by_sub_capacity",0x355,uVar4);
                return 0xffffffff;
              }
              iVar3 = iVar2 + uVar4 * 0x2d8;
              if ((*(int *)(iVar3 + 0x1c) == 0) || (*(int *)(iVar3 + 0xc) == 0)) {
                if ((apmngr_debug_switch == '\0') ||
                   (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
                pcVar6 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not used\n";
                uVar7 = 0x35b;
              }
              else {
                if ((1 < *(uint *)(iVar3 + 0x2ac)) && (*(uint *)(iVar3 + 0x2ac) < 4)) {
                  uVar1 = *(undefined2 *)(iVar3 + 0x280);
                  if (49999 < (int)param_1) {
                    iVar9 = (iVar10 + apmngr_ap_num_max + apmngr_template_num_max) * 0x2d8;
                  }
                  uVar7 = 1;
                  goto LAB_0053761c;
                }
                if ((apmngr_debug_switch == '\0') ||
                   (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
                pcVar6 = "[APMNGR_DEBUG]%s()/%d cap(%d) is not in right state\n";
                uVar7 = 0x360;
              }
              goto LAB_0053716c;
            }
            if ((apmngr_err_switch == '\0') ||
               (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
            pcVar6 = "[APMNGR_ERROR]%s()/%d ap_id(%d), main_cap(%d) no sub capability idx\n";
            uVar7 = 0x331;
          }
          else {
            if ((apmngr_err_switch == '\0') ||
               (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
            pcVar6 = "[APMNGR_ERROR]%s()/%d ap_id(%d), main_cap(%d) is not support\n";
            uVar7 = 0x328;
          }
LAB_005372b4:
          printf(pcVar6,"apmngr_db_get_addr_by_sub_capacity",uVar7,param_1,param_6);
          goto LAB_005371a4;
        }
        if ((apmngr_debug_switch == '\0') ||
           (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
        pcVar6 = "[APMNGR_DEBUG]%s()/%d ap(%d) role is not matched\n";
        uVar7 = 0x31b;
      }
      else {
        if ((apmngr_debug_switch == '\0') ||
           (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 == 0)) goto LAB_005371a4;
        pcVar6 = "[APMNGR_DEBUG]%s()/%d ap(%d) is not in master link state\n";
        uVar7 = 0x316;
      }
    }
  }
LAB_0053716c:
  printf(pcVar6,"apmngr_db_get_addr_by_sub_capacity",uVar7,uVar4);
LAB_005371a4:
  FUN_00407f30(apmngr_db_mutex);
  return 0;
}

