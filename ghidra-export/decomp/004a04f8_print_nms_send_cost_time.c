// func print_nms_send_cost_time @ 004a04f8 size=208

void print_nms_send_cost_time(void)

{
  puts("=====================================================================\r");
  printf("send ok count:%llu \r\n");
  printf("send fail count:%llu \r\n");
  printf("send cost total time:%llu \r\n");
  printf("total send bytes:%llu \r\n");
  if (g_test_total_send_cost_ok_count != 0 || DAT_00767a5c != 0) {
    __udivdi3(g_test_total_send_cost_time,DAT_00767a54);
    printf("send cost average time:%llu \r\n");
  }
  puts("=====================================================================\r");
  return;
}

