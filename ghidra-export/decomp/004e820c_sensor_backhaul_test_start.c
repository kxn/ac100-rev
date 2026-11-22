// func sensor_backhaul_test_start @ 004e820c size=1548

/* WARNING: Type propagation algorithm not settling */

undefined4 sensor_backhaul_test_start(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  short *psVar8;
  ushort *puVar9;
  ushort *puVar10;
  int local_14c8 [5];
  undefined1 auStack_14b4 [524];
  undefined1 auStack_12a8 [64];
  undefined4 local_1268;
  undefined1 auStack_1090 [192];
  undefined1 auStack_fd0 [4000];
  int local_30;
  undefined1 *local_2c;
  
  memset(auStack_12a8,0,0x2d8);
  memset(auStack_fd0,0,4000);
  local_14c8[0] = 0;
  memset(auStack_14b4,0,0x205);
  local_14c8[1] = 0;
  local_14c8[2] = 0;
  local_14c8[3] = 0;
  local_14c8[4] = 0;
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if (((g_sensor_enable == 0) || (g_backhaul_wserv_id == -1)) || (g_sensor_state != 3)) {
    uVar6 = 0xfffffffe;
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed or g_backhaul_wserv_id(%d) or state(%d/%d) is error\n"
             ,"sensor_backhaul_test_start",0xa65,g_sensor_enable,g_backhaul_wserv_id,g_sensor_state,
             g_sensor_backhaul_test_state);
    }
  }
  else {
    iVar2 = wserv_db_get_entry_by_id(g_backhaul_wserv_id,auStack_14b4);
    if (iVar2 == 0) {
      if (((unfinished_sensor_list != 0) && (0 < unfinished_sensor_num)) &&
         (backhaul_test_suc_sensor_num < unfinished_sensor_num)) {
        iVar2 = 0;
        backhaul_test_finished_sensor_num = backhaul_test_suc_sensor_num;
LAB_004e83d8:
        do {
          if (unfinished_sensor_num_first <= iVar2) goto LAB_004e84b8;
          iVar7 = iVar2 * 0x30;
          psVar8 = (short *)(unfinished_sensor_list + iVar7);
          if (*psVar8 != -1) {
            iVar3 = *(int *)(psVar8 + 2);
            if (iVar3 == 6) {
              iVar2 = iVar2 + 1;
              goto LAB_004e83d8;
            }
            if ((iVar3 != 2) && (iVar3 != 1)) {
              psVar8[2] = 0;
              psVar8[3] = 0;
              psVar8[4] = 0;
              psVar8[5] = 0;
              memset(psVar8 + 6,0,0x24);
              iVar3 = apmngr_db_entry_get_by_id(*psVar8,auStack_12a8);
              if ((iVar3 == 0) &&
                 (iVar3 = apdb_get_radio_extend_capability
                                    (local_1268,auStack_1090,1,0xffffffff,local_14c8 + 1,0x10),
                 iVar3 == 0)) {
                if ((local_14c8[4] & 0x40U) == 0) {
                  if (sensor_warning_switch != '\0') {
                    printf("[SENSOR_WARNING]%s()/%d Sensor not support backhaul, no need to test\n",
                           "sensor_backhaul_test_start",0xa89);
                  }
                  iVar2 = iVar2 + 1;
                  *(undefined4 *)(unfinished_sensor_list + iVar7 + 4) = 6;
                  backhaul_test_finished_sensor_num = backhaul_test_finished_sensor_num + 1;
                  backhaul_test_suc_sensor_num = backhaul_test_suc_sensor_num + 1;
                  goto LAB_004e83d8;
                }
                iVar3 = sensor_backhaul_bssid_list_get
                                  (*(undefined2 *)(unfinished_sensor_list + iVar7),auStack_fd0,200,
                                   local_14c8);
                if (iVar3 == 0) {
                  local_30 = 0;
                  iVar3 = 2;
                  if (local_14c8[0] < 3) {
                    iVar3 = local_14c8[0];
                  }
                  puVar10 = (ushort *)(unfinished_sensor_list + iVar7);
                  *(int *)(puVar10 + 4) = iVar3 + 1;
                  local_2c = auStack_fd0;
                  puVar9 = puVar10;
                  for (; local_30 < iVar3; local_30 = local_30 + 1) {
                    memcpy(puVar9 + 6,local_2c,6);
                    *(undefined1 *)(puVar9 + 9) = 1;
                    local_2c = local_2c + 0x14;
                    puVar9 = puVar9 + 6;
                  }
                  *(undefined1 *)(puVar10 + iVar3 * 6 + 9) = 0;
                  local_30 = iVar2 * 4;
                  uVar1 = *puVar10;
                  iVar3 = FUN_00408eec(*(undefined4 *)
                                        (current_backhaul_test_operation_id + local_30),auStack_fd0,
                                       iVar3,auStack_14b4);
                  if (iVar3 == 0) {
                    if (sensor_err_switch != '\0') {
                      printf("[SENSOR_ERROR]%s()/%d _sensor_backhaul_set_json_create failed\n",
                             "_sensor_backhaul_test_send",0x5d7);
                    }
                  }
                  else {
                    if (sensor_debug_switch != '\0') {
                      printf("[SENSOR_DEBUG]%s()/%d json_str is %s\n","_sensor_backhaul_test_send",
                             0x5da,iVar3);
                    }
                    iVar4 = sensor_pkt_tdcp_send((uint)uVar1,iVar3);
                    if (iVar4 == 0) {
                      FUN_00407df0(iVar3);
                      iVar2 = iVar2 + 1;
                      iVar3 = *(int *)(current_backhaul_test_operation_id + local_30) + 1;
                      if (iVar3 < 0) {
                        iVar3 = 0;
                      }
                      *(int *)(current_backhaul_test_operation_id + local_30) = iVar3;
                      *(undefined4 *)(unfinished_sensor_list + iVar7 + 4) = 1;
                      goto LAB_004e83d8;
                    }
                    if (sensor_err_switch != '\0') {
                      printf("[SENSOR_ERROR]%s()/%d Send tdcp to ap %d failed\n",
                             "_sensor_backhaul_test_send",0x5dd,(uint)uVar1);
                    }
                    FUN_00407df0(iVar3);
                  }
                  if (sensor_warning_switch != '\0') {
                    printf("[SENSOR_WARNING]%s()/%d _sensor_backhaul_test_send failed for sensor %d\n"
                           ,"sensor_backhaul_test_start",0xaa1,
                           (uint)*(ushort *)(unfinished_sensor_list + iVar7));
                  }
                  goto LAB_004e8468;
                }
                if (sensor_warning_switch != '\0') {
                  printf("[SENSOR_WARNING]%s()/%d sensor_backhaul_bssid_list_get failed or no bssid found for sensor %d\n"
                         ,"sensor_backhaul_test_start",0xa91,
                         (uint)*(ushort *)(unfinished_sensor_list + iVar7));
                }
                uVar6 = 4;
              }
              else {
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d apdb_get_radio_extend_capability failed\n",
                         "sensor_backhaul_test_start",0xa82);
                }
LAB_004e8468:
                uVar6 = 5;
              }
              *(undefined4 *)(unfinished_sensor_list + iVar7 + 4) = uVar6;
              backhaul_test_finished_sensor_num = backhaul_test_finished_sensor_num + 1;
            }
          }
          iVar2 = iVar2 + 1;
        } while( true );
      }
      uVar6 = 0xfffffff6;
      if (sensor_warning_switch != '\0') {
        printf("[SENSOR_WARNING]%s()/%d No sensor found\n","sensor_backhaul_test_start",0xac4);
      }
    }
    else {
      uVar6 = 0xfffffff7;
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d Get backhaul wservice(%d) failed\n",
               "sensor_backhaul_test_start",0xa6b,g_backhaul_wserv_id);
      }
    }
  }
LAB_004e82d4:
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar6;
LAB_004e84b8:
  if (backhaul_test_finished_sensor_num < unfinished_sensor_num) {
    if (sensor_backhaul_test_timer != -1) {
      FUN_00408060();
      sensor_backhaul_test_timer = -1;
    }
    uVar6 = 0xffffffff;
    sensor_backhaul_test_timer =
         FUN_00408340(sensor_backhaul_test_timeout,0,_sensor_backhaul_test_timeout,0,0,
                      "sensor_backhaul_test_start",0xab5);
    uVar5 = 1;
    if (sensor_backhaul_test_timer == -1) goto LAB_004e82d4;
  }
  else {
    uVar5 = 2;
  }
  uVar6 = 0;
  g_sensor_backhaul_test_state = uVar5;
  goto LAB_004e82d4;
}

