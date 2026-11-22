// func rrm_ap_is_rrm_set @ 004aac44 size=468

undefined4 rrm_ap_is_rrm_set(uint param_1,uint param_2,int param_3)

{
  char *__format;
  undefined4 uVar1;
  
  param_2 = param_2 & 0xff;
  param_1 = param_1 & 0xffff;
  if (param_3 == 0) {
    if (param_2 == 0) {
      if (rrm_debug_switch != '\0') {
        printf("[RRM_DEBUG]%s()/%d apid = %d, set is_rrm = 1\n","rrm_ap_is_rrm_set",0x17e,param_1);
      }
      apmngr_db_ap_is_rrm_set(param_1,1);
      return 1;
    }
    if (rrm_debug_switch == '\0') {
      return 1;
    }
    __format = "[RRM_DEBUG]%s()/%d ap(%d) radio(%d) do not need set rrm state\n";
    uVar1 = 0x184;
    goto LAB_004aacb8;
  }
  if (param_2 == 0) {
    if ((*(short *)(*(int *)(DAT_00767bfc + 0x14) + param_1 * 2) == -1) &&
       (*(short *)(*(int *)(DAT_00767c00 + 0x14) + param_1 * 2) == -1)) {
      if (rrm_debug_switch == '\0') goto LAB_004aadcc;
      param_2 = 0;
      uVar1 = 0x18b;
      goto LAB_004aad68;
    }
  }
  else if (param_2 == 1) {
    if (*(short *)(*(int *)(DAT_00767c00 + 0x14) + param_1 * 2) == -1) {
      if (rrm_debug_switch == '\0') goto LAB_004aadcc;
      uVar1 = 0x191;
LAB_004aad68:
      printf("[RRM_DEBUG]%s()/%d ap(%d) radio(%d), set is_rrm = 0\n","rrm_ap_is_rrm_set",uVar1,
             param_1,param_2);
LAB_004aadcc:
      apmngr_db_ap_is_rrm_set(param_1,0);
      return 0;
    }
  }
  else if (param_2 == 2) {
    if (rrm_debug_switch == '\0') goto LAB_004aadcc;
    uVar1 = 0x197;
    goto LAB_004aad68;
  }
  if (rrm_debug_switch == '\0') {
    return 1;
  }
  __format = "[RRM_DEBUG]%s()/%d ap(%d) radio(%d) is_rrm = 1\n";
  uVar1 = 0x19c;
LAB_004aacb8:
  printf(__format,"rrm_ap_is_rrm_set",uVar1,param_1,param_2);
  return 1;
}

