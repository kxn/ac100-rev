// func wips_profile_dump @ 004ceb0c size=1

void wips_profile_dump(void)

{
  printf("WIPS_ENABLE: %d\n",g_wips_enable);
  printf("WIPS_INFO_MAX_SIZE: %d\n",(uint)g_wips_info_max_size);
  printf("WHITE_LIST_MAX_SIZE: %d\n",(uint)g_whitelist_max_size);
  return;
}

