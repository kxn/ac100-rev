// func mac_auth_print_mem_stat @ 00457b00 size=64

void mac_auth_print_mem_stat(void)

{
  puts("########################################################");
  printf("g_mac_auth_mem_stat = %d\n",g_mac_auth_mem_stat);
  puts("########################################################");
  return;
}

