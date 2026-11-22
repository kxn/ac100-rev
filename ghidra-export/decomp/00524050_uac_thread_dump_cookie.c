// func uac_thread_dump_cookie @ 00524050 size=28

void uac_thread_dump_cookie(void)

{
  uac_thread_traverse_list(_uac_print_cookie);
  return;
}

