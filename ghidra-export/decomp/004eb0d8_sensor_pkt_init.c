// func sensor_pkt_init @ 004eb0d8 size=312

undefined4 sensor_pkt_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = register_sub_device_report_handle(_sensor_pkt_passthrough_event_callback,1);
  if (iVar1 == -1) {
    if (sensor_err_switch != '\0') {
      __format = "[SENSOR_ERROR]%s()/%d register callback to passthrough event handle failed.\n";
      uVar2 = 0x1f7;
      goto LAB_004eb1c4;
    }
  }
  else {
    iVar1 = register_sub_device_report_handle(_sensor_pkt_passthrough_op_result_callback,4);
    if (iVar1 == -1) {
      if (sensor_err_switch != '\0') {
        __format = 
        "[SENSOR_ERROR]%s()/%d register callback to passthrough op result handle failed.\n";
        uVar2 = 0x1fc;
        goto LAB_004eb1c4;
      }
    }
    else {
      iVar1 = serv_msg_mngr_register(9,0x78,_sensor_pkt_wtp_event_req_listen);
      if (iVar1 == -1) {
        if (sensor_err_switch != '\0') {
          __format = 
          "[SENSOR_ERROR]%s()/%d register callback to listen wtp-event-req capwap message event failed.\n"
          ;
          uVar2 = 0x201;
          goto LAB_004eb1c4;
        }
      }
      else {
        iVar1 = serv_msg_mngr_register(3,0x32,_sensor_pkt_join_req_listen);
        if (iVar1 != -1) {
          return 0;
        }
        if (sensor_err_switch != '\0') {
          __format = 
          "[SENSOR_ERROR]%s()/%d register callback to listen join-req capwap message event failed.\n"
          ;
          uVar2 = 0x206;
LAB_004eb1c4:
          printf(__format,"sensor_pkt_init",uVar2);
          return 0xffffffff;
        }
      }
    }
  }
  return 0xffffffff;
}

