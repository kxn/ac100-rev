// func _uac_report_client_tcp_send @ 004b61c4 size=256

undefined4 _uac_report_client_tcp_send(char *param_1)

{
  size_t __n;
  ssize_t sVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_client_tcp_send\n",
           "_uac_report_client_tcp_send",0xec);
  }
  __n = strlen(param_1);
  sVar1 = send(DAT_00767e70,param_1,__n,0);
  if (sVar1 < (int)__n) {
    if (report_warning_switch != 0) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      printf("[REPORT_WARNING]%s()/line %d : _uac_report_client_tcp_send fail, n = %d, err = %s\n",
             "_uac_report_client_tcp_send",0xf1,sVar1,pcVar4);
    }
    close(DAT_00767e70);
    uVar2 = 0xffffffff;
  }
  else {
    close(DAT_00767e70);
    uVar2 = 0;
  }
  return uVar2;
}

