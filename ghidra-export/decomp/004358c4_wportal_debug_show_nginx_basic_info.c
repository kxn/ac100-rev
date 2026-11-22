// func wportal_debug_show_nginx_basic_info @ 004358c4 size=72

void wportal_debug_show_nginx_basic_info(void)

{
  char acStack_108 [260];
  
  memset(acStack_108,0,0x100);
  strcpy(acStack_108,"/debug/show_basic_info");
  puts("Basic info in nginx:");
  _wportal_send_http_request_get(acStack_108);
  return;
}

