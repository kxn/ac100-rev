// func _uac_report_work_thread_wakeup @ 004b3bb0 size=108

void _uac_report_work_thread_wakeup(void)

{
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_work_thread_wakeup\n",
           "_uac_report_work_thread_wakeup",0xb4);
  }
  FUN_004082d0(uac_report_mutex,0xffffffff);
  time_to_report = 1;
  FUN_004084b0(uac_report_cond);
  FUN_00407f30(uac_report_mutex);
  return;
}

