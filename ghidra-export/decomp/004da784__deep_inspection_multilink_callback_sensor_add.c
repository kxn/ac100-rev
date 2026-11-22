// func _deep_inspection_multilink_callback_sensor_add @ 004da784 size=748

undefined4 _deep_inspection_multilink_callback_sensor_add(uint param_1)

{
  int iVar1;
  uint uVar2;
  void *__ptr;
  char *__format;
  undefined4 uVar3;
  undefined1 local_168 [152];
  uint local_d0;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined1 local_b4 [160];
  
  param_1 = param_1 & 0xffff;
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : _deep_inspection_multilink_callback_sensor_add ENTER,ap_id=%d\n"
           ,"_deep_inspection_multilink_callback_sensor_add",0x6c7,param_1);
  }
  memset(&local_c0,0,0xa4);
  FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
  iVar1 = l_sensor_di_status;
  FUN_00407f30(l_sensor_di_status_mutex);
  if (iVar1 == 0) {
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_DEBUG]%s()/line %d : cur status is off,no need to resend\n";
    uVar3 = 0x6d2;
LAB_004da88c:
    printf(__format,"_deep_inspection_multilink_callback_sensor_add",uVar3);
    return 0;
  }
  iVar1 = sensor_di_db_get_specified_di_setting(param_1,&local_c0);
  if (iVar1 == -1) {
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_DEBUG]%s()/line %d : no this sensor\'s setting,exit\n";
    uVar3 = 0x6d9;
    goto LAB_004da88c;
  }
  local_d0 = 0;
  for (uVar2 = 0; uVar2 < 0x98; uVar2 = uVar2 + 1) {
    local_168[uVar2] = local_b4[uVar2];
  }
  __ptr = (void *)sensor_di_packet_json_generate(0,local_c0,local_bc,local_b8);
  if (__ptr == (void *)0x0) {
    if (sensor_di_err_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : generate json_str fail\n";
    uVar3 = 0x6e2;
    goto LAB_004da88c;
  }
  iVar1 = sensor_pkt_tdcp_send(param_1,__ptr);
  if (iVar1 == -1) {
    if (sensor_di_err_switch == 0) goto LAB_004da97c;
    uVar3 = 0x6e8;
  }
  else {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n","_deep_inspection_multilink_callback_sensor_add"
             ,0x6eb,__ptr);
    }
    free(__ptr);
    if (local_bc._2_1_ != '\x01') {
      return 0;
    }
    local_d0 = local_bc & 0xff;
    for (uVar2 = 0; uVar2 < 0x98; uVar2 = uVar2 + 1) {
      local_168[uVar2] = local_b4[uVar2];
    }
    __ptr = (void *)sensor_di_packet_json_generate(2,local_c0,local_bc,local_b8);
    if (__ptr == (void *)0x0) {
      if (sensor_di_err_switch == 0) {
        return 0;
      }
      __format = "[SENSOR_DI_ERROR]%s()/line %d : generate json_str fail\n";
      uVar3 = 0x6f9;
      goto LAB_004da88c;
    }
    iVar1 = sensor_pkt_tdcp_send(param_1,__ptr);
    if (iVar1 != -1) {
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n",
               "_deep_inspection_multilink_callback_sensor_add",0x701,__ptr);
      }
      goto LAB_004da97c;
    }
    if (sensor_di_err_switch == 0) goto LAB_004da97c;
    uVar3 = 0x6fe;
  }
  printf("[SENSOR_DI_ERROR]%s()/line %d : sensor_pkt_tdcp_send fail\n",
         "_deep_inspection_multilink_callback_sensor_add",uVar3);
LAB_004da97c:
  free(__ptr);
  return 0;
}

