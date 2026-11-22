// func jcs_sensor_test_group_delete_event_handle @ 004ed158 size=548

void jcs_sensor_test_group_delete_event_handle(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined8 uVar7;
  undefined2 local_820 [1024];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d group_delete_event_handle ENTER\n",
           "jcs_sensor_test_group_delete_event_handle",0x1b93);
  }
  memset(local_820,0,0x800);
  iVar1 = json_object_object_get(param_1,"group_id");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar6 = local_820;
      for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
        if (iVar2 == 0x400) goto LAB_004ed340;
        iVar3 = json_object_array_get_idx(iVar1,iVar2);
        if (iVar3 == 0) {
LAB_004ed2e8:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_sensor_test_group_delete_event_handle",0x1b9b);
          }
          *puVar6 = 0xffff;
        }
        else {
          iVar4 = json_object_get_type(iVar3);
          if (iVar4 == 3) {
            uVar5 = json_object_get_int(iVar3);
            *puVar6 = uVar5;
          }
          else {
            iVar4 = json_object_get_type();
            if (iVar4 != 2) goto LAB_004ed2e8;
            uVar7 = json_object_get_double(iVar3);
            uVar5 = __fixunsdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
            *puVar6 = uVar5;
          }
        }
        puVar6 = puVar6 + 1;
      }
      if (0 < iVar2) {
LAB_004ed340:
        sensor_test_db_group_id_delete(local_820,iVar2);
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (((iVar2 != 4) || (iVar1 = json_object_object_length(iVar1), iVar1 != 0)) &&
         (jcs_err_switch != 0)) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "jcs_sensor_test_group_delete_event_handle",0x1b9b);
      }
    }
  }
  return;
}

