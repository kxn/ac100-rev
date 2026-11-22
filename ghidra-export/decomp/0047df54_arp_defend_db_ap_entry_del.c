// func arp_defend_db_ap_entry_del @ 0047df54 size=576

undefined4 arp_defend_db_ap_entry_del(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *__format;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar1 = *(ushort *)(param_1 + 0x10);
  iVar2 = apmngr_db_get_ap_max();
  iVar3 = apmngr_db_get_template_max();
  if (((int)(uint)uVar1 < iVar2 + iVar3) ||
     ((uVar1 = *(ushort *)(param_1 + 0x10), 49999 < uVar1 &&
      (iVar2 = apmngr_db_get_sensor_max(), (int)(uint)uVar1 < iVar2 + 50000)))) {
    iVar2 = DAT_00767104;
    uVar8 = (uint)*(ushort *)(param_1 + 0x10);
    if (49999 < uVar8) {
      iVar3 = apmngr_db_get_ap_max();
      iVar5 = apmngr_db_get_template_max();
      uVar8 = (uVar8 - 50000) + iVar3 + iVar5;
    }
    if (*(int *)(iVar2 + uVar8 * 0x10) != -1) {
      FUN_004082d0(DAT_007670fc,0xffffffff);
      iVar2 = DAT_00767104;
      uVar8 = (uint)*(ushort *)(param_1 + 0x10);
      if (49999 < uVar8) {
        iVar3 = apmngr_db_get_ap_max();
        iVar5 = apmngr_db_get_template_max();
        uVar8 = (uVar8 - 50000) + iVar3 + iVar5;
      }
      puVar7 = (undefined4 *)(iVar2 + uVar8 * 0x10);
      if (*(int *)(param_1 + 0x3c) != 0) {
        puVar4 = (undefined4 *)FUN_00408450(4,0x734);
        if (puVar4 == (undefined4 *)0x0) {
          if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(4), iVar2 != 0)) {
            printf("[ARP_DEFEND_ERROR]%s()/%d no memory.\n","arp_defend_db_ap_entry_del",0x73d);
          }
        }
        else {
          *puVar4 = *puVar7;
          arp_defend_db_msg_send(4,puVar4);
        }
      }
      _arp_defend_ap_entry_init(puVar7);
      DAT_00767108 = DAT_00767108 + -1;
      FUN_00407f30(DAT_007670fc);
      return 0;
    }
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d ap entry(%d) not used.\n";
    uVar6 = 0x72b;
  }
  else {
    if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid ap id(%d).\n";
    uVar6 = 0x725;
  }
  printf(__format,"arp_defend_db_ap_entry_del",uVar6,(uint)*(ushort *)(param_1 + 0x10));
  return 0xffffffff;
}

