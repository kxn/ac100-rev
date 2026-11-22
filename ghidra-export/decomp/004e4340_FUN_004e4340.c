// func FUN_004e4340 @ 004e4340 size=1316

char * FUN_004e4340(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *__s;
  size_t sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined1 auStack_1c4 [152];
  char acStack_12c [260];
  
  local_1d8 = 0;
  local_1d4 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  memset(auStack_1c4,0,0x96);
  if ((param_4 - 1U < 3) && (param_3 != 0)) {
    iVar1 = json_object_new_object();
    uVar2 = json_object_new_object();
    if (param_4 == 1) {
      pcVar7 = "add";
    }
    else if (param_4 == 2) {
      pcVar7 = "set";
    }
    else {
      pcVar7 = "delete";
    }
    uVar3 = json_object_new_string(pcVar7);
    json_object_object_add(iVar1,"method",uVar3);
    uVar3 = json_object_new_string("sensor_backhaul_config");
    json_object_object_add(uVar2,"table",uVar3);
    if (param_4 - 1U != 2) {
      uVar3 = json_object_new_object();
      if (param_4 == 1) {
        memset(acStack_12c,0,0x100);
        snprintf(acStack_12c,0x100,"%d",(uint)(param_1 == 0));
        uVar5 = json_object_new_string(acStack_12c);
        json_object_object_add(uVar3,"backhaul_id",uVar5);
        memset(acStack_12c,0,0x100);
        snprintf(acStack_12c,0x100,"%d",1);
        uVar5 = json_object_new_string(acStack_12c);
        json_object_object_add(uVar3,"radio_id",uVar5);
      }
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",(uint)(param_1 != 0));
      uVar5 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar3,"primary",uVar5);
      if (param_2 != 0) {
        FUN_004e3340(param_2,&local_1d8);
        uVar5 = json_object_new_string(&local_1d8);
        json_object_object_add(uVar3,"bssid",uVar5);
      }
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",*(undefined4 *)(param_3 + 0x80));
      uVar5 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar3,"ssid_id",uVar5);
      sVar4 = strlen((char *)(param_3 + 0x130));
      FUN_00407fc0((char *)(param_3 + 0x130),sVar4,auStack_1c4,0x96);
      uVar5 = json_object_new_string(auStack_1c4);
      json_object_object_add(uVar3,"ssid",uVar5);
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",*(undefined4 *)(param_3 + 300));
      uVar5 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar3,"ssid_code_type",uVar5);
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",*(undefined4 *)(param_3 + 0x16a));
      uVar5 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar3,"encryption",uVar5);
      if (*(int *)(param_3 + 0x16a) == 1) {
        uVar5 = json_object_new_string(param_3 + 0x17a);
        json_object_object_add(uVar3,"key",uVar5);
      }
      json_object_object_add(uVar2,"para",uVar3);
    }
    if (param_4 - 2U < 2) {
      uVar3 = json_object_new_array();
      uVar5 = json_object_new_object();
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",(uint)(param_1 == 0));
      uVar6 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar5,"backhaul_id",uVar6);
      memset(acStack_12c,0,0x100);
      snprintf(acStack_12c,0x100,"%d",1);
      uVar6 = json_object_new_string(acStack_12c);
      json_object_object_add(uVar5,"radio_id",uVar6);
      json_object_array_add(uVar3,uVar5);
      json_object_object_add(uVar2,"filter",uVar3);
    }
    json_object_object_add(iVar1,"backhaul",uVar2);
    __s = (char *)json_object_to_json_string_ext(iVar1,0);
    sVar4 = strlen(__s);
    pcVar7 = (char *)FUN_00408450(sVar4 + 1,0x279);
    if (pcVar7 == (char *)0x0) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_backhaul_set_json_create",0x27c);
      }
      if (iVar1 == 0) {
        return (char *)0x0;
      }
    }
    else {
      strcpy(pcVar7,__s);
    }
    json_object_put(iVar1);
  }
  else {
    pcVar7 = (char *)0x0;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","_sensor_backhaul_set_json_create",0x23b);
    }
  }
  return pcVar7;
}

