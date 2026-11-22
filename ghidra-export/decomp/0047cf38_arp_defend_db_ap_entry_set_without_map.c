// func arp_defend_db_ap_entry_set_without_map @ 0047cf38 size=396

undefined4 arp_defend_db_ap_entry_set_without_map(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (int *)0x0) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid mac entry.\n","arp_defend_db_ap_entry_set_without_map"
           ,0x700);
    return 0xffffffff;
  }
  iVar4 = *param_1;
  if (iVar4 < 0) {
    iVar4 = *param_1;
  }
  else {
    iVar1 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if (iVar4 < iVar1 + iVar3) goto LAB_0047cf8c;
    iVar4 = *param_1;
  }
  if ((iVar4 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= iVar4)) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap entry Id(%d).\n",
           "arp_defend_db_ap_entry_set_without_map",0x706,*param_1);
    return 0xffffffff;
  }
LAB_0047cf8c:
  FUN_004082d0(DAT_007670f8,0xffffffff);
  iVar4 = DAT_00767104;
  iVar3 = *param_1;
  iVar1 = iVar3 << 4;
  if (49999 < iVar3) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    iVar1 = (iVar3 + -50000 + iVar1 + iVar2) * 0x10;
  }
  memcpy((void *)(iVar4 + iVar1),param_1,0x10);
  FUN_00407f30(DAT_007670f8);
  return 0;
}

