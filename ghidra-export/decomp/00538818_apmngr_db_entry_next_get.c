// func apmngr_db_entry_next_get @ 00538818 size=1

undefined4 apmngr_db_entry_next_get(uint param_1,void *param_2)

{
  int iVar1;
  void *__src;
  
  param_1 = param_1 & 0xffff;
  if ((((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
      ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) &&
     (param_2 != (void *)0x0)) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    if (param_1 != 0xffff) {
      if (49999 < param_1) {
        param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar1 = g_apmngr_entry_array + param_1 * 0x2d8;
      if (*(int *)(iVar1 + 0x1c) != 0) {
        __src = (void *)FUN_00408680(iVar1);
        if (__src == (void *)0x0) {
          iVar1 = g_apmngr_group_array + (uint)*(ushort *)(iVar1 + 0x12) * 0x84;
          do {
            iVar1 = FUN_00408680(iVar1);
            if (iVar1 == 0) goto code_r0x005389c8;
            __src = (void *)FUN_004081b0(iVar1 + 0x78);
          } while (__src == (void *)0x0);
        }
        memcpy(param_2,__src,0x2d8);
        FUN_00407f30(apmngr_db_mutex);
        return 0;
      }
    }
code_r0x005389c8:
    FUN_00407f30(apmngr_db_mutex);
  }
  else if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or entry is null.\n","apmngr_db_entry_next_get",
           0x552,param_1);
  }
  return 0xffffffff;
}

