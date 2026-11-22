// func apupd_config_update_request_send @ 0064be8c size=508

undefined4 apupd_config_update_request_send(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: apupd_config_update_request_send\r\n",
           "apupd_config_update_request_send",0xfb6);
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (((param_1 == 0) || (*(int *)(param_1 + 8) == 0)) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar3 = 0xfbd;
  }
  else {
    iVar1 = apupd_software_version_to_buffer(param_2,&local_28,0xe);
    if (iVar1 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
      uVar3 = 0xfc4;
    }
    else {
      iVar1 = apupd_config_update_request_create(0x12345678,&local_28,0xe);
      if (iVar1 != 0) {
        iVar2 = serv_packet_send(param_1,iVar1,param_3);
        if (iVar2 != -1) {
          cw_pkt_buf_destroy(iVar1);
          return 0;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: send config update request failed.\r\n",
                 "apupd_config_update_request_send",0xfd2);
        }
        cw_pkt_buf_destroy(iVar1);
        return 0xffffffff;
      }
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APUPD_ERROR]%32s() %05d: create config update request failed.\r\n";
      uVar3 = 0xfcb;
    }
  }
  printf(__format,"apupd_config_update_request_send",uVar3);
  return 0xffffffff;
}

