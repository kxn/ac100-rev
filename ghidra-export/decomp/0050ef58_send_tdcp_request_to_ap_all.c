// func send_tdcp_request_to_ap_all @ 0050ef58 size=80

void send_tdcp_request_to_ap_all
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
               undefined4 param_5)

{
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  _send_tdcp_request_to_ap_by_id(param_1,1,0xffff,param_2,param_3,param_4,param_5,&stack0x00000014);
  return;
}

