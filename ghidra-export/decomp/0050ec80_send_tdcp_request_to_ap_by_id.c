// func send_tdcp_request_to_ap_by_id @ 0050ec80 size=80

void send_tdcp_request_to_ap_by_id
               (undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5,undefined4 param_6)

{
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  _send_tdcp_request_to_ap_by_id(param_1,0,param_2,param_3,param_4,param_5,param_6,&stack0x00000018)
  ;
  return;
}

