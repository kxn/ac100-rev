// func balance_capwap_callback_wtp_event_request_listen @ 00459f60 size=224

undefined4 balance_capwap_callback_wtp_event_request_listen(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (g_balance_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_ERROR](%32s) %05d: inputs error.\r\n";
    uVar2 = 0x3e1;
  }
  else {
    iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = balance_sta_want_connect_wtp(iVar1 + 2,param_2);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_balance_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[BALANCE_WARNING](%32s) %05d: balance sta dis failed.\r\n";
    uVar2 = 0x3eb;
  }
  printf(__format,"balance_capwap_callback_wtp_event_request_listen",uVar2);
  return 0xffffffff;
}

