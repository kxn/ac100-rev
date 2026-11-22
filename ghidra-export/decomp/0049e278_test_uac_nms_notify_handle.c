// func test_uac_nms_notify_handle @ 0049e278 size=116

void test_uac_nms_notify_handle(undefined4 param_1,int param_2,undefined4 param_3)

{
  char acStack_110 [256];
  
  memset(acStack_110,0,0x100);
  if (param_2 != 0) {
    snprintf(acStack_110,0x100,"\"ap_mac\":\"%s\",",param_2);
  }
  local_uac_nms_notify_handle(param_1,acStack_110,param_3);
  return;
}

