// func ac_send_packet_response_need @ 00590548 size=72

bool ac_send_packet_response_need(int *param_1)

{
  bool bVar1;
  
  if (param_1 == (int *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","ac_send_packet_response_need",0x88,"send_pkt");
    bVar1 = false;
  }
  else {
    bVar1 = *param_1 != 0;
  }
  return bVar1;
}

