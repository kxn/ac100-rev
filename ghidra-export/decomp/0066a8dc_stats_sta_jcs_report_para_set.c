// func stats_sta_jcs_report_para_set @ 0066a8dc size=1516

void stats_sta_jcs_report_para_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  iVar1 = json_object_object_get(param_1,"clientStats");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"report_time");
    if (iVar2 == 0) {
LAB_0066a94c:
      uVar5 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x683);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_0066a94c;
        uVar6 = json_object_get_double(iVar2);
        uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    iVar1 = json_object_object_get(iVar1,"sample_time");
    if (iVar1 == 0) {
LAB_0066a99c:
      uVar4 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x686);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0066a99c;
        uVar6 = json_object_get_double(iVar1);
        uVar4 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    set_stats_sample_time(uVar4,0);
    set_stats_sample_report_time(uVar5,0);
  }
  iVar1 = json_object_object_get(param_1,"radioStats");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"report_time");
    if (iVar2 == 0) {
LAB_0066aa1c:
      uVar5 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x690);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_0066aa1c;
        uVar6 = json_object_get_double(iVar2);
        uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    iVar1 = json_object_object_get(iVar1,"sample_time");
    if (iVar1 == 0) {
LAB_0066aa6c:
      uVar4 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x693);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0066aa6c;
        uVar6 = json_object_get_double(iVar1);
        uVar4 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    set_stats_sample_time(uVar4,2);
    set_stats_sample_report_time(uVar5,2);
  }
  iVar1 = json_object_object_get(param_1,"vapStats");
  if (iVar1 != 0) {
    iVar2 = json_object_object_get(iVar1,"report_time");
    if (iVar2 == 0) {
LAB_0066aaec:
      uVar5 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x69d);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar5 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_0066aaec;
        uVar6 = json_object_get_double(iVar2);
        uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    iVar1 = json_object_object_get(iVar1,"sample_time");
    if (iVar1 == 0) {
LAB_0066ab3c:
      uVar4 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "stats_sta_jcs_report_para_set",0x6a0);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar4 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 != 2) goto LAB_0066ab3c;
        uVar6 = json_object_get_double(iVar1);
        uVar4 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
    }
    set_stats_sample_time(uVar4,3);
    set_stats_sample_report_time(uVar5,3);
  }
  iVar1 = json_object_object_get(param_1,"devStats");
  if (iVar1 == 0) {
    return;
  }
  iVar2 = json_object_object_get(iVar1,"report_time");
  if (iVar2 == 0) {
LAB_0066abbc:
    uVar5 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "stats_sta_jcs_report_para_set",0x6aa);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar5 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_0066abbc;
      uVar6 = json_object_get_double(iVar2);
      uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
  }
  iVar1 = json_object_object_get(iVar1,"sample_time");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar4 = json_object_get_int(iVar1);
      goto LAB_0066ac20;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar6 = json_object_get_double(iVar1);
      uVar4 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      goto LAB_0066ac20;
    }
  }
  uVar4 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "stats_sta_jcs_report_para_set",0x6ad);
  }
LAB_0066ac20:
  set_stats_sample_time(uVar4,1);
  set_stats_sample_report_time(uVar5,1);
  return;
}

