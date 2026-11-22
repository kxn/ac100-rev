// func _rrm_pkt_rssi_request @ 004adad4 size=2460

/* WARNING: Removing unreachable block (ram,0x004adfd4) */

undefined4 _rrm_pkt_rssi_request(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  short *psVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  int iVar18;
  int local_670;
  int local_66c;
  int local_668;
  uint local_664 [2];
  short local_65c [8];
  uint local_64c [22];
  char local_5f4;
  undefined1 auStack_5e8 [16];
  ushort local_5d8;
  int local_5d4;
  short local_5d0;
  uint local_398;
  uint local_33c;
  undefined1 auStack_310 [16];
  ushort local_300;
  int local_2fc;
  short local_2f8;
  int local_c0;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  memset(auStack_310,0,0x2d8);
  memset(auStack_5e8,0,0x2d8);
  local_664[0] = 0;
  local_664[1] = 0;
  local_64c[0] = 0;
  local_64c[1] = 0;
  local_64c[2] = 0;
  local_64c[3] = 0;
  local_65c[0] = 0;
  local_65c[1] = 0;
  local_65c[2] = 0;
  local_65c[3] = 0;
  local_65c[4] = 0;
  local_65c[5] = 0;
  local_65c[6] = 0;
  local_65c[7] = 0;
  memset(local_64c + 4,0,0x54);
  local_668 = 0;
  local_66c = 0;
  local_670 = 0;
  rrm_pkt_dump(param_2);
  if (param_1 == (byte *)0x0) {
    uVar11 = 0xffffffff;
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar9 = "[RRM_ERROR]%s()/%d wrong input\n";
    uVar12 = 0x6b4;
LAB_004adbfc:
    printf(pcVar9,"_rrm_pkt_rssi_request",uVar12);
    return uVar11;
  }
  mesh_db_mesh_enable_get(&local_670);
  iVar2 = rrm_db_state_get();
  if (iVar2 == 1) {
    iVar2 = apmngr_db_entry_get_by_mac(param_3,auStack_310);
    if ((iVar2 != 0) || (-1 < local_c0 << 4)) {
      uVar11 = 0;
      if (rrm_warning_switch == '\0') {
        return 0;
      }
      pcVar9 = "[RRM_WARNING]%s()/%d can not find the AP or AP does not support rrm\n";
      uVar12 = 0x72f;
      goto LAB_004adbfc;
    }
    iVar2 = rdmngr_db_generate_rd_id(local_300,*param_1);
    iVar3 = rdmngr_db_rd_entry_get(iVar2,local_64c + 4);
    if ((((iVar3 != 0) || (local_64c[4] == -1)) || (local_5f4 != '\x01')) ||
       (iVar3 = rdmngr_db_get_freq_band_idx(iVar2,&local_668,&local_66c), iVar3 != 0)) {
      if (rrm_err_switch == '\0') {
        return 0;
      }
      uVar11 = 0x6d4;
      goto LAB_004adc80;
    }
    if (local_668 == 0) {
      local_38 = 0;
      iVar2 = ap_para;
LAB_004adeb0:
      if (iVar2 != 0) {
        iVar3 = (int)*(short *)(*(int *)(iVar2 + 0x14) + (uint)local_300 * 2);
        if (((iVar3 < 0) ||
            (*(char *)(*(int *)(iVar2 + 0x1c) + iVar3 * 0xf + (uint)*param_1 + 2) < '\0')) ||
           (iVar3 = rrm_ap_para_neighbor_radio_map_get(iVar2), iVar3 != 0)) {
          if (rrm_warning_switch != '\0') {
            printf("[RRM_WARNING]%s()/%d illegal radio id of (%d,%d)\n","_rrm_pkt_rssi_request",
                   0x72a,(uint)local_300,(uint)*param_1);
            return 0;
          }
          return 0;
        }
        if ((local_2fc == 4) || (local_2fc == 8)) {
          uVar6 = (uint)local_2f8;
        }
        else {
          uVar6 = (uint)local_2f8;
          if (local_2fc != 6) {
            uVar6 = (uint)local_300;
          }
        }
        uVar5 = rdmngr_db_get_freq_band_rd_id(uVar6,1,1);
        iVar3 = 0;
LAB_004adf40:
        uVar1 = *(ushort *)(param_1 + 2);
LAB_004adf44:
        if ((int)(uint)uVar1 <= iVar3) {
          rrm_ap_para_neighbor_radio_map_set(iVar2,local_300,*param_1,1);
          if (((local_670 != 0) && (local_668 == 0)) &&
             (((local_2fc == 1 || ((local_2fc == 3 || (local_2fc == 2)))) && (uVar5 != 0xffffffff)))
             ) {
            iVar3 = rrm_ap_para_neighbor_radio_map_get(DAT_00767bfc,local_300,uVar5 & 0xf);
            if (iVar3 != -1) {
              rrm_ap_para_neighbor_radio_map_set(DAT_00767bfc,local_300,uVar5 & 0xf,1);
            }
          }
          iVar2 = rrm_ap_para_is_collect_finished(iVar2);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = 0;
          piVar16 = &ap_para;
          piVar17 = piVar16;
          do {
            if ((iVar2 != local_38) &&
               (iVar3 = rrm_ap_para_is_collect_finished(*piVar17), iVar3 == 0)) {
              return 0;
            }
            iVar2 = iVar2 + 1;
            piVar17 = piVar17 + 1;
          } while (iVar2 != 3);
          rrm_db_state_set(2);
          iVar2 = ap_para;
          while( true ) {
            piVar16 = piVar16 + 1;
            rrm_ap_para_exceed_neighbor_delete(iVar2,6);
            if (piVar16 == (int *)&g_rrm_cb_list) break;
            iVar2 = *piVar16;
          }
          if (rrm_collect_timer == -1) goto LAB_004ae0f4;
          FUN_00408060();
          goto LAB_004ae0f0;
        }
        iVar4 = apmngr_db_entry_get_by_mac(*(int *)(param_1 + 4) + iVar3 * 0xc,auStack_5e8);
        if (iVar4 == 0) {
          if (local_33c < 2) goto LAB_004ae040;
          if ((int)(local_398 << 4) < 0) {
            puVar7 = local_64c;
            iVar15 = *(int *)(param_1 + 4) + iVar3 * 0xc;
            uVar13 = (uint)*(byte *)(iVar15 + 7);
            for (iVar4 = 0; iVar4 < (int)uVar13; iVar4 = iVar4 + 1) {
              puVar10 = (undefined1 *)(*(int *)(iVar15 + 8) + iVar4 * 3);
              *(undefined1 *)((int)local_664 + iVar4) = *puVar10;
              iVar18 = (char)puVar10[2] + 100;
              *(short *)puVar7 = (short)((iVar18 * iVar18) / 100);
              puVar7 = (uint *)((int)puVar7 + 2);
            }
            if (uVar13 != 0) {
              rrm_ap_para_neighbor_add
                        (iVar2,local_300,*param_1,local_5d8,local_664,local_64c,uVar13,6);
            }
            if (local_670 == 0) {
              iVar3 = iVar3 + 1;
            }
            else {
              if (uVar13 != 1) goto LAB_004ae040;
              if (local_668 == 0) {
                if ((local_2fc == 0) && (local_5d4 == 0)) {
                  iVar3 = iVar3 + 1;
                }
                else if (uVar5 == 0xffffffff) {
LAB_004ae040:
                  iVar3 = iVar3 + 1;
                }
                else {
                  local_30 = uVar6 & 0xffff;
                  local_2c = uVar5 & 0xf;
                  iVar4 = rrm_ap_para_neighbor_radio_map_get(DAT_00767bfc,local_30,local_2c);
                  if (iVar4 == -1) goto LAB_004ae040;
                  if ((local_5d4 == 4) || (local_5d4 == 8)) {
                    uVar13 = (uint)local_5d0;
                  }
                  else {
                    uVar13 = (uint)local_5d0;
                    if (local_5d4 != 6) {
                      uVar13 = (uint)local_5d8;
                    }
                  }
                  if (uVar6 == uVar13) goto LAB_004ae040;
                  local_34 = rdmngr_db_get_freq_band_rd_id(uVar13,1,1);
                  local_664[0] = CONCAT13((char)local_34,local_664[0]._1_3_) & 0xfffffff;
                  if (local_34 == 0xffffffff) goto LAB_004ae040;
                  iVar4 = rrm_ap_para_neighbor_radio_map_get(DAT_00767bfc,uVar13 & 0xffff);
                  if (iVar4 == -1) goto LAB_004ae040;
                  rrm_ap_para_neighbor_add
                            (DAT_00767bfc,local_30,local_2c,uVar13 & 0xffff,local_664,local_64c,1,6)
                  ;
                  iVar3 = iVar3 + 1;
                  if (rrm_debug_switch != '\0') goto code_r0x004ae41c;
                }
              }
              else {
                iVar3 = iVar3 + 1;
              }
            }
          }
          else {
            iVar3 = iVar3 + 1;
          }
        }
        else {
          iVar3 = iVar3 + 1;
        }
        goto LAB_004adf40;
      }
    }
    else if ((local_668 == 1) && (local_38 = local_66c, local_66c < 3)) {
      iVar2 = (&ap_para)[local_66c];
      goto LAB_004adeb0;
    }
    if (rrm_err_switch == '\0') {
      return 0;
    }
    pcVar9 = "[RRM_ERROR]%s()/%d freq band(%d) is illegal \n";
    uVar11 = 0x6d9;
    iVar2 = local_668;
    goto LAB_004adc84;
  }
  if (iVar2 != 4) {
    return 0;
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_3,auStack_310);
  if (iVar2 != 0) {
    return 0;
  }
  if (-1 < local_c0 << 4) {
    return 0;
  }
  iVar2 = rdmngr_db_generate_rd_id(local_300,*param_1);
  iVar3 = rdmngr_db_rd_entry_get(iVar2,local_64c + 4);
  if (((iVar3 != 0) || (local_5f4 != '\x01')) ||
     (iVar3 = rdmngr_db_get_freq_band_idx(iVar2,&local_668,&local_66c), iVar3 != 0)) {
    if (rrm_err_switch == '\0') {
      return 0;
    }
    uVar11 = 0x74b;
LAB_004adc80:
    pcVar9 = "[RRM_ERROR]%s()/%d get rd entry of id(%d) failed\n";
    goto LAB_004adc84;
  }
  if (local_668 == 0) {
    iVar2 = ap_pwr_para;
    iVar3 = 0;
LAB_004add68:
    if (iVar2 != 0) {
      iVar4 = (int)*(short *)(*(int *)(iVar2 + 0x14) + (uint)local_300 * 2);
      if ((iVar4 < 0) ||
         (iVar15 = 0, *(char *)(*(int *)(iVar2 + 0x1c) + iVar4 * 0xf + (uint)*param_1 + 2) < '\0'))
      {
        if (rrm_warning_switch != '\0') {
          printf("[RRM_WARNING]%s()/%d illegal radio id of (%d,%d)\n","_rrm_pkt_rssi_request",0x787,
                 (uint)local_300,(uint)*param_1);
          return 0;
        }
        return 0;
      }
LAB_004addbc:
      do {
        if ((int)(uint)*(ushort *)(param_1 + 2) <= iVar15) {
          rrm_ap_pwr_para_neighbor_radio_map_set(iVar2,local_300,*param_1,1);
          iVar2 = rrm_ap_pwr_para_is_collect_finished(iVar2);
          if (iVar2 == 0) {
            return 0;
          }
          iVar2 = 0;
          puVar14 = &ap_pwr_para;
          do {
            if ((iVar2 != iVar3) &&
               (iVar4 = rrm_ap_pwr_para_is_collect_finished(*puVar14), iVar4 == 0)) {
              return 0;
            }
            iVar2 = iVar2 + 1;
            puVar14 = puVar14 + 1;
          } while (iVar2 != 3);
          rrm_db_state_set(5);
          if (rrm_collect_timer != -1) {
            FUN_00408060();
LAB_004ae0f0:
            rrm_collect_timer = -1;
          }
LAB_004ae0f4:
          FUN_004081c0(rrm_signal);
          return 0;
        }
        iVar4 = apmngr_db_entry_get_by_mac(*(int *)(param_1 + 4) + iVar15 * 0xc,auStack_5e8);
        if (iVar4 != 0) {
          iVar15 = iVar15 + 1;
          goto LAB_004addbc;
        }
        if (local_33c < 2) {
LAB_004ade80:
          iVar15 = iVar15 + 1;
        }
        else {
          if ((local_398 & 0x8000000) != 0) {
            psVar8 = local_65c;
            iVar18 = *(int *)(param_1 + 4) + iVar15 * 0xc;
            uVar6 = (uint)*(byte *)(iVar18 + 7);
            for (iVar4 = 0; iVar4 < (int)uVar6; iVar4 = iVar4 + 1) {
              puVar10 = (undefined1 *)(*(int *)(iVar18 + 8) + iVar4 * 3);
              *(undefined1 *)((int)local_664 + iVar4) = *puVar10;
              *psVar8 = (short)(char)puVar10[2];
              psVar8 = psVar8 + 1;
            }
            if (uVar6 != 0) {
              rrm_ap_pwr_para_neighbor_add
                        (iVar2,local_300,*param_1,local_5d8,local_664,local_65c,uVar6,
                         rrm_pwr_max_neigh_size);
            }
            goto LAB_004ade80;
          }
          iVar15 = iVar15 + 1;
        }
      } while( true );
    }
  }
  else if ((local_668 == 1) && (local_66c < 3)) {
    iVar2 = (&ap_pwr_para)[local_66c];
    iVar3 = local_66c;
    goto LAB_004add68;
  }
  if (rrm_err_switch == '\0') {
    return 0;
  }
  pcVar9 = "[RRM_ERROR]%s()/%d freq band(%d) is illegal \n";
  uVar11 = 0x750;
  iVar2 = local_668;
LAB_004adc84:
  printf(pcVar9,"_rrm_pkt_rssi_request",uVar11,iVar2);
  return 0;
code_r0x004ae41c:
  printf("[RRM_DEBUG]%s()/%d Add RE 5G itf [%d(%d)] <- [%d(%d)]:%d\n\n","_rrm_pkt_rssi_request",
         0x703,uVar6,uVar5 & 0xf,uVar13,local_34 & 0xf,local_64c[0] >> 0x10);
  uVar1 = *(ushort *)(param_1 + 2);
  goto LAB_004adf44;
}

