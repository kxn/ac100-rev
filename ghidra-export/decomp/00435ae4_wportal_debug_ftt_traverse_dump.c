// func wportal_debug_ftt_traverse_dump @ 00435ae4 size=1

void wportal_debug_ftt_traverse_dump(void)

{
  undefined4 auStack_10 [3];
  
  auStack_10[0] = 0;
  puts("Free strategy list:");
  wportal_db_ftt_traverse(ftt_traverse_func,auStack_10);
  printf("Total: %d\n",auStack_10[0]);
  putchar(10);
  return;
}

