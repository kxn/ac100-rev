// func _sensor_test_generate_ssid_info_to_deploy @ 004eb6f8 size=1428

undefined4 _sensor_test_generate_ssid_info_to_deploy(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined1 *__src;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined1 auStack_1500 [300];
  undefined4 local_13d4;
  char acStack_13d0 [58];
  int local_1396;
  undefined1 auStack_1386 [48];
  undefined1 auStack_1356 [94];
  short local_12f8;
  short local_12f6;
  ushort local_12f4 [2];
  undefined1 auStack_12f0 [12];
  undefined1 auStack_12e4 [8];
  int local_12dc [1195];
  int local_30;
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_generate_ssid_info_to_deploy ENTER,sensor_id=%d\n"
           ,"_sensor_test_generate_ssid_info_to_deploy",0x3bb,param_3);
  }
  memset(&local_12f8,0,0x12c8);
  memset(auStack_1500,0,0x205);
  if (((param_1 == (int *)0x0) || (param_2 == 0)) || (*(int *)(param_2 + 8) == 0)) {
    if (sensor_test_warning_switch != '\0') {
      pcVar6 = "[SENSOR_TEST_WARNING]%s()/%d input invalid\n";
      uVar9 = 0x3cc;
LAB_004ebbe4:
      printf(pcVar6,"_sensor_test_generate_ssid_info_to_deploy",uVar9);
    }
LAB_004eb904:
    if (sensor_test_warning_switch == '\0') {
      iVar11 = param_1[1];
    }
    else {
      printf("[SENSOR_TEST_WARNING]%s()/%d _sensor_test_generate_ssid_info_to_deploy fail EXIT\n",
             "_sensor_test_generate_ssid_info_to_deploy",0x452);
      iVar11 = param_1[1];
    }
    iVar13 = 0;
    if (iVar11 != 0) {
      while (iVar13 < *param_1) {
        iVar11 = iVar13 * 0x254;
        iVar13 = iVar13 + 1;
        if (*(int *)(param_1[1] + iVar11 + 0x250) != 0) {
          FUN_00407df0();
          *(undefined4 *)(param_1[1] + iVar11 + 0x250) = 0;
        }
      }
      FUN_00407df0();
      param_1[1] = 0;
      *param_1 = 0;
    }
    uVar9 = 0xffffffff;
  }
  else {
    if (*(int *)(param_2 + 4) < 1) {
      if (sensor_test_warning_switch == '\0') {
        return 0;
      }
      pcVar6 = "[SENSOR_TEST_WARNING]%s()/%d no ssid to deploy in ssid_alloc_list\n";
      uVar7 = 0x3d2;
    }
    else {
      local_12f8 = (short)param_3;
      iVar13 = 0;
      iVar11 = 0;
      memset(auStack_12f0,0,0x12c0);
      while (iVar13 < *(int *)(param_2 + 4)) {
        for (iVar15 = FUN_004081b0(*(int *)(param_2 + 8) + iVar13 * 0x14 + 8); iVar15 != 0;
            iVar15 = FUN_00408680(iVar15)) {
          if (sensor_test_debug_switch == '\0') {
            cVar1 = *(char *)(iVar15 + 0x22);
          }
          else {
            printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_check_bssid_allocated_cb ENTER\n",
                   "_sensor_test_check_bssid_allocated_cb",0x390);
            cVar1 = *(char *)(iVar15 + 0x22);
          }
          if ((cVar1 == '\x02') && (*(short *)(iVar15 + 0x20) == local_12f8)) {
            memcpy(auStack_12e4 + (uint)local_12f4[0] * 0x18,(void *)(iVar15 + 0xc),6);
            uVar2 = (uint)local_12f4[0];
            local_12f4[0] = (ushort)(uVar2 + 1);
            local_12f6 = 1;
            *(undefined4 *)(local_12f4 + (uVar2 + 1) * 0xc) = *(undefined4 *)(iVar15 + 0x14);
            if (sensor_test_debug_switch != '\0') {
              printf("[SENSOR_TEST_DEBUG]%s()/%d found and deploy\n",
                     "_sensor_test_check_bssid_allocated_cb",0x3a0);
            }
          }
        }
        if (local_12f6 == 1) {
          iVar11 = iVar11 + 1;
          local_12f6 = 0;
          iVar13 = iVar13 + 1;
        }
        else {
          iVar13 = iVar13 + 1;
        }
      }
      if (sensor_test_debug_switch != '\0') {
        printf("[SENSOR_TEST_DEBUG]%s()/%d bssid_cnt_to_deploy=%d, ssid_cnt_to_deploy=%d\n",
               "_sensor_test_generate_ssid_info_to_deploy",0x3ed,(uint)local_12f4[0],iVar11);
      }
      *param_1 = iVar11;
      if (iVar11 != 0) {
        param_1[1] = 0;
        pvVar3 = (void *)FUN_00408450(iVar11 * 0x254,0x3f8);
        param_1[1] = (int)pvVar3;
        if (pvVar3 != (void *)0x0) {
          iVar15 = 0;
          memset(pvVar3,0,*param_1 * 0x254);
          iVar13 = 0;
          iVar11 = 0;
          do {
            if (*param_1 <= iVar15) {
              return 0;
            }
            iVar5 = 0;
            iVar12 = 0;
            puVar10 = (undefined4 *)(param_1[1] + iVar15 * 0x254);
            iVar4 = iVar11;
            iVar14 = iVar13;
            while (iVar8 = iVar13, local_30 = iVar11, iVar4 < (int)(uint)local_12f4[0]) {
              iVar8 = iVar4 + 1;
              if (iVar4 == iVar11) {
                iVar12 = 1;
                iVar4 = iVar4 + 1;
                iVar5 = iVar5 + 0x18;
                iVar14 = *(int *)(local_12f4 + iVar8 * 0xc);
              }
              else {
                iVar8 = *(int *)((int)local_12dc + iVar5 + iVar11 * 0x18);
                iVar5 = iVar5 + 0x18;
                local_30 = iVar4;
                if (iVar14 != iVar8) break;
                iVar12 = iVar12 + 1;
                iVar4 = iVar4 + 1;
              }
            }
            iVar13 = iVar8;
            puVar10[2] = iVar12;
            puVar10[0x94] = 0;
            if (iVar12 != 0) {
              pvVar3 = (void *)FUN_00408450(iVar12 * 0x18,0x422);
              puVar10[0x94] = pvVar3;
              if (pvVar3 == (void *)0x0) {
                if (sensor_test_err_switch == '\0') goto LAB_004eb904;
                pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
                uVar9 = 0x425;
                goto LAB_004ebbe4;
              }
              memset(pvVar3,0,iVar12 * 0x18);
              iVar4 = 0;
              for (iVar5 = 0; iVar5 < iVar12; iVar5 = iVar5 + 1) {
                iVar8 = iVar4 + iVar11 * 0x18;
                pvVar3 = (void *)(puVar10[0x94] + iVar4);
                iVar4 = iVar4 + 0x18;
                memcpy(pvVar3,auStack_12f0 + iVar8,0x18);
              }
            }
            memset(auStack_1500,0,0x205);
            if (iVar14 != -1) {
              wserv_db_get_entry_by_id(iVar14,auStack_1500);
              puVar10[1] = local_1396;
              *puVar10 = local_13d4;
              if ((local_1396 == 1) || (local_1396 == 4)) {
                pvVar3 = (void *)((int)puVar10 + 0x1d6);
                __src = auStack_1386;
LAB_004ebba0:
                memcpy(pvVar3,__src,0x41);
              }
              else {
                pvVar3 = (void *)((int)puVar10 + 0x5e);
                if (local_1396 == 2) {
                  __src = auStack_1356;
                  goto LAB_004ebba0;
                }
              }
              strncpy((char *)(puVar10 + 3),acStack_13d0,0x32);
            }
            iVar15 = iVar15 + 1;
            iVar11 = local_30;
          } while( true );
        }
        if (sensor_test_err_switch != '\0') {
          pcVar6 = "[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n";
          uVar9 = 0x3fb;
          goto LAB_004ebbe4;
        }
        goto LAB_004eb904;
      }
      if (sensor_test_debug_switch == '\0') {
        return 0;
      }
      pcVar6 = "[SENSOR_TEST_DEBUG]%s()/%d no ssid to deploy\n";
      uVar7 = 0x3f3;
    }
    uVar9 = 0;
    printf(pcVar6,"_sensor_test_generate_ssid_info_to_deploy",uVar7);
  }
  return uVar9;
}

