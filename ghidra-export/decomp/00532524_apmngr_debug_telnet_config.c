// func apmngr_debug_telnet_config @ 00532524 size=1

void apmngr_debug_telnet_config(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iVar1 = serv_wtp_address_arg_init(&uStack_20);
  if (iVar1 == 0) {
    apmngr_db_get_all_addr_by_capacity(&uStack_20,1,1,0x15f0000,0);
    iVar1 = apmngr_pkt_telnet_config_send(&uStack_20,param_1,param_2);
    if (((iVar1 != 0) && (apmngr_err_switch != '\0')) && (iVar1 = is_target_debug_ap(), iVar1 != 0))
    {
      printf("[APMNGR_ERROR]%s()/%d Failed to send led change packet.\n",
             "apmngr_debug_telnet_config",0xe36);
    }
  }
  serv_wtp_address_arg_destroy(&uStack_20);
  return;
}

