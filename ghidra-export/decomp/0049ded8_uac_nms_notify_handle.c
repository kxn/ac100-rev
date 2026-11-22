// func uac_nms_notify_handle @ 0049ded8 size=156

void uac_nms_notify_handle(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  char acStack_110 [256];
  
  memset(acStack_110,0,0x100);
  if (param_2 != (byte *)0x0) {
    snprintf(acStack_110,0x100,"\"ap_mac\":\"%02x-%02x-%02x-%02x-%02x-%02x\",",(uint)*param_2,
             (uint)param_2[1],(uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
  }
  local_uac_nms_notify_handle(param_1,acStack_110,param_3);
  return;
}

