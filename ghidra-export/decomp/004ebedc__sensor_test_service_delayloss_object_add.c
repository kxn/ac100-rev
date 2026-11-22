// func _sensor_test_service_delayloss_object_add @ 004ebedc size=268

undefined4 _sensor_test_service_delayloss_object_add(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_110 [260];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_service_delayloss_object_add ENTER\n",
           "_sensor_test_service_delayloss_object_add",0xdc2);
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if (sensor_test_err_switch != '\0') {
      printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
             "_sensor_test_service_delayloss_object_add",0xdc6);
    }
  }
  else {
    uVar2 = json_object_new_string("delayloss");
    json_object_object_add(iVar1,"ser_name",uVar2);
    memset(acStack_110,0,0x100);
    snprintf(acStack_110,0x100,"%d",0);
    uVar2 = json_object_new_string(acStack_110);
    json_object_object_add(iVar1,"ser_index",uVar2);
    uVar2 = 0;
    json_object_array_add(param_1,iVar1);
  }
  return uVar2;
}

