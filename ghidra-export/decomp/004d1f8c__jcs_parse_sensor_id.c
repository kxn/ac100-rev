// func _jcs_parse_sensor_id @ 004d1f8c size=468

int _jcs_parse_sensor_id(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (iVar1 == 0) {
    if (sensor_di_err_switch == 0) {
      return -1;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : get sensor_id json obj failed\n";
    uVar3 = 0x105;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_jcs_parse_sensor_id",0x108);
        }
      }
    }
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : selected_sensor_id=%d\n","_jcs_parse_sensor_id",0x109,
             iVar1);
    }
    if (iVar1 != -1) {
      FUN_004082d0(l_sensor_di_status_mutex,0xffffffff);
      if (iVar1 != l_sensor_di_cur_viewed_sensor_id) {
        l_sensor_di_cur_viewed_sensor_id = iVar1;
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : jcs_parse_sensor_id, l_sensor_di_cur_viewed_sensor_id=%d\n"
                 ,"_jcs_parse_sensor_id",0x114,iVar1);
        }
        FUN_00407f30(l_sensor_di_status_mutex);
        sensor_di_db_add_new_sensor_to_cached_list(iVar1);
        return iVar1;
      }
      FUN_00407f30(l_sensor_di_status_mutex);
      return iVar1;
    }
    if (sensor_di_err_switch == 0) {
      return -1;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : get sensor_id int failed\n";
    uVar3 = 0x10c;
  }
  printf(__format,"_jcs_parse_sensor_id",uVar3);
  return -1;
}

