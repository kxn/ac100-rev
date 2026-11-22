// func ucl_auth_fill_first_report_station @ 004a5f20 size=1192

undefined4 ucl_auth_fill_first_report_station(int param_1,int param_2,uint param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char acStack_68 [32];
  char acStack_48 [32];
  
  memset(acStack_68,0,0x20);
  if (((param_1 == 0) || (param_2 < 0)) || (1000 < param_2)) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar5 = 0xb3;
    pcVar4 = "[UCL_AUTH_ERR]%s()/%d Para is invalid.\n";
LAB_004a5ff0:
    printf(pcVar4,"ucl_auth_fill_first_report_station",uVar5);
    return 0xffffffff;
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar5 = 0xba;
    pcVar4 = "[UCL_AUTH_ERR]%s()/%d Create first report json obj failed.\n";
    goto LAB_004a5ff0;
  }
  iVar2 = json_object_new_array();
  if (iVar2 == 0) {
    uVar5 = 0xffffffff;
    if (ucl_err_switch == 0) goto LAB_004a61f0;
    uVar6 = 0xc1;
    pcVar4 = "[UCL_AUTH_ERR]%s()/%d Create first report client array json obj failed.\n";
  }
  else {
    json_object_object_add(iVar1,"terminalList",iVar2);
    if (param_3 == 2) {
      pcVar4 = "start";
    }
    else if (param_3 < 3) {
      if (param_3 != 1) {
LAB_004a61e4:
        uVar5 = 0xffffffff;
        if (ucl_err_switch == 0) goto LAB_004a61f0;
        uVar6 = 0xdf;
        pcVar4 = "[UCL_AUTH_ERR]%s()/%d First report schedule message type is invalid.\n";
        goto LAB_004a6258;
      }
      pcVar4 = "all";
    }
    else if (param_3 == 3) {
      pcVar4 = "middle";
    }
    else {
      if (param_3 != 4) goto LAB_004a61e4;
      pcVar4 = "end";
    }
    snprintf(acStack_48,0x20,pcVar4);
    for (iVar7 = 0; iVar7 != param_2; iVar7 = iVar7 + 1) {
      iVar3 = json_object_new_object();
      if (iVar3 == 0) {
        uVar5 = 0xffffffff;
        if (ucl_err_switch == 0) goto LAB_004a61f0;
        uVar6 = 0xe9;
        pcVar4 = "[UCL_AUTH_ERR]%s()/%d Create first report client json obj failed.\n";
        goto LAB_004a6258;
      }
      snprintf(acStack_68,0x20,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 100),
               (uint)*(byte *)(param_1 + 0x65),(uint)*(byte *)(param_1 + 0x66),
               (uint)*(byte *)(param_1 + 0x67),(uint)*(byte *)(param_1 + 0x68),
               (uint)*(byte *)(param_1 + 0x69));
      uVar5 = json_object_new_string(param_1);
      json_object_object_add(iVar3,"userName",uVar5);
      uVar5 = json_object_new_string(acStack_68);
      json_object_object_add(iVar3,"userMac",uVar5);
      uVar5 = json_object_new_string(param_1 + 0x92);
      json_object_object_add(iVar3,"ssid",uVar5);
      if (*(char *)(param_1 + 0x6a) != '\0') {
        uVar5 = json_object_new_string(param_1 + 0x6a);
        json_object_object_add(iVar3,"userIp",uVar5);
      }
      json_object_array_add(iVar2,iVar3);
      param_1 = param_1 + 0xc4;
    }
    uVar5 = json_object_new_string(site_id);
    json_object_object_add(iVar1,"projectId",uVar5);
    uVar5 = json_object_new_string(device_mac);
    json_object_object_add(iVar1,"deviceMac",uVar5);
    uVar5 = json_object_new_string(acStack_48);
    json_object_object_add(iVar1,"schedule",uVar5);
    iVar2 = json_object_to_json_string_ext(iVar1,0);
    if (iVar2 != 0) {
      uVar5 = (*param_4)(iVar2);
      goto LAB_004a61f0;
    }
    uVar5 = 0xffffffff;
    if (ucl_err_switch == 0) goto LAB_004a61f0;
    uVar6 = 0x105;
    pcVar4 = "[UCL_AUTH_ERR]%s()/%d Transfer ucl first report json obj to string failed.\n";
  }
LAB_004a6258:
  uVar5 = 0xffffffff;
  printf(pcVar4,"ucl_auth_fill_first_report_station",uVar6);
LAB_004a61f0:
  json_object_put(iVar1);
  return uVar5;
}

