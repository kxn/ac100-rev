// func _sensor_test_ssid_alloc_list_init @ 004f8668 size=1440

undefined4 _sensor_test_ssid_alloc_list_init(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined2 *puVar7;
  void *pvVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int local_30 [2];
  
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d _sensor_test_ssid_alloc_list_init ENTER,case_id=%d\n",
           "_sensor_test_ssid_alloc_list_init",0x12d5,param_1);
  }
  local_30[0] = 0;
  uVar3 = sensor_test_db_get_case_num_max();
  if ((((int)param_1 < 0) || (uVar3 <= param_1)) || (param_2 == 0)) {
    uVar11 = 0xffffffff;
    if (sensor_test_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d input invalid\n";
    uVar10 = 0x12e3;
LAB_004f897c:
    printf(pcVar9,"_sensor_test_ssid_alloc_list_init",uVar10);
    return uVar11;
  }
  iVar4 = FUN_00407fe0(param_2);
  if (iVar4 < 1) {
    uVar11 = 0;
    if (sensor_test_warning_switch == '\0') {
      return 0;
    }
    pcVar9 = "[SENSOR_TEST_WARNING]%s()/%d des_bssid_cnt <= 0\n";
    uVar10 = 0x12ea;
    goto LAB_004f897c;
  }
  puVar5 = (undefined4 *)sensor_test_db_get_ssid_info_list_by_case_id(param_1,local_30);
  if ((puVar5 == (undefined4 *)0x0) || (local_30[0] < 1)) {
    uVar11 = 0;
    if (sensor_test_warning_switch == '\0') {
      return 0;
    }
    pcVar9 = "[SENSOR_TEST_WARNING]%s()/%d ssid_cnt <= 0 or NULL == ssid_info_list\n";
    uVar10 = 0x12f2;
    goto LAB_004f897c;
  }
  iVar4 = param_1 * 4;
  puVar12 = (undefined4 *)(l_sensor_test_ssid_alloc_list + iVar4);
  *puVar12 = 0;
  uVar11 = FUN_00408450(0x14,0x12f8);
  *puVar12 = uVar11;
  piVar13 = (int *)(l_sensor_test_ssid_alloc_list + iVar4);
  if ((void *)*piVar13 == (void *)0x0) {
    if (sensor_test_err_switch == '\0') goto LAB_004f8b24;
    uVar11 = 0x12fb;
LAB_004f8be4:
    printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","_sensor_test_ssid_alloc_list_init",uVar11
          );
  }
  else {
    memset((void *)*piVar13,0,0x14);
    *(undefined4 *)(*piVar13 + 0xc) = 0;
    iVar14 = *piVar13;
    uVar11 = FUN_004080a0(_sensor_test_bssid_alloc_hash_obj,_sensor_test_bssid_alloc_hash_key,
                          _sensor_test_bssid_alloc_hash_cmp,1000);
    *(undefined4 *)(iVar14 + 0xc) = uVar11;
    piVar13 = (int *)(l_sensor_test_ssid_alloc_list + iVar4);
    iVar14 = *piVar13;
    if (*(int *)(iVar14 + 0xc) == 0) {
      if (sensor_test_err_switch == '\0') goto LAB_004f8b24;
      pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d test_case_id=%d \'s bssid_alloc_hash create fail\n";
      uVar11 = 0x1307;
    }
    else {
      *(undefined4 *)(iVar14 + 0x10) = 0;
      iVar14 = *piVar13;
      uVar11 = FUN_004080a0(_sensor_test_sensor_alloc_hash_obj,_sensor_test_sensor_alloc_hash_key,
                            _sensor_test_sensor_alloc_hash_cmp,100);
      *(undefined4 *)(iVar14 + 0x10) = uVar11;
      piVar13 = (int *)(l_sensor_test_ssid_alloc_list + iVar4);
      if (((uint *)*piVar13)[4] != 0) {
        *(uint *)*piVar13 = param_1;
        *(int *)(*piVar13 + 4) = local_30[0];
        *(undefined4 *)(*piVar13 + 8) = 0;
        iVar14 = *piVar13;
        uVar11 = FUN_00408450(local_30[0] * 0x14,0x1316);
        *(undefined4 *)(iVar14 + 8) = uVar11;
        pvVar8 = *(void **)(*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 8);
        if (pvVar8 != (void *)0x0) {
          memset(pvVar8,0,local_30[0] * 0x14);
          puVar12 = puVar5;
          for (iVar14 = 0; iVar14 < local_30[0]; iVar14 = iVar14 + 1) {
            iVar6 = iVar14 * 0x14;
            piVar13 = (int *)(l_sensor_test_ssid_alloc_list + iVar4);
            *(undefined4 *)(*(int *)(*piVar13 + 8) + iVar6) = *puVar12;
            puVar1 = puVar12 + 1;
            puVar12 = puVar12 + 0x88;
            *(undefined4 *)(*(int *)(*piVar13 + 8) + iVar6 + 4) = *puVar1;
            FUN_0051ad88(*(int *)(*piVar13 + 8) + iVar6 + 8);
          }
          iVar14 = FUN_004081b0(param_2);
          do {
            if (iVar14 == 0) {
              FUN_00407df0(puVar5);
              return 0;
            }
            for (iVar6 = 0; iVar6 < local_30[0]; iVar6 = iVar6 + 1) {
              if (*(int *)(iVar14 + 0x14) ==
                  *(int *)(*(int *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 8) +
                          iVar6 * 0x14)) {
                pvVar8 = (void *)FUN_00408450(0x24,0x1331);
                if (pvVar8 == (void *)0x0) {
                  if (sensor_test_err_switch != '\0') {
                    printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail, continue\n",
                           "_sensor_test_ssid_alloc_list_init",0x1334);
                  }
                }
                else {
                  memset(pvVar8,0,0x24);
                  memcpy((void *)((int)pvVar8 + 0xc),(void *)(iVar14 + 0xc),6);
                  *(undefined4 *)((int)pvVar8 + 0x14) = *(undefined4 *)(iVar14 + 0x14);
                  *(undefined4 *)((int)pvVar8 + 0x18) = *(undefined4 *)(iVar14 + 0x18);
                  *(undefined4 *)((int)pvVar8 + 0x1c) = *(undefined4 *)(iVar14 + 0x1c);
                  *(undefined2 *)((int)pvVar8 + 0x20) = *(undefined2 *)(iVar14 + 0x20);
                  *(undefined1 *)((int)pvVar8 + 0x22) = *(undefined1 *)(iVar14 + 0x22);
                  *(undefined1 *)((int)pvVar8 + 0x23) = *(undefined1 *)(iVar14 + 0x23);
                  FUN_00408380(*(undefined4 *)
                                (*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 0xc),pvVar8);
                  FUN_004086b0(*(int *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 8) +
                               iVar6 * 0x14 + 8,pvVar8);
                  iVar6 = FUN_00407fa0(*(undefined4 *)
                                        (*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 0x10),
                                       (int)pvVar8 + 0x20);
                  if (iVar6 == 0) {
                    puVar7 = (undefined2 *)FUN_00408450(4,0x1349);
                    if (puVar7 != (undefined2 *)0x0) {
                      uVar2 = *(undefined2 *)((int)pvVar8 + 0x20);
                      puVar7[1] = 1;
                      *puVar7 = uVar2;
                      FUN_00408380(*(undefined4 *)
                                    (*(int *)(l_sensor_test_ssid_alloc_list + iVar4) + 0x10),puVar7)
                      ;
                    }
                  }
                  else {
                    *(short *)(iVar6 + 2) = *(short *)(iVar6 + 2) + 1;
                  }
                }
                break;
              }
            }
            iVar14 = FUN_00408680(iVar14);
          } while( true );
        }
        if (sensor_test_err_switch == '\0') goto LAB_004f8b24;
        uVar11 = 0x1319;
        goto LAB_004f8be4;
      }
      if (sensor_test_err_switch == '\0') goto LAB_004f8b24;
      pcVar9 = "[SENSOR_TEST_ERROR]%s()/%d test_case_id=%d \'s sensor_alloc_hash create fail\n";
      uVar11 = 0x130f;
    }
    printf(pcVar9,"_sensor_test_ssid_alloc_list_init",uVar11,param_1);
  }
LAB_004f8b24:
  if (sensor_test_err_switch != '\0') {
    printf("[SENSOR_TEST_ERROR]%s()/%d _sensor_test_ssid_alloc_list_init fail EXIT\n",
           "_sensor_test_ssid_alloc_list_init",0x135e);
  }
  FUN_00407df0(puVar5);
  _sensor_test_ssid_alloc_list_mem_free(*(undefined4 *)(l_sensor_test_ssid_alloc_list + iVar4));
  *(undefined4 *)(l_sensor_test_ssid_alloc_list + iVar4) = 0;
  return 0xffffffff;
}

