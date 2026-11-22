// func uac_arp_defend_init @ 00476bb4 size=328

undefined4 uac_arp_defend_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  iVar1 = arp_defend_db_init();
  if (iVar1 == -1) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_init() falied.\n";
    uVar2 = 0x5c5;
  }
  else {
    iVar1 = arp_defend_init();
    if (iVar1 != -1) {
      FUN_004084d0("arp_defend_ap",3,_uac_arp_defend_ap_jcs_get);
      FUN_004084d0("arp_defend_ap",2,_uac_arp_defend_ap_jcs_set);
      FUN_004084d0("arp_defend_arp",3,_uac_arp_defend_arp_jcs_get);
      FUN_004084d0("arp_defend_arp",0,_uac_arp_defend_arp_jcs_add);
      FUN_004084d0("arp_defend_arp",1,_uac_arp_defend_arp_jcs_del);
      FUN_004084d0("arp_defend_arp",2,_uac_arp_defend_arp_jcs_set);
      apmngr_support_capacity_register(0x10);
      apmngr_support_capacity_register(0x1f);
      return 0;
    }
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_init() falied.\n";
    uVar2 = 0x5cb;
  }
  printf(__format,"uac_arp_defend_init",uVar2);
  return 0xffffffff;
}

