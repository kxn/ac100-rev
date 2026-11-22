// func _sensor_multilink_callback_add @ 004e5bf4 size=1096

undefined4 _sensor_multilink_callback_add(uint param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 local_528;
  undefined4 local_524;
  undefined4 local_520;
  uint local_51c;
  undefined4 local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined4 local_50c;
  undefined4 local_508;
  undefined4 local_504;
  undefined1 auStack_500 [283];
  undefined1 auStack_3e5 [21];
  undefined1 auStack_3d0 [216];
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  int local_2e4;
  int local_2bc;
  undefined4 local_2b8;
  undefined1 auStack_e0 [196];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f8,0,0x2d8);
  local_518 = 0;
  local_514 = 0;
  local_510 = 0;
  local_50c = 0;
  local_508 = 0;
  local_504 = 0;
  memset(auStack_500,0,0x205);
  local_528 = 0;
  local_524 = 0;
  local_520 = 0;
  local_51c = 0;
  if (sensor_send_cfg_when_join == 0) {
    uVar8 = 0;
    if (sensor_debug_switch == '\0') {
      return 0;
    }
    pcVar6 = "[SENSOR_DEBUG]%s()/%d sensor_send_cfg_when_join is not open,do not send.\n";
    uVar7 = 0x617;
    goto LAB_004e5d04;
  }
  iVar3 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
  if (iVar3 == -1) {
    uVar8 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar7 = 0x61d;
    goto LAB_004e5d04;
  }
  if (local_2e4 != 7) {
    uVar8 = 0;
    if (sensor_debug_switch == '\0') {
      return 0;
    }
    pcVar6 = "[SENSOR_DEBUG]%s()/%d Not sensor or sensor is not firmed,no need to handle.\n";
    uVar7 = 0x622;
    goto LAB_004e5d04;
  }
  bVar1 = false;
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  iVar2 = g_sensor_state;
  iVar3 = g_sensor_enable;
  uVar9 = g_backhaul_wserv_id;
  if (0 < unfinished_sensor_num) {
    bVar1 = *(short *)(unfinished_sensor_id_map + (local_2e8 - 50000) * 2) != -1;
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  if (iVar3 == 0) {
    uVar8 = 0;
    if (sensor_debug_switch == '\0') {
      return 0;
    }
    pcVar6 = "[SENSOR_DEBUG]%s()/%d Sensor is not enabled\n";
    uVar7 = 0x62d;
    goto LAB_004e5d04;
  }
  iVar3 = apdb_get_radio_extend_capability(local_2b8,auStack_e0,1,0xffffffff,&local_528,0x10);
  if (iVar3 != 0) {
    uVar8 = 0xffffffff;
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d apdb_get_radio_extend_capability failed\n";
    uVar7 = 0x632;
    goto LAB_004e5d04;
  }
  if (uVar9 == 0xffffffff) {
    uVar9 = 1;
    puVar5 = (undefined1 *)0x0;
    goto LAB_004e5e7c;
  }
  iVar3 = wserv_db_get_entry_by_id(uVar9,auStack_500);
  uVar4 = (uint)auStack_3e5 & 3;
  if (iVar3 != 0) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d Get backhaul wservice(%d) failed\n";
    uVar8 = 0x639;
    param_1 = uVar9;
    goto LAB_004e5e64;
  }
  puVar5 = auStack_3d0;
  uVar9 = (uint)(auStack_3e5 + 3) & 3;
  uVar9 = (*(int *)(auStack_3e5 + -uVar4) << uVar4 * 8 | 0xffffffffU >> (4 - uVar4) * 8 & 0x770000)
          & -1 << (uVar9 + 1) * 8 | *(uint *)(auStack_3e5 + 3 + -uVar9) >> (3 - uVar9) * 8;
  if (local_2bc == 0) {
LAB_004e5e7c:
    uVar4 = local_51c & 0xff;
  }
  else {
    uVar4 = local_51c & 0xff;
    if ((!bVar1) && (uVar4 = local_51c & 0xff, (local_51c & 0x40) != 0)) {
      iVar3 = sensor_db_get(param_1,&local_518,0);
      if (iVar3 != 0) {
        uVar8 = 0xffffffff;
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar6 = 
        "[SENSOR_ERROR]%s()/%d sensor_db_get/apmngr_db_entry_get_by_id failed or role error or not firmed\n"
        ;
        uVar7 = 0x643;
        goto LAB_004e5d04;
      }
      if ((local_514._0_1_ != '\0') &&
         (iVar3 = _sensor_backhaul_ssid_send(param_1,(int)&local_514 + 1,1,auStack_500,1,0),
         iVar3 != 0)) {
        uVar8 = 0xffffffff;
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar6 = "[SENSOR_ERROR]%s()/%d sensor_backhaul_ssid_send for primary bssid failed\n";
        uVar7 = 0x648;
        goto LAB_004e5d04;
      }
      iVar3 = _sensor_backhaul_ssid_send(param_1,0,0,auStack_500,1,0);
      puVar5 = auStack_3d0;
      if (iVar3 != 0) {
        uVar8 = 0xffffffff;
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar6 = "[SENSOR_ERROR]%s()/%d sensor_backhaul_ssid_send for ssid bh failed\n";
        uVar7 = 0x64e;
        goto LAB_004e5d04;
      }
      goto LAB_004e5e7c;
    }
  }
  if ((uVar4 & 2) != 0) {
    uVar8 = 0x1e;
    if (local_2bc != 0) {
      if (iVar2 == 3) {
        if (!bVar1) {
          puVar5 = (undefined1 *)0x0;
          uVar8 = 0xb4;
          uVar9 = 1;
        }
      }
      else {
        uVar8 = 0xb4;
        uVar9 = 1;
        puVar5 = (undefined1 *)0x0;
      }
    }
    iVar3 = _sensor_neighbor_scan_send(param_1,0,1,uVar8,0,puVar5,uVar9);
    if (iVar3 == 0) {
      return 0;
    }
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar6 = "[SENSOR_ERROR]%s()/%d _sensor_regular_neighbor_scan_send for AP %d failed\n";
    uVar8 = 0x66b;
LAB_004e5e64:
    printf(pcVar6,"_sensor_multilink_callback_add",uVar8,param_1);
    return 0xffffffff;
  }
  uVar8 = 0;
  if (sensor_warning_switch == '\0') {
    return 0;
  }
  pcVar6 = "[SENSOR_WARNING]%s()/%d Sensor not support neighbor scan\n";
  uVar7 = 0x655;
LAB_004e5d04:
  printf(pcVar6,"_sensor_multilink_callback_add",uVar7);
  return uVar8;
}

