// func _sensor_test_detail_result_data_object_add @ 004f061c size=1556

int _sensor_test_detail_result_data_object_add(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined1 auStack_150 [40];
  char acStack_128 [256];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_detail_result_data_object_add ENTER\n",
           "_sensor_test_detail_result_data_object_add",0xdf9);
  }
  memset(auStack_150,0,0x28);
  iVar2 = json_object_new_array();
  if (iVar2 == 0) {
    if (sensor_test_debug_switch != '\0') {
      pcVar6 = "[SENSOR_TEST_DEBUG]%s()/%d JSON_ARRAY_CREATE fail\n";
      uVar5 = 0xe04;
LAB_004f0ba4:
      printf(pcVar6,"_sensor_test_detail_result_data_object_add",uVar5);
    }
LAB_004f0b58:
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d data object add fail EXIT\n",
             "_sensor_test_detail_result_data_object_add",0xe8a);
    }
    if (iVar2 != 0) {
      json_object_put(iVar2);
      iVar2 = 0;
    }
  }
  else {
    iVar7 = 0;
    if (*(char *)(param_1 + 0x12) != '\0') {
      for (; iVar7 < (int)(uint)*(byte *)(param_1 + 0x12); iVar7 = iVar7 + 1) {
        iVar4 = json_object_new_object();
        if (iVar4 == 0) {
          if (sensor_test_debug_switch == '\0') goto LAB_004f0b58;
          pcVar6 = "[SENSOR_TEST_DEBUG]%s()/%d JSON_ARRAY_CREATE fail\n";
          uVar5 = 0xe0f;
          goto LAB_004f0ba4;
        }
        iVar8 = iVar7 * 0x10;
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",*(undefined4 *)(*(int *)(param_1 + 8) + iVar8));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"errorCode",uVar5);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%lld");
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"startTime",uVar5);
        memset(acStack_128,0,0x100);
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + iVar8 + 8);
        uVar10 = 0;
        snprintf(acStack_128,0x100,"%lld");
        uVar3 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"duration",uVar3);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(uint)*(byte *)(*(int *)(param_1 + 8) + iVar8 + 0xc),uVar10,
                 uVar5);
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"retryTime",uVar5);
        json_object_array_add(iVar2,iVar4);
      }
    }
    iVar7 = 0;
    if (*(char *)(param_1 + 0x13) == '\0') {
      cVar1 = *(char *)(param_1 + 0x11);
    }
    else {
      for (; iVar7 < (int)(uint)*(byte *)(param_1 + 0x13); iVar7 = iVar7 + 1) {
        iVar4 = json_object_new_object();
        if (iVar4 == 0) {
          if (sensor_test_debug_switch == '\0') goto LAB_004f0b58;
          pcVar6 = "[SENSOR_TEST_DEBUG]%s()/%d JSON_ARRAY_CREATE fail\n";
          uVar5 = 0xe23;
          goto LAB_004f0ba4;
        }
        iVar8 = iVar7 * 8;
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(int)*(short *)(*(int *)(param_1 + 0xc) + iVar8));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"downloadSpeed",uVar5);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(int)*(short *)(*(int *)(param_1 + 0xc) + iVar8 + 2));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"uploadSpeed",uVar5);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(int)*(short *)(*(int *)(param_1 + 0xc) + iVar8 + 4));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"latency",uVar5);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(int)*(short *)(*(int *)(param_1 + 0xc) + iVar8 + 6));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"distance",uVar5);
        json_object_array_add(iVar2,iVar4);
      }
      cVar1 = *(char *)(param_1 + 0x11);
    }
    iVar7 = 0;
    if (cVar1 != '\0') {
      for (; iVar7 < (int)(uint)*(byte *)(param_1 + 0x11); iVar7 = iVar7 + 1) {
        iVar4 = json_object_new_object();
        if (iVar4 == 0) {
          if (sensor_test_debug_switch == '\0') goto LAB_004f0b58;
          pcVar6 = "[SENSOR_TEST_DEBUG]%s()/%d JSON_OBJ_CREATE fail\n";
          uVar5 = 0xe52;
          goto LAB_004f0ba4;
        }
        iVar8 = iVar7 * 0x1c;
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",*(undefined4 *)(*(int *)(param_1 + 4) + iVar8 + 0x14));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"errorCode",uVar5);
        memset(acStack_128,0,0x100);
        snprintf(acStack_128,0x100,"%d",(uint)*(ushort *)(*(int *)(param_1 + 4) + iVar8 + 0x18));
        uVar5 = json_object_new_string(acStack_128);
        json_object_object_add(iVar4,"duration",uVar5);
        memset(auStack_150,0,0x28);
        puVar9 = (undefined4 *)(*(int *)(param_1 + 4) + iVar8);
        FUN_00408190(*puVar9,puVar9[1],puVar9[2],puVar9[3],puVar9[4],auStack_150,0x28,"---");
        if (*(char *)(param_1 + 0x10) == '\x01') {
          uVar5 = json_object_new_string(auStack_150);
          pcVar6 = "domainServerIp";
        }
        else {
          uVar5 = json_object_new_string(auStack_150);
          pcVar6 = "ip";
        }
        json_object_object_add(iVar4,pcVar6,uVar5);
        json_object_array_add(iVar2,iVar4);
      }
    }
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d data object add success EXIT\n",
             "_sensor_test_detail_result_data_object_add",0xe87);
    }
  }
  return iVar2;
}

