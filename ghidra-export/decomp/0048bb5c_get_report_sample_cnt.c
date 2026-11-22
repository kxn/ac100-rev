// func get_report_sample_cnt @ 0048bb5c size=640

int get_report_sample_cnt
              (uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
              uint param_7)

{
  uint uVar1;
  int extraout_v1;
  int extraout_v1_00;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = __udivdi3(param_1,param_2,0,1000);
  iVar4 = (int)((ulonglong)uVar5 >> 0x20);
  uVar1 = (uint)uVar5;
  if ((param_3 < param_5) || ((param_5 == param_3 && (param_4 < param_6)))) {
    if (param_1 <= param_5) {
      if (param_1 != param_5) {
        iVar4 = 0;
        goto LAB_0048bc74;
      }
      if (param_2 <= param_6) {
        iVar4 = 0;
        goto LAB_0048bc74;
      }
    }
    uVar5 = __udivdi3(param_5,param_6,0,1000);
    uVar3 = uVar1 + 10000;
    uVar2 = uVar3 - (int)uVar5;
    __udivdi3((((uint)(uVar3 < uVar1) + iVar4) - (int)((ulonglong)uVar5 >> 0x20)) -
              (uint)(uVar3 < uVar2),uVar2,(int)((ulonglong)param_7 * 1000 >> 0x20),
              (int)((ulonglong)param_7 * 1000));
    iVar4 = extraout_v1_00 + 1;
    goto LAB_0048bc74;
  }
  if (param_1 <= param_3) {
    if (param_1 != param_3) {
      iVar4 = 0;
      goto LAB_0048bc74;
    }
    if (param_2 <= param_4) {
      iVar4 = 0;
      goto LAB_0048bc74;
    }
  }
  uVar5 = __udivdi3(param_3,param_4,0,1000);
  uVar3 = uVar1 + 10000;
  uVar2 = uVar3 - (int)uVar5;
  __udivdi3((((uint)(uVar3 < uVar1) + iVar4) - (int)((ulonglong)uVar5 >> 0x20)) -
            (uint)(uVar3 < uVar2),uVar2,(int)((ulonglong)param_7 * 1000 >> 0x20),
            (int)((ulonglong)param_7 * 1000));
  iVar4 = extraout_v1;
LAB_0048bc74:
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d client_stats_begin_report_time:%llu\n","get_report_sample_cnt",
           0x1259);
  }
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d stat_last_time:%llu\n","get_report_sample_cnt",0x125a);
  }
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d sta_stat->cloud_report_last_time:%llu\n",
           "get_report_sample_cnt",0x125b);
  }
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d interval:%llu\n","get_report_sample_cnt",0x125c);
  }
  if (cloud_mngt_info_switch != '\0') {
    printf("[CLOUD_MNGT_INFO]%s()/%d stat_num:%d\n","get_report_sample_cnt",0x125d,iVar4);
  }
  return iVar4;
}

