// func apmngr_db_group_get_by_id @ 00538ac0 size=292

undefined4 apmngr_db_group_get_by_id(uint param_1,void *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_group_num_max) && (param_2 != (void *)0x0)) {
    if (*(int *)(g_apmngr_group_array + param_1 * 0x84 + 0x10) != 0) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      memcpy(param_2,(void *)(g_apmngr_group_array + param_1 * 0x84),0x84);
      FUN_00407f30(apmngr_db_mutex);
      return 0;
    }
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APMNGR_ERROR]%s()/%d Group id[%d] not in use.\n";
      uVar2 = 0x5af;
LAB_00538b88:
      printf(__format,"apmngr_db_group_get_by_id",uVar2,param_1);
      return 0xffffffff;
    }
  }
  else if (apmngr_err_switch != '\0') {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid group id[%d] or entry is null.\n";
    uVar2 = 0x5a8;
    goto LAB_00538b88;
  }
  return 0xffffffff;
}

