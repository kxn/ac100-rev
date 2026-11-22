// func arp_defend_print_profile @ 0047ec94 size=1

void arp_defend_print_profile(void)

{
  puts("########################################################");
  printf("g_arp_defend_profile.max_arp       = %d\n",g_arp_defend_profile);
  printf("g_arp_defend_profile.max_bind_num  = %d\n",DAT_007670f0);
  (*(code *)PTR_puts_00758f90)("########################################################");
  return;
}

