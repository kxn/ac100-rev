// func apdb_debug_stat_dump @ 0060e1d8 size=1

void apdb_debug_stat_dump(void)

{
  puts("######################apdb statistic information########################");
  printf("%s:%u\n\r","mem_malloc_times",g_stat);
  printf("%s:%u\n\r","mem_free_times",DAT_007cc2b0);
  puts("##################################end###################################");
  return;
}

