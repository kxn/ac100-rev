// func _bind_default_ssid_to_online_ap @ 004e2af4 size=708

undefined4 _bind_default_ssid_to_online_ap(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar11 = 1;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d Input ap_entry or data invalid.\n",
             "_bind_default_ssid_to_online_ap",0x14b);
    }
  }
  else {
    uVar11 = 0;
    if ((*(int *)(param_1 + 0x2ac) - 2U < 2) && (*(int *)(param_1 + 0x24) == 0)) {
      bVar3 = false;
      iVar4 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
      iVar12 = 0;
      do {
        bVar2 = iVar12 < iVar4;
        while( true ) {
          do {
            do {
              while( true ) {
                while( true ) {
                  if (!bVar2) {
                    if (!bVar3) {
                      return 0;
                    }
                    if (*(int *)(param_1 + 0x14) == 1) {
                      local_3c = 0;
                      local_38 = 0;
                      local_40 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_40._2_2_);
                      local_34 = 0;
                      local_30 = 0;
                      wserv_db_sync_wlan_to_re(&local_40);
                      iVar4 = param_2[1];
                    }
                    else {
                      iVar4 = param_2[1];
                    }
                    param_2[1] = iVar4 + 1;
                    return 0;
                  }
                  iVar12 = iVar12 + 1;
                  uVar11 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar12);
                  iVar5 = rdmngr_db_rd_entry_max_ssid_get(uVar11);
                  if (-1 < iVar5) break;
                  if (sensor_err_switch == '\0') {
                    bVar2 = iVar12 < iVar4;
                  }
                  else {
                    printf("[SENSOR_ERROR]%s()/%d rdmngr_db_rd_entry_max_ssid_get() fail, max_ssid=%d.\n"
                           ,"_bind_default_ssid_to_online_ap",0x160,iVar5);
                    bVar2 = iVar12 < iVar4;
                  }
                }
                iVar6 = wserv_db_rd_wlan_binded_other_num(uVar11,*param_2);
                if (iVar6 < iVar5) break;
                if (sensor_err_switch == '\0') {
                  bVar2 = iVar12 < iVar4;
                }
                else {
                  printf("[SENSOR_ERROR]%s()/%d reach max ssid, wlan_cnt=%d, max_ssid=%d.\n",
                         "_bind_default_ssid_to_online_ap",0x166,iVar6,iVar5);
                  bVar2 = iVar12 < iVar4;
                }
              }
              if (sensor_debug_switch == '\0') {
                uVar10 = *param_2;
              }
              else {
                printf("[SENSOR_DEBUG]%s()/%d wlan_cnt=%d, max_ssid=%d.\n",
                       "_bind_default_ssid_to_online_ap",0x169,iVar6,iVar5);
                uVar10 = *param_2;
              }
              iVar5 = uac_wservice_rd_bind(uVar11,uVar10,0);
              bVar2 = iVar12 < iVar4;
            } while (iVar5 != 0);
            if (sensor_debug_switch != '\0') {
              printf("[SENSOR_DEBUG]%s()/%d bind rd_id[%d], wserv_id[%d], vlan_id[%d].\n",
                     "_bind_default_ssid_to_online_ap",0x16c,uVar11,*param_2,0);
            }
            bVar3 = true;
            iVar5 = apmngr_db_get_ap_max();
            uVar1 = *(ushort *)(param_1 + 0x10);
            bVar2 = iVar12 < iVar4;
          } while (iVar5 <= (int)(uint)uVar1);
          uVar9 = uVar1 & 0x1f;
          puVar8 = (uint *)(param_2[2] + (uint)(uVar1 >> 5) * 4);
          uVar7 = *puVar8;
          if (((int)uVar7 >> uVar9 & 1U) == 0) break;
          bVar2 = iVar12 < iVar4;
        }
        *puVar8 = uVar7 | 1 << uVar9;
        param_2[3] = param_2[3] + 1;
      } while( true );
    }
  }
  return uVar11;
}

