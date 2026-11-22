// func uac_report_client_send @ 004b6458 size=348

undefined4 uac_report_client_send(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (report_warning_switch != 0) {
      printf("[REPORT_WARNING]%s()/line %d : uac_report_client_send argument error\n",
             "uac_report_client_send",0x13a);
    }
  }
  else {
    iVar3 = 3;
    _reset_by_jcs = 0;
    do {
      if (_reset_by_jcs == 1) break;
      if (server_session == '\x02') {
        iVar1 = _uac_report_client_setup_udp_sock();
        if ((iVar1 == 0) && (iVar1 = _uac_report_client_udp_send(param_1), iVar1 == 0)) {
          return 0;
        }
      }
      else if (server_session == '\x04') {
        iVar1 = _uac_report_client_http_send(param_1);
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        if (server_session != '\x01') {
          return 0;
        }
        iVar1 = _uac_report_client_setup_tcp_sock();
        if ((iVar1 == 0) && (iVar1 = _uac_report_client_tcp_send(param_1), iVar1 == 0)) {
          return 0;
        }
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar2 = 0xfffffffe;
    if (_reset_by_jcs != 1) {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

