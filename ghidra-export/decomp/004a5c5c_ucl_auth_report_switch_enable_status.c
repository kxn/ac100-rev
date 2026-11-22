// func ucl_auth_report_switch_enable_status @ 004a5c5c size=676

undefined4 ucl_auth_report_switch_enable_status(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_30;
  char *local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_2c = (char *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_30 = 0;
  iVar2 = json_object_new_object();
  if (iVar2 == 0) {
    if (ucl_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[UCL_AUTH_ERR]%s()/%d Create ucl switch enable json obj failed.\n",
           "ucl_auth_report_switch_enable_status",0x41);
    return 0xffffffff;
  }
  uVar3 = json_object_new_string(site_id);
  json_object_object_add(iVar2,"projectId",uVar3);
  uVar3 = json_object_new_string(device_mac);
  json_object_object_add(iVar2,"deviceMac",uVar3);
  iVar4 = ucl_auth_db_get_switch_status();
  if (iVar4 == 1) {
    pcVar1 = "Led on";
  }
  else {
    pcVar1 = "Led off";
  }
  uVar3 = json_object_new_string(pcVar1 + 4);
  json_object_object_add(iVar2,"uclAuthEnable",uVar3);
  iVar4 = json_object_to_json_string_ext(iVar2,0);
  if (iVar4 == 0) {
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Transfer ucl switch json obj to string failed.\n",
             "ucl_auth_report_switch_enable_status",0x4c);
    }
    json_object_put(iVar2);
    return 0xffffffff;
  }
  if (ucl_info_switch != 0) {
    printf("[UCL_AUTH_INFO]%s()/%d %s\n","ucl_auth_report_switch_enable_status",0x52,iVar4);
  }
  local_1c = 0;
  local_2c = "/tums/ucl/v1/uclAuthConfig";
  local_24 = 0;
  local_20 = 0;
  local_28 = iVar4;
  iVar4 = sendto_business_by_short_link(&local_2c,&local_30);
  if (iVar4 == 0) {
    uVar3 = 0;
    if (local_30 == 0) goto LAB_004a5e0c;
    if (ucl_err_switch != 0) {
      printf("[UCL_AUTH_ERR]%s()/%d Error code is %d.\n","ucl_auth_report_switch_enable_status",0x5e
            );
    }
  }
  if (ucl_warn_switch != 0) {
    printf("[UCL_AUTH_WARN]%s()/%d Report ucl auth switch to NMS failed.\n",
           "ucl_auth_report_switch_enable_status",0x6d);
  }
  uVar3 = 0xffffffff;
LAB_004a5e0c:
  json_object_put(iVar2);
  return uVar3;
}

