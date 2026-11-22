// func wportal_debug_show_nginx_jump_page_entry @ 0043590c size=72

void wportal_debug_show_nginx_jump_page_entry(void)

{
  char acStack_108 [260];
  
  memset(acStack_108,0,0x100);
  strcpy(acStack_108,"/debug/show_jump_page_entry");
  puts("Template entry in nginx:");
  _wportal_send_http_request_get(acStack_108);
  return;
}

