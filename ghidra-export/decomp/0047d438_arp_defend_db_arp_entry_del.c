// func arp_defend_db_arp_entry_del @ 0047d438 size=360

undefined4 arp_defend_db_arp_entry_del(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *__s;
  
  if (((int)param_1 < 0) || (g_arp_defend_profile <= param_1)) {
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp_id(%d).\n","arp_defend_db_arp_entry_del",0x7cc,
             param_1);
    }
  }
  else {
    FUN_004082d0(DAT_007670fc,0xffffffff);
    uVar2 = *(uint *)(DAT_0076710c + param_1 * 0x120);
    if (((int)uVar2 < 0) || (g_arp_defend_profile <= uVar2)) {
      uVar3 = 0xffffffff;
      if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d arp_id(%d) not used.\n","arp_defend_db_arp_entry_del",
               0x7d3,param_1);
      }
    }
    else {
      FUN_004080f0(DAT_00767100,param_1);
      __s = (undefined4 *)(DAT_0076710c + param_1 * 0x120);
      memset(__s,0,0x120);
      *__s = 0xffffffff;
      uVar3 = 0;
      DAT_00767110 = DAT_00767110 + -1;
    }
    FUN_00407f30(DAT_007670fc);
  }
  return uVar3;
}

