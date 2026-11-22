// func apmngr_db_ap_flag_unset @ 00539704 size=456

undefined4 apmngr_db_ap_flag_unset(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  
  param_1 = param_1 & 0xffff;
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    if (param_2 < 4) {
      FUN_004082d0(apmngr_db_mutex,0xffffffff);
      uVar2 = param_1;
      if (49999 < param_1) {
        uVar2 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      uVar3 = 0xffffffff;
      if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) != 0) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        iVar1 = g_apmngr_entry_array + param_1 * 0x2d8;
        uVar3 = 0;
        *(ushort *)(iVar1 + 0x28) = ~(ushort)(1 << (param_2 & 0x1f)) & *(ushort *)(iVar1 + 0x28);
      }
      FUN_00407f30(apmngr_db_mutex);
      return uVar3;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid flag bit[%d] \n";
    uVar3 = 0x6ac;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or entry is NULL.\n";
    uVar3 = 0x6a7;
    param_2 = param_1;
  }
  printf(__format,"apmngr_db_ap_flag_unset",uVar3,param_2);
  return 0xffffffff;
}

