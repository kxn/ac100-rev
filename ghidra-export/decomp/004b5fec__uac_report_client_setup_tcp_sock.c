// func _uac_report_client_setup_tcp_sock @ 004b5fec size=472

undefined4 _uac_report_client_setup_tcp_sock(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  char *__format;
  sockaddr *__addr;
  socklen_t __len;
  undefined4 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_client_setup_tcp_sock\n",
           "_uac_report_client_setup_tcp_sock",0xb9);
  }
  iVar1 = _uac_report_client_addr_setup();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = 2;
  if (DAT_00767ea0 != 1) {
    iVar1 = 10;
  }
  iVar1 = socket(iVar1,2,0);
  if (iVar1 < 0) {
    if (report_debug_switch == 0) {
      return 0xffffffff;
    }
    printf("[REPORT_DEBUG]%s()/line %d : Create socket failed\n","_uac_report_client_setup_tcp_sock"
           ,0xc5);
    return 0xffffffff;
  }
  local_28 = 10;
  local_24 = 0;
  iVar2 = setsockopt(iVar1,0xffff,0x1005,&local_28,8);
  if (iVar2 == -1) {
    if (report_warning_switch == 0) goto LAB_004b614c;
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    __format = 
    "[REPORT_WARNING]%s()/line %d : _uac_report_client_setup_tcp_sock setsockopt fail, err = %s\n";
    uVar5 = 0xcd;
  }
  else {
    if (DAT_00767ea0 == 1) {
      __len = 0x10;
      __addr = (sockaddr *)&DAT_00767e74;
    }
    else {
      __len = 0x1c;
      __addr = (sockaddr *)&DAT_00767e84;
    }
    DAT_00767e70 = iVar1;
    iVar2 = connect(iVar1,__addr,__len);
    if (iVar2 != -1) {
      return 0;
    }
    if (report_warning_switch == 0) goto LAB_004b614c;
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    __format = 
    "[REPORT_WARNING]%s()/line %d : _uac_report_client_setup_tcp_sock connect fail, err = %s\n";
    uVar5 = 0xe0;
  }
  printf(__format,"_uac_report_client_setup_tcp_sock",uVar5,pcVar4);
LAB_004b614c:
  close(iVar1);
  return 0xffffffff;
}

