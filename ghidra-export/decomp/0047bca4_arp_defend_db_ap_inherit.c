// func arp_defend_db_ap_inherit @ 0047bca4 size=1000

undefined4 arp_defend_db_ap_inherit(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_3 == 0) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Invalid ap_entry.\n","arp_defend_db_ap_inherit",0x622);
    return 0xffffffff;
  }
  if (-1 < param_1) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    if ((param_1 < iVar1 + iVar2) ||
       ((49999 < param_1 && (iVar1 = apmngr_db_get_sensor_max(), param_1 < iVar1 + 50000)))) {
      if (-1 < param_2) {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        if ((param_2 < iVar1 + iVar2) ||
           ((49999 < param_2 && (iVar1 = apmngr_db_get_sensor_max(), param_2 < iVar1 + 50000)))) {
          FUN_004082d0(DAT_007670f8,0xffffffff);
          iVar1 = DAT_00767104;
          iVar2 = param_1 << 4;
          if (49999 < param_1) {
            iVar2 = apmngr_db_get_ap_max();
            iVar7 = apmngr_db_get_template_max();
            iVar2 = (param_1 + -50000 + iVar2 + iVar7) * 0x10;
          }
          iVar7 = DAT_00767104;
          if (*(int *)(iVar1 + iVar2) == -1) {
            uVar5 = 0xffffffff;
            if ((arp_defend_warning_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_0047be94;
            pcVar4 = "[ARP_DEFEND_WARNING]%s()/%d parent_id[%d] is not used!\n";
            uVar6 = 0x635;
            param_2 = param_1;
          }
          else {
            iVar1 = param_2 << 4;
            if (49999 < param_2) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar1 = (param_2 + -50000 + iVar1 + iVar2) * 0x10;
            }
            iVar2 = DAT_00767104;
            if (*(int *)(iVar7 + iVar1) == -1) {
              uVar5 = 0xffffffff;
              if ((arp_defend_warning_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0047be94;
              pcVar4 = "[ARP_DEFEND_WARNING]%s()/%d child_id[%d] is not used!\n";
              uVar6 = 0x63b;
            }
            else {
              iVar1 = param_1 << 4;
              if (49999 < param_1) {
                iVar1 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar1 = (param_1 + -50000 + iVar1 + iVar7) * 0x10;
              }
              iVar7 = DAT_00767104;
              iVar2 = iVar2 + iVar1;
              iVar1 = param_2 << 4;
              if (49999 < param_2) {
                iVar1 = apmngr_db_get_ap_max();
                iVar3 = apmngr_db_get_template_max();
                iVar1 = (param_2 + -50000 + iVar1 + iVar3) * 0x10;
              }
              iVar7 = iVar7 + iVar1;
              *(undefined1 *)(iVar7 + 4) = *(undefined1 *)(iVar2 + 4);
              *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar2 + 8);
              if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                printf("[ARP_DEFEND_DEBUG]%s()/%d child bind_list:%p\n","arp_defend_db_ap_inherit",
                       0x642,*(undefined4 *)(iVar7 + 0xc));
              }
              memcpy(*(void **)(iVar7 + 0xc),*(void **)(iVar2 + 0xc),DAT_007670f0 << 2);
              uVar5 = 0;
              if ((arp_defend_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0047be94;
              param_2 = *(int *)(iVar7 + 0xc);
              pcVar4 = "[ARP_DEFEND_DEBUG]%s()/%d child bind_list:%p\n";
              uVar6 = 0x644;
            }
          }
          printf(pcVar4,"arp_defend_db_ap_inherit",uVar6,param_2);
LAB_0047be94:
          FUN_00407f30(DAT_007670f8);
          return uVar5;
        }
      }
      if (arp_defend_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d child_id[%d] is invalid!\n";
      uVar5 = 0x62e;
      goto LAB_0047bed8;
    }
  }
  if (arp_defend_err_switch == 0) {
    return 0xffffffff;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d parent_id[%d] is invalid!\n";
  uVar5 = 0x628;
  param_2 = param_1;
LAB_0047bed8:
  printf(pcVar4,"arp_defend_db_ap_inherit",uVar5,param_2);
  return 0xffffffff;
}

