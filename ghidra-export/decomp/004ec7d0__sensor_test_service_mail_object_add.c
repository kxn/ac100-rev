// func _sensor_test_service_mail_object_add @ 004ec7d0 size=696

undefined4 _sensor_test_service_mail_object_add(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  int iVar4;
  int iVar5;
  char acStack_128 [256];
  
  if (sensor_test_debug_switch == '\0') {
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 0x10);
LAB_004ec81c:
      iVar5 = 0;
      if (iVar1 != 0) {
        while( true ) {
          if (**(int **)(param_2 + 0x10) <= iVar5) {
            return 0;
          }
          iVar1 = json_object_new_object();
          if (iVar1 == 0) break;
          iVar2 = json_object_new_object();
          if (iVar2 == 0) {
            if (sensor_test_err_switch != '\0') {
              printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
                     "_sensor_test_service_mail_object_add",0xd03);
            }
            json_object_put(iVar1);
            return 0xffffffff;
          }
          uVar3 = json_object_new_string(&DAT_006b2e20);
          json_object_object_add(iVar1,"ser_name",uVar3);
          iVar4 = iVar5 * 0x28c;
          memset(acStack_128,0,0x100);
          iVar5 = iVar5 + 1;
          snprintf(acStack_128,0x100,"%d",
                   (uint)*(ushort *)(*(int *)(*(int *)(param_2 + 0x10) + 4) + iVar4 + 0x28a));
          uVar3 = json_object_new_string(acStack_128);
          json_object_object_add(iVar1,"ser_index",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x10) + 4) + iVar4);
          json_object_object_add(iVar2,&DAT_0068376c,uVar3);
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",
                   (uint)*(ushort *)(*(int *)(*(int *)(param_2 + 0x10) + 4) + iVar4 + 0x288));
          uVar3 = json_object_new_string(acStack_128);
          json_object_object_add(iVar2,"port",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x10) + 4) + iVar4 + 0x100);
          json_object_object_add(iVar2,"protocol",uVar3);
          json_object_object_add(iVar1,"params",iVar2);
          json_object_array_add(param_1,iVar1);
        }
        if (sensor_test_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n";
        uVar3 = 0xcfd;
        goto LAB_004eca14;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_service_mail_object_add ENTER\n",
           "_sensor_test_service_mail_object_add",0xced);
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 0x10);
      goto LAB_004ec81c;
    }
  }
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d Input error\n";
  uVar3 = 0xcf5;
LAB_004eca14:
  printf(__format,"_sensor_test_service_mail_object_add",uVar3);
  return 0xffffffff;
}

