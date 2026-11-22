// func wportal_debug_show_nginx_portal_entry @ 00435954 size=72

void wportal_debug_show_nginx_portal_entry(void)

{
  char acStack_108 [260];
  
  memset(acStack_108,0,0x100);
  strcpy(acStack_108,"/debug/show_portal_entry");
  puts("Portal entry in nginx:");
  _wportal_send_http_request_get(acStack_108);
  return;
}

