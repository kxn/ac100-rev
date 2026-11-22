// func apupd_capwap_callback_image_request_listen @ 00643550 size=844

undefined4 apupd_capwap_callback_image_request_listen(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_b18;
  undefined1 auStack_b14 [16];
  undefined4 local_b04;
  undefined4 local_b00;
  undefined4 local_afc;
  undefined4 local_af8;
  undefined1 auStack_af0 [728];
  undefined1 auStack_818 [2048];
  
  local_b18 = 0;
  memset(auStack_af0,0,0x2d8);
  local_b04 = 0;
  local_b00 = 0;
  local_afc = 0;
  local_af8 = 0;
  memset(auStack_818,0,0x800);
  memset(auStack_af0,0,0x2d8);
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0xfd7;
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_af0);
    if (iVar1 == 0) {
      iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0xb1);
      if (iVar1 != 0) {
        uVar3 = apupd_db_update_wtp_sub_image_action_request_confirm(param_2,iVar1,param_3);
        return uVar3;
      }
      iVar1 = cw_msg_ele_val_get(param_1,0x19);
      if (iVar1 == 0) {
        if (g_apupd_debug == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_DEBUG]%32s() %05d: get image identifier failed.\r\n";
        uVar3 = 0xfeb;
      }
      else {
        iVar2 = cw_msg_ele_val_get(param_1,0x1b);
        if (iVar2 == 0) {
          if (g_apupd_debug == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_DEBUG]%32s() %05d: get initiate download failed.\r\n";
          uVar3 = 0xff1;
        }
        else {
          iVar1 = apupd_buffer_to_software_version
                            (*(undefined4 *)(iVar1 + 8),*(undefined2 *)(iVar1 + 4),&local_b04);
          if (iVar1 == -1) {
            if (g_apupd_error == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            __format = 
            "[APUPD_ERROR]%32s() %05d: turn image identifier to software version failed.\r\n";
            uVar3 = 0xff7;
          }
          else {
            iVar1 = apupd_db_update_wtp_image_request_confirm(param_2,&local_b04);
            iVar2 = 0;
            if (iVar1 == -1) {
              iVar2 = 0x10;
            }
            iVar1 = apupd_result_code_add(param_3,iVar2);
            if (iVar1 == -1) {
              if (g_apupd_error == 0) {
                return 0xffffffff;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0xffffffff;
              }
              __format = "[APUPD_ERROR]%32s() %05d: add result code failed.\r\n";
              uVar3 = 0x1005;
            }
            else {
              if (iVar2 != 0) {
                return 0;
              }
              iVar1 = apupd_db_file_info_get_by_mac(param_2,&local_b18,auStack_b14,0);
              if (iVar1 == -1) {
                if (g_apupd_error == 0) {
                  return 0xffffffff;
                }
                iVar1 = is_target_debug_ap();
                if (iVar1 == 0) {
                  return 0xffffffff;
                }
                __format = "[APUPD_ERROR]%32s() %05d: apupd_db_file_info_get_by_mac failed.\r\n";
                uVar3 = 0x100d;
              }
              else {
                iVar1 = apupd_image_information_add(param_3,local_b18,auStack_b14,0x10);
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
                __format = "[APUPD_ERROR]%32s() %05d: add image information failed.\r\n";
                uVar3 = 0x1013;
              }
            }
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
      uVar3 = 0xfdd;
    }
  }
  printf(__format,"apupd_capwap_callback_image_request_listen",uVar3);
  return 0xffffffff;
}

