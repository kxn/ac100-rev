// func arp_defend_api_for_apmngr_inherit @ 00476f60 size=16

void arp_defend_api_for_apmngr_inherit(int param_1,int param_2)

{
  arp_defend_db_ap_inherit(*(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_1 + 0x10));
  return;
}

