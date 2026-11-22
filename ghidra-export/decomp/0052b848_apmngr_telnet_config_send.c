// func apmngr_telnet_config_send @ 0052b848 size=244

undefined4 apmngr_telnet_config_send(undefined2 param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&local_20);
  if (iVar1 == 0) {
    iVar1 = apmngr_db_get_addr_by_capacity(param_1,&local_20,1,1,0x15f0000,1,0x45);
    if (iVar1 == 0) {
      iVar1 = apmngr_pkt_telnet_config_send(&local_20,param_2,param_3);
      if (iVar1 == 0) {
        serv_wtp_address_arg_destroy(&local_20);
        return 0;
      }
      if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(&local_20), iVar1 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d Failed to send telnet config packet.\n",
               "apmngr_telnet_config_send",0x469);
      }
    }
  }
  serv_wtp_address_arg_destroy(&local_20);
  return 0xffffffff;
}

