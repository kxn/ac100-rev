// func arp_defend_db_arp_entry_set @ 0047d1dc size=272

undefined4 arp_defend_db_arp_entry_set(uint *param_1)

{
  int iVar1;
  
  if (param_1 == (uint *)0x0) {
    if (arp_defend_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp entry.\n","arp_defend_db_arp_entry_set",0x77b);
      return 0xffffffff;
    }
  }
  else {
    if ((-1 < (int)*param_1) && (*param_1 < g_arp_defend_profile)) {
      FUN_004082d0(DAT_007670fc,0xffffffff);
      memcpy((void *)(DAT_0076710c + *param_1 * 0x120),param_1,0x120);
      FUN_00407f30(DAT_007670fc);
      return 0;
    }
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp id(%d).\n","arp_defend_db_arp_entry_set",0x781,
             *param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

