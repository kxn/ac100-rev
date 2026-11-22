// func apupd_capwap_callback_image_response_listen @ 00643ab0 size=652

undefined4 apupd_capwap_callback_image_response_listen(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char *__format;
  char cVar4;
  undefined4 uVar5;
  undefined1 auStack_2e8 [728];
  
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar5 = 0x1048;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_2e8);
    if (iVar1 == 0) {
      iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb0);
      if (iVar1 != 0) {
        uVar5 = apupd_db_update_wtp_sub_image_info_request_confirm(param_2,iVar1);
        return uVar5;
      }
      iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb1);
      if (iVar1 != 0) {
        uVar5 = apupd_db_update_wtp_sub_image_action_request_confirm(param_2,iVar1,param_3);
        return uVar5;
      }
      piVar2 = (int *)cw_msg_ele_priv_val_get_from_pkt(param_1,0x1c);
      if (piVar2 == (int *)0x0) {
        if (g_apupd_debug == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_DEBUG]%32s() %05d: get image update result failed.\r\n";
        uVar5 = 0x105d;
      }
      else {
        piVar3 = (int *)cw_msg_ele_val_get(param_1,0x21);
        if (piVar3 == (int *)0x0) {
          if (g_apupd_debug == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_DEBUG]%32s() %05d: get result code failed.\r\n";
          uVar5 = 0x1064;
        }
        else {
          iVar1 = *piVar2;
          if ((*piVar3 == 0) && (iVar1 == 0)) {
            iVar1 = apupd_db_update_wtp_image_response_confirm_by_mac(param_2);
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
            __format = "[APUPD_ERROR]%32s() %05d: confirm wtp failed.\r\n";
            uVar5 = 0x1079;
          }
          else {
            cVar4 = '\n';
            if (iVar1 - 3U < 7) {
              cVar4 = "apupd_capwap_callback_image_response_listen"[iVar1 + 0x29];
            }
            iVar1 = apupd_db_update_wtp_reset_request_send_by_mac(param_2,cVar4);
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
            __format = "[APUPD_ERROR]%32s() %05d: sned reset packet failed.\r\n";
            uVar5 = 0x106e;
          }
        }
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
      uVar5 = 0x104e;
    }
  }
  printf(__format,"apupd_capwap_callback_image_response_listen",uVar5);
  return 0xffffffff;
}

