// func sensor_add @ 004e7ab4 size=1064

undefined4 sensor_add(ushort *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  void *__s;
  ushort *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_300 [20];
  int local_2ec;
  int local_2c4;
  
  memset(auStack_300,0,0x2d8);
  if ((param_1 == (ushort *)0x0) || (param_2 < 1)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[SENSOR_ERROR]%s()/%d Input error\n","sensor_add",0x9b4);
    return 0xffffffff;
  }
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if ((g_sensor_enable == 0) || (1 < g_sensor_state - 1U)) {
    uVar7 = 0xfffffffe;
    if (sensor_warning_switch == '\0') goto LAB_004e7b54;
    pcVar5 = "[SENSOR_WARNING]%s()/%d State(%d+%d) is error\n";
    uVar6 = 0x9ba;
    iVar2 = g_sensor_enable;
    param_2 = g_sensor_state;
  }
  else {
    iVar2 = apmngr_db_get_firm_sensor_max();
    if (param_2 <= iVar2) {
      iVar2 = apmngr_db_firm_sensor_num_get();
      iVar3 = apmngr_db_get_firm_sensor_max();
      if (iVar2 + param_2 <= iVar3) {
        unfinished_sensor_list = (void *)FUN_00408450(param_2 * 0x30,0x9c4);
        if (unfinished_sensor_list == (void *)0x0) {
          uVar7 = 0xffffffff;
          if (sensor_err_switch == '\0') goto LAB_004e7b54;
          pcVar5 = "[SENSOR_ERROR]%s()/%d Malloc failed\n";
          uVar6 = 0x9c7;
LAB_004e7e08:
          printf(pcVar5,"sensor_add",uVar6);
        }
        else {
          memset(unfinished_sensor_list,0,param_2 * 0x30);
          current_backhaul_test_operation_id = (void *)FUN_00408450(param_2 << 2,0x9cd);
          if (current_backhaul_test_operation_id == (void *)0x0) {
            if (sensor_err_switch != '\0') {
              uVar7 = 0x9d0;
LAB_004e7e68:
              printf("[SENSOR_ERROR]%s()/%d Malloc failed\n","sensor_add",uVar7);
            }
          }
          else {
            memset(current_backhaul_test_operation_id,0,param_2 << 2);
            iVar2 = apmngr_db_get_sensor_max();
            __s = (void *)FUN_00408450(iVar2 << 1,0x9da);
            unfinished_sensor_id_map = __s;
            if (__s != (void *)0x0) {
              iVar2 = apmngr_db_get_sensor_max();
              memset(__s,-1,iVar2 << 1);
              unfinished_sensor_num = 0;
              iVar2 = 0;
              backhaul_test_finished_sensor_num = 0;
              do {
                iVar3 = apmngr_db_entry_get_by_id(*param_1,auStack_300);
                if ((((iVar3 == 0) && (local_2ec == 7)) && (local_2c4 == 0)) &&
                   (iVar3 = apmngr_ap_firm(param_1,1,0,1), iVar3 == 0)) {
                  puVar4 = (ushort *)((int)unfinished_sensor_list + unfinished_sensor_num * 0x30);
                  uVar1 = *param_1;
                  puVar4[2] = 0;
                  puVar4[3] = 0;
                  *puVar4 = uVar1;
                  *(short *)((int)unfinished_sensor_id_map + (*param_1 - 50000) * 2) =
                       (short)unfinished_sensor_num;
                  unfinished_sensor_num = unfinished_sensor_num + 1;
                }
                iVar2 = iVar2 + 1;
                param_1 = param_1 + 1;
              } while (iVar2 != param_2);
              unfinished_sensor_num_first = unfinished_sensor_num;
              if (0 < unfinished_sensor_num) {
                uVar7 = 0;
                apmngr_db_foreach_proc(0x800000,_delete_unfirmed_sensor,0);
                g_sensor_state = 3;
                goto LAB_004e7b54;
              }
              FUN_00407df0(unfinished_sensor_list);
              unfinished_sensor_list = (void *)0x0;
              uVar7 = 0xfffffff9;
              FUN_00407df0(current_backhaul_test_operation_id);
              current_backhaul_test_operation_id = (void *)0x0;
              FUN_00407df0(unfinished_sensor_id_map);
              unfinished_sensor_id_map = (void *)0x0;
              if (sensor_err_switch == '\0') goto LAB_004e7b54;
              pcVar5 = "[SENSOR_ERROR]%s()/%d No illegal sensor found\n";
              uVar6 = 0xa01;
              goto LAB_004e7e08;
            }
            if (sensor_err_switch != '\0') {
              uVar7 = 0x9dd;
              goto LAB_004e7e68;
            }
          }
          FUN_00407df0(unfinished_sensor_list);
          unfinished_sensor_list = (void *)0x0;
          uVar7 = 0xffffffff;
          FUN_00407df0(current_backhaul_test_operation_id);
          current_backhaul_test_operation_id = (void *)0x0;
        }
        goto LAB_004e7b54;
      }
    }
    uVar7 = 0xfffffffa;
    if (sensor_warning_switch == '\0') goto LAB_004e7b54;
    iVar2 = apmngr_db_firm_sensor_num_get();
    apmngr_db_get_firm_sensor_max();
    pcVar5 = "[SENSOR_WARNING]%s()/%d Sensor count(%d+%d) will exceed, max count:%d\n";
    uVar6 = 0x9c0;
  }
  printf(pcVar5,"sensor_add",uVar6,iVar2,param_2);
LAB_004e7b54:
  FUN_00407f30(g_sensor_mngt_mutex);
  return uVar7;
}

