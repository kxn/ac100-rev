// func sensor_discover_finish @ 004e8818 size=832

undefined4 sensor_discover_finish(void)

{
  char cVar1;
  int iVar2;
  short *psVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int local_fd0;
  short asStack_fcc [2002];
  
  memset(asStack_fcc,0,4000);
  local_fd0 = 0;
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if ((g_sensor_enable == 0) || (g_sensor_state != 3)) {
    uVar8 = 0xfffffffe;
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Sensor(%d) is closed or state(%d) is error\n",
             "sensor_discover_finish",0xad8,g_sensor_enable,g_sensor_state);
    }
  }
  else {
    if (((sensor_test_force == 0) || (unfinished_sensor_num < 1)) ||
       (g_sensor_backhaul_test_state == 2)) {
      iVar10 = 0;
      if (unfinished_sensor_list != 0) {
        while (iVar10 < unfinished_sensor_num_first) {
          iVar9 = iVar10 * 0x30;
          psVar3 = (short *)(unfinished_sensor_list + iVar9);
          sVar4 = *psVar3;
          if (sVar4 == -1) {
LAB_004e8a70:
            iVar10 = iVar10 + 1;
          }
          else if ((*(int *)(psVar3 + 2) == 2) || (sensor_test_force != 0)) {
            iVar7 = -1;
            iVar2 = -1;
            psVar6 = psVar3;
            for (iVar5 = 0; iVar5 < *(int *)(psVar3 + 4); iVar5 = iVar5 + 1) {
              if (iVar2 == -1) {
                if (*(char *)(psVar6 + 9) != '\0') {
                  if (*(int *)(psVar6 + 10) != 0) {
                    iVar2 = iVar5;
                  }
                  goto LAB_004e89ec;
                }
                cVar1 = *(char *)(psVar6 + 9);
              }
              else {
LAB_004e89ec:
                cVar1 = *(char *)(psVar6 + 9);
              }
              if ((cVar1 == '\0') && (*(int *)(psVar6 + 10) != 0)) {
                iVar7 = iVar5;
              }
              psVar6 = psVar6 + 6;
            }
            if ((iVar2 != -1) || (iVar7 != -1)) {
              psVar6 = (short *)0x0;
              if (iVar2 != -1) {
                psVar6 = psVar3 + iVar2 * 6 + 6;
              }
              goto LAB_004e8a2c;
            }
            apmngr_ap_delete(psVar3,1,1,0x3cf2,1);
            iVar10 = iVar10 + 1;
          }
          else {
            iVar2 = sensor_backhaul_bssid_list_get(sVar4,asStack_fcc,200,&local_fd0);
            if (iVar2 == 0) {
              psVar6 = (short *)0x0;
              if (0 < local_fd0) {
                psVar6 = asStack_fcc;
              }
              sVar4 = *(short *)(unfinished_sensor_list + iVar9);
LAB_004e8a2c:
              sensor_backhaul_set(sVar4,1,psVar6,1);
              _sensor_neighbor_scan_send
                        (*(undefined2 *)(unfinished_sensor_list + iVar9),0,1,0xb4,0,0,0);
              apupd_wtp_add(*(undefined2 *)(unfinished_sensor_list + iVar9));
              goto LAB_004e8a70;
            }
            if (sensor_warning_switch == '\0') {
              iVar10 = iVar10 + 1;
            }
            else {
              printf("[SENSOR_WARNING]%s()/%d sensor_backhaul_bssid_list_get failed for sensor %d\n"
                     ,"sensor_discover_finish",0xaee,
                     (uint)*(ushort *)(unfinished_sensor_list + iVar9));
              iVar10 = iVar10 + 1;
            }
          }
        }
        FUN_00407df0(unfinished_sensor_list);
        unfinished_sensor_list = 0;
      }
      unfinished_sensor_num_first = 0;
      unfinished_sensor_num = 0;
      _sensor_discover_reset(1);
      FUN_00407f30(g_sensor_mngt_mutex);
      return 0;
    }
    uVar8 = 0xfffffff8;
    if (sensor_warning_switch != '\0') {
      printf("[SENSOR_WARNING]%s()/%d Must test backhual first \n","sensor_discover_finish",0xade);
    }
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar8;
}

