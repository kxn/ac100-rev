// func sensor_test_db_wserv_id_delete @ 00504638 size=672

undefined4 sensor_test_db_wserv_id_delete(int *param_1,int param_2,uint *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  void *__s;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar2 = 0xffffffff;
  if ((((param_1 != (int *)0x0) && (param_3 != (uint *)0x0)) && (0 < param_2)) &&
     (((0 < (int)param_4 && (param_2 < 0x65)) && (param_4 <= g_sensor_test_case_num_max)))) {
    uVar9 = 0;
    FUN_004082d0(l_sensor_test_db_mutex,0xffffffff);
    do {
      uVar3 = *param_3;
      if (((-1 < (int)uVar3) && (uVar3 <= g_sensor_test_case_num_max)) &&
         ((iVar4 = *(int *)(l_sensor_test_case_list + uVar3 * 4), iVar4 != 0 &&
          (((iVar4 = *(int *)(iVar4 + 4), iVar4 != 0 &&
            (uVar3 = (uint)*(byte *)(iVar4 + 0xb), uVar3 != 0)) && (*(int *)(iVar4 + 0x38) != 0)))))
         ) {
        __s = (void *)FUN_00408450(uVar3 * 0x220,0x125f);
        if (__s == (void *)0x0) {
          if (sensor_test_err_switch != '\0') {
            printf("[SENSOR_TEST_ERROR]%s()/%d mem malloc fail\n","sensor_test_db_wserv_id_delete",
                   0x1262);
          }
        }
        else {
          iVar8 = 0;
          iVar4 = 0;
          memset(__s,0,uVar3 * 0x220);
          do {
            iVar1 = l_sensor_test_case_list;
            iVar7 = *(int *)(*(int *)(*(int *)(l_sensor_test_case_list + *param_3 * 4) + 4) + 0x38);
            iVar5 = 0;
            piVar6 = param_1;
            do {
              iVar5 = iVar5 + 1;
              if (*(int *)(iVar7 + iVar4 * 0x220) == *piVar6) goto LAB_005047b4;
              piVar6 = piVar6 + 1;
            } while (iVar5 < param_2);
            iVar5 = iVar8 * 0x220;
            iVar8 = iVar8 + 1;
            memcpy((void *)((int)__s + iVar5),(void *)(iVar7 + iVar4 * 0x220),0x220);
LAB_005047b4:
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)uVar3);
          FUN_00407df0(*(undefined4 *)(*(int *)(*(int *)(iVar1 + *param_3 * 4) + 4) + 0x38));
          iVar4 = l_sensor_test_case_list;
          *(void **)(*(int *)(*(int *)(l_sensor_test_case_list + *param_3 * 4) + 4) + 0x38) = __s;
          *(char *)(*(int *)(*(int *)(iVar4 + *param_3 * 4) + 4) + 0xb) = (char)iVar8;
          iVar8 = *(int *)(*(int *)(iVar4 + *param_3 * 4) + 4);
          *(char *)(iVar8 + 8) = *(char *)(iVar8 + 8) + '\x01';
          uVar2 = _sensor_test_db_deep_copy_test_case(*(undefined4 *)(iVar4 + *param_3 * 4));
          sensor_test_db_msg_send(2,uVar2);
        }
      }
      uVar9 = uVar9 + 1;
      param_3 = param_3 + 1;
    } while (uVar9 != param_4);
    FUN_00407f30(l_sensor_test_db_mutex);
    uVar2 = 0;
  }
  return uVar2;
}

