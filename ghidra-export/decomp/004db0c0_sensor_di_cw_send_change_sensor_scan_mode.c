// func sensor_di_cw_send_change_sensor_scan_mode @ 004db0c0 size=764

undefined4 sensor_di_cw_send_change_sensor_scan_mode(uint param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  void *__ptr;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *local_4b0;
  undefined4 local_4ac;
  undefined4 *local_418;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  int local_3f8 [25];
  undefined4 local_394;
  uint local_390;
  undefined4 local_38c;
  undefined1 local_388 [216];
  undefined4 local_2b0;
  undefined1 auStack_d8 [192];
  
  if (sensor_di_debug_switch != 0) {
    local_4b0 = param_2;
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_change_sensor_scan_mode ENTER, entry_id=%d, chnl=%d\n"
           ,"sensor_di_cw_send_change_sensor_scan_mode",0x898,param_1);
  }
  memset(&local_394,0,0xa4);
  local_408 = 0;
  local_404 = 0;
  local_400 = 0;
  local_3fc = 0;
  memset(local_388 + 0x98,0,0x2d8);
  if (((int)param_1 < 0) || ((int)param_2 < 0)) {
    uVar6 = 0xffffffff;
    if (sensor_di_err_switch == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : input param invalid\n";
    uVar5 = 0x8a1;
LAB_004db1b4:
    printf(pcVar4,"sensor_di_cw_send_change_sensor_scan_mode",uVar5);
  }
  else {
    iVar1 = sensor_di_db_get_specified_di_setting(param_1,&local_394);
    if (iVar1 == -1) {
      if (sensor_di_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : no such setting,entry_id=%d\n";
      uVar5 = 0x8a7;
    }
    else {
      iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,local_388 + 0x98);
      if (iVar1 == 0) {
        local_4ac = 0x10;
        local_4b0 = &local_408;
        iVar1 = apdb_get_radio_extend_capability(local_2b0,auStack_d8,1,0xffffffff);
        if (iVar1 == 0) {
          if ((local_3fc & 8) == 0) {
            local_390 = local_390 & 0x2ffffff;
          }
          if ((local_3fc & 4) == 0) {
            local_390 = local_390 & 0x5ffffff;
          }
          if (local_390._0_1_ == '\0') {
            return 0xffffffff;
          }
          if (-1 < (char)local_3fc) {
            memcpy(local_3f8,&DAT_006ace98,100);
            iVar1 = 0;
            do {
              piVar3 = (int *)((int)local_3f8 + iVar1);
              iVar1 = iVar1 + 4;
              if (param_2 == (undefined4 *)*piVar3) {
                return 0xffffffff;
              }
            } while (iVar1 != 100);
          }
          local_418 = param_2;
          for (uVar2 = 0; uVar2 < 0x98; uVar2 = uVar2 + 1) {
            *(undefined1 *)((int)&local_4b0 + uVar2) = local_388[uVar2];
          }
          __ptr = (void *)sensor_di_packet_json_generate(2,local_394,local_390,local_38c);
          if (__ptr == (void *)0x0) {
            uVar6 = 0xffffffff;
            if (sensor_di_err_switch == 0) {
              return 0xffffffff;
            }
            pcVar4 = "[SENSOR_DI_ERROR]%s()/line %d : generate json_str fail\n";
            uVar5 = 0x8c8;
          }
          else {
            sensor_pkt_tdcp_send(param_1 & 0xffff,__ptr);
            if (sensor_di_debug_switch != 0) {
              printf("[SENSOR_DI_DEBUG]%s()/line %d : %s\n",
                     "sensor_di_cw_send_change_sensor_scan_mode",0x8cc,__ptr);
            }
            free(__ptr);
            uVar6 = 0;
            if (sensor_di_debug_switch == 0) {
              return 0;
            }
            pcVar4 = 
            "[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_cw_send_change_sensor_scan_mode success EXIT\n"
            ;
            uVar5 = 0x8d2;
          }
          goto LAB_004db1b4;
        }
      }
      if (sensor_di_err_switch == 0) {
        return 0xffffffff;
      }
      pcVar4 = 
      "[SENSOR_DI_ERROR]%s()/line %d : apdb_get_radio_extend_capability failed,entry_id=%d\n";
      uVar5 = 0x8ad;
    }
    uVar6 = 0xffffffff;
    printf(pcVar4,"sensor_di_cw_send_change_sensor_scan_mode",uVar5,param_1);
  }
  return uVar6;
}

