// func sensor_pkt_tdcp_send @ 004eaef0 size=48

void sensor_pkt_tdcp_send(undefined2 param_1,undefined4 param_2)

{
  send_tdcp_request_to_ap_by_id(0,param_1,0x800000,param_2,0,0);
  return;
}

