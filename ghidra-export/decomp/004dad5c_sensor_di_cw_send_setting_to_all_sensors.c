// func sensor_di_cw_send_setting_to_all_sensors @ 004dad5c size=868

undefined4 sensor_di_cw_send_setting_to_all_sensors(undefined4 *param_1,int param_2)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  void *__ptr;
  char *__format;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *local_3b8;
  undefined4 local_3b4;
  undefined4 local_320;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  uint local_304;
  undefined1 auStack_300 [64];
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_setting_to_all_sensors ENTER, cnt=%d\n"
           ,"sensor_di_cw_send_setting_to_all_sensors",0x848,param_2);
  }
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  local_304 = 0;
  memset(auStack_300,0,0x2d8);
  if (param_1 == (undefined4 *)0x0) {
    uVar7 = 0xffffffff;
    if (sensor_di_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[SENSOR_DI_ERROR]%s()/line %d : input setting ptr is null\n";
    uVar6 = 0x851;
  }
  else {
    bVar3 = true;
    iVar8 = 0;
    while (iVar8 < param_2) {
      iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 2),auStack_300);
      if (iVar4 == 0) {
        local_3b4 = 0x10;
        local_3b8 = &local_310;
        iVar4 = apdb_get_radio_extend_capability(local_2c0,auStack_e8,1,0xffffffff);
        if (iVar4 != 0) goto LAB_004dae08;
        if ((local_304 & 8) == 0) {
          *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 2;
        }
        bVar1 = *(byte *)(param_1 + 1);
        if ((local_304 & 4) == 0) {
          *(byte *)(param_1 + 1) = bVar1 & 5;
          bVar1 = *(byte *)(param_1 + 1);
        }
        if (bVar1 == 0) goto LAB_004dae14;
        local_320 = 0;
        for (uVar5 = 0; uVar5 < 0x98; uVar5 = uVar5 + 1) {
          *(undefined1 *)((int)&local_3b8 + uVar5) = *(undefined1 *)((int)param_1 + uVar5 + 0xc);
        }
        __ptr = (void *)sensor_di_packet_json_generate(0,*param_1,param_1[1],param_1[2]);
        if (__ptr == (void *)0x0) {
          uVar7 = 0xffffffff;
          if (sensor_di_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[SENSOR_DI_ERROR]%s()/line %d : generate json_str fail\n";
          uVar6 = 0x86f;
          goto LAB_004daf94;
        }
        if (sensor_di_debug_switch == 0) {
          uVar2 = *(undefined2 *)((int)param_1 + 2);
        }
        else {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : to send sensor_id is=%d\n",
                 "sensor_di_cw_send_setting_to_all_sensors",0x872,*param_1);
          uVar2 = *(undefined2 *)((int)param_1 + 2);
        }
        iVar4 = sensor_pkt_tdcp_send(uVar2,__ptr);
        if (iVar4 == -1) {
          if (sensor_di_err_switch != 0) {
            printf("[SENSOR_DI_ERROR]%s()/line %d : sensor_pkt_tdcp_send return fail\n",
                   "sensor_di_cw_send_setting_to_all_sensors",0x875);
          }
          if (sensor_di_err_switch != 0) {
            printf("[SENSOR_DI_ERROR]%s()/line %d : sensor_di_cw_send_setting_to_all_sensors fail EXIT\n"
                   ,"sensor_di_cw_send_setting_to_all_sensors",0x88d);
          }
          free(__ptr);
          return 0xffffffff;
        }
        if (sensor_di_debug_switch != 0) {
          printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n","sensor_di_cw_send_setting_to_all_sensors",
                 0x878,__ptr);
        }
        free(__ptr);
        bVar3 = false;
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 0x29;
      }
      else {
LAB_004dae08:
        if (sensor_di_err_switch == 0) {
LAB_004dae14:
          iVar8 = iVar8 + 1;
          param_1 = param_1 + 0x29;
        }
        else {
          printf("[SENSOR_DI_ERROR]%s()/line %d : apdb_get_radio_extend_capability failed,entry_id=%d\n"
                 ,"sensor_di_cw_send_setting_to_all_sensors",0x859,*param_1);
          iVar8 = iVar8 + 1;
          param_1 = param_1 + 0x29;
        }
      }
    }
    if (bVar3) {
      uVar7 = 0xfffffffc;
      if (sensor_di_err_switch == 0) {
        return 0xfffffffc;
      }
      __format = "[SENSOR_DI_ERROR]%s()/line %d : all sensor ext_cap check fail\n";
      uVar6 = 0x881;
    }
    else {
      uVar7 = 0;
      if (sensor_di_debug_switch == 0) {
        return 0;
      }
      __format = 
      "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_setting_to_all_sensors success EXIT\n";
      uVar6 = 0x889;
    }
  }
LAB_004daf94:
  printf(__format,"sensor_di_cw_send_setting_to_all_sensors",uVar6);
  return uVar7;
}

