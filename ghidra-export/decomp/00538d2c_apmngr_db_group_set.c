// func apmngr_db_group_set @ 00538d2c size=284

undefined4 apmngr_db_group_set(uint param_1,char *param_2)

{
  char *__format;
  undefined4 uVar1;
  int iVar2;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_group_num_max) && (param_2 != (char *)0x0)) {
    iVar2 = g_apmngr_group_array + param_1 * 0x84;
    if (*(int *)(iVar2 + 0x10) != 0) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      strncpy((char *)(iVar2 + 0x14),param_2,0x61);
      uVar1 = apmngr_db_mutex;
      *(undefined1 *)(iVar2 + 0x75) = 0;
      FUN_00407f30(uVar1);
      return 0;
    }
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "[APMNGR_ERROR]%s()/%d Group id[%d] not in use.\n";
      uVar1 = 0x5e0;
LAB_00538dec:
      printf(__format,"apmngr_db_group_set",uVar1,param_1);
      return 0xffffffff;
    }
  }
  else if (apmngr_err_switch != '\0') {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid group id[%d] or group_name is NULL.\n";
    uVar1 = 0x5d9;
    goto LAB_00538dec;
  }
  return 0xffffffff;
}

