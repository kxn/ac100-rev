// func _sensor_test_service_radius_object_add @ 004eca88 size=684

undefined4 _sensor_test_service_radius_object_add(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  char acStack_118 [256];
  
  if (sensor_test_debug_switch == '\0') {
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 0xc);
LAB_004ecac4:
      if (iVar1 != 0) {
        iVar1 = json_object_new_object();
        if (iVar1 != 0) {
          iVar2 = json_object_new_object();
          if (iVar2 != 0) {
            uVar3 = json_object_new_string("radius");
            json_object_object_add(iVar1,"ser_name",uVar3);
            memset(acStack_118,0,0x100);
            snprintf(acStack_118,0x100,"%d",(uint)*(ushort *)(*(int *)(param_2 + 0xc) + 0x38a));
            uVar3 = json_object_new_string(acStack_118);
            json_object_object_add(iVar1,"ser_index",uVar3);
            uVar3 = json_object_new_string(*(undefined4 *)(param_2 + 0xc));
            json_object_object_add(iVar2,&DAT_0068376c,uVar3);
            memset(acStack_118,0,0x100);
            snprintf(acStack_118,0x100,"%d",(uint)*(ushort *)(*(int *)(param_2 + 0xc) + 0x388));
            uVar3 = json_object_new_string(acStack_118);
            json_object_object_add(iVar2,"port",uVar3);
            uVar3 = json_object_new_string(*(int *)(param_2 + 0xc) + 0x100);
            json_object_object_add(iVar2,"user_name",uVar3);
            uVar3 = json_object_new_string(*(int *)(param_2 + 0xc) + 0x200);
            json_object_object_add(iVar2,"passwd",uVar3);
            uVar3 = json_object_new_string(*(int *)(param_2 + 0xc) + 0x278);
            json_object_object_add(iVar2,"share_key",uVar3);
            uVar3 = json_object_new_string(*(int *)(param_2 + 0xc) + 0x378);
            json_object_object_add(iVar2,"auth_type",uVar3);
            json_object_object_add(iVar1,"params",iVar2);
            json_object_array_add(param_1,iVar1);
            return 0;
          }
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
                   "_sensor_test_service_radius_object_add",0xccb);
          }
          json_object_put(iVar1);
          return 0xffffffff;
        }
        if (sensor_test_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n";
        uVar3 = 0xcc5;
        goto LAB_004ecce8;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_service_radius_object_add ENTER\n",
           "_sensor_test_service_radius_object_add",0xcb7);
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 0xc);
      goto LAB_004ecac4;
    }
  }
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d Input error\n";
  uVar3 = 0xcbe;
LAB_004ecce8:
  printf(__format,"_sensor_test_service_radius_object_add",uVar3);
  return 0xffffffff;
}

