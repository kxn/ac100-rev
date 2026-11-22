// func arp_defend_init @ 0047736c size=664

undefined4 arp_defend_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_70;
  char *local_6c;
  undefined4 local_68;
  code *local_64;
  undefined4 local_60;
  undefined1 auStack_5c [12];
  char *local_50;
  undefined4 local_4c;
  code *local_48;
  code *local_40;
  code *local_3c;
  code *local_30;
  code *local_2c;
  code *local_24;
  
  local_70 = 0;
  iVar1 = apmngr_db_foreach_proc(0xff7fffff,arp_defend_recover_ap_config_cb,&local_70);
  if (iVar1 == 1) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[ARP_DEFEND_ERROR]%s()/%d apmngr_db_foreach_proc() fail, ret=%d!\n",
             "arp_defend_recover_firm_aps",0x74,1);
    }
    uVar3 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_recover_firm_aps() failed.\n";
    uVar2 = 0x33f;
  }
  else {
    if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d ##########recover %d ap entries!##########\n",
             "arp_defend_recover_firm_aps",0x78,local_70);
    }
    memset(auStack_5c,0,0x4c);
    local_4c = 0x6e;
    local_50 = "arp_defend";
    local_48 = arp_defend_api_for_apmngr_join;
    local_40 = arp_defend_api_for_apmngr_firm;
    local_3c = arp_defend_api_for_apmngr_del;
    local_30 = arp_defend_api_for_apmngr_inherit;
    local_2c = arp_defend_api_for_apmngr_copy;
    local_24 = arp_defend_api_for_apmngr_cap_change;
    iVar1 = apmngr_callback_register(auStack_5c);
    if (iVar1 == 0) {
      local_60 = 0;
      local_68 = 0x5a000000;
      local_6c = "arp_defend";
      local_64 = arp_defend_multilink_callback_ap_add;
      iVar1 = multi_link_reg(&local_6c);
      if (iVar1 == -1) {
        if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d register callback to multi link failed.\n",
                 "arp_defend_multilink_callback_ap_init",0xbe);
        }
        uVar3 = 0xffffffff;
        if (arp_defend_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_multilink_callback_ap_init() failed.\n";
        uVar2 = 0x356;
      }
      else {
        udbg_help_register("arp_defend","arp_defend_debug_help()");
        if (arp_defend_debug_switch == 0) {
          return 0;
        }
        uVar3 = 0;
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = "[ARP_DEFEND_DEBUG]%s()/%d arp_defend_init() OK.\n";
        uVar2 = 0x35b;
      }
    }
    else {
      uVar3 = 0xffffffff;
      if (arp_defend_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[ARP_DEFEND_ERROR]%s()/%d apmngr_callback_register() failed.\n";
      uVar2 = 0x350;
    }
  }
  printf(__format,"arp_defend_init",uVar2);
  return uVar3;
}

