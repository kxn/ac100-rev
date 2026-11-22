// func _uac_arp_entry_modify_cb @ 00474780 size=132

undefined4 _uac_arp_entry_modify_cb(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = arp_defend_wtp_pkt_send(*param_1,param_1,1);
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, arp_defend_warning_switch != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_WARNING]%s()/%d arp_defend_wtp_pkt_send(%d) failed.\n",
           "_uac_arp_entry_modify_cb",0x44f,*param_1);
  }
  return uVar2;
}

