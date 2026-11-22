// func wportal_debug_show_nginx_auth_calc_num @ 004359e4 size=72

void wportal_debug_show_nginx_auth_calc_num(void)

{
  char acStack_108 [260];
  
  memset(acStack_108,0,0x100);
  strcpy(acStack_108,"/debug/calc_all_auth_entry");
  puts("Authed entry calc number in nginx:");
  _wportal_send_http_request_get(acStack_108);
  return;
}

