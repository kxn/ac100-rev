// func rrm_pwr_collect_active_ap @ 004ac988 size=1672

undefined4 rrm_pwr_collect_active_ap(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  byte bVar6;
  uint uVar7;
  int *piVar8;
  char *__format;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  byte local_1b8;
  byte local_1b7 [3];
  undefined4 local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8 [5];
  char local_194;
  char local_154;
  undefined1 auStack_148 [280];
  uint local_30;
  
  uVar12 = 1;
  local_1a8[0] = 0;
  local_1a8[1] = 0;
  local_1a8[2] = 0;
  memset(local_1a8 + 3,0,0x54);
  local_1ac = 0;
  local_1b0 = 0;
  local_1b7[0] = 0;
  local_1b8 = 0;
  memset(auStack_148,0,0x114);
  local_1b4 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar12 = 0;
    mesh_db_bh_work_mode_get(&local_1b4);
    if ((*(int *)(param_1 + 0x2ac) == 2) &&
       ((iVar3 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10)), iVar3 == 1 &&
        (uVar12 = 0, *(int *)(param_1 + 0x250) << 4 < 0)))) {
      if ((*(uint *)(param_2 + 0xc) & 1) == 0) {
        uVar14 = *(ushort *)(param_1 + 0x12) + 1;
        if (0x1ff < *(ushort *)(param_1 + 0x12)) {
          return 0;
        }
        if ((*(uint *)(param_2 + (((int)uVar14 >> 5) + 2) * 4 + 4) >> (uVar14 & 0x1f) & 1) == 0) {
          return 0;
        }
        uVar2 = *(undefined2 *)(param_1 + 0x10);
      }
      else {
        uVar2 = *(undefined2 *)(param_1 + 0x10);
      }
      iVar3 = rdmngr_db_get_radio_cnt_by_ap_id(uVar2,&local_1ac,&local_1b0);
      if (iVar3 < 1) {
        uVar12 = 0;
        if (rrm_err_switch != '\0') {
          printf("[RRM_ERROR]%s()/%d rdmngr_db_get_radio_cnt_by_ap_id(%d) failed:%d\n",
                 "rrm_pwr_collect_active_ap",0x560,(uint)*(ushort *)(param_1 + 0x10),iVar3);
        }
      }
      else {
        uVar12 = 0;
        if ((local_1ac < 2) && (iVar13 = 0, local_1b0 < 3)) {
          iVar15 = 0;
          uVar14 = 1;
          do {
            uVar12 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),uVar14);
            local_30 = *(uint *)(param_1 + 0x254);
            iVar4 = rdmngr_db_rd_entry_get(uVar12,local_1a8 + 3);
            if ((((iVar4 == 0) && (local_1a8[3] != -1)) && (local_154 == '\x01')) &&
               (iVar4 = apdb_get_radio_by_id
                                  (*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,uVar14 & 0xff,
                                   auStack_148,(int)local_194), iVar4 == 0)) {
              iVar4 = *(int *)(param_1 + 0x14);
              if ((local_194 == '\0') && (*(int *)(param_2 + 4) == 1)) {
                if (((iVar4 == 4) || (iVar4 == 8)) || (iVar4 == 6)) {
                  if (rrm_debug_switch != '\0') {
                    uVar7 = 1;
                    if ((iVar4 != 4) && (iVar4 != 8)) {
                      uVar7 = (uint)(iVar4 == 6);
                    }
                    __format = "[RRM_DEBUG]%s()/%d work_mode:%d role:%d skip 2.4G\n";
                    uVar12 = 0x57e;
LAB_004acfbc:
                    printf(__format,"rrm_pwr_collect_active_ap",uVar12,local_1b4,uVar7);
                  }
                }
                else {
                  if ((((iVar4 != 1) && (iVar4 != 3)) && (iVar4 != 2)) ||
                     (iVar4 = mesh_db_ap_entry_child_num_get(*(undefined2 *)(param_1 + 0x10)),
                     iVar4 < 1)) {
                    piVar5 = ap_pwr_para;
                    *(char *)(ap_pwr_para[7] + *ap_pwr_para * 0xf + local_1a8[0]) = (char)uVar14;
                    *(char *)(piVar5[7] + *piVar5 * 0xf + iVar13 + 3) = (char)local_1a8[0];
                    local_1a8[0] = local_1a8[0] + 1;
                    cVar1 = *(char *)(piVar5[7] + *piVar5 * 0xf + iVar13 + 3);
                    goto LAB_004acd24;
                  }
                  if (rrm_debug_switch != '\0') {
                    uVar7 = *(uint *)(param_1 + 0x14);
                    __format = "[RRM_DEBUG]%s()/%d work_mode:%d role:%d skip 2.4G, child_num: %d\n";
                    uVar12 = 0x582;
                    goto LAB_004acfbc;
                  }
                }
              }
              else if (((iVar4 == 0) ||
                       ((((iVar4 == 1 || (iVar4 == 3)) || (iVar4 == 2)) &&
                        (iVar4 = mesh_db_ap_entry_child_num_get(*(undefined2 *)(param_1 + 0x10)),
                        iVar4 == 0)))) &&
                      (((local_194 == '\x01' && (iVar4 = iVar15 + 1, iVar4 < 3)) &&
                       (*(int *)(param_2 + 8) == 1)))) {
                piVar5 = (&ap_pwr_para)[iVar4];
                iVar15 = local_1a8[iVar4];
                *(char *)(piVar5[7] + *piVar5 * 0xf + iVar15) = (char)uVar14;
                *(char *)(piVar5[7] + *piVar5 * 0xf + iVar13 + 3) = (char)iVar15;
                iVar11 = *piVar5;
                iVar9 = piVar5[7];
                local_1a8[iVar4] = iVar15 + 1;
                cVar1 = *(char *)(iVar9 + iVar11 * 0xf + iVar13 + 3);
                iVar15 = iVar4;
LAB_004acd24:
                iVar9 = (int)cVar1;
                iVar4 = *(int *)(param_1 + 0x14);
                if ((iVar4 == 4) || (iVar4 == 8)) {
LAB_004acd4c:
                  iVar4 = *piVar5;
                }
                else {
                  if (iVar4 != 6) {
                    uac_wstation_rd_disable(uVar12);
                    goto LAB_004acd4c;
                  }
                  iVar4 = *piVar5;
                }
                iVar4 = piVar5[6] + iVar4 * 0x12;
                *(char *)(iVar4 + 2) = *(char *)(iVar4 + 2) + '\x01';
                rrm_get_apdb_pwr(auStack_148,local_1b7,&local_1b8,local_30 & 0x40);
                iVar4 = *piVar5;
                iVar11 = piVar5[6];
                bVar6 = local_1b7[0];
                if ((0 < (int)rrm_pwr_max_power) &&
                   ((int)rrm_pwr_max_power < (int)(uint)local_1b7[0])) {
                  uVar10 = (uint)local_1b8;
                  uVar7 = rrm_pwr_max_power;
                  if ((int)rrm_pwr_max_power <= (int)uVar10) {
                    uVar7 = uVar10;
                  }
                  bVar6 = rrm_adjust_cur_pwr_for_collect(uVar7 & 0xff,(uint)local_1b7[0],uVar10,0);
                }
                *(byte *)(iVar11 + iVar4 * 0x12 + iVar9 + 6) = bVar6 + 1;
                iVar4 = *piVar5;
                iVar11 = piVar5[6];
                bVar6 = local_1b8;
                if ((0 < (int)rrm_pwr_min_power) && ((int)(uint)local_1b8 < (int)rrm_pwr_min_power))
                {
                  uVar10 = (uint)local_1b7[0];
                  uVar7 = rrm_pwr_min_power;
                  if ((int)uVar10 <= (int)rrm_pwr_min_power) {
                    uVar7 = uVar10;
                  }
                  bVar6 = rrm_adjust_cur_pwr_for_collect(uVar7 & 0xff,uVar10,(uint)local_1b8,1);
                }
                *(byte *)(iVar11 + iVar4 * 0x12 + iVar9 + 9) = bVar6 - 1;
                iVar4 = piVar5[6] + *piVar5 * 0x12 + iVar9;
                if ((int)(*(byte *)(iVar4 + 6) - 1) < (int)(*(byte *)(iVar4 + 9) + 1)) {
                  *(byte *)(iVar4 + 9) = *(byte *)(iVar4 + 6) - 2;
                  iVar4 = *piVar5;
                }
                else {
                  iVar4 = *piVar5;
                }
                iVar4 = piVar5[6] + iVar4 * 0x12 + iVar9;
                *(char *)(iVar4 + 3) = *(char *)(iVar4 + 6) + -1;
                *(byte *)(piVar5[6] + *piVar5 * 0x12 + iVar9 + 0xc) = local_1b7[0];
                *(byte *)(piVar5[6] + *piVar5 * 0x12 + iVar9 + 0xf) = local_1b8;
              }
            }
            uVar14 = uVar14 + 1;
            iVar13 = iVar13 + 1;
          } while ((int)uVar14 <= iVar3);
          iVar3 = 0;
          piVar5 = (int *)&ap_pwr_para;
          do {
            piVar8 = (int *)((int)local_1a8 + iVar3);
            iVar3 = iVar3 + 4;
            if (0 < *piVar8) {
              *(undefined2 *)(((int *)*piVar5)[6] + *(int *)*piVar5 * 0x12) =
                   *(undefined2 *)(param_1 + 0x10);
              *(short *)(((undefined4 *)*piVar5)[5] + (uint)*(ushort *)(param_1 + 0x10) * 2) =
                   (short)*(undefined4 *)*piVar5;
              *(int *)*piVar5 = *(int *)*piVar5 + 1;
            }
            piVar5 = piVar5 + 1;
          } while (iVar3 != 0xc);
          uVar12 = 0;
        }
      }
    }
  }
  return uVar12;
}

