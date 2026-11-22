// func FUN_00498f20 @ 00498f20 size=1964

undefined4 FUN_00498f20(int param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *__s;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int extraout_v1;
  char *pcVar11;
  int iVar12;
  undefined8 uVar13;
  int local_5e8;
  char local_5e4 [12];
  char acStack_5d8 [32];
  undefined1 auStack_5b8 [128];
  undefined1 auStack_538 [256];
  char acStack_438 [1023];
  undefined1 local_39;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_5e8 = 0;
  memset(auStack_5b8,0,0x80);
  memset(acStack_5d8,0,0x20);
  memset(auStack_538,0,0x100);
  FUN_00407e70();
  memset(acStack_438,0,0x400);
  local_5e4[0] = '\0';
  local_5e4[1] = '\0';
  local_5e4[2] = '\0';
  local_5e4[3] = '\0';
  local_5e4[4] = '\0';
  local_5e4[5] = '\0';
  local_5e4[6] = '\0';
  local_5e4[7] = '\0';
  local_5e4[8] = '\0';
  local_5e4[9] = '\0';
  iVar1 = json_object_new_object();
  iVar2 = json_object_new_object();
  iVar3 = json_object_new_object();
  iVar4 = json_object_new_object();
  uVar5 = json_object_new_string(&DAT_00697f28);
  json_object_object_add(iVar1,"method",uVar5);
  uVar5 = json_object_new_string(site_id);
  json_object_object_add(iVar4,"project_id",uVar5);
  uVar5 = json_object_new_string("public");
  json_object_object_add(iVar4,"cloud_type",uVar5);
  if (param_1 == 0) {
    __s = (int *)0x0;
    iVar6 = 0;
    uVar5 = json_object_new_string("offline");
LAB_00499054:
    json_object_object_add(iVar3,"type",uVar5);
    json_object_object_add(iVar3,"para",iVar4);
    json_object_object_add(iVar2,"notify_sub_device",iVar3);
    json_object_object_add(iVar1,"cloud_status",iVar2);
    uVar5 = json_object_to_json_string_ext(iVar1,0);
    if (cloud_mngt_debug_switch != '\0') {
      printf("[CLOUD_MNGT_DEBUG]%s()/%d get send tdcp_msg:%s\n",
             "cloud_mngt_notify_device_on_offline",0x1cc2,uVar5);
    }
    if (param_3 == 0) {
      iVar2 = tdcp_send_request_to_ap_by_id(0,"notify_sub_device",uVar5,5,param_2);
      uVar5 = 0;
      if ((iVar2 == 0) || (uVar5 = 0xffffffff, cloud_mngt_err_switch == '\0')) goto LAB_00499114;
      uVar9 = 0x1cd2;
    }
    else {
      iVar2 = tdcp_send_request_to_ap_all(0,"notify_sub_device",uVar5,5);
      uVar5 = 0;
      if ((iVar2 == 0) || (uVar5 = 0xffffffff, cloud_mngt_err_switch == '\0')) goto LAB_00499114;
      uVar9 = 0x1cc9;
    }
    uVar5 = 0xffffffff;
    printf("[CLOUD_MNGT_ERROR]%s()/%d send online or offline to ap all failed!\n",
           "cloud_mngt_notify_device_on_offline",uVar9);
    goto LAB_00499114;
  }
  __s = (int *)FUN_00408450(0x4808,0x1c5c);
  if (__s == (int *)0x0) {
    if (cloud_mngt_err_switch == '\0') goto LAB_0049920c;
    pcVar11 = "[CLOUD_MNGT_ERROR]%s()/%d malloc failed!!!\n\n";
    uVar5 = 0x1c5e;
LAB_004993dc:
    iVar12 = 0;
    printf(pcVar11,"cloud_mngt_notify_device_on_offline",uVar5);
    iVar6 = 0;
  }
  else {
    memset(__s,0,0x4808);
    iVar6 = get_new_token_str_info(0,__s);
    if ((iVar6 == 0) && (iVar6 = jsonParseStr(__s + 1), iVar6 != 0)) {
      iVar12 = json_object_object_get(iVar6,"deviceToken");
      if ((iVar12 == 0) || (iVar7 = json_object_get_type(iVar12), iVar7 != 6)) {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "cloud_mngt_notify_device_on_offline",0x1c6f);
        }
        pcVar11 = "";
      }
      else {
        pcVar11 = (char *)json_object_get_string(iVar12);
      }
      strncpy(acStack_438,pcVar11,0x3ff);
      local_39 = 0;
      iVar12 = json_object_object_get(iVar6,"expiresIn");
      iVar7 = *__s;
      if (iVar12 == 0) {
LAB_00499320:
        iVar12 = -1;
        if (jcs_err_switch == 0) {
LAB_00499330:
          iVar7 = iVar7 - extraout_v1;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "cloud_mngt_notify_device_on_offline",0x1c76);
          iVar7 = iVar7 - extraout_v1;
        }
      }
      else {
        iVar8 = json_object_get_type(iVar12);
        if (iVar8 != 3) {
          iVar8 = json_object_get_type();
          if (iVar8 != 2) goto LAB_00499320;
          uVar13 = json_object_get_double(iVar12);
          iVar12 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
          goto LAB_00499330;
        }
        iVar7 = iVar7 - extraout_v1;
        iVar12 = json_object_get_int(iVar12);
      }
      snprintf(local_5e4,10,"%d",iVar12 + iVar7);
      if (cloud_mngt_debug_switch != '\0') {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d token:%s,expiresIn:%d\n",
               "cloud_mngt_notify_device_on_offline",0x1c7b,acStack_438,iVar12 + iVar7);
      }
      iVar12 = sec_get_serviceids_cnt(&local_5e8);
      if (iVar12 == 0) {
        if (cloud_mngt_debug_switch != '\0') {
          printf("[CLOUD_MNGT_DEBUG]%s()/%d get service id cnt:%d\n",
                 "cloud_mngt_notify_device_on_offline",0x1c85,local_5e8);
        }
        iVar12 = json_object_new_array();
        iVar7 = 0;
        while (iVar7 < local_5e8) {
          local_38 = iVar7 + 1;
          snprintf(acStack_5d8,0x20,"report_info_%d",local_38);
          memset(auStack_5b8,0,0x80);
          iVar7 = sec_get_serviceids(auStack_5b8,0x80,iVar7);
          if (iVar7 != 0) {
            if (cloud_mngt_err_switch == '\0') goto LAB_00499210;
            pcVar11 = "[CLOUD_MNGT_ERROR]%s()/%d get service_id failed\n";
            uVar5 = 0x1c90;
            goto LAB_00499394;
          }
          if (cloud_mngt_debug_switch != '\0') {
            printf("[CLOUD_MNGT_DEBUG]%s()/%d get service id:%s\n",
                   "cloud_mngt_notify_device_on_offline",0x1c95,auStack_5b8);
          }
          memset(auStack_538,0,0x100);
          iVar7 = sec_get_urls_by_serviceid(0,auStack_5b8,auStack_538,0x100);
          if (iVar7 != 0) {
            if (cloud_mngt_err_switch == '\0') goto LAB_00499210;
            pcVar11 = "[CLOUD_MNGT_ERROR]%s()/%d get urls failed\n";
            uVar5 = 0x1c9a;
            goto LAB_00499394;
          }
          uVar5 = json_object_new_object();
          uVar9 = json_object_new_array();
          local_34 = json_object_new_object();
          local_30 = json_object_new_array();
          uVar10 = json_object_new_string(auStack_5b8);
          json_object_object_add(uVar5,"service_id",uVar10);
          uVar10 = json_object_new_string(acStack_438);
          json_object_object_add(uVar5,"token",uVar10);
          uVar10 = json_object_new_string(local_5e4);
          json_object_object_add(uVar5,"expires",uVar10);
          uVar10 = json_object_new_string(auStack_538);
          json_object_array_add(uVar9,uVar10);
          json_object_object_add(uVar5,&DAT_00677ca8,uVar9);
          uVar9 = json_object_new_string("0");
          json_object_array_add(local_30,uVar9);
          json_object_object_add(uVar5,"ac_port",local_30);
          json_object_object_add(local_34,acStack_5d8,uVar5);
          json_object_array_add(iVar12,local_34);
          iVar7 = local_38;
        }
        json_object_object_add(iVar4,"report_info",iVar12);
        uVar5 = json_object_new_string("online");
        goto LAB_00499054;
      }
      iVar12 = 0;
      if (cloud_mngt_err_switch != '\0') {
        pcVar11 = "[CLOUD_MNGT_ERROR]%s()/%d get service id cnt failed\n";
        uVar5 = 0x1c80;
LAB_00499394:
        printf(pcVar11,"cloud_mngt_notify_device_on_offline",uVar5);
      }
    }
    else {
      if (cloud_mngt_err_switch != '\0') {
        pcVar11 = "[CLOUD_MNGT_ERROR]%s()/%d get_new_token_str_info failed!!!\n\n";
        uVar5 = 0x1c68;
        goto LAB_004993dc;
      }
LAB_0049920c:
      iVar12 = 0;
      iVar6 = 0;
    }
  }
LAB_00499210:
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (iVar12 != 0) {
    json_object_put(iVar12);
  }
  uVar5 = 0xffffffff;
  if (iVar4 != 0) {
    json_object_put(iVar4);
  }
LAB_00499114:
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  if (__s != (int *)0x0) {
    FUN_00407df0(__s);
  }
  if (iVar6 != 0) {
    json_object_put(iVar6);
  }
  return uVar5;
}

