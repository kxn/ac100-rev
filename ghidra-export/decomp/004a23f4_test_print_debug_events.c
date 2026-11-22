// func test_print_debug_events @ 004a23f4 size=1

void test_print_debug_events(void)

{
  printf("g_test_events_debug:%d \r\n",g_test_events_debug);
  printf("g_test_report_events_interval:%d \r\n",g_test_report_events_interval);
  printf("g_test_events_remain_count:%d \r\n",g_test_events_remain_count);
  printf("g_test_events_len:%d \r\n",g_test_events_len);
  if (g_test_send_event != 0) {
    printf("g_test_send_event:%s \r\n");
    return;
  }
  return;
}

