// func sensor_tdcp_confirm @ 004e9480 size=376

void sensor_tdcp_confirm(uint param_1,int param_2)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  
  bVar1 = false;
  FUN_004082d0(g_sensor_mngt_mutex,0xffffffff);
  if ((g_change_backhaul_wserv != 0) && (sensor_backhaul_set_id_map != 0)) {
    iVar3 = (param_1 & 0xffff) - 50000;
    pcVar2 = (char *)(sensor_backhaul_set_id_map + iVar3);
    if ((*pcVar2 == '\0') &&
       (bVar1 = false, *(int *)(sensor_backhaul_set_pkt_id_list + iVar3 * 4) == param_2)) {
      *pcVar2 = '\x01';
      sensor_backhaul_set_finished = sensor_backhaul_set_finished + 1;
      if (sensor_backhaul_set_total == sensor_backhaul_set_finished) {
        if (sensor_backhaul_set_timer != -1) {
          FUN_00408060();
          sensor_backhaul_set_timer = -1;
        }
        bVar1 = true;
        _clear_backhaul_wserv_cfg();
        g_change_backhaul_wserv = 1;
        sensor_backhaul_set_timer =
             FUN_00408340(0x14,0,_wserv_change_state_timeout,0,0,"sensor_tdcp_confirm",0xb7d);
        if (sensor_backhaul_set_timer == -1) {
          g_change_backhaul_wserv = 0;
        }
      }
    }
  }
  FUN_00407f30(g_sensor_mngt_mutex);
  if (bVar1) {
    system("/usr/lib/lua/sensor/bh_wserv_set");
    return;
  }
  return;
}

