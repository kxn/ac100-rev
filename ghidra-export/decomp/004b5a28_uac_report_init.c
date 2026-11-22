// func uac_report_init @ 004b5a28 size=308

undefined4 uac_report_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  uac_report_mutex = FUN_00407f00("uac_report_mutex",0);
  uac_report_cond = FUN_00407d80("uac_report_cond");
  time_to_report = 0;
  FUN_004084e0(&uac_report_tid,"uac_report_tid",_uac_report_work_thread,0);
  FUN_004084d0("ac_report",2,_uac_report_jcs_set);
  iVar1 = _uac_report_read_config();
  if (iVar1 == 0) {
    iVar1 = _uac_report_run();
    if (iVar1 == 0) {
      return 0;
    }
    if (report_err_switch == 0) goto LAB_004b5adc;
    __format = "[REPORT_ERROR]%s()/line %d : _uac_report_run() fail!\n";
    uVar2 = 0x3da;
  }
  else {
    if (report_err_switch == 0) goto LAB_004b5adc;
    __format = "[REPORT_ERROR]%s()/line %d : _uac_report_read_config() fail!\n";
    uVar2 = 0x3d4;
  }
  printf(__format,"uac_report_init",uVar2);
LAB_004b5adc:
  if (report_err_switch != 0) {
    printf("[REPORT_ERROR]%s()/line %d : uac_report_init fail!\n","uac_report_init",0x3e0);
  }
  uac_report_uninit();
  return 0xffffffff;
}

