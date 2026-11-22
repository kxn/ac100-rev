// func uac_nms_report @ 0049f64c size=540

undefined4
uac_nms_report(uint param_1,char *param_2,undefined4 param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_48;
  undefined *local_44;
  char *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar3 = 0xffffffff;
  local_44 = (undefined *)0x0;
  local_40 = (char *)0x0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_48 = 0;
  uVar5 = FUN_004081f0();
  if (((param_1 < 3) && (param_4 != (code *)0x0)) && (iVar1 = check_nms_report_switch(), iVar1 == 0)
     ) {
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d  report params:#%s#\n","uac_nms_report",0x606,param_2);
    }
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_44 = (&PTR_s__tums_devmsg_v1_reportDevEventMs_0069cc98)[param_1];
    local_2c = param_5;
    local_40 = param_2;
    iVar1 = sendto_business_by_long_link_retran(&local_44,&local_48,0);
    uVar6 = FUN_004081f0();
    uVar4 = (uint)uVar6 - (int)uVar5;
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d  report total cost one time:#%llu #\n","uac_nms_report",
             0x612);
    }
    if ((iVar1 == 0) && (local_48 == 0)) {
      DAT_00767a54 = uVar4 + DAT_00767a54;
      g_test_total_send_cost_time =
           (uint)(DAT_00767a54 < uVar4) +
           (((int)((ulonglong)uVar6 >> 0x20) - (int)((ulonglong)uVar5 >> 0x20)) -
           (uint)((uint)uVar6 < uVar4)) + g_test_total_send_cost_time;
      uVar3 = 0;
      g_test_total_send_cost_ok_count =
           (uint)(DAT_00767a5c + 1 < DAT_00767a5c) + g_test_total_send_cost_ok_count;
      DAT_00767a5c = DAT_00767a5c + 1;
      sVar2 = strlen(param_2);
      DAT_00767a64 = sVar2 + DAT_00767a64;
      g_test_total_send_len = (uint)(DAT_00767a64 < sVar2) + g_test_total_send_len;
      (*param_4)();
    }
    else {
      uVar3 = 0xffffffff;
      g_test_total_send_cost_fail_count =
           (uint)(DAT_00767a4c + 1 < DAT_00767a4c) + g_test_total_send_cost_fail_count;
      DAT_00767a4c = DAT_00767a4c + 1;
    }
  }
  return uVar3;
}

