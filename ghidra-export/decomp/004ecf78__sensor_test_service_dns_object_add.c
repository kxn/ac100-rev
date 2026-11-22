// func _sensor_test_service_dns_object_add @ 004ecf78 size=480

undefined4 _sensor_test_service_dns_object_add(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  char acStack_118 [260];
  
  if (sensor_test_debug_switch == '\0') {
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 4);
LAB_004ecfb0:
      if (iVar1 != 0) {
        iVar1 = json_object_new_object();
        if (iVar1 != 0) {
          iVar2 = json_object_new_object();
          if (iVar2 != 0) {
            uVar3 = json_object_new_string("dns");
            json_object_object_add(iVar1,"ser_name",uVar3);
            memset(acStack_118,0,0x100);
            snprintf(acStack_118,0x100,"%d",(uint)*(ushort *)(*(int *)(param_2 + 4) + 0x100));
            uVar3 = json_object_new_string(acStack_118);
            json_object_object_add(iVar1,"ser_index",uVar3);
            uVar3 = json_object_new_string(*(undefined4 *)(param_2 + 4));
            json_object_object_add(iVar2,"domain",uVar3);
            json_object_object_add(iVar1,"params",iVar2);
            json_object_array_add(param_1,iVar1);
            return 0;
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
                   "_sensor_test_service_dns_object_add",0xc66);
          }
          json_object_put(iVar1);
          return 0xffffffff;
        }
        if (sensor_test_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n";
        uVar3 = 0xc60;
        goto LAB_004ed10c;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_service_dns_object_add ENTER\n",
           "_sensor_test_service_dns_object_add",0xc52);
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 4);
      goto LAB_004ecfb0;
    }
  }
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d Input error\n";
  uVar3 = 0xc59;
LAB_004ed10c:
  printf(__format,"_sensor_test_service_dns_object_add",uVar3);
  return 0xffffffff;
}

