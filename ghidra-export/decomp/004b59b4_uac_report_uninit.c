// func uac_report_uninit @ 004b59b4 size=116

undefined4 uac_report_uninit(void)

{
  _uac_report_stop();
  if (DAT_00767d58 != 0) {
    FUN_00407df0();
    DAT_00767d58 = 0;
  }
  if (uac_report_mutex != 0) {
    FUN_00408360();
  }
  if (uac_report_cond != 0) {
    FUN_00408220();
  }
  return 0;
}

