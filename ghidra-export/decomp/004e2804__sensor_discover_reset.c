// func _sensor_discover_reset @ 004e2804 size=528

void _sensor_discover_reset(int param_1)

{
  short *psVar1;
  int iVar2;
  int local_28 [2];
  
  g_sensor_state = 0;
  local_28[0] = 0;
  g_sensor_backhaul_test_state = 0;
  if (sensor_discover_timer != -1) {
    FUN_00408060();
    sensor_discover_timer = -1;
  }
  if (sensor_backhaul_test_timer != -1) {
    FUN_00408060();
    sensor_backhaul_test_timer = -1;
  }
  iVar2 = 0;
  if (unfinished_sensor_list != 0) {
    for (; iVar2 < unfinished_sensor_num_first; iVar2 = iVar2 + 1) {
      psVar1 = (short *)(unfinished_sensor_list + iVar2 * 0x30);
      if (*psVar1 != -1) {
        apmngr_ap_delete(psVar1,1,1,0x3cf2,1);
        local_28[0] = 1;
      }
    }
    FUN_00407df0(unfinished_sensor_list);
    unfinished_sensor_list = 0;
  }
  if (current_backhaul_test_operation_id != 0) {
    FUN_00407df0();
    current_backhaul_test_operation_id = 0;
  }
  if (unfinished_sensor_id_map != 0) {
    FUN_00407df0();
    unfinished_sensor_id_map = 0;
  }
  unfinished_sensor_num_first = 0;
  unfinished_sensor_num = 0;
  backhaul_test_finished_sensor_num = 0;
  backhaul_test_suc_sensor_num = 0;
  apmngr_db_foreach_proc(0x800000,_delete_unfirmed_sensor,local_28);
  if (g_dft_backhaul_wserv_id != -1) {
    if ((param_1 == 0) && (local_28[0] == 0)) {
      uac_wservice_entry_delete_by_id();
      g_dft_backhaul_wserv_id = -1;
    }
    else {
      iVar2 = FUN_00408340(0x28,0,_sensor_delete_dft_wserv_timeout,0,0,"_sensor_discover_reset",
                           0x1cb);
      if (iVar2 == -1) {
        uac_wservice_entry_delete_by_id(g_dft_backhaul_wserv_id);
        g_dft_backhaul_wserv_id = -1;
      }
      else {
        wait_for_delete_dft_wserv_id = 1;
      }
    }
  }
  return;
}

