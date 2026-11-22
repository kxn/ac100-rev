// func set_speed_test_param @ 004fd030 size=128

void set_speed_test_param(undefined4 param_1,char *param_2)

{
  l_tmp_speed_test_type = param_1;
  memset(&l_tmp_speed_test_url,0,500);
  strncpy(&l_tmp_speed_test_url,param_2,500);
  printf("test_type=%d\n",param_1);
  printf("url=%s\n",&l_tmp_speed_test_url);
  return;
}

