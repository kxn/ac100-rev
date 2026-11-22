// func arp_defend_multilink_callback_ap_add @ 00478250 size=296

undefined4 arp_defend_multilink_callback_ap_add(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [12];
  uint local_2dc;
  
  param_1 = param_1 & 0xffff;
  uVar2 = 0xffffffff;
  local_2f8 = 0;
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if ((iVar1 == 0) && (uVar2 = 0, local_2dc < 3)) {
    iVar1 = arp_defend_db_ap_entry_get(param_1,&local_2f8);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
      if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_ap_entry_get(%d) failed.\n",
               "arp_defend_multilink_callback_ap_add",0x96,param_1);
      }
    }
    else {
      iVar1 = arp_defend_wtp_pkt_send(param_1,&local_2f8,1);
      if (((iVar1 == -1) && (uVar2 = 0xffffffff, arp_defend_err_switch != 0)) &&
         (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d add wtp, then send packet failed.\n",
               "arp_defend_multilink_callback_ap_add",0x9f);
      }
    }
  }
  return uVar2;
}

