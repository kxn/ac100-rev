// func arp_defend_db_ap_entry_set @ 0047c8fc size=696

undefined4 arp_defend_db_ap_entry_set(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) {
    if (arp_defend_err_switch != 0) {
      iVar5 = is_target_debug_ap();
      if (iVar5 == 0) {
        return 0xffffffff;
      }
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid mac entry.\n","arp_defend_db_ap_entry_set",0x6d7);
      return 0xffffffff;
    }
LAB_0047c994:
    uVar4 = 0xffffffff;
  }
  else {
    iVar5 = *param_1;
    if (iVar5 < 0) {
      iVar5 = *param_1;
LAB_0047c968:
      if ((iVar5 < 50000) || (iVar1 = apmngr_db_get_sensor_max(), iVar1 + 50000 <= iVar5)) {
        if ((arp_defend_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap entry Id(%d).\n","arp_defend_db_ap_entry_set"
                 ,0x6dd,*param_1);
          return 0xffffffff;
        }
        goto LAB_0047c994;
      }
    }
    else {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      if (iVar1 + iVar2 <= iVar5) {
        iVar5 = *param_1;
        goto LAB_0047c968;
      }
    }
    FUN_004082d0(DAT_007670f8,0xffffffff);
    iVar1 = DAT_00767104;
    iVar5 = *param_1;
    if (49999 < iVar5) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar5 = iVar5 + -50000 + iVar2 + iVar3;
    }
    *(int *)(iVar1 + iVar5 * 0x10) = *param_1;
    iVar1 = DAT_00767104;
    iVar5 = *param_1;
    if (49999 < iVar5) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar5 = iVar5 + -50000 + iVar2 + iVar3;
    }
    *(undefined1 *)(iVar1 + iVar5 * 0x10 + 4) = *(undefined1 *)(param_1 + 1);
    iVar1 = DAT_00767104;
    iVar5 = *param_1;
    if (49999 < iVar5) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar5 = iVar5 + -50000 + iVar2 + iVar3;
    }
    *(int *)(iVar1 + iVar5 * 0x10 + 8) = param_1[2];
    for (uVar6 = 0; iVar5 = DAT_00767104, uVar6 < DAT_007670f0; uVar6 = uVar6 + 1) {
      iVar1 = *param_1;
      if (49999 < iVar1) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar1 = iVar1 + -50000 + iVar2 + iVar3;
      }
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      *(undefined4 *)(*(int *)(iVar5 + iVar1 * 0x10 + 0xc) + uVar6 * 4) = uVar4;
    }
    uVar4 = 0;
    DAT_00767108 = DAT_00767108 + 1;
    FUN_00407f30(DAT_007670f8);
  }
  return uVar4;
}

