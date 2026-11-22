// func arp_defend_db_batch_bind_no_optimize @ 0047a9b4 size=2328

undefined4
arp_defend_db_batch_bind_no_optimize
          (int *param_1,int param_2,uint *param_3,int param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *local_50;
  int local_44;
  int local_40;
  uint *local_3c;
  int *local_38;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    uVar9 = 0xffffffff;
    if ((arp_defend_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
      return 0xffffffff;
    }
    pcVar7 = "[ARP_DEFEND_ERROR]%s()/%d Invalid ap params.\n";
    uVar8 = 0x474;
  }
  else if ((param_3 == (uint *)0x0) || (param_4 == 0)) {
    uVar9 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[ARP_DEFEND_ERROR]%s()/%d Invalid arp params.\n";
    uVar8 = 0x479;
  }
  else if (param_5 == (undefined4 *)0x0) {
    uVar9 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar8 = 0x47e;
  }
  else if (param_6 == (undefined4 *)0x0) {
    uVar9 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar7 = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar8 = 0x483;
  }
  else {
    if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d ap_num: %d, arp_num: %d\n",
             "arp_defend_db_batch_bind_no_optimize",0x487,param_2,param_4);
    }
    iVar12 = 0;
    FUN_004082d0(DAT_007670fc,0xffffffff);
    puVar10 = param_3;
    for (iVar3 = 0; iVar3 < param_4; iVar3 = iVar3 + 1) {
      uVar16 = *puVar10;
      if (((((int)uVar16 < 0) || (g_arp_defend_profile <= uVar16)) ||
          (uVar16 = *(uint *)(DAT_0076710c + uVar16 * 0x120), (int)uVar16 < 0)) ||
         (g_arp_defend_profile <= uVar16)) {
        if ((arp_defend_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) {
          *puVar10 = 0xffffffff;
        }
        else {
          printf("[ARP_DEFEND_WARNING]%s()/%d arp_id[%d] is not used!\n",
                 "arp_defend_db_batch_bind_no_optimize",0x490,0xffffffff);
          *puVar10 = 0xffffffff;
        }
        iVar12 = iVar12 + 1;
      }
      puVar10 = puVar10 + 1;
    }
    FUN_00407f30(DAT_007670fc);
    if (iVar12 < param_4) {
      FUN_004082d0(DAT_007670f8,0xffffffff);
      local_50 = param_5;
      local_38 = param_1;
      for (local_44 = 0; local_44 < param_2; local_44 = local_44 + 1) {
        *local_50 = 0;
        iVar3 = *local_38;
        if (iVar3 < 0) {
LAB_0047afcc:
          if ((arp_defend_warning_switch != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
            pcVar7 = "[ARP_DEFEND_WARNING]%s()/%d ap_id:%d is invalid!\n";
            uVar9 = 0x4a5;
LAB_0047aff8:
            printf(pcVar7,"arp_defend_db_batch_bind_no_optimize",uVar9,iVar3);
          }
        }
        else {
          iVar12 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if ((iVar12 + iVar4 <= iVar3) &&
             ((iVar3 < 50000 || (iVar12 = apmngr_db_get_sensor_max(), iVar12 + 50000 <= iVar3))))
          goto LAB_0047afcc;
          iVar4 = DAT_00767104;
          iVar12 = iVar3;
          if (49999 < iVar3) {
            iVar13 = apmngr_db_get_ap_max();
            iVar12 = apmngr_db_get_template_max();
            iVar12 = iVar3 + -50000 + iVar13 + iVar12;
          }
          iVar13 = DAT_00767104;
          if (*(int *)(iVar4 + iVar12 * 0x10) < 0) {
LAB_0047b060:
            iVar4 = DAT_00767104;
            iVar12 = iVar3;
            if (49999 < iVar3) {
              iVar13 = apmngr_db_get_ap_max();
              iVar12 = apmngr_db_get_template_max();
              iVar12 = iVar3 + -50000 + iVar13 + iVar12;
            }
            iVar13 = DAT_00767104;
            if (49999 < *(int *)(iVar4 + iVar12 * 0x10)) {
              iVar12 = iVar3;
              if (49999 < iVar3) {
                iVar4 = apmngr_db_get_ap_max();
                iVar12 = apmngr_db_get_template_max();
                iVar12 = iVar3 + -50000 + iVar4 + iVar12;
              }
              iVar4 = *(int *)(iVar13 + iVar12 * 0x10);
              iVar12 = apmngr_db_get_sensor_max();
              if (iVar4 < iVar12 + 50000) goto LAB_0047acfc;
            }
            if ((arp_defend_warning_switch == 0) || (iVar12 = is_target_debug_ap(), iVar12 == 0))
            goto LAB_0047ae94;
            uVar9 = 0x4ab;
            pcVar7 = "[ARP_DEFEND_WARNING]%s()/%d ap_id[%d] is not used!\n";
            goto LAB_0047aff8;
          }
          iVar12 = iVar3;
          if (49999 < iVar3) {
            iVar4 = apmngr_db_get_ap_max();
            iVar12 = apmngr_db_get_template_max();
            iVar12 = iVar3 + -50000 + iVar4 + iVar12;
          }
          iVar13 = *(int *)(iVar13 + iVar12 * 0x10);
          iVar12 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          if (iVar12 + iVar4 <= iVar13) goto LAB_0047b060;
LAB_0047acfc:
          iVar12 = iVar3 << 4;
          local_40 = 0;
          local_3c = param_3;
          do {
            uVar16 = *local_3c;
            if (((int)uVar16 < 0) || (g_arp_defend_profile <= uVar16)) {
              if ((arp_defend_warning_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("[ARP_DEFEND_WARNING]%s()/%d arp_id:%d is invalid!\n",
                       "arp_defend_db_batch_bind_no_optimize",0x4b4,uVar16);
              }
            }
            else {
              bVar1 = 49999 < iVar3;
              iVar4 = iVar3 + -50000;
              uVar2 = 0;
              uVar15 = 0xffffffff;
              while (uVar14 = uVar2, iVar13 = DAT_00767104, uVar14 < DAT_007670f0) {
                iVar6 = iVar12;
                if (bVar1) {
                  iVar6 = apmngr_db_get_ap_max();
                  iVar5 = apmngr_db_get_template_max();
                  iVar6 = (iVar4 + iVar6 + iVar5) * 0x10;
                }
                iVar5 = DAT_00767104;
                iVar11 = uVar14 * 4;
                if (*(int *)(*(int *)(iVar13 + iVar6 + 0xc) + iVar11) < 0) {
LAB_0047add0:
                  if (uVar15 != 0xffffffff) goto LAB_0047addc;
                  uVar2 = uVar14 + 1;
                  uVar15 = uVar14;
                }
                else {
                  iVar13 = iVar12;
                  if (bVar1) {
                    iVar13 = apmngr_db_get_ap_max();
                    iVar6 = apmngr_db_get_template_max();
                    iVar13 = (iVar4 + iVar13 + iVar6) * 0x10;
                  }
                  if (g_arp_defend_profile <= *(uint *)(*(int *)(iVar5 + iVar13 + 0xc) + iVar11))
                  goto LAB_0047add0;
LAB_0047addc:
                  iVar13 = DAT_00767104;
                  iVar6 = iVar12;
                  if (bVar1) {
                    iVar6 = apmngr_db_get_ap_max();
                    iVar5 = apmngr_db_get_template_max();
                    iVar6 = (iVar4 + iVar6 + iVar5) * 0x10;
                  }
                  if (*(uint *)(*(int *)(iVar13 + iVar6 + 0xc) + iVar11) == uVar16) {
                    uVar15 = 0xffffffff;
                    if ((arp_defend_warning_switch != 0) &&
                       (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                      printf("[ARP_DEFEND_WARNING]%s()/%d arp_id [%d] has been binded to ap_id [%d] already!\n"
                             ,"arp_defend_db_batch_bind_no_optimize",0x4c4,uVar16,iVar3);
                    }
                    break;
                  }
                  uVar2 = uVar14 + 1;
                }
              }
              iVar4 = DAT_00767104;
              iVar13 = iVar12;
              if (49999 < iVar3) {
                iVar13 = apmngr_db_get_ap_max();
                iVar6 = apmngr_db_get_template_max();
                iVar13 = (iVar3 + -50000 + iVar13 + iVar6) * 0x10;
              }
              iVar6 = DAT_00767104;
              if (*(uint *)(iVar4 + iVar13 + 8) < DAT_007670f0) {
                if (uVar15 != 0xffffffff) {
                  iVar4 = iVar12;
                  if (49999 < iVar3) {
                    iVar4 = apmngr_db_get_ap_max();
                    iVar13 = apmngr_db_get_template_max();
                    iVar4 = (iVar3 + -50000 + iVar4 + iVar13) * 0x10;
                  }
                  *(uint *)(*(int *)(iVar6 + iVar4 + 0xc) + uVar15 * 4) = uVar16;
                  iVar4 = DAT_00767104;
                  iVar13 = iVar12;
                  if (49999 < iVar3) {
                    iVar13 = apmngr_db_get_ap_max();
                    iVar6 = apmngr_db_get_template_max();
                    iVar13 = (iVar3 + -50000 + iVar13 + iVar6) * 0x10;
                  }
                  *(int *)(iVar4 + iVar13 + 8) = *(int *)(iVar4 + iVar13 + 8) + 1;
                  *local_50 = 1;
                }
              }
              else if ((uVar15 != 0xffffffff) || (uVar14 == DAT_007670f0)) {
                if ((arp_defend_warning_switch != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0)
                   ) {
                  printf("[ARP_DEFEND_WARNING]%s()/%d Can NOT find empty space for new bind, ap_id [%d]!\n"
                         ,"arp_defend_db_batch_bind_no_optimize",0x4cd,iVar3);
                }
                *param_6 = 1;
                break;
              }
            }
            local_40 = local_40 + 1;
            local_3c = local_3c + 1;
          } while (local_40 < param_4);
        }
LAB_0047ae94:
        local_50 = local_50 + 1;
        local_38 = local_38 + 1;
      }
      FUN_00407f30(DAT_007670f8);
      if (arp_defend_debug_switch == 0) {
        return 0;
      }
      uVar9 = 0;
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      pcVar7 = "[ARP_DEFEND_DEBUG]%s()/%d succeed to batch_bind()!\n";
      uVar8 = 0x4e1;
    }
    else {
      uVar9 = 0xffffffff;
      if (arp_defend_debug_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "[ARP_DEFEND_DEBUG]%s()/%d fail to batch_bind()!\n";
      uVar8 = 0x4e5;
    }
  }
  printf(pcVar7,"arp_defend_db_batch_bind_no_optimize",uVar8);
  return uVar9;
}

