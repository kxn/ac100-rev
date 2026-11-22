// func sensor_backhaul_bssid_list_get @ 004e76e8 size=972

/* WARNING: Type propagation algorithm not settling */

undefined4 sensor_backhaul_bssid_list_get(uint param_1,void *param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int local_fe0 [3];
  undefined2 local_fd4;
  byte local_fc8 [4000];
  
  param_1 = param_1 & 0xffff;
  memset(local_fc8,0,4000);
  local_fe0[0] = 0;
  if ((((param_1 < 50000) || (iVar2 = apmngr_db_get_sensor_max(), iVar2 + 50000 <= (int)param_1)) ||
      (param_2 == (void *)0x0)) || ((param_4 == (int *)0x0 || (param_3 < 1)))) {
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_backhaul_bssid_list_get",0x98d);
    }
  }
  else {
    iVar2 = sensor_db_scan_bssid_get(param_1,local_fc8,200,local_fe0);
    if (iVar2 == 0) {
      pbVar5 = local_fc8 + 6;
      *param_4 = 0;
      iVar2 = 0;
      do {
        while( true ) {
          if (local_fe0[0] <= iVar2) {
            iVar2 = *param_4;
            if (iVar2 < 1) {
              return 0;
            }
            iVar6 = 0;
            do {
              iVar6 = iVar6 + 1;
              pvVar4 = param_2;
              for (iVar7 = iVar6; iVar7 < iVar2; iVar7 = iVar7 + 1) {
                bVar1 = 0xc < (ushort)(*(short *)((int)pvVar4 + 0x1c) - 1U);
                if (0xc < (ushort)(*(short *)((int)param_2 + 8) - 1U) == bVar1) {
                  bVar1 = *(char *)((int)param_2 + 6) < *(char *)((int)pvVar4 + 0x1a);
                }
                else if (bVar1) {
                  bVar1 = true;
                  if ((int)*(char *)((int)pvVar4 + 0x1a) < (int)sensor_bh_use_5g_threshold) {
                    bVar1 = (int)*(char *)((int)param_2 + 6) - (int)*(char *)((int)pvVar4 + 0x1a) <=
                            (int)sensor_bh_threshold_diff;
                  }
                }
                else {
                  bVar1 = false;
                  if ((int)*(char *)((int)param_2 + 6) < (int)sensor_bh_use_5g_threshold) {
                    bVar1 = (int)sensor_bh_threshold_diff <
                            (int)*(char *)((int)pvVar4 + 0x1a) - (int)*(char *)((int)param_2 + 6);
                  }
                }
                if (bVar1) {
                  memcpy(local_fe0 + 1,param_2,0x14);
                  memcpy(param_2,(void *)((int)pvVar4 + 0x14),0x14);
                  memcpy((void *)((int)pvVar4 + 0x14),local_fe0 + 1,0x14);
                }
                pvVar4 = (void *)((int)pvVar4 + 0x14);
              }
              param_2 = (void *)((int)param_2 + 0x14);
            } while (iVar6 != iVar2);
            return 0;
          }
          if (sensor_bh_filter_threshold <= (char)*pbVar5) break;
LAB_004e7810:
          iVar2 = iVar2 + 1;
          pbVar5 = pbVar5 + 0x14;
        }
        local_fe0[1] = 0;
        local_fe0[2] = 0;
        local_fd4 = 0;
        memcpy(local_fe0 + 1,pbVar5 + -6,6);
        iVar6 = stats_db_bssid_get(local_fe0 + 1);
        if (iVar6 == 0) {
          uVar3 = rdmngr_db_generate_rd_id(local_fe0[2] & 0xffff,local_fd4._0_1_);
          iVar6 = wserv_db_rd_get_wserv_id(uVar3,(undefined1)local_fd4);
          if ((iVar6 != -1) && (iVar6 == g_backhaul_wserv_id)) {
            memcpy((void *)((int)param_2 + *param_4 * 0x14),pbVar5 + -6,0x14);
            iVar6 = *param_4;
            *param_4 = iVar6 + 1;
            if (param_3 < iVar6 + 1) {
              if (sensor_warning_switch == '\0') {
                return 0xffffffff;
              }
              printf("[SENSOR_WARNING]%s()/%d list size(%d) is not enough for sensor %d.\n",
                     "sensor_backhaul_bssid_list_get",0x9a1,param_3,param_1);
              return 0xffffffff;
            }
          }
          goto LAB_004e7810;
        }
        if (sensor_warning_switch == '\0') goto LAB_004e7810;
        iVar6 = iVar2 * 0x14;
        iVar2 = iVar2 + 1;
        pbVar5 = pbVar5 + 0x14;
        printf("[SENSOR_WARNING]%s()/%d Find bssid[[%02x:%02x:%02x:%02x:%02x:%02x]] failed\n",
               "_sensor_wserv_id_get_by_bssid",0x603,(uint)local_fc8[iVar6],
               (uint)local_fc8[iVar6 + 1],(uint)local_fc8[iVar6 + 2],(uint)local_fc8[iVar6 + 3],
               (uint)local_fc8[iVar6 + 4],(uint)local_fc8[iVar6 + 5]);
      } while( true );
    }
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d sensor_db_scan_bssid_get of sensor %d failed\n",
             "sensor_backhaul_bssid_list_get",0x992,param_1);
    }
  }
  return 0xffffffff;
}

