// func st_mem_stat_dump @ 005086e8 size=44

void st_mem_stat_dump(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  printf("cur_time=%d,l_st_mem_stat=%d\n",tVar1,0);
  return;
}

