// func sensor_test_service_object_generate @ 004f91bc size=440

int sensor_test_service_object_generate(ushort *param_1)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_48 [10];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d sensor_test_service_object_generate ENTER\n",
           "sensor_test_service_object_generate",0x1c3d);
  }
  memcpy(local_48,&PTR__sensor_test_service_onboarding_object_add_006b73b4,0x24);
  if (param_1 == (ushort *)0x0) {
    iVar3 = 0;
    if (sensor_test_err_switch != '\0') {
      __format = "[SENSOR_TEST_ERROR]%s()/%d Input error\n";
      uVar2 = 0x1c4e;
LAB_004f9364:
      printf(__format,"sensor_test_service_object_generate",uVar2);
    }
  }
  else {
    if (sensor_test_debug_switch != '\0') {
      printf("[SENSOR_TEST_DEBUG]%s()/%d service->service_type=%d\n",
             "sensor_test_service_object_generate",0x1c52,(uint)*param_1);
    }
    puVar5 = local_48;
    uVar4 = 0;
    iVar3 = 0;
    do {
      if (((int)(uint)*param_1 >> (uVar4 & 0x1f) & 1U) != 0) {
        if ((iVar3 == 0) && (iVar3 = json_object_new_array(), iVar3 == 0)) {
          if (sensor_test_err_switch == '\0') {
            return 0;
          }
          __format = "[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n";
          uVar2 = 0x1c5c;
          goto LAB_004f9364;
        }
        iVar1 = (*(code *)*puVar5)(iVar3,param_1);
        if ((iVar1 != 0) && (sensor_test_err_switch != '\0')) {
          printf("[SENSOR_TEST_ERROR]%s()/%d Generate type %d\'s json object failed\n",
                 "sensor_test_service_object_generate",0x1c62,uVar4);
        }
      }
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 != 9);
  }
  return iVar3;
}

