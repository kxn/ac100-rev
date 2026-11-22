// func test_report_nms_event @ 004a1abc size=484

/* WARNING: Removing unreachable block (ram,0x004a1bd0) */

undefined4 test_report_nms_event(int *param_1)

{
  int iVar1;
  size_t __n;
  char *__dest;
  FILE *__stream;
  int iVar2;
  int iVar3;
  size_t __n_00;
  int iVar4;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (g_test_send_event == (char *)0x0) {
    g_test_send_event = (char *)FUN_00408450(0x32000,0x275);
    memset(g_test_send_event,0,0x32000);
  }
  iVar3 = 0;
LAB_004a1b28:
  do {
    iVar2 = *param_1;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    if ((g_test_events_debug != 0) &&
       (iVar1 = access("/tmp/test_ap_passthrough_event.txt",0), iVar1 == 0)) {
      if (*g_test_send_event == '\0') {
        __stream = fopen("/tmp/test_ap_passthrough_event.txt","rb");
        if (__stream != (FILE *)0x0) {
          fread(g_test_send_event,0x32000,1,__stream);
          fclose(__stream);
        }
      }
      else {
        iVar1 = 0;
        if (-1 < iVar3) {
          do {
            __n = strlen(g_test_send_event);
            __n_00 = __n + 1;
            __dest = (char *)FUN_00408450(__n_00,0x28e);
            if (__dest == (char *)0x0) goto LAB_004a1b28;
            memset(__dest,0,__n_00);
            iVar1 = iVar1 + 1;
            strncpy(__dest,g_test_send_event,__n);
            __dest[__n] = '\0';
            iVar4 = iVar3 % 10000;
            iVar3 = iVar3 + 1;
            _uac_nms_event_report_test(__dest,__n_00,iVar4);
            FUN_00407df0(__dest);
          } while (iVar1 < iVar2);
        }
      }
    }
    usleep(g_test_report_events_interval * 1000);
  } while( true );
}

