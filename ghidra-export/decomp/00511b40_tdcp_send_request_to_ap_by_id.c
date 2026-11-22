// func tdcp_send_request_to_ap_by_id @ 00511b40 size=68

void tdcp_send_request_to_ap_by_id
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined2 param_5)

{
  tdcp_send_to_ap(0,param_1,1,param_2,param_3,param_4,param_5,0);
  return;
}

