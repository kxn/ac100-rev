// func uac_report_client_set @ 004b65b4 size=216

undefined4 uac_report_client_set(undefined1 param_1,char *param_2,uint param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if (report_debug_switch != 0) {
    printf("[REPORT_DEBUG]%s()/line %d : uac_report_client_set\n","uac_report_client_set",0x17d);
  }
  if (param_2 == (char *)0x0) {
    uVar2 = 0xffffffff;
    if (report_warning_switch != 0) {
      printf("[REPORT_WARNING]%s()/line %d : uac_report_client_set, server_address null\n",
             "uac_report_client_set",0x180);
    }
  }
  else {
    server_session = param_1;
    sVar1 = strlen(param_2);
    uVar2 = 0;
    memcpy(&DAT_00767d71,param_2,sVar1 + 1);
    DAT_00767e6c = param_3 & 0xffff;
  }
  return uVar2;
}

