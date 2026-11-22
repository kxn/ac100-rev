// func di_mem_stat_dump @ 004e1f1c size=1

void di_mem_stat_dump(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  printf("cur_time=%d,l_di_mem_stat=%d\n",tVar1,0);
  return;
}

