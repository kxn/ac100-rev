// func arp_defend_db_batch_unbind @ 0047b2cc size=1424

undefined4
arp_defend_db_batch_unbind(int *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_34;
  int *local_30;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    uVar8 = 0xffffffff;
    if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      return 0xffffffff;
    }
    pcVar6 = "[ARP_DEFEND_ERROR]%s()/%d Invalid ap params.\n";
    uVar7 = 0x4f5;
  }
  else if ((param_3 == 0) || (param_4 == 0)) {
    uVar8 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[ARP_DEFEND_ERROR]%s()/%d Invalid arp params.\n";
    uVar7 = 0x4fa;
  }
  else if (param_5 == (undefined4 *)0x0) {
    uVar8 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar7 = 0x4ff;
  }
  else {
    FUN_004082d0(DAT_007670f8,0xffffffff);
    local_30 = param_1;
    for (local_34 = 0; local_34 < param_2; local_34 = local_34 + 1) {
      *param_5 = 0;
      iVar2 = *local_30;
      if (iVar2 < 0) {
LAB_0047b5fc:
        if ((arp_defend_warning_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          pcVar6 = "[ARP_DEFEND_WARNING]%s()/%d ap_id:%d is invalid!\n";
          uVar8 = 0x50c;
LAB_0047b628:
          printf(pcVar6,"arp_defend_db_batch_unbind",uVar8,iVar2);
        }
      }
      else {
        iVar3 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        if ((iVar3 + iVar4 <= iVar2) &&
           ((iVar2 < 50000 || (iVar3 = apmngr_db_get_sensor_max(), iVar3 + 50000 <= iVar2))))
        goto LAB_0047b5fc;
        iVar4 = DAT_00767104;
        iVar3 = iVar2;
        if (49999 < iVar2) {
          iVar9 = apmngr_db_get_ap_max();
          iVar3 = apmngr_db_get_template_max();
          iVar3 = iVar2 + -50000 + iVar9 + iVar3;
        }
        iVar9 = DAT_00767104;
        if (*(int *)(iVar4 + iVar3 * 0x10) < 0) {
LAB_0047b68c:
          iVar4 = DAT_00767104;
          iVar3 = iVar2;
          if (49999 < iVar2) {
            iVar9 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar3 = iVar2 + -50000 + iVar9 + iVar3;
          }
          iVar9 = DAT_00767104;
          if (49999 < *(int *)(iVar4 + iVar3 * 0x10)) {
            iVar3 = iVar2;
            if (49999 < iVar2) {
              iVar4 = apmngr_db_get_ap_max();
              iVar3 = apmngr_db_get_template_max();
              iVar3 = iVar2 + -50000 + iVar4 + iVar3;
            }
            iVar4 = *(int *)(iVar9 + iVar3 * 0x10);
            iVar3 = apmngr_db_get_sensor_max();
            if (iVar4 < iVar3 + 50000) goto LAB_0047b47c;
          }
          if ((arp_defend_warning_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0047b634;
          pcVar6 = "[ARP_DEFEND_WARNING]%s()/%d ap_id[%d] is not used!\n";
          uVar8 = 0x511;
          goto LAB_0047b628;
        }
        iVar3 = iVar2;
        if (49999 < iVar2) {
          iVar4 = apmngr_db_get_ap_max();
          iVar3 = apmngr_db_get_template_max();
          iVar3 = iVar2 + -50000 + iVar4 + iVar3;
        }
        iVar9 = *(int *)(iVar9 + iVar3 * 0x10);
        iVar3 = apmngr_db_get_ap_max();
        iVar4 = apmngr_db_get_template_max();
        if (iVar3 + iVar4 <= iVar9) goto LAB_0047b68c;
LAB_0047b47c:
        iVar3 = iVar2 << 4;
        bVar1 = 49999 < iVar2;
        uVar11 = 0;
        iVar2 = iVar2 + -50000;
        while (iVar4 = DAT_00767104, uVar11 < DAT_007670f0) {
          iVar9 = iVar3;
          if (bVar1) {
            iVar9 = apmngr_db_get_ap_max();
            iVar5 = apmngr_db_get_template_max();
            iVar9 = (iVar2 + iVar9 + iVar5) * 0x10;
          }
          iVar5 = DAT_00767104;
          iVar10 = uVar11 * 4;
          if (*(int *)(*(int *)(iVar4 + iVar9 + 0xc) + iVar10) < 0) {
LAB_0047b59c:
            uVar11 = uVar11 + 1;
          }
          else {
            iVar4 = iVar3;
            if (bVar1) {
              iVar4 = apmngr_db_get_ap_max();
              iVar9 = apmngr_db_get_template_max();
              iVar4 = (iVar2 + iVar4 + iVar9) * 0x10;
            }
            iVar9 = DAT_00767104;
            if (*(uint *)(*(int *)(iVar5 + iVar4 + 0xc) + iVar10) < g_arp_defend_profile) {
              iVar4 = iVar3;
              if (bVar1) {
                iVar4 = apmngr_db_get_ap_max();
                iVar5 = apmngr_db_get_template_max();
                iVar4 = (iVar2 + iVar4 + iVar5) * 0x10;
              }
              iVar9 = _arp_defend_binary_search
                                (param_3,param_4,
                                 *(undefined4 *)(*(int *)(iVar9 + iVar4 + 0xc) + iVar10));
              iVar4 = DAT_00767104;
              if (-1 < iVar9) {
                iVar9 = iVar3;
                if (bVar1) {
                  iVar9 = apmngr_db_get_ap_max();
                  iVar5 = apmngr_db_get_template_max();
                  iVar9 = (iVar2 + iVar9 + iVar5) * 0x10;
                }
                *(undefined4 *)(*(int *)(iVar4 + iVar9 + 0xc) + iVar10) = 0xffffffff;
                iVar4 = DAT_00767104;
                iVar9 = iVar3;
                if (bVar1) {
                  iVar9 = apmngr_db_get_ap_max();
                  iVar5 = apmngr_db_get_template_max();
                  iVar9 = (iVar2 + iVar9 + iVar5) * 0x10;
                }
                *(int *)(iVar4 + iVar9 + 8) = *(int *)(iVar4 + iVar9 + 8) + -1;
                *param_5 = 1;
              }
              goto LAB_0047b59c;
            }
            uVar11 = uVar11 + 1;
          }
        }
      }
LAB_0047b634:
      param_5 = param_5 + 1;
      local_30 = local_30 + 1;
    }
    uVar8 = 0;
    FUN_00407f30(DAT_007670f8);
    if (arp_defend_debug_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar6 = "[ARP_DEFEND_DEBUG]%s()/%d succeed to batch_unbind()!\n";
    uVar7 = 0x523;
  }
  printf(pcVar6,"arp_defend_db_batch_unbind",uVar7);
  return uVar8;
}

