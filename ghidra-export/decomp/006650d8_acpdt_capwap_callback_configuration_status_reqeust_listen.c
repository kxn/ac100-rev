// func acpdt_capwap_callback_configuration_status_reqeust_listen @ 006650d8 size=620

undefined4
acpdt_capwap_callback_configuration_status_reqeust_listen(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_58;
  void *local_54;
  undefined4 local_50 [16];
  
  memset(local_50,0,0x40);
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar2 = 0x351;
  }
  else {
    local_58 = 0x1000078;
    iVar1 = cw_service_msg_add(param_3,0x10,&local_58,0);
    if (iVar1 == -1) {
      if (g_acpdt_error != 0) {
        printf("[ACPDT_ERROR] %32s() %05d: add decryptin error report period failed.\r\n",
               "acpdt_decryption_error_report_period_add",0x1bd);
      }
      if (g_acpdt_error == 0) {
        return 0xffffffff;
      }
      __format = "[ACPDT_ERROR] %32s() %05d: add Decryption Error Report Period failed.\r\n";
      uVar2 = 0x358;
    }
    else {
      local_58 = CONCAT13(1,local_58._1_3_);
      iVar1 = cw_service_msg_add(param_3,0x28,&local_58,0);
      if (iVar1 == -1) {
        if (g_acpdt_error != 0) {
          printf("[ACPDT_ERROR] %32s() %05d: add wtp fallback failed.\r\n","acpdt_wtp_fallback_add",
                 0x1d5);
        }
        if (g_acpdt_error == 0) {
          return 0xffffffff;
        }
        __format = "[ACPDT_ERROR] %32s() %05d: add wtp fallback failed.\r\n";
        uVar2 = 0x35f;
      }
      else {
        local_58 = 0;
        local_54 = (void *)0x0;
        local_50[0] = 0xc0a801fd;
        local_54 = (void *)FUN_00408450(4,0x1e8);
        if (local_54 == (void *)0x0) {
          if (g_acpdt_error != 0) {
            printf("[ACPDT_ERROR] %32s() %05d: malloc failed.\r\n","acpdt_ac_ipv4_list_add",0x1ea);
          }
        }
        else {
          local_58 = CONCAT22(1,local_58._2_2_);
          memcpy(local_54,local_50,4);
          iVar1 = cw_service_msg_add(param_3,2,&local_58,0);
          if (iVar1 != -1) {
            FUN_00407df0(local_54);
            return 0;
          }
          if (g_acpdt_error != 0) {
            printf("[ACPDT_ERROR] %32s() %05d: add ac ipv4 list failed.\r\n",
                   "acpdt_ac_ipv4_list_add",0x1f5);
          }
          FUN_00407df0(local_54);
        }
        if (g_acpdt_error == 0) {
          return 0xffffffff;
        }
        __format = "[ACPDT_ERROR] %32s() %05d: add ipv4 list failed.\r\n";
        uVar2 = 0x368;
      }
    }
  }
  printf(__format,"acpdt_capwap_callback_configuration_status_reqeust_listen",uVar2);
  return 0xffffffff;
}

