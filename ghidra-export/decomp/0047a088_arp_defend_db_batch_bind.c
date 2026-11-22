// func arp_defend_db_batch_bind @ 0047a088 size=1

undefined4
arp_defend_db_batch_bind(int *param_1,int param_2,uint *param_3,size_t param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__s;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  int iStack_48;
  int iStack_40;
  undefined4 *puStack_3c;
  int iStack_38;
  int *piStack_34;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    uVar11 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[ARP_DEFEND_ERROR]%s()/%d Invalid ap params.\n";
    uVar10 = 0x3e2;
  }
  else if ((param_3 == (uint *)0x0) || (param_4 == 0)) {
    uVar11 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[ARP_DEFEND_ERROR]%s()/%d Invalid arp params.\n";
    uVar10 = 999;
  }
  else if (param_5 == (undefined4 *)0x0) {
    uVar11 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar10 = 0x3ec;
  }
  else {
    if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d ap_num: %d, arp_num: %d\n","arp_defend_db_batch_bind",0x3f0,
             param_2,param_4);
    }
    puVar3 = (undefined4 *)FUN_004082a0(DAT_007670f0,4,0x3f2);
    if (puVar3 == (undefined4 *)0x0) {
      if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n","arp_defend_db_batch_bind",0x3f5);
      }
    }
    else {
      __s = (void *)FUN_004082a0(param_4,1,0x3f9);
      if (__s == (void *)0x0) {
        iVar2 = -1;
        if ((arp_defend_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d no memory!\n","arp_defend_db_batch_bind",0x3fc);
        }
      }
      else {
        FUN_004082d0(DAT_007670f8,0xffffffff);
        puStack_3c = param_5;
        piStack_34 = param_1;
        for (iStack_38 = 0; iVar2 = DAT_00767104, iStack_38 < param_2; iStack_38 = iStack_38 + 1) {
          *puStack_3c = 0;
          iVar12 = *piStack_34;
          iVar4 = iVar12;
          if (49999 < iVar12) {
            iVar14 = apmngr_db_get_ap_max();
            iVar4 = apmngr_db_get_template_max();
            iVar4 = iVar12 + -50000 + iVar14 + iVar4;
          }
          iVar14 = DAT_00767104;
          if (*(int *)(iVar2 + iVar4 * 0x10) < 0) {
code_r0x0047a438:
            iVar4 = DAT_00767104;
            iVar2 = iVar12;
            if (49999 < iVar12) {
              iVar14 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar2 = iVar12 + -50000 + iVar14 + iVar2;
            }
            iVar14 = DAT_00767104;
            if (49999 < *(int *)(iVar4 + iVar2 * 0x10)) {
              iVar2 = iVar12;
              if (49999 < iVar12) {
                iVar4 = apmngr_db_get_ap_max();
                iVar2 = apmngr_db_get_template_max();
                iVar2 = iVar12 + -50000 + iVar4 + iVar2;
              }
              iVar4 = *(int *)(iVar14 + iVar2 * 0x10);
              iVar2 = apmngr_db_get_sensor_max();
              if (iVar4 < iVar2 + 50000) goto code_r0x0047a22c;
            }
            if ((arp_defend_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[ARP_DEFEND_WARNING]%s()/%d ap_id(%d) not used.\n","arp_defend_db_batch_bind",
                     0x409,iVar12);
            }
          }
          else {
            iVar2 = iVar12;
            if (49999 < iVar12) {
              iVar4 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar2 = iVar12 + -50000 + iVar4 + iVar2;
            }
            iVar14 = *(int *)(iVar14 + iVar2 * 0x10);
            iVar2 = apmngr_db_get_ap_max();
            iVar4 = apmngr_db_get_template_max();
            if (iVar2 + iVar4 <= iVar14) goto code_r0x0047a438;
code_r0x0047a22c:
            puVar8 = puVar3;
            for (uVar5 = 0; uVar5 < DAT_007670f0; uVar5 = uVar5 + 1) {
              *puVar8 = 0xffffffff;
              puVar8 = puVar8 + 1;
            }
            iVar4 = iVar12 << 4;
            uVar5 = 0;
            memset(__s,0,param_4);
            iStack_40 = 0;
            iVar2 = iVar12 + -50000;
            iStack_48 = 0;
            bVar1 = 49999 < iVar12;
            while (iVar14 = DAT_00767104, uVar5 < DAT_007670f0) {
              iVar6 = iVar4;
              if (bVar1) {
                iVar6 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar6 = (iVar2 + iVar6 + iVar7) * 0x10;
              }
              iVar7 = DAT_00767104;
              iVar13 = uVar5 * 4;
              if (*(int *)(*(int *)(iVar14 + iVar6 + 0xc) + iVar13) < 0) {
code_r0x0047a308:
                puVar3[iStack_48] = uVar5;
                iStack_48 = iStack_48 + 1;
              }
              else {
                iVar14 = iVar4;
                if (bVar1) {
                  iVar14 = apmngr_db_get_ap_max();
                  iVar6 = apmngr_db_get_template_max();
                  iVar14 = (iVar2 + iVar14 + iVar6) * 0x10;
                }
                if (g_arp_defend_profile <= *(uint *)(*(int *)(iVar7 + iVar14 + 0xc) + iVar13))
                goto code_r0x0047a308;
              }
              iVar14 = DAT_00767104;
              iVar6 = iVar4;
              if (bVar1) {
                iVar6 = apmngr_db_get_ap_max();
                iVar7 = apmngr_db_get_template_max();
                iVar6 = (iVar2 + iVar6 + iVar7) * 0x10;
              }
              iVar14 = _arp_defend_binary_search
                                 (param_3,param_4,
                                  *(undefined4 *)(*(int *)(iVar14 + iVar6 + 0xc) + iVar13));
              if (iVar14 < 0) {
code_r0x0047a384:
                uVar5 = uVar5 + 1;
              }
              else {
                if (iVar14 < (int)param_4) {
                  iStack_40 = iStack_40 + 1;
                  *(undefined1 *)((int)__s + iVar14) = 1;
                  goto code_r0x0047a384;
                }
                uVar5 = uVar5 + 1;
              }
            }
            if ((arp_defend_debug_switch != 0) &&
               (iVar14 = is_target_debug_ap(), iVar2 = DAT_00767104, iVar14 != 0)) {
              iVar14 = iVar4;
              if (49999 < iVar12) {
                iVar14 = apmngr_db_get_ap_max();
                iVar6 = apmngr_db_get_template_max();
                iVar14 = (iVar12 + -50000 + iVar14 + iVar6) * 0x10;
              }
              printf("[ARP_DEFEND_DEBUG]%s()/%d ap_id[%d], num_bind_arp[%d], empty_count[%d], select arps\' bind_count[%d]\n"
                     ,"arp_defend_db_batch_bind",0x429,iVar12,*(undefined4 *)(iVar2 + iVar14 + 8),
                     iStack_48,iStack_40);
            }
            iVar2 = 0;
            iVar14 = 0;
            puVar15 = param_3;
            while (iVar6 = DAT_00767104, iVar14 < (int)param_4) {
              if ((-1 < (int)*puVar15) && (*puVar15 < g_arp_defend_profile)) {
                if (iVar2 < iStack_48) {
                  if (iVar2 + iStack_40 < (int)param_4) {
                    if (*(char *)((int)__s + iVar14) == '\0') {
                      iVar7 = iVar4;
                      if (49999 < iVar12) {
                        iVar7 = apmngr_db_get_ap_max();
                        iVar13 = apmngr_db_get_template_max();
                        iVar7 = (iVar12 + -50000 + iVar7 + iVar13) * 0x10;
                      }
                      *(uint *)(*(int *)(iVar6 + iVar7 + 0xc) + puVar3[iVar2] * 4) = *puVar15;
                      iVar6 = DAT_00767104;
                      iVar7 = iVar4;
                      if (49999 < iVar12) {
                        iVar7 = apmngr_db_get_ap_max();
                        iVar13 = apmngr_db_get_template_max();
                        iVar7 = (iVar12 + -50000 + iVar7 + iVar13) * 0x10;
                      }
                      *(int *)(iVar6 + iVar7 + 8) = *(int *)(iVar6 + iVar7 + 8) + 1;
                      *puStack_3c = 1;
                      iVar2 = iVar2 + 1;
                    }
                    goto code_r0x0047a5cc;
                  }
                  if ((arp_defend_debug_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                  break;
                  pcVar9 = 
                  "[ARP_DEFEND_DEBUG]%s()/%d select arps are all binded to ap_id[%d], fill_count[%d]!\n"
                  ;
                  uVar11 = 0x43c;
                }
                else {
                  if ((arp_defend_warning_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)
                     ) break;
                  pcVar9 = 
                  "[ARP_DEFEND_WARNING]%s()/%d ap_id[%d]\'s arp_id_list is full, fill_count[%d]!\n";
                  uVar11 = 0x436;
                }
                printf(pcVar9,"arp_defend_db_batch_bind",uVar11,iVar12,iVar2);
                break;
              }
              if ((arp_defend_err_switch == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0)) {
code_r0x0047a5cc:
                iVar14 = iVar14 + 1;
                puVar15 = puVar15 + 1;
              }
              else {
                printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arps[%d] = %d!\n",
                       "arp_defend_db_batch_bind",0x430,iVar14,*puVar15);
                iVar14 = iVar14 + 1;
                puVar15 = puVar15 + 1;
              }
            }
            if ((arp_defend_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[ARP_DEFEND_DEBUG]%s()/%d ap_id[%d], fill_count[%d]\n",
                     "arp_defend_db_batch_bind",0x448,iVar12,iVar2);
            }
          }
          puStack_3c = puStack_3c + 1;
          piStack_34 = piStack_34 + 1;
        }
        iVar2 = 0;
        FUN_00407f30(DAT_007670f8);
      }
      FUN_00407df0(puVar3);
      if (__s != (void *)0x0) {
        FUN_00407df0(__s);
      }
      if (iVar2 == 0) {
        uVar11 = 0;
        if (arp_defend_debug_switch == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        pcVar9 = "[ARP_DEFEND_DEBUG]%s()/%d succeed to batch_bind()!\n";
        uVar10 = 0x45d;
        goto code_r0x0047a3d0;
      }
    }
    uVar11 = 0xffffffff;
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[ARP_DEFEND_ERROR]%s()/%d fail to batch_bind()!\n";
    uVar10 = 0x461;
  }
code_r0x0047a3d0:
  printf(pcVar9,"arp_defend_db_batch_bind",uVar10);
  return uVar11;
}

