// func arp_defend_db_arp_entry_get @ 0047d0c4 size=280

undefined4 arp_defend_db_arp_entry_get(uint param_1,void *param_2)

{
  int iVar1;
  
  if (((int)param_1 < 0) || (g_arp_defend_profile <= param_1)) {
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp_id(%d).\n","arp_defend_db_arp_entry_get",0x759,
             param_1);
      return 0xffffffff;
    }
  }
  else {
    if (param_2 != (void *)0x0) {
      FUN_004082d0(DAT_007670fc,0xffffffff);
      memcpy(param_2,(void *)(DAT_0076710c + param_1 * 0x120),0x120);
      FUN_00407f30(DAT_007670fc);
      return 0;
    }
    if (arp_defend_err_switch != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp entry.\n","arp_defend_db_arp_entry_get",0x75f);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

