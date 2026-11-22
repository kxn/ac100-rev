// func arp_defend_db_ap_entry_not_used @ 0047c08c size=540

bool arp_defend_db_ap_entry_not_used(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (param_1 < 0) {
LAB_0047c1f8:
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_id(%d).\n","arp_defend_db_ap_entry_not_used",
             0x652,param_1);
    }
    return false;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  if ((iVar1 + iVar2 <= param_1) &&
     ((param_1 < 50000 || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= param_1))))
  goto LAB_0047c1f8;
  FUN_004082d0(DAT_007670f8,0xffffffff);
  iVar1 = DAT_00767104;
  iVar2 = param_1 << 4;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
  }
  iVar3 = DAT_00767104;
  if (-1 < *(int *)(iVar1 + iVar2)) {
    iVar1 = param_1 << 4;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
    }
    iVar3 = *(int *)(iVar3 + iVar1);
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    bVar4 = false;
    if (iVar3 < iVar1 + iVar2) goto LAB_0047c1a0;
  }
  iVar1 = DAT_00767104;
  iVar2 = param_1 << 4;
  if (49999 < param_1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar2 = (param_1 + -50000 + iVar2 + iVar3) * 0x10;
  }
  iVar3 = DAT_00767104;
  bVar4 = true;
  if (49999 < *(int *)(iVar1 + iVar2)) {
    iVar1 = param_1 << 4;
    if (49999 < param_1) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar1 = (param_1 + -50000 + iVar1 + iVar2) * 0x10;
    }
    iVar2 = *(int *)(iVar3 + iVar1);
    iVar1 = apmngr_db_get_sensor_max();
    bVar4 = iVar1 + 50000 <= iVar2;
  }
LAB_0047c1a0:
  FUN_00407f30(DAT_007670f8);
  return bVar4;
}

