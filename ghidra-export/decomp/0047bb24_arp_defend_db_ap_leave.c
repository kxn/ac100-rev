// func arp_defend_db_ap_leave @ 0047bb24 size=1

undefined4 arp_defend_db_ap_leave(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      FUN_004082d0(DAT_007670f8,0xffffffff);
      iVar1 = DAT_00767104;
      iVar2 = param_1 << 4;
      if (49999 < param_1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
      }
      if (*(int *)(iVar1 + iVar2) == -1) {
        uVar4 = 0xffffffff;
        if ((arp_defend_warning_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[ARP_DEFEND_WARNING]%s()/%d ap_id(%d) is not used.\n","arp_defend_db_ap_leave",
                 0x5c8,param_1);
        }
      }
      else {
        uVar4 = 0;
        _arp_defend_ap_entry_init();
      }
      FUN_00407f30(DAT_007670f8);
      return uVar4;
    }
  }
  if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_id(%d).\n","arp_defend_db_ap_leave",0x5c0,param_1);
  }
  return 0xffffffff;
}

