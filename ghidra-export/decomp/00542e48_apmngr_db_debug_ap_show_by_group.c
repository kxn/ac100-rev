// func apmngr_db_debug_ap_show_by_group @ 00542e48 size=1

/* WARNING: Removing unreachable block (ram,0x005381ac) */
/* WARNING: Removing unreachable block (ram,0x005381b0) */
/* WARNING: Removing unreachable block (ram,0x005381b8) */

int apmngr_db_debug_ap_show_by_group(uint param_1)

{
  bool bVar1;
  void *__src;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  param_1 = param_1 & 0xffff;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  if ((int)param_1 < apmngr_group_num_max) {
    if (*(int *)(g_apmngr_group_array + param_1 * 0x84 + 0x10) != 0) {
      FUN_0051ad88(&uStack_38);
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      pvVar3 = (void *)FUN_004081b0(g_apmngr_group_array + param_1 * 0x84 + 0x78);
joined_r0x00538160:
      __src = pvVar3;
      if (__src != (void *)0x0) {
        pvVar3 = (void *)FUN_00408680(__src);
        if (*(int *)((int)__src + 0x24) != 0) goto code_r0x00538180;
        iVar2 = *(int *)((int)__src + 0x14);
        goto LAB_00538190;
      }
LAB_005381f4:
      bVar1 = true;
      FUN_00407f30(apmngr_db_mutex);
      iVar7 = 0;
      iVar2 = FUN_004081b0(&uStack_38);
      while (iVar2 != 0) {
        iVar4 = FUN_00408680(iVar2);
        if (bVar1) {
          bVar1 = true;
          iVar7 = _apmngr_db_entry_printf_pf(iVar2 + 0x10,0);
          if ((((iVar7 != 0) && (bVar1 = false, iVar7 != 2)) &&
              (bVar1 = true, apmngr_err_switch != '\0')) &&
             (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[APMNGR_ERROR]%s()/%d Failed to proc callback for ap(%d).\n",
                   "apmngr_db_foreach_proc_by_group",0x53d,(uint)*(ushort *)(iVar2 + 0x20));
          }
        }
        FUN_00407df0(iVar2);
        iVar2 = iVar4;
      }
      return iVar7;
    }
    if (apmngr_err_switch != '\0') {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 1;
      }
      __format = "[APMNGR_ERROR]%s()/%d Group id[%d] not in use.\n";
      uVar6 = 0x507;
LAB_005380e8:
      printf(__format,"apmngr_db_foreach_proc_by_group",uVar6,param_1);
      return 1;
    }
  }
  else if (apmngr_err_switch != '\0') {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 1;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid group id[%d] or Callback is null.\n";
    uVar6 = 0x500;
    goto LAB_005380e8;
  }
  return 1;
code_r0x00538180:
  if (*(int *)((int)__src + 0x3c) != 0) {
    iVar2 = *(int *)((int)__src + 0x14);
LAB_00538190:
    if (1 << (iVar2 + 0x10U & 0x1f) != 0) {
      iVar2 = FUN_00408450(0x2e8,0x520);
      if (iVar2 == 0) {
        if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(apmngr_db_mutex), iVar2 != 0)
           ) {
          printf("[APMNGR_ERROR]%s()/%d No memory.\n","apmngr_db_foreach_proc_by_group",0x523);
        }
        goto LAB_005381f4;
      }
      memcpy((void *)(iVar2 + 0x10),__src,0x2d8);
      FUN_004086b0(&uStack_38,iVar2);
    }
  }
  goto joined_r0x00538160;
}

