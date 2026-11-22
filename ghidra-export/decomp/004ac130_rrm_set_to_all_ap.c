// func rrm_set_to_all_ap @ 004ac130 size=1728

void rrm_set_to_all_ap(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  undefined1 auStack_4a8 [8];
  char local_4a0;
  undefined1 auStack_454 [12];
  int local_448;
  undefined1 auStack_340 [64];
  undefined4 local_300;
  undefined1 auStack_128 [192];
  short *local_68;
  short *local_64;
  undefined4 local_60;
  int local_5c;
  short *local_58;
  int local_54;
  int local_50;
  size_t local_4c;
  undefined1 *local_48;
  short *local_44;
  int local_40;
  int local_3c;
  int *local_38;
  uint local_34;
  int local_30;
  
  memset(auStack_4a8,0,0x54);
  memset(auStack_340,0,0x2d8);
  memset(auStack_454,0,0x114);
  memset(auStack_4a8,0,0x54);
  memset(auStack_340,0,0x2d8);
  memset(auStack_454,0,0x114);
  if (g_chnl_enable == 0) {
    rrm_pwr_set_to_all_ap();
  }
  else if (g_pwr_enable == 0) {
    rrm_channel_set_to_all_ap();
  }
  else {
    local_3c = apmngr_db_get_ap_max();
    local_4c = local_3c << 1;
    local_58 = (short *)FUN_00408450(local_4c,0x3c0);
    if (local_58 != (short *)0x0) {
      iVar12 = 0;
      local_68 = (short *)FUN_00408450(local_4c,0x3c5);
      if (local_68 != (short *)0x0) {
        local_5c = 0;
        local_30 = local_3c * 3;
        piVar11 = &ap_para;
        piVar9 = &ap_pwr_para;
        iVar14 = 0;
        iVar15 = 0;
        iVar12 = 0;
        do {
          memset(local_58,-1,local_4c);
          memset(local_68,-1,local_4c);
          iVar3 = 0;
          piVar8 = (int *)*piVar11;
          if (piVar8 == (int *)0x0) {
            iVar3 = *piVar9;
          }
          else {
            for (; iVar3 < *piVar8; iVar3 = iVar3 + 1) {
              local_58[*(ushort *)(piVar8[6] + iVar3 * 0x2a)] = (short)iVar3;
              piVar8 = (int *)*piVar11;
            }
            iVar3 = *piVar9;
          }
          iVar5 = 0;
          if (iVar3 != 0) {
            for (; iVar5 < *(int *)*piVar9; iVar5 = iVar5 + 1) {
              local_68[*(ushort *)(((int *)*piVar9)[6] + iVar5 * 0x12)] = (short)iVar5;
            }
          }
          if (iVar15 == 0) {
            local_50 = g_bw_2g;
          }
          else {
            local_50 = g_bw_5g;
          }
          local_64 = local_68;
          local_44 = local_58;
          local_40 = iVar15;
          local_38 = piVar11;
          for (local_54 = 0; local_54 < local_3c; local_54 = local_54 + 1) {
            iVar15 = (int)*local_44;
            if (iVar15 == -1) {
              iVar15 = (int)*local_64;
              if (iVar15 != -1) {
                local_48 = (undefined1 *)(*(int *)(*piVar9 + 0x1c) + iVar15 * 0xf);
                bVar1 = *(byte *)(*(int *)(*piVar9 + 0x18) + iVar15 * 0x12 + 2);
                goto LAB_004ac3d0;
              }
            }
            else {
              local_48 = (undefined1 *)(*(int *)(*local_38 + 0x1c) + iVar15 * 0xf);
              bVar1 = *(byte *)(*(int *)(*local_38 + 0x18) + iVar15 * 0x2a + 2);
LAB_004ac3d0:
              local_34 = (uint)bVar1;
              for (iVar15 = 0; iVar15 < (int)local_34; iVar15 = iVar15 + 1) {
                uVar4 = rdmngr_db_generate_rd_id(local_54,*local_48);
                uVar2 = *local_48;
                if (((rrm_chnl_failed == 0) && (-1 < *local_44)) &&
                   (iVar3 = (int)*(char *)(*(int *)(*local_38 + 0x18) + *local_44 * 0x2a + iVar15 +
                                          3), iVar3 != -1)) {
                  uVar10 = (uint)(byte)(&DAT_00767bd1)[local_40 * 5 + iVar3];
                  iVar14 = local_50;
                  if ((local_50 != 5) || (iVar14 = 3, 0x94 < uVar10)) {
LAB_004ac474:
                    iVar3 = 1;
                    goto LAB_004ac478;
                  }
                  uVar7 = rdmngr_db_generate_ap_id(uVar4);
                  iVar14 = apmngr_db_entry_get_by_id(uVar7,auStack_340);
                  if (iVar14 == 0) {
                    iVar14 = rdmngr_db_rd_entry_get(uVar4,auStack_4a8);
                    if ((iVar14 != -1) &&
                       (iVar14 = apdb_get_radio_by_id
                                           (local_300,auStack_128,uVar2,auStack_454,(int)local_4a0),
                       iVar14 == 0)) {
                      iVar14 = local_50;
                      if (local_448 == 0) {
                        iVar14 = 3;
                      }
                      goto LAB_004ac474;
                    }
                  }
                  iVar14 = 5;
                  if (rrm_err_switch != '\0') {
                    printf("[RRM_ERROR]%s()/%d Get rdEntry failed\n","rrm_set_to_all_ap",0x413);
                  }
                }
                else {
                  iVar3 = 0;
                  uVar10 = 0xffffffff;
LAB_004ac478:
                  if ((rrm_pwr_failed == 0) && (-1 < *local_64)) {
                    iVar5 = *(int *)(*piVar9 + 0x18) + *local_64 * 0x12 + iVar15;
                    uVar13 = rrm_transfer_pwr_to_level
                                       (*(undefined1 *)(iVar5 + 3),*(undefined1 *)(iVar5 + 0xc),
                                        *(undefined1 *)(iVar5 + 0xf));
                    local_60 = 1;
joined_r0x004ac4c4:
                    if ((iVar12 == 0) && (iVar12 = FUN_004082a0(local_30,0x1c,0x429), iVar12 == 0))
                    goto LAB_004ac5bc;
                    iVar5 = local_5c * 0x1c;
                    local_5c = local_5c + 1;
                    puVar6 = (undefined4 *)(iVar12 + iVar5);
                    *puVar6 = uVar4;
                    puVar6[1] = iVar3;
                    *(short *)(puVar6 + 2) = (short)uVar10;
                    puVar6[3] = iVar3;
                    puVar6[4] = iVar14;
                    puVar6[5] = local_60;
                    puVar6[6] = uVar13;
                  }
                  else {
                    local_60 = 0;
                    uVar13 = 0;
                    if (iVar3 != 0) goto joined_r0x004ac4c4;
                  }
                  uVar7 = rdmngr_db_generate_ap_id(uVar4);
                  rrm_ap_is_rrm_set(uVar7,local_40,0);
                  uac_rdmngr_chnl_pwr_modify_by_rdid
                            (uVar4,uVar10,iVar3,iVar14,iVar3,uVar13,local_60);
                  iVar5 = rrm_ap_is_rrm_set(uVar7,local_40,1);
                  if (iVar5 == 0) {
                    rdmngr_callback_proc(6,uVar4,0,0);
                  }
                  if (rrm_debug_switch != '\0') {
                    iVar5 = *(int *)(*piVar9 + 0x18) + *local_64 * 0x12 + iVar15;
                    printf("[RRM_DEBUG]%s()/%d rd_id:%d chnl:%d chnl_enable:%d bw:%d bw_enable:%d pwrLevel:%d pwr_enable:%d min-max:%d-%d\n\n"
                           ,"rrm_set_to_all_ap",0x440,uVar4,uVar10,iVar3,iVar14,iVar3,uVar13,
                           local_60,(uint)*(byte *)(iVar5 + 6),(uint)*(byte *)(iVar5 + 9));
                  }
                }
                local_48 = local_48 + 1;
              }
            }
            local_64 = local_64 + 1;
            local_44 = local_44 + 1;
          }
          piVar9 = piVar9 + 1;
          iVar15 = local_40 + 1;
          piVar11 = local_38 + 1;
        } while (iVar15 != 3);
        if ((iVar12 != 0) && (local_5c != 0)) {
          uac_rrm_sync_rd_entry(iVar12,local_5c);
        }
        if ((rrm_chnl_failed == 0) || (rrm_pwr_failed == 0)) {
          rdmngr_callback_proc(3,0xffffffff,0,0);
        }
      }
LAB_004ac5bc:
      FUN_00407df0(local_58);
      if (local_68 != (short *)0x0) {
        FUN_00407df0(local_68);
      }
      if (iVar12 != 0) {
        FUN_00407df0(iVar12);
      }
    }
  }
  return;
}

