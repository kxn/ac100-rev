// func rrm_channel_set_to_all_ap @ 004aba4c size=1048

void rrm_channel_set_to_all_ap(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  undefined2 *puVar13;
  undefined1 auStack_488 [8];
  char local_480;
  undefined1 auStack_434 [12];
  int local_428;
  undefined1 auStack_320 [64];
  undefined4 local_2e0;
  undefined1 auStack_108 [192];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  ushort local_34;
  int local_30;
  uint local_2c;
  
  iVar8 = 0;
  piVar11 = &ap_para;
  iVar7 = 0;
  iVar6 = 0;
  memset(auStack_488,0,0x54);
  memset(auStack_320,0,0x2d8);
  memset(auStack_434,0,0x114);
  memset(auStack_488,0,0x54);
  memset(auStack_320,0,0x2d8);
  memset(auStack_434,0,0x114);
  local_44 = 0;
  do {
    if (*piVar11 != 0) {
      local_40 = g_bw_5g;
      if (iVar8 == 0) {
        local_40 = g_bw_2g;
      }
      for (local_48 = 0; piVar2 = (int *)*piVar11, local_48 < *piVar2; local_48 = local_48 + 1) {
        iVar10 = 0;
        local_3c = local_48 * 0x2a;
        puVar13 = (undefined2 *)(piVar2[6] + local_3c);
        local_38 = local_48 * 0xf;
        local_30 = piVar2[7] + local_38;
        while (iVar10 < (int)(uint)*(byte *)(puVar13 + 1)) {
          uVar3 = rdmngr_db_generate_rd_id(*puVar13,*(undefined1 *)(local_30 + iVar10));
          local_2c = (uint)*(byte *)(*(int *)(*piVar11 + 0x1c) + local_38 + iVar10);
          if ((rrm_chnl_failed == 0) &&
             (iVar5 = (int)*(char *)((int)puVar13 + iVar10 + 3), iVar5 != -1)) {
            local_34 = (ushort)(byte)(&DAT_00767bd1)[iVar8 * 5 + iVar5];
            uVar12 = (uint)(short)local_34;
            iVar6 = local_40;
            if ((local_40 != 5) || (iVar6 = 3, 0x94 < uVar12)) {
LAB_004abbf4:
              if (iVar7 == 0) {
                iVar7 = apmngr_db_get_ap_max();
                iVar7 = FUN_004082a0(iVar7 * 3,0x1c,0x32c);
                if (iVar7 == 0) {
                  return;
                }
              }
              uVar9 = 1;
              iVar5 = local_44 * 0x1c;
              local_44 = local_44 + 1;
              puVar4 = (undefined4 *)(iVar7 + iVar5);
              puVar4[1] = 1;
              puVar4[3] = 1;
              *puVar4 = uVar3;
              *(ushort *)(puVar4 + 2) = local_34;
              puVar4[4] = iVar6;
              puVar4[5] = 0;
              puVar4[6] = 0xffffffff;
              goto LAB_004abc44;
            }
            iVar5 = apmngr_db_entry_get_by_id
                              (*(undefined2 *)(*(int *)(*piVar11 + 0x18) + local_3c),auStack_320);
            if (iVar5 == 0) {
              iVar5 = rdmngr_db_rd_entry_get(uVar3,auStack_488);
              if ((iVar5 != -1) &&
                 (iVar5 = apdb_get_radio_by_id
                                    (local_2e0,auStack_108,local_2c,auStack_434,(int)local_480),
                 iVar5 == 0)) {
                if (local_428 != 0) {
                  iVar6 = local_40;
                }
                goto LAB_004abbf4;
              }
            }
            iVar6 = 5;
            if (rrm_err_switch == '\0') {
LAB_004abca0:
              iVar10 = iVar10 + 1;
            }
            else {
              printf("[RRM_ERROR]%s()/%d Get rdEntry failed\n","rrm_channel_set_to_all_ap",0x31e);
              iVar10 = iVar10 + 1;
            }
          }
          else {
            uVar9 = 0;
            uVar12 = 0xffffffff;
LAB_004abc44:
            rrm_ap_is_rrm_set(*puVar13,iVar8,0);
            uac_rdmngr_chnl_pwr_modify_by_rdid(uVar3,uVar12,uVar9,iVar6,uVar9,0xffffffff,0);
            if (rrm_debug_switch == '\0') {
              uVar1 = *puVar13;
            }
            else {
              printf("[RRM_DEBUG]%s()/%d rd_id:%d chnl:%d chnl_enable:%d bw:%d bw_enable:%d\n",
                     "rrm_channel_set_to_all_ap",0x33d,uVar3,uVar12,uVar9,iVar6,uVar9);
              uVar1 = *puVar13;
            }
            iVar5 = rrm_ap_is_rrm_set(uVar1,iVar8,1);
            if (iVar5 != 0) goto LAB_004abca0;
            rdmngr_callback_proc(6,uVar3,0,0);
            iVar10 = iVar10 + 1;
          }
        }
      }
    }
    iVar8 = iVar8 + 1;
    piVar11 = piVar11 + 1;
    if (iVar8 == 3) {
      if ((iVar7 != 0) && (local_44 != 0)) {
        uac_rrm_sync_rd_entry(iVar7,local_44);
      }
      if (rrm_chnl_failed == 0) {
        rdmngr_callback_proc(3,0xffffffff,0,0);
      }
      if (iVar7 != 0) {
        FUN_00407df0(iVar7);
      }
      return;
    }
  } while( true );
}

