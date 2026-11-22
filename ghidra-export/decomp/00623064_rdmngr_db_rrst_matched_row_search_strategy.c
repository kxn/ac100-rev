// func rdmngr_db_rrst_matched_row_search_strategy @ 00623064 size=996

/* WARNING: Type propagation algorithm not settling */

undefined4
rdmngr_db_rrst_matched_row_search_strategy
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int in_stack_00000054;
  int in_stack_00000058;
  byte in_stack_0000005f;
  byte in_stack_00000063;
  int in_stack_00000064;
  int in_stack_00000068;
  int *in_stack_0000006c;
  int *local_100;
  int *local_fc;
  uint local_bc;
  uint local_b8;
  int local_b4;
  int local_b0;
  byte *local_ac;
  int *local_a8;
  byte local_98 [4];
  int local_94 [21];
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  piVar1 = in_stack_0000006c;
  iVar3 = in_stack_00000068;
  iVar5 = in_stack_00000064;
  local_98[0] = 0;
  uVar8 = (uint)in_stack_0000005f;
  uVar10 = (uint)in_stack_00000063;
  memset(local_94 + 1,0,0x50);
  local_94[1] = 0xffffffff;
  local_94[0] = 0;
  if (in_stack_00000054 == 0) {
    return 0xffffffff;
  }
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  if (iVar3 < 1) {
    return 0xffffffff;
  }
  local_ac = local_98;
  if (piVar1 == (int *)0x0) {
    return 0xffffffff;
  }
  local_b4 = iVar5;
  local_b0 = iVar3;
  local_bc = uVar8;
  for (uVar2 = 0; uVar2 < 0x44; uVar2 = uVar2 + 1) {
    *(undefined1 *)((int)&local_100 + uVar2) = (&stack0x00000010)[uVar2];
  }
  local_b8 = uVar10;
  local_a8 = local_94 + 1;
  iVar3 = rdmngr_db_rrst_matched_row_find(param_1,param_2,param_3,param_4);
  if (iVar3 == -1) {
    uVar7 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rrst_matched_row_find fail\n";
    uVar6 = 0x15b0;
  }
  else if (local_98[0] == 0) {
    *piVar1 = -1;
    uVar7 = 0;
    if (rdmngr_debug_switch == 0) {
      return 0;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0;
    }
    __format = "[RDMNGR_DEBUG]%s()/%d no pre_matched row of src_rrst\n";
    uVar6 = 0x15b7;
  }
  else {
    uVar8 = (uint)local_98[0];
    if (rdmngr_debug_switch != 0) {
      iVar3 = is_target_debug_ap();
      uVar8 = (uint)local_98[0];
      if (iVar3 != 0) {
        printf("[RDMNGR_DEBUG]%s()/%d pre_matched rrst_row cnt = %d\n",
               "rdmngr_db_rrst_matched_row_search_strategy",0x15ba,uVar8);
        uVar8 = (uint)local_98[0];
      }
    }
    local_fc = local_94;
    piVar14 = local_94 + 1;
    local_100 = piVar14;
    iVar3 = rdmngr_db_rrst_matched_row_pre_match(in_stack_00000054,in_stack_00000058,iVar5,uVar8);
    if (iVar3 != -1) {
      if (local_94[0] == 1) {
        if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d cfg_no_changed_match_success, idx=%d\n",
                 "rdmngr_db_rrst_matched_row_search_strategy",0x15c6,0xffffffff);
        }
      }
      else {
        iVar3 = 0;
        local_38 = (uint)local_98[0];
LAB_00623200:
        if (iVar3 < (int)local_38) {
          local_40 = *piVar14;
          iVar13 = 0;
          local_3c = iVar5 + local_40 * 0x1fc;
          iVar11 = in_stack_00000054;
          do {
            if (in_stack_00000058 <= iVar13) {
              *piVar1 = local_40;
              if (rdmngr_debug_switch == 0) {
                return 0;
              }
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                return 0;
              }
              printf("[RDMNGR_DEBUG]%s()/%d cfg_changed_match_success, idx=%d\n",
                     "rdmngr_db_rrst_matched_row_search_strategy",0x15f2,local_40);
              return 0;
            }
            local_34 = (uint)*(byte *)(iVar11 + 3);
            local_30 = (uint)*(byte *)(local_3c + 8);
            local_2c = (uint)(*(char *)(iVar11 + 0x4e) == '\0');
            iVar9 = local_3c;
            for (iVar12 = 0; iVar12 < (int)local_30; iVar12 = iVar12 + 1) {
              if ((*(byte *)(iVar9 + 0x98) == local_34) &&
                 (iVar4 = rdmngr_db_check_fit_row_rrst_radio_abstract_status
                                    (local_2c,*(undefined4 *)(iVar9 + 0x2c)), iVar4 == 0)) {
                iVar3 = iVar3 + 1;
                piVar14 = piVar14 + 1;
                goto LAB_00623200;
              }
              iVar9 = iVar9 + 0x74;
            }
            iVar13 = iVar13 + 1;
            iVar11 = iVar11 + 0x54;
          } while( true );
        }
        if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[RDMNGR_DEBUG]%s()/%d no matched row, idx=-1\n",
                 "rdmngr_db_rrst_matched_row_search_strategy",0x15f6);
        }
      }
      *piVar1 = -1;
      return 0;
    }
    uVar7 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rrst_matched_row_pre_match fail\n";
    uVar6 = 0x15bf;
  }
  printf(__format,"rdmngr_db_rrst_matched_row_search_strategy",uVar6);
  return uVar7;
}

