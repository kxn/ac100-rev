// func _uac_report_client_udp_send @ 004b5eb8 size=308

undefined4 _uac_report_client_udp_send(char *param_1)

{
  size_t __n;
  socklen_t __addr_len;
  ssize_t sVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  sockaddr *__addr;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_client_udp_send\n",
           "_uac_report_client_udp_send",0x9a);
  }
  __n = strlen(param_1);
  if (DAT_00767ea0 == 1) {
    __addr_len = 0x10;
    __addr = (sockaddr *)&DAT_00767e74;
  }
  else {
    __addr_len = 0x1c;
    __addr = (sockaddr *)&DAT_00767e84;
  }
  sVar1 = sendto(DAT_00767e70,param_1,__n,0,__addr,__addr_len);
  if (sVar1 < (int)__n) {
    if (report_warning_switch != 0) {
      piVar3 = __errno_location();
      pcVar4 = strerror(*piVar3);
      printf("[REPORT_WARNING]%s()/line %d : _uac_report_client_udp_send fail, n = %d, err = %s\n",
             "_uac_report_client_udp_send",0xac,sVar1,pcVar4);
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

