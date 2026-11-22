// func FUN_004c8a08 @ 004c8a08 size=1032

void FUN_004c8a08(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *__s;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined2 local_420;
  undefined1 auStack_41c [40];
  char local_3f4;
  undefined1 auStack_3c8 [152];
  char acStack_330 [256];
  undefined1 auStack_230 [300];
  undefined4 local_104;
  char acStack_100 [54];
  undefined4 local_ca;
  
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  local_424 = 0;
  local_420 = 0;
  memset(auStack_230,0,0x205);
  memset(auStack_41c,0,0x54);
  memset(auStack_3c8,0,0x96);
  iVar1 = json_object_new_object();
  iVar2 = json_object_new_array();
  __s = (char *)FUN_00408450(0x8000,0x526);
  if (iVar1 != 0) {
    if ((iVar2 != 0) && (iVar7 = 0, __s != (char *)0x0)) {
      for (; iVar7 < param_2; iVar7 = iVar7 + 1) {
        wips_mac2str(param_1,&local_430);
        uVar6 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 6),*(undefined1 *)(param_1 + 8));
        uVar3 = wserv_db_rd_get_wserv_id(uVar6,*(undefined1 *)(param_1 + 9));
        rdmngr_db_rd_entry_get(uVar6,auStack_41c);
        wserv_db_get_entry_by_id(uVar3,auStack_230);
        iVar4 = json_object_new_object();
        if (iVar4 == 0) {
          if (sensor_err_switch != '\0') {
            printf("[SENSOR_ERROR]%s()/%d malloc json obj failed.\n","wips_bssid_whitelist_send",
                   0x539);
          }
        }
        else {
          uVar6 = json_object_new_string(&local_430);
          json_object_object_add(iVar4,"bssid",uVar6);
          memset(auStack_3c8,0,0x96);
          sVar5 = strlen(acStack_100);
          FUN_00407fc0(acStack_100,sVar5,auStack_3c8,0x96);
          uVar6 = json_object_new_string(auStack_3c8);
          json_object_object_add(iVar4,"ssid",uVar6);
          memset(acStack_330,0,0x100);
          snprintf(acStack_330,0x100,"%d",local_104);
          uVar6 = json_object_new_string(acStack_330);
          json_object_object_add(iVar4,"ssid_code_type",uVar6);
          memset(acStack_330,0,0x100);
          snprintf(acStack_330,0x100,"%d",local_ca);
          uVar6 = json_object_new_string(acStack_330);
          json_object_object_add(iVar4,&DAT_006a6fbc,uVar6);
          memset(acStack_330,0,0x100);
          snprintf(acStack_330,0x100,"%d",(int)local_3f4);
          uVar6 = json_object_new_string(acStack_330);
          json_object_object_add(iVar4,"brd_probe",uVar6);
          memset(acStack_330,0,0x100);
          snprintf(acStack_330,0x100,"%d",1);
          uVar6 = json_object_new_string(acStack_330);
          json_object_object_add(iVar4,"support_scan",uVar6);
          uVar6 = json_tokener_parse("[20011012,20011013]");
          json_object_object_add(iVar4,"support_event_list",uVar6);
          json_object_array_add(iVar2,iVar4);
        }
        param_1 = param_1 + 10;
      }
      json_object_object_add(iVar1,"bssid_list",iVar2);
      uVar6 = json_tokener_parse(&DAT_006a6b30);
      json_object_object_add(iVar1,"ssid_list",uVar6);
      uVar6 = json_object_to_json_string_ext(iVar1,0);
      sprintf(__s,"{\"method\":\"do\",\"sensor_white_list\":{\"%s\":%s}}","set_white_list",uVar6);
      if (sensor_debug_switch != '\0') {
        printf("[SENSOR_DEBUG]%s()/%d wips_bssid_whitelist_send[ap_id=%d]: %s\n",
               "wips_bssid_whitelist_send",0x54e,param_3,__s);
      }
      if (param_3 == 0xffff) {
        sensor_pkt_tdcp_send_all(__s);
      }
      else {
        sensor_pkt_tdcp_send(param_3,__s);
      }
      json_object_put(iVar1);
      goto LAB_004c8d7c;
    }
    json_object_put(iVar1);
  }
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  if (__s == (char *)0x0) {
    return;
  }
LAB_004c8d7c:
  FUN_00407df0(__s);
  return;
}

