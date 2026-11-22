// func apmngr_get_linkage_support_160m @ 00533034 size=796

undefined4 apmngr_get_linkage_support_160m(uint param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_468;
  undefined1 auStack_464 [356];
  int local_300;
  undefined1 auStack_2f8 [64];
  undefined4 local_2b8;
  undefined2 local_2b4;
  undefined2 local_2b2;
  undefined1 auStack_e0 [192];
  
  param_2 = param_2 & 0xff;
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_get_linkage_support_160m region_code:%d\n",
           "apmngr_get_linkage_support_160m",0xf11,param_2);
  }
  memset(auStack_464,0,0x168);
  memset(auStack_2f8,0,0x2d8);
  local_468 = 0;
  iVar2 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f8);
  if (iVar2 == 0) {
    local_468 = CONCAT22(local_2b4,local_2b2);
    iVar2 = apdb_hwver_exist_by_id(local_2b8,&local_468);
    if ((iVar2 != 1) || (iVar2 = apdb_get_ap_by_id(local_2b8,auStack_e0,auStack_464), iVar2 != 0)) {
      uVar7 = 0xffffffff;
      if (apmngr_warning_switch == '\0') {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n";
      uVar6 = 0xf25;
LAB_00533148:
      printf(pcVar5,"apmngr_get_linkage_support_160m",uVar6);
      return uVar7;
    }
    iVar2 = 0;
    if (0 < *(int *)(local_300 + 4)) {
      do {
        while( true ) {
          while( true ) {
            if (*(int *)(local_300 + 4) <= iVar2) {
              return 0xffffffff;
            }
            iVar8 = *(int *)(local_300 + 0x34) + iVar2 * 0x1fc;
            if ((apmngr_debug_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[APMNGR_DEBUG]%s()/%d rrst->related_radio_cnt:%d\n",
                     "apmngr_get_linkage_support_160m",0xf32,(uint)*(byte *)(iVar8 + 8));
            }
            if (apmngr_debug_switch == '\0') {
              uVar3 = *(uint *)(iVar8 + 4);
            }
            else {
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                uVar3 = *(uint *)(iVar8 + 4);
              }
              else {
                printf("[APMNGR_DEBUG]%s()/%d rrst->table_index:%d radio_role_table_idx:%d rrst->region_code_list[region_code]:%d\n"
                       ,"apmngr_get_linkage_support_160m",0xf33,*(undefined4 *)(iVar8 + 4),0,
                       (int)*(char *)(iVar8 + param_2 + 9));
                uVar3 = *(uint *)(iVar8 + 4);
              }
            }
            if ((uVar3 & 1) != 0) break;
            iVar2 = iVar2 + 1;
          }
          if (*(char *)(iVar8 + param_2 + 9) == '\x01') break;
          iVar2 = iVar2 + 1;
        }
        pbVar1 = (byte *)(iVar8 + 8);
        iVar4 = 0;
        while (iVar4 < (int)(uint)*pbVar1) {
          iVar4 = iVar4 + 1;
          if (((*(byte *)(iVar8 + 0x99) & 0x20) != 0) && (*(char *)(iVar8 + 0x98) == '\x03')) {
            uVar7 = 0;
            if (apmngr_debug_switch == '\0') {
              return 0;
            }
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              return 0;
            }
            pcVar5 = "[APMNGR_DEBUG]%s()/%d find the row to change!\n";
            uVar6 = 0xf3b;
            goto LAB_00533148;
          }
          iVar8 = iVar8 + 0x74;
        }
        iVar2 = iVar2 + 1;
      } while( true );
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APMNGR_ERROR]%s()/%d this ap:%d radio role search table in AC\n";
    uVar7 = 0xf2b;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n";
    uVar7 = 0xf1b;
  }
  printf(pcVar5,"apmngr_get_linkage_support_160m",uVar7,param_1 & 0xffff);
  return 0xffffffff;
}

