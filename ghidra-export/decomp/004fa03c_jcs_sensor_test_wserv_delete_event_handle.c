// func jcs_sensor_test_wserv_delete_event_handle @ 004fa03c size=1316

void jcs_sensor_test_wserv_delete_event_handle(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined8 uVar16;
  undefined4 local_9a8;
  undefined4 local_9a4;
  undefined4 local_9a0;
  undefined4 local_99c;
  int local_998;
  int local_994;
  int local_990 [100];
  uint local_800 [500];
  int local_30;
  uint local_2c;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d wserv_delete_event_handle ENTER\n",
           "jcs_sensor_test_wserv_delete_event_handle",0x1ba8);
  }
  memset(local_990,0,400);
  memset(local_800,0,2000);
  local_9a8 = 0;
  local_9a4 = 0;
  local_9a0 = 0;
  local_99c = 0;
  local_998 = 0;
  local_994 = 0;
  local_2c = sensor_test_db_get_case_num_max();
  iVar2 = json_object_object_get(param_1,"serv_id");
  if (((iVar2 != 0) && (iVar3 = json_object_get_type(iVar2), iVar3 == 5)) &&
     (iVar3 = json_object_array_length(iVar2), 0 < iVar3)) {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 5) {
      piVar12 = local_990;
      for (iVar3 = 0; iVar4 = json_object_array_length(iVar2), iVar3 < iVar4; iVar3 = iVar3 + 1) {
        if (iVar3 == 100) goto LAB_004fa240;
        iVar4 = json_object_array_get_idx(iVar2,iVar3);
        if (iVar4 == 0) {
LAB_004fa208:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "jcs_sensor_test_wserv_delete_event_handle",0x1bbd);
          }
          *piVar12 = -1;
        }
        else {
          iVar5 = json_object_get_type(iVar4);
          if (iVar5 == 3) {
            iVar4 = json_object_get_int(iVar4);
          }
          else {
            iVar5 = json_object_get_type();
            if (iVar5 != 2) goto LAB_004fa208;
            uVar16 = json_object_get_double(iVar4);
            iVar4 = __fixdfsi((int)((ulonglong)uVar16 >> 0x20),(int)uVar16);
          }
          *piVar12 = iVar4;
        }
        piVar12 = piVar12 + 1;
      }
      if (0 < iVar3) {
LAB_004fa240:
        uVar10 = 0;
        FUN_004082d0(0,0xffffffff);
        uVar13 = 0;
        while (uVar10 != local_2c) {
          iVar4 = uVar10 * 4;
          iVar2 = *(int *)(l_sensor_test_ssid_alloc_list + iVar4);
          uVar14 = uVar13;
          if (iVar2 == 0) {
LAB_004fa434:
            uVar10 = uVar10 + 1;
            uVar13 = uVar14;
          }
          else if (*(int *)(iVar2 + 8) == 0) {
            uVar10 = uVar10 + 1;
          }
          else if (*(int *)(iVar2 + 4) == 0) {
            uVar10 = uVar10 + 1;
          }
          else {
            piVar12 = local_990;
            local_30 = 0;
            bVar1 = false;
            do {
              iVar2 = 0;
              while( true ) {
                piVar9 = (int *)(l_sensor_test_ssid_alloc_list + iVar4);
                iVar5 = *piVar9;
                if (*(int *)(iVar5 + 4) <= iVar2) break;
                iVar15 = iVar2 * 0x14;
                piVar8 = (int *)(*(int *)(iVar5 + 8) + iVar15);
                if (*piVar8 == *piVar12) {
                  *piVar8 = -1;
                  *(undefined4 *)(*(int *)(*piVar9 + 8) + iVar15 + 4) = 0;
                  while (iVar5 = FUN_004081b0(*(int *)(*(int *)(l_sensor_test_ssid_alloc_list +
                                                               iVar4) + 8) + iVar15 + 8), iVar5 != 0
                        ) {
                    FUN_00408500(iVar5);
                    sensor_test_db_del_bssid_to_result_list(uVar10,iVar5 + 0xc);
                    iVar6 = FUN_00407fa0(*(undefined4 *)
                                          (*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 0x10),
                                         iVar5 + 0x20);
                    if (iVar6 != 0) {
                      *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + -1;
                    }
                    FUN_00407f40(*(undefined4 *)
                                  (*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 0xc),iVar5);
                    FUN_00407df0(iVar5);
                  }
                  iVar2 = iVar2 + 1;
                  FUN_0051ad88(*(int *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 8) +
                               iVar15 + 8);
                  bVar1 = true;
                }
                else {
                  iVar2 = iVar2 + 1;
                }
              }
              piVar12 = piVar12 + 1;
              local_30 = local_30 + 1;
            } while (local_30 < iVar3);
            if (bVar1) {
              if (uVar13 < local_2c) {
                uVar14 = uVar13 + 1;
                local_800[uVar13] = uVar10;
              }
              sensor_test_sql_del_bssid_alloc_table(uVar10);
              iVar2 = _sensor_test_build_bssid_alloc_list
                                (uVar10,*(undefined4 *)(l_sensor_test_ssid_alloc_list + iVar4),
                                 &local_9a8);
              if (iVar2 != 0) {
                sensor_test_sql_add_bssid_alloc_table(uVar10,iVar2,local_9a8);
                FUN_00407df0(iVar2);
              }
              goto LAB_004fa434;
            }
            uVar10 = uVar10 + 1;
          }
        }
        puVar11 = local_800;
        FUN_00407f30(0);
        iVar2 = 0;
        sensor_test_db_wserv_id_delete(local_990,iVar3,local_800,uVar13);
        while (iVar2 < (int)uVar13) {
          local_9a4 = 0;
          local_9a0 = 0;
          local_99c = 0;
          local_998 = 0;
          local_994 = 0;
          iVar3 = sensor_test_db_get_case_brief_info(*puVar11,&local_9a4);
          if (((iVar3 == 0) && (local_99c._2_1_ != '\0')) && (iVar3 = 0, local_998 != 0)) {
            do {
              while( true ) {
                if ((int)(uint)local_99c._2_1_ <= iVar3) goto LAB_004fa4ec;
                puVar7 = (undefined2 *)(local_998 + iVar3 * 4);
                if (*(char *)(puVar7 + 1) == '\0') break;
                iVar3 = iVar3 + 1;
                _sensor_test_sync_case_config_to_sensor(*puVar7,*puVar11,2);
              }
              iVar3 = iVar3 + 1;
            } while( true );
          }
LAB_004fa4ec:
          if (local_998 != 0) {
            FUN_00407df0();
            local_998 = 0;
          }
          iVar2 = iVar2 + 1;
          if (local_994 != 0) {
            FUN_00407df0();
          }
          puVar11 = puVar11 + 1;
        }
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (((iVar3 != 4) || (iVar2 = json_object_object_length(iVar2), iVar2 != 0)) &&
         (jcs_err_switch != 0)) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "jcs_sensor_test_wserv_delete_event_handle",0x1bbd);
      }
    }
  }
  return;
}

