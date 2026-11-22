// func sensor_pkt_uninit @ 004eb210 size=1

void sensor_pkt_uninit(void)

{
  unregister_sub_device_report_handle(_sensor_pkt_passthrough_event_callback,1);
  unregister_sub_device_report_handle(_sensor_pkt_passthrough_op_result_callback,4);
  serv_msg_mngr_unregister(9,0x78,_sensor_pkt_wtp_event_req_listen);
  serv_msg_mngr_unregister(3,0x32,_sensor_pkt_join_req_listen);
  if (sensor_cb_hash != 0) {
    FUN_00408570(sensor_cb_hash,sensor_mngt_destroy,0);
    FUN_00408310(sensor_cb_hash);
    sensor_cb_hash = 0;
  }
  return;
}

