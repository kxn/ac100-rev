// func dhcpdef_db_profile_print @ 0046e874 size=1

void dhcpdef_db_profile_print(void)

{
  puts("########################################################\r");
  printf("l_dhcpdef_profile.max_server   = %d\r\n",l_dhcpdef_profile);
  printf("l_dhcpdef_profile.max_svr_per_ap   = %d\r\n",DAT_0076708c);
  (*(code *)PTR_puts_00758f90)(&DAT_0068d614);
  return;
}

