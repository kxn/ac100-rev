// func uac_nms_fit_ap_info_report_handle @ 0049f868 size=1088

undefined4
uac_nms_fit_ap_info_report_handle
          (code *param_1,code *param_2,code *param_3,code *param_4,int param_5,char *param_6,
          undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  char *__s;
  char *__s_00;
  size_t sVar3;
  size_t __n;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  size_t local_30 [2];
  
  lVar10 = CONCAT44(g_test_total_handle_cost_time,DAT_00767a34);
  local_30[0] = 0x40000;
  if ((((param_1 == (code *)0x0) || (param_2 == (code *)0x0)) || (param_3 == (code *)0x0)) ||
     ((param_5 == 0 || (param_6 == (char *)0x0)))) {
    uVar6 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d cb func invalid.\n\n","uac_nms_fit_ap_info_report_handle",
             0x58b);
      lVar10 = CONCAT44(g_test_total_handle_cost_time,DAT_00767a34);
    }
  }
  else {
    uVar6 = 0;
    iVar1 = check_nms_report_switch();
    lVar10 = CONCAT44(g_test_total_handle_cost_time,DAT_00767a34);
    if (iVar1 == 0) {
      uVar9 = FUN_004081f0();
      iVar1 = (int)((ulonglong)uVar9 >> 0x20);
      iVar2 = json_object_new_object();
      if (iVar2 == 0) {
        __s = (char *)0x0;
        if (cloud_mngt_err_switch != '\0') {
          printf("[CLOUD_MNGT_ERROR]%s()/%d malloc obj failed.\n\n",
                 "uac_nms_fit_ap_info_report_handle",0x597);
          __s = (char *)0x0;
        }
      }
      else {
        (*param_1)(iVar2);
        __s = (char *)FUN_00408450(local_30[0],0x59d);
        if (__s == (char *)0x0) {
          if (cloud_mngt_err_switch != '\0') {
            printf("[CLOUD_MNGT_ERROR]%s()/%d malloc buf failed.\n\n",
                   "uac_nms_fit_ap_info_report_handle",0x5a0);
          }
        }
        else {
          memset(__s,0,local_30[0]);
          local_30[0] = local_30[0] - 3;
          __s_00 = (char *)json_object_to_json_string_ext(iVar2,0);
          sVar3 = strlen(__s_00);
          sVar3 = sVar3 - 1;
          memcpy(__s,__s_00,sVar3);
          local_30[0] = local_30[0] - sVar3;
          __n = strlen(param_6);
          memcpy(__s + sVar3,param_6,__n);
          sVar7 = local_30[0] - __n;
          local_30[0] = sVar7;
          sVar4 = strlen(__s);
          iVar5 = (*param_2)(__s + sVar4,local_30);
          if ((iVar5 == 0) && (sVar7 != local_30[0])) {
            __s[sVar3 + __n + (sVar7 - local_30[0])] = ']';
            (__s + sVar3 + __n + (sVar7 - local_30[0]))[1] = '}';
            local_30[0] = local_30[0] - 2;
            if (cloud_mngt_debug_switch != '\0') {
              printf("[CLOUD_MNGT_DEBUG]%s()/%d send buf:%s\r\n\n",
                     "uac_nms_fit_ap_info_report_handle",0x5c2,__s);
            }
            iVar5 = (*param_3)(param_7,__s,0,param_5,param_8);
            if (iVar5 == 0) {
              g_test_total_handle_cost_ok_count =
                   (uint)(DAT_00767a24 + 1 < DAT_00767a24) + g_test_total_handle_cost_ok_count;
              DAT_00767a24 = DAT_00767a24 + 1;
              sVar3 = strlen(__s);
              DAT_00767a44 = sVar3 + DAT_00767a44;
              g_test_total_handle_len = (uint)(DAT_00767a44 < sVar3) + g_test_total_handle_len;
              lVar10 = FUN_004081f0();
              uVar8 = DAT_00767a3c - (int)uVar9;
              lVar10 = lVar10 + CONCAT44((g_test_total_handle_ok_cost_time - iVar1) -
                                         (uint)(DAT_00767a3c < uVar8),uVar8);
            }
            else {
              if (cloud_mngt_err_switch != '\0') {
                printf("[CLOUD_MNGT_ERROR]%s()/%d uac_nms_report failed .\n\n",
                       "uac_nms_fit_ap_info_report_handle",0x5c6);
              }
              lVar10 = CONCAT44(g_test_total_handle_ok_cost_time,DAT_00767a3c);
              g_test_total_handle_cost_fail_count =
                   (uint)(DAT_00767a2c + 1 < DAT_00767a2c) + g_test_total_handle_cost_fail_count;
              DAT_00767a2c = DAT_00767a2c + 1;
            }
            g_test_total_handle_ok_cost_time = (int)((ulonglong)lVar10 >> 0x20);
            DAT_00767a3c = (uint)lVar10;
            json_object_put(iVar2);
            FUN_00407df0(__s);
            uVar6 = 0;
            lVar10 = FUN_004081f0();
            uVar8 = DAT_00767a34 - (int)uVar9;
            lVar10 = lVar10 + CONCAT44((g_test_total_handle_cost_time - iVar1) -
                                       (uint)(DAT_00767a34 < uVar8),uVar8);
            goto LAB_0049f8e8;
          }
          if (cloud_mngt_info_switch != '\0') {
            printf("[CLOUD_MNGT_INFO]%s()/%d malloc buf failed origin_size:%d report_size:%d.\n\n",
                   "uac_nms_fit_ap_info_report_handle",0x5b9,sVar7,local_30[0]);
          }
        }
      }
      if (param_4 != (code *)0x0) {
        (*param_4)(0,0);
      }
      if (iVar2 != 0) {
        json_object_put(iVar2);
      }
      lVar10 = CONCAT44(g_test_total_handle_cost_time,DAT_00767a34);
      uVar6 = 0xffffffff;
      if (__s != (char *)0x0) {
        FUN_00407df0(__s);
        lVar10 = CONCAT44(g_test_total_handle_cost_time,DAT_00767a34);
      }
    }
  }
LAB_0049f8e8:
  g_test_total_handle_cost_time = (int)((ulonglong)lVar10 >> 0x20);
  DAT_00767a34 = (uint)lVar10;
  return uVar6;
}

