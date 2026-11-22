// func check_ap_can_report_by_statics @ 0048e4a0 size=508

undefined4 check_ap_can_report_by_statics(byte *param_1,uint param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  char cVar3;
  char *__format;
  undefined4 uVar4;
  
  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (cloud_mngt_info_switch == '\0') {
    uVar1 = *(undefined2 *)(param_1 + 10);
  }
  else {
    printf("[CLOUD_MNGT_INFO]%s()/%d %02X-%02X-%02X-%02X-%02X-%02X  \n",
           "check_ap_can_report_by_statics",0x15db,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
           (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    uVar1 = *(undefined2 *)(param_1 + 10);
  }
  iVar2 = stats_db_radio_sample_mask_check(uVar1,0);
  if (iVar2 == 0) {
    if (cloud_mngt_info_switch == '\0') {
      return 0xffffffff;
    }
    printf("[CLOUD_MNGT_INFO]%s()/%d %02X-%02X-%02X-%02X-%02X-%02X  \n",
           "check_ap_can_report_by_statics",0x15e0,(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
           (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    return 0xffffffff;
  }
  iVar2 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 10),param_3);
  if (iVar2 == 0) {
    cVar3 = *(char *)(param_3 + 0x1c5);
LAB_0048e5b8:
    if ((cVar3 == '\0') || (*(int *)(param_3 + 0x3c) == 0)) {
      iVar2 = is_stats_db_ap_config_id_set(*(undefined2 *)(param_1 + 10));
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_3 + 0xc);
        goto LAB_0048e5e0;
      }
    }
    else {
      iVar2 = *(int *)(param_3 + 0xc);
LAB_0048e5e0:
      if (iVar2 != 0) {
        iVar2 = check_can_direct_report_by_ac(param_3,0);
        if (iVar2 == 0) {
          return 0;
        }
        if ((param_2 & 8) != 0) {
          return 0;
        }
        if (cloud_mngt_info_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[CLOUD_MNGT_INFO]%s()/%d ===state:%d\n";
        uVar4 = 0x15f5;
        goto LAB_0048e5a8;
      }
    }
    if (cloud_mngt_info_switch != '\0') {
      printf("[CLOUD_MNGT_INFO]%s()/%d ap not support to cloud\n","check_ap_can_report_by_statics",
             0x15ed);
    }
  }
  else {
    if ((param_2 & 8) != 0) {
      cVar3 = *(char *)(param_3 + 0x1c5);
      goto LAB_0048e5b8;
    }
    if (cloud_mngt_info_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_INFO]%s()/%d ===ap_stats_entry->ap_simple.state:%d\n";
    uVar4 = 0x15e6;
LAB_0048e5a8:
    printf(__format,"check_ap_can_report_by_statics",uVar4,param_2);
  }
  return 0xffffffff;
}

