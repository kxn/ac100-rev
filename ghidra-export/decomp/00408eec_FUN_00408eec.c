// func FUN_00408eec @ 00408eec size=1560

char * FUN_00408eec(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined4 uVar6;
  char *__s;
  char *__dest;
  int iVar7;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined1 auStack_1cc [152];
  char acStack_134 [260];
  undefined4 local_30;
  
  local_1e0 = 0;
  local_1dc = 0;
  local_1d8 = 0;
  local_1d4 = 0;
  local_1d0 = 0;
  memset(auStack_1cc,0,0x96);
  if (((param_2 == 0) && (0 < param_3)) || (param_4 == 0)) {
    __dest = (char *)0x0;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_backhaul_test_json_create",0x2ac);
    }
  }
  else {
    iVar1 = json_object_new_object();
    local_30 = json_object_new_object();
    uVar2 = json_object_new_object();
    uVar3 = json_object_new_array();
    uVar4 = json_object_new_string(&DAT_00697f28);
    json_object_object_add(iVar1,"method",uVar4);
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",param_1);
    uVar4 = json_object_new_string(acStack_134);
    json_object_object_add(uVar2,"operation_id",uVar4);
    uVar4 = json_object_new_string("sensor_backhaul_test");
    json_object_object_add(uVar2,"function",uVar4);
    sVar5 = strlen((char *)(param_4 + 0x130));
    FUN_00407fc0((char *)(param_4 + 0x130),sVar5,auStack_1cc,0x96);
    for (iVar7 = 0; iVar7 < param_3; iVar7 = iVar7 + 1) {
      uVar4 = json_object_new_object();
      memset(acStack_134,0,0x100);
      snprintf(acStack_134,0x100,"%d",1);
      uVar6 = json_object_new_string(acStack_134);
      json_object_object_add(uVar4,"radio_id",uVar6);
      FUN_004e3340(param_2,&local_1e0);
      uVar6 = json_object_new_string(&local_1e0);
      json_object_object_add(uVar4,"bssid",uVar6);
      memset(acStack_134,0,0x100);
      snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 0x80));
      uVar6 = json_object_new_string(acStack_134);
      json_object_object_add(uVar4,"ssid_id",uVar6);
      uVar6 = json_object_new_string(auStack_1cc);
      json_object_object_add(uVar4,"ssid",uVar6);
      memset(acStack_134,0,0x100);
      snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 300));
      uVar6 = json_object_new_string(acStack_134);
      json_object_object_add(uVar4,"ssid_code_type",uVar6);
      memset(acStack_134,0,0x100);
      snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 0x16a));
      uVar6 = json_object_new_string(acStack_134);
      json_object_object_add(uVar4,"encryption",uVar6);
      if (*(int *)(param_4 + 0x16a) == 1) {
        uVar6 = json_object_new_string(param_4 + 0x17a);
        json_object_object_add(uVar4,"key",uVar6);
      }
      param_2 = param_2 + 0x14;
      memset(acStack_134,0,0x100);
      snprintf(acStack_134,0x100,"%d",iVar7);
      uVar6 = json_object_new_string(acStack_134);
      json_object_object_add(uVar4,"test_idx",uVar6);
      json_object_array_add(uVar3,uVar4);
    }
    uVar4 = json_object_new_object();
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",1);
    uVar6 = json_object_new_string(acStack_134);
    json_object_object_add(uVar4,"radio_id",uVar6);
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 0x80));
    uVar6 = json_object_new_string(acStack_134);
    json_object_object_add(uVar4,"ssid_id",uVar6);
    uVar6 = json_object_new_string(auStack_1cc);
    json_object_object_add(uVar4,"ssid",uVar6);
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 300));
    uVar6 = json_object_new_string(acStack_134);
    json_object_object_add(uVar4,"ssid_code_type",uVar6);
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",*(undefined4 *)(param_4 + 0x16a));
    uVar6 = json_object_new_string(acStack_134);
    json_object_object_add(uVar4,"encryption",uVar6);
    if (*(int *)(param_4 + 0x16a) == 1) {
      uVar6 = json_object_new_string(param_4 + 0x17a);
      json_object_object_add(uVar4,"key",uVar6);
    }
    memset(acStack_134,0,0x100);
    snprintf(acStack_134,0x100,"%d",param_3);
    uVar6 = json_object_new_string(acStack_134);
    json_object_object_add(uVar4,"test_idx",uVar6);
    json_object_array_add(uVar3,uVar4);
    json_object_object_add(uVar2,"params",uVar3);
    json_object_object_add(local_30,"sensor_backhaul_test",uVar2);
    json_object_object_add(iVar1,"backhaul",local_30);
    __s = (char *)json_object_to_json_string_ext(iVar1,0);
    sVar5 = strlen(__s);
    __dest = (char *)FUN_00408450(sVar5 + 1,0x2e4);
    if (__dest == (char *)0x0) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_backhaul_test_json_create",0x2e7);
      }
      if (iVar1 == 0) {
        return (char *)0x0;
      }
    }
    else {
      strcpy(__dest,__s);
    }
    json_object_put(iVar1);
  }
  return __dest;
}

