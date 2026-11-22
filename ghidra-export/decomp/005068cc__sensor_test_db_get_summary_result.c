// func _sensor_test_db_get_summary_result @ 005068cc size=940

undefined4
_sensor_test_db_get_summary_result
          (int param_1,uint param_2,short param_3,uint param_4,uint param_5,undefined4 *param_6,
          short *param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (param_6 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if (param_7 == (short *)0x0) {
    return 0xffffffff;
  }
  iVar2 = sensor_test_db_is_test_case_id_legal();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (8 < param_2) {
    return 0xffffffff;
  }
  FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
  if (param_3 == -1) {
    iVar2 = _sensor_test_db_get_config_cnt
                      (*(undefined4 *)(l_sensor_test_case_list + param_1 * 4),param_2);
    if (iVar2 == 0) {
      FUN_00407f30(l_sensor_test_db_mutex);
      return 0xffffffff;
    }
    iVar9 = 0;
    for (iVar4 = FUN_004081b0(l_sensor_test_result_list + param_1 * 0xc); iVar4 != 0;
        iVar4 = FUN_00408680(iVar4)) {
      uVar3 = 0;
LAB_00506b88:
      if ((int)uVar3 < iVar2) {
        iVar5 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                          (iVar4,param_2 & 0xff,uVar3 & 0xffff);
        if (iVar5 == 0) {
          uVar3 = uVar3 + 1;
        }
        else {
          for (iVar5 = FUN_004081b0(iVar5); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
            bVar1 = *(uint *)(iVar5 + 0x2c) < param_5;
            if (param_4 <= *(uint *)(iVar5 + 0x2c)) {
              if (bVar1) {
                iVar9 = iVar9 + 1;
                if (*(int *)(iVar5 + 0x10) == 0) {
                  iVar8 = sensor_test_db_is_test_result_slow
                                    (*(undefined1 *)(iVar5 + 0x32),*(undefined4 *)(iVar5 + 0xc));
                  if (iVar8 == 1) {
                    param_7[2] = param_7[2] + 1;
                  }
                  else {
                    *param_7 = *param_7 + 1;
                  }
                }
                else {
                  param_7[1] = param_7[1] + 1;
                }
                uVar7 = *(uint *)(iVar5 + 0x2c);
              }
              else {
                uVar7 = *(uint *)(iVar5 + 0x2c);
              }
              bVar1 = uVar7 < param_5;
            }
            if (!bVar1) {
              uVar3 = uVar3 + 1;
              goto LAB_00506b88;
            }
          }
          uVar3 = uVar3 + 1;
        }
        goto LAB_00506b88;
      }
    }
  }
  else {
    iVar9 = 0;
    iVar2 = FUN_004081b0(l_sensor_test_result_list + param_1 * 0xc);
    for (; iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      uVar3 = _sensor_test_db_get_idx_of_serindex
                        (*(int *)(*(int *)(l_sensor_test_case_list + param_1 * 4) + 4) + 0x3c,
                         param_2,param_3);
      if (uVar3 == 0xffffffff) {
        if (sensor_test_err_switch != '\0') {
          printf("[SENSOR_TEST_ERROR]%s()/%d get index of serindex fail\n",
                 "_sensor_test_db_get_summary_result",0xcdf);
        }
        FUN_00407f30(l_sensor_test_db_mutex);
        return 0xffffffff;
      }
      iVar4 = _sensor_test_db_get_sepcified_list_from_bssid_result_node
                        (iVar2,param_2 & 0xff,uVar3 & 0xffff);
      if (iVar4 != 0) {
        for (iVar4 = FUN_004081b0(iVar4); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
          bVar1 = *(uint *)(iVar4 + 0x2c) < param_5;
          if (param_4 <= *(uint *)(iVar4 + 0x2c)) {
            if (bVar1) {
              iVar9 = iVar9 + 1;
              if (*(int *)(iVar4 + 0x10) == 0) {
                iVar5 = sensor_test_db_is_test_result_slow
                                  (*(undefined1 *)(iVar4 + 0x32),*(undefined4 *)(iVar4 + 0xc));
                if (iVar5 == 1) {
                  param_7[2] = param_7[2] + 1;
                }
                else {
                  *param_7 = *param_7 + 1;
                }
              }
              else {
                param_7[1] = param_7[1] + 1;
              }
              uVar3 = *(uint *)(iVar4 + 0x2c);
            }
            else {
              uVar3 = *(uint *)(iVar4 + 0x2c);
            }
            bVar1 = uVar3 < param_5;
          }
          if (!bVar1) break;
        }
      }
    }
  }
  uVar6 = 0xffffffff;
  if (iVar9 != 0) {
    if (param_7[1] == 0) {
      if (param_7[2] == 0) {
        *param_6 = 0;
        goto LAB_00506a80;
      }
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if (*param_7 == 0) {
        if (param_7[2] == 0) {
          uVar6 = 1;
        }
        else {
          uVar6 = 3;
        }
      }
    }
  }
  *param_6 = uVar6;
LAB_00506a80:
  FUN_00407f30(l_sensor_test_db_mutex);
  return 0;
}

