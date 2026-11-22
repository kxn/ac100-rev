// func _sensor_delete @ 004e2dfc size=632

undefined4 _sensor_delete(int param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  if (*(int *)(param_1 + 0x14) == 7) {
    uVar8 = 0xffffffff;
    iVar3 = sensor_db_delete(*(undefined2 *)(param_1 + 0x10));
    if (iVar3 == 0) {
      FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
      iVar3 = unfinished_sensor_id_map;
      if ((((g_sensor_enable != 0) && (g_sensor_state == 3)) && (0 < unfinished_sensor_num)) &&
         (iVar4 = (int)*(short *)(unfinished_sensor_id_map +
                                 (*(ushort *)(param_1 + 0x10) - 50000) * 2), iVar4 != -1)) {
        if (((g_sensor_backhaul_test_state != 0) &&
            (uVar6 = *(uint *)(unfinished_sensor_list + iVar4 * 0x30 + 4), 1 < uVar6)) &&
           ((backhaul_test_finished_sensor_num = backhaul_test_finished_sensor_num + -1, uVar6 == 2
            || (uVar6 == 6)))) {
          backhaul_test_suc_sensor_num = backhaul_test_suc_sensor_num + -1;
        }
        *(undefined2 *)(unfinished_sensor_list + iVar4 * 0x30) = 0xffff;
        iVar7 = unfinished_sensor_num + -1;
        unfinished_sensor_num = iVar7;
        *(undefined2 *)(iVar3 + (*(ushort *)(param_1 + 0x10) - 50000) * 2) = 0xffff;
        *(undefined4 *)(current_backhaul_test_operation_id + iVar4 * 4) = 0;
        if (iVar7 <= backhaul_test_finished_sensor_num) {
          g_sensor_backhaul_test_state = 2;
        }
      }
      if ((g_change_backhaul_wserv != 0) && (sensor_backhaul_set_id_map != 0)) {
        pcVar5 = (char *)(sensor_backhaul_set_id_map + (*(ushort *)(param_1 + 0x10) - 50000));
        cVar2 = *pcVar5;
        if (cVar2 != -1) {
          if (cVar2 == '\x01') {
            sensor_backhaul_set_finished = sensor_backhaul_set_finished + -1;
          }
          sensor_backhaul_set_total = sensor_backhaul_set_total + -1;
          bVar1 = sensor_backhaul_set_total == sensor_backhaul_set_finished;
          *pcVar5 = -1;
          if (bVar1) {
            if (sensor_backhaul_set_timer != -1) {
              FUN_00408060();
              sensor_backhaul_set_timer = -1;
            }
            FUN_00408340(2,0,_update_backhaul_to_wserv_cfg_immediately,0,0,"_sensor_delete",0x3e9);
          }
        }
      }
      uVar8 = 0;
      FUN_00407f30(g_sensor_mngt_mutex);
    }
  }
  return uVar8;
}

