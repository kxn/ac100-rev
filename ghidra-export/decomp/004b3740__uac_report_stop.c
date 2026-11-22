// func _uac_report_stop @ 004b3740 size=120

undefined4 _uac_report_stop(void)

{
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_stop\n","_uac_report_stop",0x359);
  }
  FUN_004082d0(uac_report_mutex,0xffffffff);
  time_to_report = 0;
  FUN_00407f30(uac_report_mutex);
  FUN_00408060(DAT_00767d64);
  uac_report_client_stop();
  return 0;
}

