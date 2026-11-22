// func rdmngr_db_get_related_radio_num @ 00623448 size=1036

undefined4
rdmngr_db_get_related_radio_num
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  byte in_stack_00000057;
  int in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int *in_stack_00000068;
  int *in_stack_0000006c;
  undefined4 local_2848;
  undefined4 *local_2844;
  int local_2804;
  int local_2800;
  uint local_27fc;
  undefined4 local_27f8;
  undefined1 *local_27f4;
  undefined4 local_27f0;
  int *local_27ec;
  undefined4 local_27e0;
  undefined4 local_27dc;
  undefined1 auStack_27d8 [8];
  byte local_27d0 [10152];
  
  piVar1 = in_stack_0000006c;
  iVar4 = in_stack_00000060;
  iVar7 = in_stack_0000005c;
  iVar2 = in_stack_00000058;
  uVar8 = (uint)in_stack_00000057;
  if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_db_get_related_radio_num ENTER\n",
           "rdmngr_db_get_related_radio_num",0x15fe);
  }
  local_27dc = 0;
  memset(auStack_27d8,0,0x27b0);
  local_27e0 = 0;
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar7 < 0) {
    return 0xffffffff;
  }
  if (in_stack_00000068 == (int *)0x0) {
    return 0xffffffff;
  }
  uVar6 = *(undefined4 *)(iVar4 + 0x40);
  if (in_stack_00000064 == 1) {
    local_27dc = *(undefined4 *)(iVar4 + 0x44);
    local_2848 = 0x27b0;
    local_2844 = &local_27e0;
    iVar4 = apdb_get_specified_rrst(uVar6,iVar4 + 0x218,local_27dc,auStack_27d8);
    if (iVar4 == -1) {
      if (rdmngr_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[RDMNGR_DEBUG]%s()/%d apdb_get_specified_rrst fail\n";
      uVar6 = 0x1616;
    }
    else {
      uVar6 = apmngr_db_get_cur_using_rrst_idx(0);
      if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d rrst exists,use rrst method to generate linked-strategy\n",
               "rdmngr_db_get_related_radio_num",0x161a);
      }
      local_27f4 = auStack_27d8;
      local_2804 = iVar2;
      local_2800 = iVar7;
      local_27ec = piVar1;
      local_27f0 = local_27e0;
      for (uVar5 = 0; uVar5 < 0x44; uVar5 = uVar5 + 1) {
        *(undefined1 *)((int)&local_2848 + uVar5) = (&stack0x00000010)[uVar5];
      }
      local_27fc = uVar8;
      local_27f8 = uVar6;
      iVar2 = rdmngr_db_rrst_matched_row_search_strategy(param_1,param_2,param_3,param_4);
      if (iVar2 == -1) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d rdmngr_db_rrst_matched_row_search_strategy fail\n";
        uVar6 = 0x161e;
      }
      else {
        if (rdmngr_debug_switch == 0) {
          iVar2 = *piVar1;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *piVar1;
          }
          else {
            printf("[RDMNGR_DEBUG]%s()/%d rrst_matched_row_index=%d\n",
                   "rdmngr_db_get_related_radio_num",0x1621,*piVar1);
            iVar2 = *piVar1;
          }
        }
        if (-2 < iVar2) {
          if (iVar2 == -1) {
            *piVar1 = 0;
            iVar7 = local_27d0[0] - 1;
          }
          else {
            iVar7 = local_27d0[iVar2 * 0x1fc] - 1;
          }
          goto LAB_00623510;
        }
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[RDMNGR_ERROR]%s()/%d invalid value rrst_matched_row_index\n";
        uVar6 = 0x1625;
      }
    }
    printf(__format,"rdmngr_db_get_related_radio_num",uVar6);
    return 0xffffffff;
  }
  if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d no rrst, just get related_radio_num\n",
           "rdmngr_db_get_related_radio_num",0x1636);
  }
  if (param_3 >> 0x18 == 0) {
    iVar2 = apdb_24g_is_supported_by_id(uVar6,iVar4 + 0x218);
    iVar7 = 0;
    if (iVar2 != 0) {
      iVar7 = apdb_24g_count_by_id(uVar6,iVar4 + 0x218);
      iVar7 = iVar7 + -1;
    }
  }
  else {
    iVar7 = 0;
    if (param_3 >> 0x18 == 1) {
      iVar2 = apdb_5g_is_supported_by_id(uVar6,iVar4 + 0x218);
      if (iVar2 != 0) {
        iVar7 = apdb_5g_count_by_id(uVar6,iVar4 + 0x218);
        iVar7 = iVar7 + -1;
      }
    }
  }
LAB_00623510:
  if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d related_radio_num=%d\n","rdmngr_db_get_related_radio_num",0x1645,
           iVar7);
  }
  *in_stack_00000068 = iVar7;
  return 0;
}

