// func ucl_auth_fill_offline_station @ 004a6e98 size=820

undefined4 ucl_auth_fill_offline_station(byte *param_1,int param_2,code *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  char acStack_48 [32];
  
  memset(acStack_48,0,0x20);
  if (((param_1 == (byte *)0x0) || (param_2 < 1)) || (1000 < param_2)) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar11 = 0x2fd;
    pcVar10 = "[UCL_AUTH_ERR]%s()/%d Para is invalid.\n";
LAB_004a6f68:
    printf(pcVar10,"ucl_auth_fill_offline_station",uVar11);
    return 0xffffffff;
  }
  iVar7 = json_object_new_object();
  if (iVar7 == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    uVar11 = 0x304;
    pcVar10 = "[UCL_AUTH_ERR]%s()/%d Create ucl offline json obj failed.\n";
    goto LAB_004a6f68;
  }
  iVar8 = json_object_new_array();
  if (iVar8 == 0) {
    uVar11 = 0xffffffff;
    if (ucl_err_switch == 0) goto LAB_004a7108;
    uVar12 = 0x30b;
    pcVar10 = "[UCL_AUTH_ERR]%s()/%d Create ucl offline client array json obj failed.\n";
  }
  else {
    iVar13 = 0;
    json_object_object_add(iVar7,"terminalList",iVar8);
    do {
      iVar9 = json_object_new_object();
      if (iVar9 == 0) {
        uVar11 = 0xffffffff;
        if (ucl_err_switch == 0) goto LAB_004a7108;
        uVar12 = 0x316;
        pcVar10 = "[UCL_AUTH_ERR]%s()/%d Create offline station json obj failed.\n";
        goto LAB_004a7168;
      }
      pbVar1 = param_1 + 1;
      bVar6 = *param_1;
      iVar13 = iVar13 + 1;
      pbVar2 = param_1 + 2;
      pbVar3 = param_1 + 3;
      pbVar4 = param_1 + 4;
      pbVar5 = param_1 + 5;
      param_1 = param_1 + 6;
      snprintf(acStack_48,0x20,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)bVar6,(uint)*pbVar1,
               (uint)*pbVar2,(uint)*pbVar3,(uint)*pbVar4,(uint)*pbVar5);
      uVar11 = json_object_new_string(acStack_48);
      json_object_object_add(iVar9,"userMac",uVar11);
      json_object_array_add(iVar8,iVar9);
    } while (iVar13 != param_2);
    uVar11 = json_object_new_string(site_id);
    json_object_object_add(iVar7,"projectId",uVar11);
    uVar11 = json_object_new_string(device_mac);
    json_object_object_add(iVar7,"deviceMac",uVar11);
    iVar8 = json_object_to_json_string_ext(iVar7,0);
    if (iVar8 != 0) {
      uVar11 = (*param_3)(iVar8);
      goto LAB_004a7108;
    }
    uVar11 = 0xffffffff;
    if (ucl_err_switch == 0) goto LAB_004a7108;
    uVar12 = 0x32a;
    pcVar10 = "[UCL_AUTH_ERR]%s()/%d Transfer ucl offline json obj to string failed.\n";
  }
LAB_004a7168:
  uVar11 = 0xffffffff;
  printf(pcVar10,"ucl_auth_fill_offline_station",uVar12);
LAB_004a7108:
  json_object_put(iVar7);
  return uVar11;
}

