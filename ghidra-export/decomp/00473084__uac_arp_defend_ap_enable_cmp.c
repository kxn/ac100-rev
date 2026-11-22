// func _uac_arp_defend_ap_enable_cmp @ 00473084 size=180

bool _uac_arp_defend_ap_enable_cmp(undefined4 param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  bVar3 = true;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (param_2 != (char *)0x0) {
    uVar1 = atoi(param_2);
    if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d enable: %d\n","_uac_arp_defend_ap_enable_cmp",0xd6,uVar1);
    }
    iVar2 = arp_defend_db_ap_entry_get(param_1,&local_20);
    bVar3 = true;
    if (iVar2 == 0) {
      bVar3 = local_1c >> 0x18 != uVar1;
    }
  }
  return bVar3;
}

