// func apupd_delete_info_in_uci @ 0064c71c size=248

void apupd_delete_info_in_uci(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_158 [36];
  undefined1 auStack_134 [36];
  char acStack_110 [256];
  
  memset(acStack_110,0,0x100);
  memset(auStack_134,0,0x21);
  memset(auStack_158,0,0x21);
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_004084f0(param_1,0x10,auStack_134);
    FUN_004084f0(param_2,0x10,auStack_158);
    snprintf(acStack_110,0xff,
             "ubus call cloudclient clean_config_for_ap \'{\"ap_hw_id\":\"%s\", \"ap_fw_id\":\"%s\"}\'"
             ,auStack_134,auStack_158);
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: %s\r\n","apupd_delete_info_in_uci",0x188,acStack_110);
    }
    apupd_excute_cmd(acStack_110);
  }
  return;
}

