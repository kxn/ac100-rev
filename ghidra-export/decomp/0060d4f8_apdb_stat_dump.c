// func apdb_stat_dump @ 0060d4f8 size=108

void apdb_stat_dump(void)

{
  puts("######################apdb statistic information########################");
  printf("%s:%u\n\r","mem_malloc_times",g_stat);
  printf("%s:%u\n\r","mem_free_times",DAT_007cc2b0);
  puts("##################################end###################################");
  return;
}

