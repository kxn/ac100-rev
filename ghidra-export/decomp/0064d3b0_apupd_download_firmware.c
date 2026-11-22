// func apupd_download_firmware @ 0064d3b0 size=308

void apupd_download_firmware
               (int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_268 [36];
  undefined1 auStack_244 [36];
  char acStack_220 [516];
  
  memset(acStack_220,0,0x200);
  memset(auStack_244,0,0x21);
  memset(auStack_268,0,0x21);
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_004084f0(param_2,0x10,auStack_244);
    FUN_004084f0(param_3,0x10,auStack_268);
    snprintf(acStack_220,0x1ff,
             "ubus call cloudclient download_fw_for_ap  \'{\"download_url_for_ap\":\"%s\", \"ap_hw_id\":\"%s\", \"ap_fw_id\":\"%s\", \"ap_offset\":%d, \"ap_download_len\":%d}\'"
             ,param_1,auStack_244,auStack_268,param_4,param_5);
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: %s\r\n","apupd_download_firmware",0x171,acStack_220);
    }
    apupd_excute_cmd(acStack_220);
  }
  return;
}

