// func _clear_backhaul_wserv_cfg @ 004e2420 size=148

void _clear_backhaul_wserv_cfg(void)

{
  g_change_backhaul_wserv = 0;
  if (sensor_backhaul_set_timer != -1) {
    FUN_00408060();
    sensor_backhaul_set_timer = -1;
  }
  if (sensor_backhaul_set_pkt_id_list != 0) {
    FUN_00407df0();
    sensor_backhaul_set_pkt_id_list = 0;
  }
  if (sensor_backhaul_set_id_map != 0) {
    FUN_00407df0();
    sensor_backhaul_set_id_map = 0;
  }
  sensor_backhaul_set_total = 0;
  sensor_backhaul_set_finished = 0;
  return;
}

