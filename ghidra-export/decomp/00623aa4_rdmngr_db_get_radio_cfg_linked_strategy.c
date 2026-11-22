// func rdmngr_db_get_radio_cfg_linked_strategy @ 00623aa4 size=1448

/* WARNING: Type propagation algorithm not settling */

void * rdmngr_db_get_radio_cfg_linked_strategy
                 (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  void *__s;
  undefined1 uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  void *pvVar13;
  byte in_stack_00000057;
  undefined4 *in_stack_00000058;
  undefined1 *in_stack_0000005c;
  undefined1 *in_stack_00000060;
  undefined1 *in_stack_00000064;
  undefined4 local_28c8;
  int *local_28c4;
  undefined1 *local_2884;
  undefined4 *local_2880;
  undefined1 *local_287c;
  undefined1 *local_2878;
  int local_2874;
  undefined1 **local_2870;
  int *local_286c;
  undefined1 *local_2860;
  undefined4 local_285c;
  int local_2858 [3];
  undefined1 auStack_284c [40];
  undefined1 auStack_2824 [64];
  undefined1 auStack_27e4 [8];
  byte abStack_27dc [36];
  undefined1 auStack_27b8 [108];
  byte abStack_274c [4];
  undefined4 auStack_2748 [2502];
  undefined1 *local_30;
  
  puVar2 = in_stack_00000064;
  puVar10 = in_stack_00000060;
  puVar1 = in_stack_0000005c;
  puVar12 = in_stack_00000058;
  local_30 = (undefined1 *)(uint)in_stack_00000057;
  if ((rdmngr_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_db_get_radio_cfg_linked_strategy ENTER\n",
           "rdmngr_db_get_radio_cfg_linked_strategy",0x1679);
  }
  memset(auStack_27e4,0,0x27b0);
  local_2858[1] = 0;
  local_2858[0] = -1;
  memset(auStack_2824,0,0x40);
  local_285c = 0;
  memset(auStack_284c,0,0x28);
  local_2860 = (undefined1 *)0x0;
  if (puVar10 == (undefined1 *)0x0) {
    return (void *)0x0;
  }
  if (puVar12 == (undefined4 *)0x0) {
    return (void *)0x0;
  }
  if ((int)puVar1 < 0) {
    return (void *)0x0;
  }
  if (puVar2 == (undefined1 *)0x0) {
    return (void *)0x0;
  }
  iVar11 = 1;
  local_2858[2] = *(int *)(puVar10 + 0x44);
  local_28c8 = 0x27b0;
  local_28c4 = local_2858 + 1;
  iVar4 = apdb_get_specified_rrst
                    (*(undefined4 *)(puVar10 + 0x40),puVar10 + 0x218,local_2858[2],auStack_27e4);
  if (((iVar4 == -1) && (iVar11 = 0, rdmngr_debug_switch != 0)) &&
     (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d apdb_get_specified_rrst fail\n",
           "rdmngr_db_get_radio_cfg_linked_strategy",0x1696);
  }
  local_2870 = &local_2860;
  local_2880 = puVar12;
  local_286c = local_2858;
  local_2884 = local_30;
  local_287c = puVar1;
  local_2878 = puVar10;
  for (uVar5 = 0; uVar5 < 0x44; uVar5 = uVar5 + 1) {
    *(undefined1 *)((int)&local_28c8 + uVar5) = (&stack0x00000010)[uVar5];
  }
  local_2874 = iVar11;
  iVar4 = rdmngr_db_get_related_radio_num(param_1,param_2,param_3,param_4);
  if (iVar4 == -1) {
    if (rdmngr_err_switch == 0) {
      return (void *)0x0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return (void *)0x0;
    }
    pcVar7 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_related_radio_num fail\n";
    uVar9 = 0x169b;
  }
  else {
    if ((int)local_2860 < 1) {
      *puVar2 = 0;
      return (void *)0x0;
    }
    __s = (void *)FUN_00408450((int)local_2860 * 0xda,0x16a8);
    if (__s != (void *)0x0) {
      memset(__s,0,(int)local_2860 * 0xda);
      if (iVar11 == 0) {
        local_2880 = &local_285c;
        local_2884 = puVar10;
        local_287c = auStack_2824;
        local_2878 = auStack_284c;
        for (uVar5 = 0; uVar5 < 0x44; uVar5 = uVar5 + 1) {
          *(undefined1 *)((int)&local_28c8 + uVar5) = (&stack0x00000010)[uVar5];
        }
        iVar4 = rdmngr_db_get_mutex_chnl_and_linked_modify_items(param_1,param_2,param_3,param_4);
        if (iVar4 == -1) {
          if ((rdmngr_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            pcVar7 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_mutex_chnl_and_linked_modify_items fail\n"
            ;
            uVar9 = 0x16d8;
LAB_00623eec:
            printf(pcVar7,"rdmngr_db_get_radio_cfg_linked_strategy",uVar9);
          }
LAB_00623ef4:
          FUN_00407df0(__s);
          return (void *)0x0;
        }
        pvVar13 = __s;
        for (puVar10 = (undefined1 *)0x0;
            (puVar3 = local_2860, (int)puVar10 < (int)local_2860 &&
            (puVar3 = puVar10, puVar10 != puVar1)); puVar10 = puVar10 + 1) {
          local_28c8 = local_285c;
          local_28c4 = (int *)(uint)*(byte *)((int)puVar12 + 3);
          puVar12 = puVar12 + 0x15;
          iVar4 = rdmngr_db_get_radio_attribute_relation_unit_by_default
                            (pvVar13,puVar10,auStack_284c,auStack_2824);
          if (iVar4 == -1) {
            if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
            goto LAB_00623ef4;
            pcVar7 = "[RDMNGR_ERROR]%s()/%d set radio attribute relation unit by default fail\n";
            uVar9 = 0x16e4;
            goto LAB_00623eec;
          }
          pvVar13 = (void *)((int)pvVar13 + 0xda);
        }
        local_2860 = puVar3;
        uVar6 = SUB41(local_2860,0);
        if (rdmngr_debug_switch != 0) {
          iVar4 = is_target_debug_ap();
          uVar6 = SUB41(local_2860,0);
          if (iVar4 != 0) {
            pcVar7 = 
            "[RDMNGR_DEBUG]%s()/%d generate radio_attribute_relation_unit_by_default success\n";
            uVar9 = 0x16e9;
LAB_00623f6c:
            printf(pcVar7,"rdmngr_db_get_radio_cfg_linked_strategy",uVar9);
            *puVar2 = (char)local_2860;
            return __s;
          }
        }
      }
      else {
        if (local_2858[0] < 0) goto LAB_00623ef4;
        for (iVar4 = 0; iVar4 < (int)(uint)abStack_27dc[local_2858[0] * 0x1fc]; iVar4 = iVar4 + 1) {
          if ((uint)abStack_274c[iVar4 * 0x74 + local_2858[0] * 0x1fc] == (param_2 & 0xf)) {
            uVar9 = auStack_2748[local_2858[0] * 0x7f + iVar4 * 0x1d];
            goto LAB_00623e30;
          }
        }
        uVar9 = 0;
LAB_00623e30:
        iVar4 = 0;
        for (iVar11 = 0; iVar11 < (int)(uint)abStack_27dc[local_2858[0] * 0x1fc];
            iVar11 = iVar11 + 1) {
          iVar8 = iVar11 * 0x74 + local_2858[0] * 0x1fc;
          if ((uint)abStack_274c[iVar8] != (param_2 & 0xf)) {
            if ((int)local_2860 <= iVar4) break;
            iVar8 = rdmngr_db_get_radio_attribute_relation_unit_by_rrst
                              ((void *)((int)__s + iVar4 * 0xda),uVar9,auStack_27b8 + iVar8);
            if (iVar8 == -1) {
              if ((rdmngr_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
              goto LAB_00623ef4;
              pcVar7 = "[RDMNGR_ERROR]%s()/%d get_radio_attribute_relation_unit_by_rrst fail\n";
              uVar9 = 0x16cc;
              goto LAB_00623eec;
            }
            iVar4 = iVar4 + 1;
          }
        }
        uVar6 = SUB41(local_2860,0);
        if (rdmngr_debug_switch != 0) {
          iVar4 = is_target_debug_ap();
          uVar6 = SUB41(local_2860,0);
          if (iVar4 != 0) {
            pcVar7 = 
            "[RDMNGR_DEBUG]%s()/%d generate radio_attribute_relation_unit_by_rrst success\n";
            uVar9 = 0x16d2;
            goto LAB_00623f6c;
          }
        }
      }
      *puVar2 = uVar6;
      return __s;
    }
    if (rdmngr_err_switch == 0) {
      return (void *)0x0;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return (void *)0x0;
    }
    pcVar7 = "[RDMNGR_ERROR]%s()/%d mem malloc fail\n";
    uVar9 = 0x16ab;
  }
  printf(pcVar7,"rdmngr_db_get_radio_cfg_linked_strategy",uVar9);
  return (void *)0x0;
}

