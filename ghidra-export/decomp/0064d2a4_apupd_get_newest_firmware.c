// func apupd_get_newest_firmware @ 0064d2a4 size=268

void apupd_get_newest_firmware(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_160 [36];
  undefined1 auStack_13c [36];
  char acStack_118 [260];
  
  memset(acStack_118,0,0x100);
  memset(auStack_13c,0,0x21);
  memset(auStack_160,0,0x21);
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_004084f0(param_1,0x10,auStack_13c);
    FUN_004084f0(param_2,0x10,auStack_160);
    snprintf(acStack_118,0xff,
             "ubus call cloudclient check_fw_version_for_ap \'{\"user_conf_path\":\"%s\",  \"ap_hw_id\":\"%s\", \"ap_fw_id\":\"%s\"}\'"
             ,"cloud_config_ap",auStack_13c,auStack_160);
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: %s\r\n","apupd_get_newest_firmware",0x11a,acStack_118);
    }
    apupd_excute_cmd(acStack_118);
  }
  return;
}

