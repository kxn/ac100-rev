// func sensor_pkt_tdcp_send_need_response @ 004eaf20 size=48

void sensor_pkt_tdcp_send_need_response(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  send_tdcp_request_to_ap_by_id(1,param_1,0x800000,param_2,param_3,0);
  return;
}

