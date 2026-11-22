// func rrm_collect_active_ap @ 004a8fa0 size=1408

undefined4 rrm_collect_active_ap(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *__format;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 local_a0;
  int local_9c;
  int local_98;
  int local_94 [5];
  char local_80;
  char local_40;
  int local_30;
  undefined4 local_2c;
  
  uVar9 = 1;
  local_94[0] = 0;
  local_94[1] = 0;
  local_94[2] = 0;
  memset(local_94 + 3,0,0x54);
  local_98 = 0;
  local_9c = 0;
  local_a0 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar9 = 0;
    mesh_db_bh_work_mode_get(&local_a0);
    if ((*(int *)(param_1 + 0x2ac) == 2) &&
       ((iVar2 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10)), iVar2 == 1 &&
        (uVar9 = 0, *(int *)(param_1 + 0x250) << 4 < 0)))) {
      if ((*(uint *)(param_2 + 0xc) & 1) == 0) {
        uVar4 = *(ushort *)(param_1 + 0x12) + 1;
        if (0x1ff < *(ushort *)(param_1 + 0x12)) {
          return 0;
        }
        if ((*(uint *)(param_2 + (((int)uVar4 >> 5) + 2) * 4 + 4) >> (uVar4 & 0x1f) & 1) == 0) {
          return 0;
        }
        uVar1 = *(undefined2 *)(param_1 + 0x10);
      }
      else {
        uVar1 = *(undefined2 *)(param_1 + 0x10);
      }
      local_30 = rdmngr_db_get_radio_cnt_by_ap_id(uVar1,&local_98,&local_9c);
      if (local_30 < 1) {
        uVar9 = 0;
        if (rrm_err_switch != '\0') {
          printf("[RRM_ERROR]%s()/%d rdmngr_db_get_radio_cnt_by_ap_id(%d) failed:%d\n",
                 "rrm_collect_active_ap",0x4c5,(uint)*(ushort *)(param_1 + 0x10),local_30);
        }
      }
      else {
        uVar9 = 0;
        if ((local_98 < 2) && (local_9c < 3)) {
          iVar11 = 0;
          iVar2 = 0;
          iVar10 = 1;
          do {
            local_2c = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar10);
            iVar3 = rdmngr_db_rd_entry_get(local_2c,local_94 + 3);
            if (((iVar3 == 0) && (local_94[3] != -1)) && (local_40 == '\x01')) {
              uVar4 = *(uint *)(param_1 + 0x14);
              if ((local_80 == '\0') && (*(int *)(param_2 + 4) == 1)) {
                if (((uVar4 == 4) || (uVar4 == 8)) || (uVar4 == 6)) {
                  if (rrm_debug_switch != '\0') {
                    uVar9 = 0x4e1;
                    __format = "[RRM_DEBUG]%s()/%d work_mode:%d role:%d skip 2.4G\n";
LAB_004a9448:
                    printf(__format,"rrm_collect_active_ap",uVar9,local_a0,uVar4);
                  }
                }
                else if ((((uVar4 == 1) || (uVar4 == 3)) || (uVar4 == 2)) &&
                        (iVar3 = mesh_db_ap_entry_child_num_get(*(undefined2 *)(param_1 + 0x10)),
                        0 < iVar3)) {
                  if (rrm_debug_switch != '\0') {
                    uVar4 = *(uint *)(param_1 + 0x14);
                    __format = "[RRM_DEBUG]%s()/%d work_mode:%d role:%d skip 2.4G, child_num: %d\n";
                    uVar9 = 0x4e5;
                    goto LAB_004a9448;
                  }
                }
                else {
                  piVar6 = ap_para;
                  *(char *)(ap_para[7] + *ap_para * 0xf + local_94[0]) = (char)iVar10;
                  *(char *)(piVar6[7] + *piVar6 * 0xf + iVar11 + 3) = (char)local_94[0];
                  local_94[0] = local_94[0] + 1;
                  iVar3 = iVar2;
LAB_004a9300:
                  iVar2 = *(int *)(param_1 + 0x14);
                  if ((iVar2 == 4) || (iVar2 == 8)) {
LAB_004a9328:
                    iVar2 = *piVar6;
                  }
                  else {
                    if (iVar2 != 6) {
                      uac_wstation_rd_disable(local_2c);
                      goto LAB_004a9328;
                    }
                    iVar2 = *piVar6;
                  }
                  iVar2 = piVar6[6] + iVar2 * 0x2a;
                  *(char *)(iVar2 + 2) = *(char *)(iVar2 + 2) + '\x01';
                  iVar2 = iVar3;
                }
              }
              else if ((((uVar4 < 2) || ((uVar4 == 3 || (uVar4 == 2)))) && (local_80 == '\x01')) &&
                      ((iVar3 = iVar2 + 1, iVar3 < 3 && (*(int *)(param_2 + 8) == 1)))) {
                if (((uVar4 != 1) && ((uVar4 != 3 && (uVar4 != 2)))) ||
                   (iVar5 = mesh_db_ap_entry_child_num_get(*(undefined2 *)(param_1 + 0x10)),
                   iVar5 < 1)) {
                  piVar6 = (&ap_para)[iVar3];
                  iVar2 = local_94[iVar3];
                  *(char *)(piVar6[7] + *piVar6 * 0xf + iVar2) = (char)iVar10;
                  *(char *)(piVar6[7] + *piVar6 * 0xf + iVar11 + 3) = (char)iVar2;
                  local_94[iVar3] = iVar2 + 1;
                  goto LAB_004a9300;
                }
                if (rrm_debug_switch != '\0') {
                  printf("[RRM_DEBUG]%s()/%d work_mode:%d role:%d skip 5G(%d) child_num: %d\n",
                         "rrm_collect_active_ap",0x4f3,local_a0,*(undefined4 *)(param_1 + 0x14),
                         iVar3,iVar5);
                }
              }
            }
            iVar10 = iVar10 + 1;
            iVar11 = iVar11 + 1;
          } while (iVar10 <= local_30);
          piVar8 = local_94;
          piVar6 = (int *)&ap_para;
          iVar2 = 0;
          do {
            if (0 < *piVar8) {
              *(undefined2 *)(((int *)*piVar6)[6] + *(int *)*piVar6 * 0x2a) =
                   *(undefined2 *)(param_1 + 0x10);
              *(short *)(((undefined4 *)*piVar6)[5] + (uint)*(ushort *)(param_1 + 0x10) * 2) =
                   (short)*(undefined4 *)*piVar6;
              piVar7 = DAT_00767bfc;
              if (iVar2 == 1) {
                if (local_9c == 2) {
                  if (DAT_00767bd8._2_1_ == '\x01') {
                    *(undefined1 *)(DAT_00767bfc[6] + *DAT_00767bfc * 0x2a + 7) = 1;
                    piVar7 = DAT_00767bfc;
                    *(undefined1 *)(DAT_00767bfc[6] + *DAT_00767bfc * 0x2a + 8) = 1;
                    *(undefined1 *)(piVar7[6] + *piVar7 * 0x2a + 9) = 1;
                  }
                  else {
                    if (DAT_00767bd8._2_1_ != '\x02') {
                      piVar7 = (int *)*piVar6;
                      goto LAB_004a91d4;
                    }
                    *(undefined1 *)(DAT_00767bfc[6] + *DAT_00767bfc * 0x2a + 8) = 1;
                    *(undefined1 *)(piVar7[6] + *piVar7 * 0x2a + 9) = 1;
                  }
                  goto LAB_004a91d0;
                }
                piVar7 = (int *)*piVar6;
              }
              else {
LAB_004a91d0:
                piVar7 = (int *)*piVar6;
              }
LAB_004a91d4:
              *piVar7 = *piVar7 + 1;
            }
            iVar2 = iVar2 + 1;
            piVar8 = piVar8 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar2 != 3);
          uVar9 = 0;
        }
      }
    }
  }
  return uVar9;
}

