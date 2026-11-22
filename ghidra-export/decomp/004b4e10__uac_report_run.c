// func _uac_report_run @ 004b4e10 size=124

undefined4 _uac_report_run(void)

{
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_run\n","_uac_report_run",0x366);
  }
  if (report_ctx == '\x01') {
    uac_report_client_set(DAT_00767c59,&DAT_00767c5a,DAT_00767d56);
    _uac_report_work_thread_wakeup(0);
  }
  return 0;
}

