// func _sensor_test_apmngr_callback_sensor_destory @ 004f8288 size=992

undefined4 _sensor_test_apmngr_callback_sensor_destory(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  short *psVar9;
  uint *puVar10;
  byte bVar12;
  uint uVar11;
  undefined4 local_810;
  int local_80c;
  undefined4 local_808;
  uint local_804;
  uint local_800 [500];
  uint local_30;
  
  memset(local_800,0,2000);
  local_80c = 0;
  local_810 = 0;
  local_808 = 0;
  local_804 = 0;
  local_30 = sensor_test_db_get_case_num_max();
  if (*(int *)(param_1 + 0x14) == 7) {
    iVar2 = sensor_test_db_get_case_id_list_by_sensor
                      (*(undefined2 *)(param_1 + 0x10),local_800,&local_80c);
    if (iVar2 == -1) {
      if (sensor_test_warning_switch != '\0') {
        printf("[SENSOR_TEST_WARNING]%s()/%d get_case_id_list fail by ap_id=%d\n",
               "_sensor_test_apmngr_callback_sensor_destory",0x874,(uint)*(ushort *)(param_1 + 0x10)
              );
      }
    }
    else {
      puVar10 = local_800;
      for (iVar2 = 0; iVar2 < local_80c; iVar2 = iVar2 + 1) {
        puVar4 = (uint *)FUN_00408450(8,0x87c);
        if (puVar4 == (uint *)0x0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                   "_sensor_test_apmngr_callback_sensor_destory",0x87f);
            return 0xffffffff;
          }
          return 0xffffffff;
        }
        uVar5 = *puVar10;
        puVar4[1] = 0;
        *puVar4 = uVar5;
        uVar5 = sensor_test_db_get_case(*puVar10);
        puVar4[1] = uVar5;
        if (uVar5 == 0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d db_get_case fail\n",
                   "_sensor_test_apmngr_callback_sensor_destory",0x889);
          }
LAB_004f8610:
          FUN_00407df0(puVar4);
          return 0xffffffff;
        }
        bVar12 = *(char *)(uVar5 + 10) - 1;
        uVar11 = (uint)bVar12;
        if (uVar11 == 0) {
          *(undefined1 *)(uVar5 + 10) = 0;
          uVar5 = puVar4[1];
          if (*(int *)(uVar5 + 0x34) != 0) {
            FUN_00407df0();
            *(undefined4 *)(puVar4[1] + 0x34) = 0;
            goto LAB_004f8378;
          }
          uVar11 = *puVar10;
        }
        else {
          iVar3 = FUN_00408450(uVar11 << 2,0x89e);
          if (iVar3 == 0) {
            if (sensor_test_err_switch == '\0') {
              uVar5 = puVar4[1];
            }
            else {
              printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n",
                     "_sensor_test_apmngr_callback_sensor_destory",0x8a1);
              uVar5 = puVar4[1];
            }
            if (uVar5 != 0) {
              sensor_test_db_case_setting_mem_free();
              puVar4[1] = 0;
            }
            goto LAB_004f8610;
          }
          iVar8 = 0;
          for (iVar6 = 0; uVar5 = puVar4[1], iVar6 < (int)(uint)*(byte *)(uVar5 + 10);
              iVar6 = iVar6 + 1) {
            sVar1 = *(short *)(*(int *)(uVar5 + 0x34) + iVar6 * 4);
            if (*(short *)(param_1 + 0x10) != sVar1) {
              if (iVar8 < (int)uVar11) {
                psVar9 = (short *)(iVar3 + iVar8 * 4);
                *psVar9 = sVar1;
                *(undefined1 *)(psVar9 + 1) =
                     *(undefined1 *)(*(int *)(puVar4[1] + 0x34) + iVar6 * 4 + 2);
                iVar8 = iVar8 + 1;
              }
              else {
                iVar8 = iVar8 + 1;
              }
            }
          }
          FUN_00407df0(*(undefined4 *)(uVar5 + 0x34));
          *(int *)(puVar4[1] + 0x34) = iVar3;
          *(byte *)(puVar4[1] + 10) = bVar12;
LAB_004f8378:
          uVar5 = puVar4[1];
          uVar11 = *puVar10;
        }
        sensor_test_db_set_case_join_test_sensor_list
                  (uVar11,*(undefined4 *)(uVar5 + 0x34),*(undefined1 *)(uVar5 + 10));
        FUN_004082d0(0,0xffffffff);
        uVar5 = *puVar10;
        if ((-1 < (int)uVar5) && (uVar5 < local_30)) {
          piVar7 = (int *)(l_sensor_test_ssid_alloc_list + uVar5 * 4);
          if (*piVar7 != 0) {
            local_808 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_808._2_2_);
            local_804 = uVar5;
            FUN_00408570(*(undefined4 *)(*piVar7 + 0xc),_sensor_test_travel_bssid_alloc_hash_cb,
                         &local_808);
            iVar3 = FUN_00407fa0(*(undefined4 *)
                                  (*(int *)(l_sensor_test_ssid_alloc_list + *puVar10 * 4) + 0x10),
                                 param_1 + 0x10);
            if (iVar3 != 0) {
              FUN_00407f40(*(undefined4 *)
                            (*(int *)(l_sensor_test_ssid_alloc_list + *puVar10 * 4) + 0x10),iVar3);
              FUN_00407df0(iVar3);
            }
            sensor_test_sql_del_bssid_alloc_table(*puVar10);
            iVar3 = _sensor_test_build_bssid_alloc_list
                              (*puVar10,*(undefined4 *)
                                         (l_sensor_test_ssid_alloc_list + *puVar10 * 4),&local_810);
            if (iVar3 != 0) {
              sensor_test_sql_add_bssid_alloc_table(*puVar10,iVar3,local_810);
              FUN_00407df0(iVar3);
            }
          }
        }
        FUN_00407f30(0);
        puVar10 = puVar10 + 1;
        sensor_test_db_msg_send(2,puVar4);
      }
    }
  }
  return 0;
}

