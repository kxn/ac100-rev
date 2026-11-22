// func mac_auth_print_profile @ 00457674 size=1

void mac_auth_print_profile(void)

{
  if (macauth_debug_switch == 0) {
    return;
  }
  puts("########################################################");
  printf("g_mac_auth_profile.max_mac_num    = %d\n",g_mac_auth_profile);
  printf("g_mac_auth_profile.max_group_num  = %d\n",DAT_00766fe8);
  printf("g_mac_auth_profile.max_vlan       = %d\n",DAT_00766fec);
  printf("MACAUTH_MAP_SIZE\t\t\t\t  = %d\n",DAT_00766fec + 0x20U >> 5);
  (*(code *)PTR_puts_00758f90)("########################################################");
  return;
}

