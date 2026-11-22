// func send_tdcp_request_to_ap @ 0050e2c0 size=68

void send_tdcp_request_to_ap(void)

{
  undefined4 *in_stack_00000010;
  
  if (in_stack_00000010 != (undefined4 *)0x0) {
    *in_stack_00000010 = 0;
  }
  _send_tdcp_request_to_ap();
  return;
}

