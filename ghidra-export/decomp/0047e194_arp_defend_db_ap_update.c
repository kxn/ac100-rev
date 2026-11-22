// func arp_defend_db_ap_update @ 0047e194 size=536

undefined4 arp_defend_db_ap_update(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      piVar3 = (int *)FUN_00408450((DAT_007670f0 + 4) * 4,0x5ea);
      if (piVar3 != (int *)0x0) {
        FUN_004082d0(DAT_007670f8,0xffffffff);
        iVar1 = DAT_00767104;
        piVar3[3] = (int)(piVar3 + 4);
        iVar2 = param_1 << 4;
        if (49999 < param_1) {
          iVar2 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar2 = (param_1 + -50000 + iVar2 + iVar4) * 0x10;
        }
        _arp_defend_db_ap_entry_deep_copy(piVar3,iVar1 + iVar2);
        if (*piVar3 == -1) {
          if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[ARP_DEFEND_ERROR]%s()/%d ap_entry(%d) update error.\n",
                   "arp_defend_db_ap_update",0x5fc,param_1);
          }
          FUN_00407f30(DAT_007670f8);
          FUN_00407df0(piVar3);
          return 0xffffffff;
        }
        arp_defend_db_msg_send(1,piVar3);
        FUN_00407f30(DAT_007670f8);
        return 0;
      }
      if (arp_defend_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        printf("[ARP_DEFEND_ERROR]%s()/%d no momery.\n","arp_defend_db_ap_update",0x5ed);
        return 0xffffffff;
      }
      return 0xffffffff;
    }
  }
  if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_id(%d).\n","arp_defend_db_ap_update",0x5e6,param_1)
    ;
    return 0xffffffff;
  }
  return 0xffffffff;
}

