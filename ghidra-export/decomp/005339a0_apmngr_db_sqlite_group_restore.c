// func apmngr_db_sqlite_group_restore @ 005339a0 size=656

undefined4
apmngr_db_sqlite_group_restore
          (undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *__nptr;
  int iVar4;
  int iVar5;
  char acStack_f0 [200];
  
  memset(acStack_f0,0,200);
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    if (apmngr_err_switch != '\0') {
      iVar4 = is_target_debug_ap();
      if (iVar4 != 0) {
        printf("[APMNGR_ERROR]%s()/%d Input value invalid.\n","apmngr_db_sqlite_group_restore",0xdcf
              );
        return 1;
      }
      return 1;
    }
  }
  else {
    iVar4 = -1;
    for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
      pcVar3 = (char *)*param_4;
      if ((pcVar3 == (char *)0x0) || (__nptr = (char *)*param_3, __nptr == (char *)0x0)) {
        if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_WARNING]%s()/%d column_name or column_value is null!\n",
                 "apmngr_db_sqlite_group_restore",0xdd8);
        }
      }
      else {
        iVar1 = strcmp(pcVar3,"group_id");
        if (iVar1 == 0) {
          iVar4 = atoi(__nptr);
          if ((iVar4 < 0) || (apmngr_group_num_max <= iVar4)) {
            if (apmngr_err_switch == '\0') {
              return 1;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return 1;
            }
            pcVar3 = "[APMNGR_ERROR]%s()/%d Invalid group id[%d].\n";
            uVar2 = 0xde1;
            goto LAB_00533b70;
          }
        }
        else {
          iVar1 = strcmp(pcVar3,"name");
          if (iVar1 == 0) {
            strncpy(acStack_f0,__nptr,199);
          }
        }
      }
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
    }
    if (iVar4 != -1) {
      iVar5 = g_apmngr_group_array + iVar4 * 0x84;
      *(short *)(iVar5 + 0xc) = (short)iVar4;
      *(undefined4 *)(iVar5 + 0x10) = 1;
      strncpy((char *)(iVar5 + 0x14),acStack_f0,0x61);
      FUN_004086b0(&g_apmngr_group_list,iVar5);
      return 0;
    }
    if (apmngr_err_switch != '\0') {
      iVar4 = is_target_debug_ap();
      if (iVar4 == 0) {
        return 1;
      }
      pcVar3 = "[APMNGR_ERROR]%s()/%d Invalid gid[%d].\n";
      uVar2 = 0xded;
      iVar4 = -1;
LAB_00533b70:
      printf(pcVar3,"apmngr_db_sqlite_group_restore",uVar2,iVar4);
      return 1;
    }
  }
  return 1;
}

