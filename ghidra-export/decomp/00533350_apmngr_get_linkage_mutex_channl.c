// func apmngr_get_linkage_mutex_channl @ 00533350 size=1016

undefined4 apmngr_get_linkage_mutex_channl(uint param_1,uint param_2,char *param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char local_480 [3];
  char acStack_47d [5];
  undefined4 local_478;
  undefined1 auStack_474 [356];
  int local_310;
  undefined1 auStack_308 [64];
  undefined4 local_2c8;
  undefined2 local_2c4;
  undefined2 local_2c2;
  undefined1 auStack_f0 [185];
  byte local_37;
  uint local_30;
  
  local_30 = param_2 & 0xff;
  if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_get_linkage_mutex_channl\n",
           "apmngr_get_linkage_mutex_channl",0xf4b);
  }
  memset(auStack_474,0,0x168);
  memset(auStack_308,0,0x2d8);
  local_478 = 0;
  acStack_47d[1] = '\0';
  acStack_47d[2] = '\0';
  acStack_47d[3] = '\0';
  acStack_47d[4] = '\0';
  local_480[0] = ',';
  iVar2 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_308);
  if (iVar2 == 0) {
    if (param_3 == (char *)0x0) {
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d get mutex channl failed id:%d\n";
      uVar5 = 0xf5e;
    }
    else {
      memset(param_3,0,100);
      local_478 = CONCAT22(local_2c4,local_2c2);
      iVar2 = apdb_hwver_exist_by_id(local_2c8,&local_478);
      if ((iVar2 != 1) || (iVar2 = apdb_get_ap_by_id(local_2c8,auStack_f0,auStack_474), iVar2 != 0))
      {
        if (apmngr_warning_switch == '\0') {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        printf("[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n",
               "apmngr_get_linkage_mutex_channl",0xf69);
        return 0xffffffff;
      }
      iVar2 = 0;
      if (0 < *(int *)(local_310 + 4)) {
        while (iVar2 < *(int *)(local_310 + 4)) {
          iVar6 = *(int *)(local_310 + 0x34) + iVar2 * 0x1fc;
          if ((apmngr_debug_switch != '\0') && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
            printf("[APMNGR_DEBUG]%s()/%d rrst->related_radio_cnt:%d\n",
                   "apmngr_get_linkage_mutex_channl",0xf76,(uint)*(byte *)(iVar6 + 8));
          }
          if (apmngr_debug_switch == '\0') {
            uVar3 = *(uint *)(iVar6 + 4);
          }
          else {
            iVar7 = is_target_debug_ap();
            if (iVar7 == 0) {
              uVar3 = *(uint *)(iVar6 + 4);
            }
            else {
              printf("[APMNGR_DEBUG]%s()/%d rrst->table_index:%d radio_role_table_idx:%d rrst->region_code_list[region_code]:%d\n"
                     ,"apmngr_get_linkage_mutex_channl",0xf77,*(undefined4 *)(iVar6 + 4),0,
                     (int)*(char *)(iVar6 + (uint)local_37 + 9));
              uVar3 = *(uint *)(iVar6 + 4);
            }
          }
          if ((uVar3 & 1) == 0) {
            iVar2 = iVar2 + 1;
          }
          else if ((*(char *)(iVar6 + (uint)local_37 + 9) == '\x01') || (local_37 == 0xff)) {
            iVar7 = iVar6;
            for (iVar9 = 0; iVar9 < (int)(uint)*(byte *)(iVar6 + 8); iVar9 = iVar9 + 1) {
              iVar8 = 0;
              while (sVar1 = *(short *)(iVar7 + iVar8 + 0x32), sVar1 != 0) {
                if ((*(byte *)(iVar7 + 0x98) == local_30) && (sVar1 != -1)) {
                  sprintf(acStack_47d + 1,"%hd ");
                  sVar4 = strlen(acStack_47d + 1);
                  if (-1 < (int)(sVar4 - 1)) {
                    acStack_47d[sVar4] = '\0';
                  }
                  sVar4 = strlen(param_3);
                  strncat(param_3,acStack_47d + 1,100 - sVar4);
                  sVar4 = strlen(param_3);
                  strncat(param_3,local_480,100 - sVar4);
                  iVar8 = iVar8 + 2;
                }
                else {
                  iVar8 = iVar8 + 2;
                }
              }
              iVar7 = iVar7 + 0x74;
            }
            iVar2 = iVar2 + 1;
          }
          else {
            iVar2 = iVar2 + 1;
          }
        }
        sVar4 = strlen(param_3);
        if ((int)(sVar4 - 1) < 0) {
          return 0;
        }
        param_3[sVar4 - 1] = '\0';
        return 0;
      }
      if (apmngr_err_switch == '\0') {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d this ap:%d radio role search table in AC\n";
      uVar5 = 0xf6f;
    }
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n";
    uVar5 = 0xf58;
  }
  printf(__format,"apmngr_get_linkage_mutex_channl",uVar5,param_1 & 0xffff);
  return 0xffffffff;
}

