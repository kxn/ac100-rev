// func wips_ssid_whitelist_add_send @ 004c65f8 size=760

void wips_ssid_whitelist_add_send(char *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 auStack_1c8 [152];
  char acStack_130 [256];
  undefined4 local_30;
  
  memset(auStack_1c8,0,0x96);
  iVar1 = json_object_new_object();
  iVar2 = json_object_new_array();
  __s = (char *)FUN_00408450(0x8000,0x4d0);
  if (iVar1 != 0) {
    if ((iVar2 != 0) && (__s != (char *)0x0)) {
      for (iVar6 = 0; iVar6 < param_3; iVar6 = iVar6 + 1) {
        local_30 = *param_2;
        iVar3 = json_object_new_object();
        if (iVar3 == 0) {
          if (sensor_err_switch != '\0') {
            printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_ssid_whitelist_add_send",
                   0x4dd);
          }
        }
        else {
          memset(auStack_1c8,0,0x96);
          sVar4 = strlen(param_1);
          FUN_00407fc0(param_1,sVar4,auStack_1c8,0x96);
          uVar5 = json_object_new_string(auStack_1c8);
          json_object_object_add(iVar3,"ssid",uVar5);
          memset(acStack_130,0,0x100);
          snprintf(acStack_130,0x100,"%d",local_30);
          uVar5 = json_object_new_string(acStack_130);
          json_object_object_add(iVar3,"ssid_code_type",uVar5);
          memset(acStack_130,0,0x100);
          snprintf(acStack_130,0x100,"%d",1);
          uVar5 = json_object_new_string(acStack_130);
          json_object_object_add(iVar3,"support_scan",uVar5);
          uVar5 = json_tokener_parse("[20011012,20011013]");
          json_object_object_add(iVar3,"support_event_list",uVar5);
          json_object_array_add(iVar2,iVar3);
        }
        param_1 = param_1 + 0x32;
        param_2 = param_2 + 1;
      }
      uVar5 = json_tokener_parse(&DAT_006a6b30);
      json_object_object_add(iVar1,"bssid_list",uVar5);
      json_object_object_add(iVar1,"ssid_list",iVar2);
      uVar5 = json_object_to_json_string_ext(iVar1,0);
      sprintf(__s,"{\"method\":\"do\",\"sensor_white_list\":{\"add_white_list\":%s}}",uVar5);
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d wips_ssid_whitelist_add_send[ap_id=%d]: %s\n",
               "wips_ssid_whitelist_add_send",0x4ef,param_4,__s);
      }
      if (param_4 == 0xffff) {
        sensor_pkt_tdcp_send_all(__s);
      }
      else {
        sensor_pkt_tdcp_send(param_4,__s);
      }
      json_object_put(iVar1);
      goto LAB_004c685c;
    }
    json_object_put(iVar1);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (__s == (char *)0x0) {
    return;
  }
LAB_004c685c:
  FUN_00407df0(__s);
  return;
}

