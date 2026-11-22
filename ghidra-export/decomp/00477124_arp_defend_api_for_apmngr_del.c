// func arp_defend_api_for_apmngr_del @ 00477124 size=32

undefined4 arp_defend_api_for_apmngr_del(int param_1)

{
  undefined4 uVar1;
  
  if (2 < *(uint *)(param_1 + 0xc)) {
    return 0;
  }
  uVar1 = arp_defend_db_ap_entry_del();
  return uVar1;
}

