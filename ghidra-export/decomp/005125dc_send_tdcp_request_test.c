// func send_tdcp_request_test @ 005125dc size=80

void send_tdcp_request_test(void)

{
  undefined1 auStack_208 [67];
  undefined1 auStack_1c5 [449];
  
  memcpy(auStack_208,
         "{\"method\":\"do\",\"apmng_status\":{\"ap_reset\":{\"entry_id\":[\"0\",\"1\"]}}}",0x43);
  memset(auStack_1c5,0,0x1bd);
  tdcp_send_request_to_ap_all(0,"ap_reset",auStack_208,5);
  return;
}

