// func check_nms_report_switch @ 0049f620 size=44

undefined4 check_nms_report_switch(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((g_uac_nms_report_switch == 1) && (g_nms_support_switch == 1)) {
    uVar1 = 0;
  }
  return uVar1;
}

