// func sensor_pkt_tdcp_send_all @ 004eaf50 size=44

void sensor_pkt_tdcp_send_all(undefined4 param_1)

{
  send_tdcp_request_to_ap_all(0,0x800000,param_1,0,0);
  return;
}

