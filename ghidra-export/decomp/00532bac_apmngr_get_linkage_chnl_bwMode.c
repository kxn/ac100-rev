// func apmngr_get_linkage_chnl_bwMode @ 00532bac size=1160

undefined4
apmngr_get_linkage_chnl_bwMode
          (uint param_1,int param_2,uint param_3,short param_4,short *param_5,undefined1 *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_478;
  undefined1 auStack_474 [356];
  int local_310;
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined2 local_2c4;
  undefined2 local_2c2;
  undefined1 auStack_f0 [192];
  int local_30;
  
  param_1 = param_1 & 0xffff;
  param_3 = param_3 & 0xff;
  iVar9 = (int)param_4;
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_get_linkage_chnl_bwMode region_code:%d\n",
           "apmngr_get_linkage_chnl_bwMode",0xec2,param_3);
  }
  memset(auStack_474,0,0x168);
  memset(auStack_308,0,0x2d8);
  local_478 = 0;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_308);
  if (iVar1 == 0) {
    local_478 = CONCAT22(local_2c4,local_2c2);
    iVar1 = apdb_hwver_exist_by_id(local_2c8,&local_478);
    if ((iVar1 != 1) || (iVar1 = apdb_get_ap_by_id(local_2c8,auStack_f0,auStack_474), iVar1 != 0)) {
      if (apmngr_warning_switch == '\0') {
        return 0xffffffff;
      }
      iVar9 = is_target_debug_ap();
      if (iVar9 == 0) {
        return 0xffffffff;
      }
      printf("[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n",
             "apmngr_get_linkage_chnl_bwMode",0xed8);
      return 0xffffffff;
    }
    iVar1 = 0;
    if (0 < *(int *)(local_310 + 4)) {
LAB_00532d5c:
      do {
        if (*(int *)(local_310 + 4) <= iVar1) {
          *param_5 = -1;
LAB_00532fbc:
          *param_6 = 2;
          return 0;
        }
        iVar7 = *(int *)(local_310 + 0x34) + iVar1 * 0x1fc;
        if ((apmngr_debug_switch != '\0') && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d rrst->related_radio_cnt:%d\n",
                 "apmngr_get_linkage_chnl_bwMode",0xee5,(uint)*(byte *)(iVar7 + 8));
        }
        if (apmngr_debug_switch == '\0') {
          uVar2 = *(uint *)(iVar7 + 4);
        }
        else {
          iVar8 = is_target_debug_ap();
          if (iVar8 == 0) {
            uVar2 = *(uint *)(iVar7 + 4);
          }
          else {
            printf("[APMNGR_DEBUG]%s()/%d rrst->table_index:%d radio_role_table_idx:%d rrst->region_code_list[region_code]:%d\n"
                   ,"apmngr_get_linkage_chnl_bwMode",0xee6,*(undefined4 *)(iVar7 + 4),0,
                   (int)*(char *)(iVar7 + param_3 + 9));
            uVar2 = *(uint *)(iVar7 + 4);
          }
        }
        if ((uVar2 & 1) != 0) {
          if ((*(char *)(iVar7 + param_3 + 9) == '\x01') || (param_3 == 0xff)) {
            local_30 = iVar7;
            for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(iVar7 + 8); iVar8 = iVar8 + 1) {
              iVar3 = rdmngr_db_generate_rd_id(param_1,*(undefined1 *)(local_30 + 0x98));
              if ((apmngr_debug_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[APMNGR_DEBUG]%s()/%d generate rf_id:%d rf_id:%d\n",
                       "apmngr_get_linkage_chnl_bwMode",0xeec,iVar3,param_2);
              }
              if (iVar3 == param_2) {
                psVar6 = (short *)(iVar7 + iVar8 * 0x74 + 0x32);
                if (apmngr_debug_switch == '\0') {
                  iVar3 = 0;
                }
                else {
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    iVar3 = 0;
                  }
                  else {
                    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_region_code_channel_support cur_chnl:%d\n"
                           ,"apmngr_region_code_channel_support",0xeb2,iVar9);
                    iVar3 = 0;
                  }
                }
                do {
                  if (apmngr_debug_switch == '\0') {
                    iVar4 = (int)*psVar6;
                  }
                  else {
                    iVar4 = is_target_debug_ap();
                    if (iVar4 == 0) {
                      iVar4 = (int)*psVar6;
                    }
                    else {
                      printf("[APMNGR_DEBUG]%s()/%d channel[i]:%d  cur_channel:%d\n",
                             "apmngr_region_code_channel_support",0xeb6,(int)*psVar6,iVar9);
                      iVar4 = (int)*psVar6;
                    }
                  }
                  iVar3 = iVar3 + 1;
                  if (iVar4 == iVar9) {
                    if ((apmngr_debug_switch != '\0') && (iVar9 = is_target_debug_ap(), iVar9 != 0))
                    {
                      printf("[APMNGR_DEBUG]%s()/%d find the row to change!\n",
                             "apmngr_get_linkage_chnl_bwMode",0xef0);
                    }
                    *param_5 = param_4;
                    if ((*(byte *)(iVar7 + iVar8 * 0x74 + 0x99) & 1) == 0) {
                      *param_6 = 0;
                      return 0;
                    }
                    goto LAB_00532fbc;
                  }
                  psVar6 = psVar6 + 1;
                } while (iVar3 != 0x33);
              }
              local_30 = local_30 + 0x74;
            }
            iVar1 = iVar1 + 1;
          }
          else {
            iVar1 = iVar1 + 1;
          }
          goto LAB_00532d5c;
        }
        iVar1 = iVar1 + 1;
      } while( true );
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar9 = is_target_debug_ap();
    if (iVar9 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d this ap:%d radio role search table in AC\n";
    uVar5 = 0xede;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar9 = is_target_debug_ap();
    if (iVar9 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n";
    uVar5 = 0xece;
  }
  printf(__format,"apmngr_get_linkage_chnl_bwMode",uVar5,param_1);
  return 0xffffffff;
}

