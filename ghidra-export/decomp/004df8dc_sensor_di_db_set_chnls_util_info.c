// func sensor_di_db_set_chnls_util_info @ 004df8dc size=648

/* WARNING: Removing unreachable block (ram,0x004df9f4) */

undefined4 sensor_di_db_set_chnls_util_info(undefined4 param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_d0 [5];
  undefined1 local_cb;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_chnls_util_info ENTER,sensor_id=%d, chnl_cnt=%d\n"
           ,"sensor_di_db_set_chnls_util_info",0x9e0,param_1,param_2);
  }
  memset(auStack_d0,0,0xa4);
  if (param_2 < 1) {
    if (sensor_di_warning_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_WARNING]%s()/line %d : chnl_cnt<=0 exit\n";
    uVar5 = 0x9e9;
  }
  else {
    iVar1 = sensor_di_db_get_specified_di_setting(param_1,auStack_d0);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
    iVar1 = _sensor_di_db_check_sensor_exists_in_cached_list(param_1);
    if (iVar1 == 0) {
      if (sensor_di_debug_switch != 0) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists_in cached list\n",
               "sensor_di_db_set_chnls_util_info",0x9f6);
      }
      FUN_00407f30(l_sensor_di_data_mutex);
      return 0;
    }
    iVar6 = 0;
    do {
      iVar2 = _sensor_di_db_get_chnl_idx(*param_3,local_cb);
      if (iVar2 + 1U < 0x1a) {
        iVar3 = iVar1 + iVar2 * 0x1c;
        uVar4 = *(short *)(iVar3 + 0x24) + 1;
        *(ushort *)(iVar3 + 0x24) = uVar4;
        iVar7 = (int)(uVar4 - 1) % 3;
        *(undefined1 *)(iVar3 + 0x26) = *param_3;
        iVar3 = iVar3 + iVar7;
        *(undefined1 *)(iVar3 + 0x27) = param_3[1];
        *(undefined1 *)(iVar3 + 0x2a) = param_3[2];
        iVar7 = iVar2 * 0xe + iVar7;
        iVar2 = iVar1 + (iVar7 + 0x18) * 2;
        *(undefined2 *)(iVar1 + (iVar7 + 0x14) * 2 + 6) = *(undefined2 *)(param_3 + 4);
        *(undefined2 *)(iVar2 + 4) = *(undefined2 *)(param_3 + 6);
        *(undefined2 *)(iVar2 + 10) = *(undefined2 *)(param_3 + 8);
      }
      else if (sensor_di_err_switch != 0) {
        printf("[SENSOR_DI_ERROR]%s()/line %d : invalid chnl_idx=%d\n",
               "sensor_di_db_set_chnls_util_info",0xa05,iVar2);
      }
      iVar6 = iVar6 + 1;
    } while ((iVar6 != param_2) && (param_3 = param_3 + 10, iVar6 != 0x19));
    FUN_00407f30(l_sensor_di_data_mutex);
    if (sensor_di_debug_switch == 0) {
      return 0;
    }
    __format = "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_chnls_util_info success EXIT\n";
    uVar5 = 0xa16;
  }
  printf(__format,"sensor_di_db_set_chnls_util_info",uVar5);
  return 0;
}

