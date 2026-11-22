// func print_nms_report_cost_time_info @ 0049f538 size=232

void print_nms_report_cost_time_info(void)

{
  puts("=====================================================================\r");
  printf("handle ok count:%llu \r\n");
  printf("handle fail count:%llu \r\n");
  printf("handle cost total time:%llu \r\n");
  printf("handle OK cost total time:%llu \r\n");
  printf("total handle bytes:%llu \r\n");
  if (g_test_total_handle_cost_ok_count != 0 || DAT_00767a24 != 0) {
    __udivdi3(g_test_total_handle_cost_time,DAT_00767a34);
    printf("handle cost average time:%llu \r\n");
  }
  puts("=====================================================================\r");
  return;
}

