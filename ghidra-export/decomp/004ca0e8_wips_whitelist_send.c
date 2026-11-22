// func wips_whitelist_send @ 004ca0e8 size=956

void wips_whitelist_send(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__dest;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  size_t sVar9;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined2 local_1c8;
  undefined1 auStack_1c4 [152];
  char acStack_12c [260];
  
  local_1d8 = 0;
  local_1d4 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  memset(auStack_1c4,0,0x96);
  iVar1 = json_object_new_object();
  iVar2 = json_object_new_array();
  iVar3 = json_object_new_array();
  __dest = (char *)FUN_00408450(0x8000,0x599);
  if (iVar1 != 0) {
    if (((iVar2 != 0) && (iVar3 != 0)) && (__dest != (char *)0x0)) {
      FUN_004082d0(wips_global_mutex,0xffffffff);
      for (iVar4 = FUN_004081b0(&g_white_list); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
        if ((param_1 == -1) || (*(int *)(iVar4 + 0xc) == param_1)) {
          iVar7 = json_object_new_object();
          if (iVar7 == 0) {
            if (sensor_err_switch != '\0') {
              printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_whitelist_send",0x5a7);
            }
          }
          else {
            iVar8 = memcmp((void *)(iVar4 + 0x10),&DAT_006a81e4,6);
            if (iVar8 == 0) {
              memset(auStack_1c4,0,0x96);
              sVar9 = strlen((char *)(iVar4 + 0x16));
              FUN_00407fc0((char *)(iVar4 + 0x16),sVar9,auStack_1c4,0x96);
              uVar5 = json_object_new_string(auStack_1c4);
              json_object_object_add(iVar7,"ssid",uVar5);
              memset(acStack_12c,0,0x100);
              snprintf(acStack_12c,0x100,"%d",*(undefined4 *)(iVar4 + 0x48));
              uVar5 = json_object_new_string(acStack_12c);
              json_object_object_add(iVar7,"ssid_code_type",uVar5);
              uVar5 = json_tokener_parse("[20011012,20011013]");
              json_object_object_add(iVar7,"support_event_list",uVar5);
              iVar8 = iVar3;
            }
            else {
              wips_mac2str((void *)(iVar4 + 0x10),&local_1d8);
              uVar5 = json_object_new_string(&local_1d8);
              json_object_object_add(iVar7,"bssid",uVar5);
              uVar5 = json_tokener_parse("[20011012,20011013]");
              json_object_object_add(iVar7,"support_event_list",uVar5);
              iVar8 = iVar2;
            }
            json_object_array_add(iVar8,iVar7);
          }
        }
      }
      FUN_00407f30(wips_global_mutex);
      json_object_object_add(iVar1,"bssid_list",iVar2);
      json_object_object_add(iVar1,"ssid_list",iVar3);
      if (param_3 == 3) {
        strcpy(__dest,"{\"method\":\"do\",\"sensor_white_list\": {\"reset_white_list\":null}}");
      }
      else {
        uVar5 = wips_whitelist_send_method2str(param_3);
        uVar6 = json_object_to_json_string_ext(iVar1,0);
        sprintf(__dest,"{\"method\":\"do\",\"sensor_white_list\":{\"%s\":%s}}",uVar5,uVar6);
      }
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d wips_whitelist_send[ap_id=%d]: %s\n","wips_whitelist_send",
               0x5cc,param_2,__dest);
      }
      if (param_2 == 0xffff) {
        sensor_pkt_tdcp_send_all(__dest);
      }
      else {
        sensor_pkt_tdcp_send(param_2,__dest);
      }
      json_object_put(iVar1);
      goto LAB_004ca288;
    }
    json_object_put(iVar1);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (iVar3 != 0) {
    json_object_put(iVar3);
  }
  if (__dest == (char *)0x0) {
    return;
  }
LAB_004ca288:
  FUN_00407df0(__dest);
  return;
}

