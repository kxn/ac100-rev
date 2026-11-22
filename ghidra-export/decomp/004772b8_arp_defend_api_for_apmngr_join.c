// func arp_defend_api_for_apmngr_join @ 004772b8 size=32

undefined4 arp_defend_api_for_apmngr_join(int param_1)

{
  undefined4 uVar1;
  
  if (2 < *(uint *)(param_1 + 0xc)) {
    return 0;
  }
  uVar1 = arp_defend_db_ap_join(*(undefined2 *)(param_1 + 0x10));
  return uVar1;
}

