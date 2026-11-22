// func _uac_report_client_setup_udp_sock @ 004b5d5c size=348

undefined4 _uac_report_client_setup_udp_sock(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : _uac_report_client_setup_udp_sock\n",
           "_uac_report_client_setup_udp_sock",0x7a);
  }
  uVar5 = 0xffffffff;
  iVar1 = _uac_report_client_addr_setup();
  if (iVar1 == 0) {
    iVar1 = 2;
    if (DAT_00767ea0 != 1) {
      iVar1 = 10;
    }
    iVar1 = socket(iVar1,1,0);
    if (iVar1 < 0) {
      if (report_debug_switch != 0) {
        printf("[REPORT_DEBUG]%s()/line %d : Create socket failed\n",
               "_uac_report_client_setup_udp_sock",0x83);
      }
    }
    else {
      local_20 = 10;
      local_1c = 0;
      iVar2 = setsockopt(iVar1,0xffff,0x1005,&local_20,8);
      if (iVar2 == -1) {
        if (report_warning_switch != 0) {
          piVar3 = __errno_location();
          pcVar4 = strerror(*piVar3);
          printf("[REPORT_WARNING]%s()/line %d : _uac_report_client_setup_udp_sock setsockopt fail, err = %s\n"
                 ,"_uac_report_client_setup_udp_sock",0x8c,pcVar4);
        }
        close(iVar1);
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = 0;
        DAT_00767e70 = iVar1;
      }
    }
  }
  return uVar5;
}

