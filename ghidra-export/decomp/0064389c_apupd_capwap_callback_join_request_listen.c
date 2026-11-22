// func apupd_capwap_callback_join_request_listen @ 0064389c size=532

undefined4 apupd_capwap_callback_join_request_listen(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_capwap_callback_join_request_listen\r\n",
           "apupd_capwap_callback_join_request_listen",0x108f);
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0x1098;
  }
  else {
    piVar1 = (int *)cw_msg_ele_val_get(param_3,0x21);
    if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
      iVar2 = cw_sub_msg_ele_get(param_1,0x27,1);
      if (iVar2 == 0) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[APUPD_ERROR]%32s() %05d: get software version from join request failed.\r\n";
        uVar3 = 0x10a5;
      }
      else {
        iVar2 = apupd_buffer_to_software_version
                          (*(undefined4 *)(iVar2 + 0x14),*(undefined2 *)(iVar2 + 0x12),&local_28);
        if (iVar2 == -1) {
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_ERROR]%32s() %05d: parse software version failed.\r\n";
          uVar3 = 0x10ab;
        }
        else {
          iVar2 = apupd_db_update_wtp_join_request_confirm(param_2,&local_28);
          if (iVar2 != -1) {
            return 0;
          }
          if (g_apupd_error == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          __format = "[APUPD_ERROR]%32s() %05d: wtp update confirm failed.\r\n";
          uVar3 = 0x10b2;
        }
      }
    }
    else {
      if (g_apupd_debug == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_DEBUG]%32s() %05d: Failed to join,don\'t need to confirm.\r\n";
      uVar3 = 0x109e;
    }
  }
  printf(__format,"apupd_capwap_callback_join_request_listen",uVar3);
  return 0xffffffff;
}

