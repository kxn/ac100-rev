// func arp_defend_db_arp_entry_add @ 0047d2ec size=332

undefined4 arp_defend_db_arp_entry_add(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint *__dest;
  undefined4 uVar3;
  
  if (param_1 == (uint *)0x0) {
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp entry.\n","arp_defend_db_arp_entry_add",0x7a0);
    }
  }
  else {
    FUN_004082d0(DAT_007670fc,0xffffffff);
    uVar1 = FUN_004085b0(DAT_00767100);
    if (((int)uVar1 < 0) || (g_arp_defend_profile <= uVar1)) {
      uVar3 = 0xffffffff;
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp id(%d).\n","arp_defend_db_arp_entry_add",0x7a8
               ,uVar1);
      }
    }
    else {
      __dest = (uint *)(DAT_0076710c + uVar1 * 0x120);
      memcpy(__dest,param_1,0x120);
      *__dest = uVar1;
      *param_1 = uVar1;
      DAT_00767110 = DAT_00767110 + 1;
      uVar3 = 0;
    }
    FUN_00407f30(DAT_007670fc);
  }
  return uVar3;
}

