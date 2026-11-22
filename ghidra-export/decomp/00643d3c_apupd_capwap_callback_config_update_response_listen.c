// func apupd_capwap_callback_config_update_response_listen @ 00643d3c size=508

undefined4
apupd_capwap_callback_config_update_response_listen(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined1 auStack_2f0 [732];
  
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_2f0,0,0x2d8);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar2 = 0xf91;
  }
  else {
    iVar1 = apupd_db_update_wtp_config_update_response_confirm_by_mac(param_2);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: update wtp confirm config_update_response failed.\r\n";
      uVar2 = 0xf9b;
    }
    else {
      iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_2f0);
      if (iVar1 == 0) {
        iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xaf);
        if ((iVar1 == 0) ||
           (iVar1 = apupd_db_update_wtp_large_image_info_request_confirm(param_2,iVar1), iVar1 != -1
           )) {
          iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb1);
          if (iVar1 == 0) {
            return 0;
          }
          iVar1 = apupd_db_update_wtp_sub_image_action_request_confirm(param_2,iVar1,param_3);
          if (iVar1 != -1) {
            return 0;
          }
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = 
          "[APUPD_ERROR]%32s() %05d: update wtp confirm config_update_response failed.\r\n";
          uVar2 = 0xfb1;
        }
        else {
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = 
          "[APUPD_ERROR]%32s() %05d: update wtp confirm config_update_response failed.\r\n";
          uVar2 = 0xfa9;
        }
      }
      else {
        if (g_apupd_debug == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_DEBUG]%32s() %05d: Cannot find the ap entry.\r\n";
        uVar2 = 0xfa1;
      }
    }
  }
  printf(__format,"apupd_capwap_callback_config_update_response_listen",uVar2);
  return 0xffffffff;
}

