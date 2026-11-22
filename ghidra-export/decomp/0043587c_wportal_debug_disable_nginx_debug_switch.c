// func wportal_debug_disable_nginx_debug_switch @ 0043587c size=72

void wportal_debug_disable_nginx_debug_switch(void)

{
  char acStack_108 [260];
  
  memset(acStack_108,0,0x100);
  strcpy(acStack_108,"/debug/disable_debug_switch");
  puts("Debug switch in nginx:");
  _wportal_send_http_request_get(acStack_108);
  return;
}

