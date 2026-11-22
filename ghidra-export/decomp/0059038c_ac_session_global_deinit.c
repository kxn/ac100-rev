// func ac_session_global_deinit @ 0059038c size=64

void ac_session_global_deinit(void)

{
  if (total_num_mutex != 0) {
    FUN_00408360();
    total_num_mutex = 0;
  }
  session_total_num = 0;
  return;
}

