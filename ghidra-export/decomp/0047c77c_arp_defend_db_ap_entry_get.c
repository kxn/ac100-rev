// func arp_defend_db_ap_entry_get @ 0047c77c size=384

undefined4 arp_defend_db_ap_entry_get(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      if (param_2 != (void *)0x0) {
        FUN_004082d0(DAT_007670f8,0xffffffff);
        iVar1 = DAT_00767104;
        iVar2 = param_1 << 4;
        if (49999 < param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar3 = apmngr_db_get_template_max();
          iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
        }
        memcpy(param_2,(void *)(iVar1 + iVar2),0x10);
        FUN_00407f30(DAT_007670f8);
        return 0;
      }
      if (arp_defend_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap entry.\n","arp_defend_db_ap_entry_get",0x6b9);
        return 0xffffffff;
      }
      return 0xffffffff;
    }
  }
  if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap id(%d).\n","arp_defend_db_ap_entry_get",0x6b3,
           param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

