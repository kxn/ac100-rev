// func wsta_print_mem_stat @ 0063a328 size=1

void wsta_print_mem_stat(void)

{
  puts("########################################################");
  printf("l_wsta_mem_stat = %d\n",l_wsta_mem_stat);
  (*(code *)PTR_puts_00758f90)("########################################################");
  return;
}

