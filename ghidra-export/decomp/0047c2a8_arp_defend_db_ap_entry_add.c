// func arp_defend_db_ap_entry_add @ 0047c2a8 size=756

undefined4 arp_defend_db_ap_entry_add(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < 0) {
LAB_0047c3c8:
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_id(%d).\n","arp_defend_db_ap_entry_add",0x666,
             param_1);
    }
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_0047c3c8;
  FUN_004082d0(DAT_007670f8,0xffffffff);
  iVar1 = DAT_00767104;
  iVar2 = param_1 << 4;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
  }
  iVar3 = DAT_00767104;
  if (*(int *)(iVar1 + iVar2) < 0) {
LAB_0047c40c:
    iVar1 = DAT_00767104;
    iVar2 = param_1 << 4;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
    }
    iVar3 = DAT_00767104;
    if (49999 < *(int *)(iVar1 + iVar2)) {
      iVar1 = param_1 << 4;
      if (49999 < param_1) {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
      }
      iVar2 = *(int *)(iVar3 + iVar1);
      iVar1 = apmngr_db_get_sensor_max();
      if (iVar2 < iVar1 + 50000) goto LAB_0047c360;
    }
    iVar1 = DAT_00767104;
    iVar2 = param_1 << 4;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
    }
    _arp_defend_ap_entry_init(iVar1 + iVar2);
    iVar1 = DAT_00767104;
    iVar2 = param_1 << 4;
    if (49999 < param_1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
    }
    *(int *)(iVar1 + iVar2) = param_1;
    DAT_00767108 = DAT_00767108 + 1;
  }
  else {
    iVar1 = param_1 << 4;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
    }
    iVar3 = *(int *)(iVar3 + iVar1);
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if (iVar1 + iVar2 <= iVar3) goto LAB_0047c40c;
LAB_0047c360:
    if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d ap_entry(%d) has been used.\n","arp_defend_db_ap_entry_add",
             0x66d,param_1);
    }
  }
  FUN_00407f30(DAT_007670f8);
  return 0;
}

