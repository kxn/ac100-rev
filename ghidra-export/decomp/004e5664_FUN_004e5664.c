// func FUN_004e5664 @ 004e5664 size=1148

char * FUN_004e5664(undefined4 param_1,int param_2,undefined4 param_3,int param_4,char *param_5,
                   undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *__s;
  size_t sVar7;
  char *__dest;
  undefined1 auStack_1c0 [152];
  char acStack_128 [256];
  
  memset(auStack_1c0,0,0x96);
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_object();
  uVar3 = json_object_new_object();
  uVar4 = json_object_new_string(&DAT_00697f28);
  json_object_object_add(iVar1,"method",uVar4);
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",param_1);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"operation_id",uVar4);
  uVar4 = json_object_new_string("neighbour_scan");
  json_object_object_add(uVar3,"function",uVar4);
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",1);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"radio_id",uVar4);
  memset(acStack_128,0,0x100);
  uVar4 = 1;
  if (param_2 != 0) {
    uVar4 = 2;
  }
  snprintf(acStack_128,0x100,"%d",uVar4);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"report_type",uVar4);
  if (param_2 != 0) {
    memset(acStack_128,0,0x100);
    snprintf(acStack_128,0x100,"%d",param_3);
    uVar4 = json_object_new_string(acStack_128);
    json_object_object_add(uVar3,"report_period_time",uVar4);
  }
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",1000);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"scan_time",uVar4);
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",0xffffffab);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"rssi_threshold",uVar4);
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",1);
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"white_list_unicast",uVar4);
  memset(acStack_128,0,0x100);
  snprintf(acStack_128,0x100,"%d",(uint)(param_4 != 0));
  uVar4 = json_object_new_string(acStack_128);
  json_object_object_add(uVar3,"white_list_report",uVar4);
  uVar4 = json_object_new_string("on");
  json_object_object_add(uVar3,"enable",uVar4);
  if (param_5 != (char *)0x0) {
    uVar4 = json_object_new_array();
    uVar5 = json_object_new_object();
    sVar7 = strlen(param_5);
    FUN_00407fc0(param_5,sVar7,auStack_1c0,0x96);
    uVar6 = json_object_new_string(param_5);
    json_object_object_add(uVar5,"ssid",uVar6);
    memset(acStack_128,0,0x100);
    snprintf(acStack_128,0x100,"%d",param_6);
    uVar6 = json_object_new_string(acStack_128);
    json_object_object_add(uVar5,"ssid_code_type",uVar6);
    json_object_array_add(uVar4,uVar5);
    json_object_object_add(uVar3,"scan_ssid_list",uVar4);
  }
  json_object_object_add(uVar2,"neighbour_scan",uVar3);
  json_object_object_add(iVar1,"test_manager",uVar2);
  __s = (char *)json_object_to_json_string_ext(iVar1,0);
  sVar7 = strlen(__s);
  __dest = (char *)FUN_00408450(sVar7 + 1,0x33b);
  if (__dest == (char *)0x0) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_neighbor_scan_do_json_create",0x33e);
    }
    if (iVar1 == 0) {
      return (char *)0x0;
    }
  }
  else {
    strcpy(__dest,__s);
  }
  json_object_put(iVar1);
  return __dest;
}

