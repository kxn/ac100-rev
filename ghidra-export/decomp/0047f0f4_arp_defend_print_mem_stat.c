// func arp_defend_print_mem_stat @ 0047f0f4 size=1

void arp_defend_print_mem_stat(void)

{
  puts("########################################################");
  printf("g_arp_defend_mem_stat = %d\n",0);
  (*(code *)PTR_puts_00758f90)("########################################################");
  return;
}

