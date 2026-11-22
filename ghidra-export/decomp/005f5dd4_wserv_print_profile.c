// func wserv_print_profile @ 005f5dd4 size=1

void wserv_print_profile(void)

{
  puts("########################################################");
  printf("l_wserv_data.max_wservice   = %d\n",l_wserv_profile);
  (*(code *)PTR_puts_00758f90)("########################################################");
  return;
}

