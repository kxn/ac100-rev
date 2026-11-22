// func rrm_pwr_set_to_all_ap @ 004abe64 size=716

void rrm_pwr_set_to_all_ap(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int local_38;
  
  iVar14 = 0;
  piVar12 = &ap_pwr_para;
  iVar13 = 0;
  iVar8 = 0;
  do {
    iVar11 = 0;
    if (*piVar12 != 0) {
      for (; piVar2 = (int *)*piVar12, iVar11 < *piVar2; iVar11 = iVar11 + 1) {
        iVar3 = piVar2[7];
        puVar10 = (undefined2 *)(piVar2[6] + iVar11 * 0x12);
        puVar9 = puVar10;
        for (local_38 = 0; local_38 < (int)(uint)*(byte *)(puVar10 + 1); local_38 = local_38 + 1) {
          bVar1 = rrm_pwr_failed != 0;
          if (bVar1) {
            uVar4 = 0;
          }
          else {
            uVar4 = rrm_transfer_pwr_to_level
                              (*(undefined1 *)((int)puVar9 + 3),*(undefined1 *)(puVar9 + 6),
                               *(undefined1 *)((int)puVar9 + 0xf));
          }
          uVar15 = (uint)!bVar1;
          uVar5 = rdmngr_db_generate_rd_id
                            (*puVar10,*(undefined1 *)(iVar3 + iVar11 * 0xf + local_38));
          if (uVar15 != 0) {
            if (iVar8 == 0) {
              iVar8 = apmngr_db_get_ap_max();
              iVar8 = FUN_004082a0(iVar8 * 3,0x1c,0x377);
              if (iVar8 == 0) {
                return;
              }
            }
            iVar6 = iVar14 * 0x1c;
            iVar14 = iVar14 + 1;
            puVar7 = (undefined4 *)(iVar8 + iVar6);
            *(undefined2 *)(puVar7 + 2) = 0xffff;
            *puVar7 = uVar5;
            puVar7[4] = 0xffffffff;
            puVar7[1] = 0;
            puVar7[3] = 0;
            puVar7[5] = 1;
            puVar7[6] = uVar4;
          }
          rrm_ap_is_rrm_set(*puVar10,iVar13,0);
          uac_rdmngr_chnl_pwr_modify_by_rdid(uVar5,0xffffffff,0,0xffffffff,0,uVar4,uVar15);
          iVar6 = rrm_ap_is_rrm_set(*puVar10,iVar13,1);
          if (iVar6 == 0) {
            rdmngr_callback_proc(6,uVar5,0,0);
          }
          if (rrm_debug_switch != '\0') {
            printf("[RRM_DEBUG]%s()/%d rd_id:%d level:%d pwr_enable:%d min-max:%d-%d\n\n",
                   "rrm_pwr_set_to_all_ap",0x38d,uVar5,uVar4,uVar15,(uint)*(byte *)(puVar9 + 3),
                   (uint)*(byte *)((int)puVar9 + 9));
          }
          puVar9 = (undefined2 *)((int)puVar9 + 1);
        }
      }
    }
    iVar13 = iVar13 + 1;
    piVar12 = piVar12 + 1;
  } while (iVar13 != 3);
  if ((iVar8 != 0) && (iVar14 != 0)) {
    uac_rrm_sync_rd_entry(iVar8,iVar14);
  }
  if (rrm_pwr_failed == 0) {
    rdmngr_callback_proc(3,0xffffffff,0,0);
  }
  if (iVar8 == 0) {
    return;
  }
  FUN_00407df0(iVar8);
  return;
}

