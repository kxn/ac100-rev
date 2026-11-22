// func _sensor_test_service_ftp_object_add @ 004ec210 size=816

undefined4 _sensor_test_service_ftp_object_add(undefined4 param_1,int param_2)

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
      iVar1 = *(int *)(param_2 + 0x18);
LAB_004ec25c:
      iVar5 = 0;
      if (iVar1 != 0) {
        while( true ) {
          if (**(int **)(param_2 + 0x18) <= iVar5) {
            return 0;
          }
          iVar1 = json_object_new_object();
          if (iVar1 == 0) break;
          iVar2 = json_object_new_object();
          if (iVar2 == 0) {
            if (sensor_test_err_switch != '\0') {
              printf("[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n",
                     "_sensor_test_service_ftp_object_add",0xd6d);
            }
            json_object_put(iVar1);
            return 0xffffffff;
          }
          uVar3 = json_object_new_string(&DAT_006b2d6c);
          json_object_object_add(iVar1,"ser_name",uVar3);
          iVar4 = iVar5 * 0xa8e;
          memset(acStack_128,0,0x100);
          iVar5 = iVar5 + 1;
          snprintf(acStack_128,0x100,"%d",
                   (uint)*(ushort *)(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0xa8c));
          uVar3 = json_object_new_string(acStack_128);
          json_object_object_add(iVar1,"ser_index",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4);
          json_object_object_add(iVar2,&DAT_0068376c,uVar3);
          memset(acStack_128,0,0x100);
          snprintf(acStack_128,0x100,"%d",
                   (uint)*(ushort *)(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0xa8a));
          uVar3 = json_object_new_string(acStack_128);
          json_object_object_add(iVar2,"port",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0x100);
          json_object_object_add(iVar2,"user_name",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0x200);
          json_object_object_add(iVar2,"passwd",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0x278);
          json_object_object_add(iVar2,"trans_type",uVar3);
          uVar3 = json_object_new_string(*(int *)(*(int *)(param_2 + 0x18) + 4) + iVar4 + 0x288);
          json_object_object_add(iVar2,"path",uVar3);
          json_object_object_add(iVar1,"params",iVar2);
          json_object_array_add(param_1,iVar1);
        }
        if (sensor_test_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_TEST_ERROR]%s()/%d Malloc failed\n";
        uVar3 = 0xd67;
        goto LAB_004ec4cc;
      }
    }
  }
  else {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_service_ftp_object_add ENTER\n",
           "_sensor_test_service_ftp_object_add",0xd57);
    if (param_2 != 0) {
      iVar1 = *(int *)(param_2 + 0x18);
      goto LAB_004ec25c;
    }
  }
  if (sensor_test_err_switch == '\0') {
    return 0xffffffff;
  }
  __format = "[SENSOR_TEST_ERROR]%s()/%d Input error\n";
  uVar3 = 0xd5f;
LAB_004ec4cc:
  printf(__format,"_sensor_test_service_ftp_object_add",uVar3);
  return 0xffffffff;
}

