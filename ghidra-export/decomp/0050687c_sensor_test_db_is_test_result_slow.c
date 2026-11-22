// func sensor_test_db_is_test_result_slow @ 0050687c size=80

bool sensor_test_db_is_test_result_slow(undefined4 param_1,uint param_2)

{
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    return 2000 < param_2;
  default:
    return false;
  case 8:
    return 100000 < param_2;
  }
}

