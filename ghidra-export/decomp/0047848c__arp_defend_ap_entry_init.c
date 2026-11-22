// func _arp_defend_ap_entry_init @ 0047848c size=176

undefined4 _arp_defend_ap_entry_init(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = 0xffffffff;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  uVar1 = 0;
  if (param_1[3] == 0) {
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid bind_list.\n","_arp_defend_ap_entry_init",0x93);
    }
  }
  else {
    for (; uVar1 < DAT_007670f0; uVar1 = uVar1 + 1) {
      *(undefined4 *)(param_1[3] + uVar1 * 4) = 0xffffffff;
    }
    uVar3 = 0;
  }
  return uVar3;
}

