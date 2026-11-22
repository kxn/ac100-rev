// func sensor_di_db_set_chnl_util_time @ 004dee4c size=792

undefined4 sensor_di_db_set_chnl_util_time(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *__src;
  undefined2 *__s;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  void *__src_00;
  byte bVar9;
  int iVar10;
  undefined4 local_res8;
  undefined4 local_38 [2];
  int local_30;
  int local_2c;
  
  local_res8 = param_3;
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_chnl_util_time ENTER,sensor_id=%d, chnl=%d\n"
           ,"sensor_di_db_set_chnl_util_time",0x904,param_1,param_2);
  }
  local_38[0] = 0;
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  iVar2 = _sensor_di_db_check_sensor_exists_in_cached_list(param_1);
  if (iVar2 == 0) {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor not exists_in cached list\n",
             "sensor_di_db_set_chnl_util_time",0x910);
    }
  }
  else {
    if (*(short *)(iVar2 + 0x12) < 0x1a) {
      iVar7 = 0;
      bVar1 = false;
      iVar5 = iVar2;
      for (iVar8 = 0; iVar3 = (int)*(short *)(iVar2 + 0x12), iVar8 < iVar3; iVar8 = iVar8 + 1) {
        if ((param_2 == *(byte *)(iVar5 + 0x4c1)) &&
           (uVar4 = (uint)*(byte *)(iVar5 + 0x4c0), uVar4 < 0x78)) {
          if (uVar4 == 0) break;
          iVar10 = 0;
          iVar3 = iVar2 + iVar8 * 0x1e2 + 0x2e0;
          memcpy((void *)(iVar3 + uVar4 * 4),&local_res8,4);
          local_2c = (iVar3 + -0x2e4) - iVar2;
          bVar9 = *(char *)(iVar5 + 0x4c0) + 1;
          local_30 = ((iVar3 - iVar2) + -0x2e0) - iVar7;
          *(byte *)(iVar5 + 0x4c0) = bVar9;
          for (psVar6 = (short *)(iVar2 + (bVar9 - 1) * 4 + iVar8 * 0x1e2 + 0x2e0);
              (0 < (int)((bVar9 - 1) + iVar10) && (iVar10 = iVar10 + 1, *psVar6 < psVar6[-2]));
              psVar6 = psVar6 + 2) {
            __src_00 = (void *)(local_30 + (int)psVar6);
            memcpy(local_38,__src_00,4);
            __src = (void *)((local_2c - iVar7) + (int)psVar6);
            memcpy(__src_00,__src,4);
            memcpy(__src,local_38,4);
          }
          bVar1 = true;
        }
        iVar7 = iVar7 + 0x1e2;
        iVar5 = iVar5 + 0x1e2;
      }
      if ((!bVar1) && (iVar3 < 0x19)) {
        iVar5 = iVar2 + iVar3 * 0x1e2;
        *(char *)(iVar5 + 0x4c1) = (char)param_2;
        __s = (undefined2 *)(iVar2 + iVar3 * 0x1e2 + 0x2e0);
        *(undefined1 *)(iVar5 + 0x4c0) = 1;
        memset(__s,0,0x1e0);
        *__s = local_res8._0_2_;
        __s[1] = local_res8._2_2_;
        *(short *)(iVar2 + 0x12) = *(short *)(iVar2 + 0x12) + 1;
      }
      FUN_00407f30(l_sensor_di_data_mutex);
      if (sensor_di_debug_switch == 0) {
        return 0;
      }
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_set_chnl_util_time success EXIT\n",
             "sensor_di_db_set_chnl_util_time",0x949);
      return 0;
    }
    if (sensor_di_warning_switch != 0) {
      printf("[SENSOR_DI_WARNING]%s()/line %d : util_time_chnl_cnt=%d\n",
             "sensor_di_db_set_chnl_util_time",0x917);
    }
  }
  FUN_00407f30(l_sensor_di_data_mutex);
  return 0;
}

