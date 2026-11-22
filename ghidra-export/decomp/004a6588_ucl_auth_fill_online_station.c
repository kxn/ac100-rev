// func ucl_auth_fill_online_station @ 004a6588 size=928

undefined4
ucl_auth_fill_online_station
          (int param_1,int param_2,code *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char acStack_48 [32];
  
  memset(acStack_48,0,0x20);
  if (((param_1 == 0) || (param_2 < 1)) || (0x32 < param_2)) {
    if (ucl_err_switch != 0) {
      uVar5 = 0x1a9;
      pcVar4 = "[UCL_AUTH_ERR]%s()/%d Para is invalid.\n";
      goto LAB_004a6658;
    }
  }
  else {
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      iVar6 = 0;
      uVar5 = json_object_new_array();
      json_object_object_add(iVar1,"terminalList",uVar5);
      do {
        iVar2 = json_object_new_object();
        if (iVar2 == 0) {
          uVar5 = 0xffffffff;
          if (ucl_err_switch == 0) goto LAB_004a68b4;
          uVar3 = 0x1c1;
          pcVar4 = "[UCL_AUTH_ERR]%s()/%d Create online client json obj failed.\n";
          goto LAB_004a68ec;
        }
        snprintf(acStack_48,0x20,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 100),
                 (uint)*(byte *)(param_1 + 0x65),(uint)*(byte *)(param_1 + 0x66),
                 (uint)*(byte *)(param_1 + 0x67),(uint)*(byte *)(param_1 + 0x68),
                 (uint)*(byte *)(param_1 + 0x69));
        uVar3 = json_object_new_string(param_1);
        json_object_object_add(iVar2,"userName",uVar3);
        uVar3 = json_object_new_string(acStack_48);
        json_object_object_add(iVar2,"userMac",uVar3);
        uVar3 = json_object_new_string(param_1 + 0x92);
        json_object_object_add(iVar2,"ssid",uVar3);
        if (*(char *)(param_1 + 0x6a) != '\0') {
          uVar3 = json_object_new_string(param_1 + 0x6a);
          json_object_object_add(iVar2,"userIp",uVar3);
        }
        iVar6 = iVar6 + 1;
        json_object_array_add(uVar5,iVar2);
        param_1 = param_1 + 0xc4;
      } while (iVar6 != param_2);
      uVar5 = json_object_new_string(site_id);
      json_object_object_add(iVar1,"projectId",uVar5);
      uVar5 = json_object_new_string(device_mac);
      json_object_object_add(iVar1,"deviceMac",uVar5);
      iVar6 = json_object_to_json_string_ext(iVar1,0);
      if (iVar6 == 0) {
        uVar5 = 0xffffffff;
        if (ucl_err_switch != 0) {
          uVar3 = 0x1dc;
          pcVar4 = "[UCL_AUTH_ERR]%s()/%d Transfer ucl online json obj to string failed.\n";
LAB_004a68ec:
          uVar5 = 0xffffffff;
          printf(pcVar4,"ucl_auth_fill_online_station",uVar3);
        }
      }
      else {
        uVar5 = (*param_3)(iVar6,param_4,param_5);
      }
LAB_004a68b4:
      json_object_put(iVar1);
      return uVar5;
    }
    if (ucl_err_switch != 0) {
      uVar5 = 0x1b0;
      pcVar4 = "[UCL_AUTH_ERR]%s()/%d Create ucl online json obj failed.\n";
LAB_004a6658:
      printf(pcVar4,"ucl_auth_fill_online_station",uVar5);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

