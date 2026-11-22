// func rdmngr_db_ap_model_update @ 0061dd98 size=664

/* WARNING: Type propagation algorithm not settling */

undefined4 rdmngr_db_ap_model_update(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_58;
  int local_54 [11];
  
  local_54[9] = (int)*(ushort *)(param_1 + 0x10);
  iVar7 = *(int *)(param_1 + 0x14);
  local_54[5] = 0;
  local_54[6] = 0;
  local_54[7] = 0;
  local_54[8] = 0;
  local_54[1] = 0;
  local_54[2] = 0;
  local_54[3] = 0;
  local_54[4] = 0;
  local_54[0] = 0;
  local_58 = 0;
  if (((iVar7 == 4) || (iVar7 == 8)) || (iVar7 == 6)) {
    bVar1 = true;
  }
  else {
    bVar1 = iVar7 == 5;
    if (!bVar1) goto LAB_0061de34;
  }
  rdmngr_db_get_radio_list_by_ap_id
            ((int)*(short *)(param_1 + 0x18),local_54 + 5,4,local_54,local_54 + 1,4,&local_58);
LAB_0061de34:
  iVar7 = 0;
  iVar9 = 0;
  uVar8 = 1;
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  do {
    if (param_2 < (int)uVar8) {
      FUN_00407f30(DAT_007cc64c);
      return 0;
    }
    iVar2 = rdmngr_db_generate_rd_idx(local_54[9],uVar8);
    iVar2 = *(int *)(DAT_007cc650 + iVar2 * 8 + 4);
    if (iVar2 == 0) {
      if ((rdmngr_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d not find rd entry\n","rdmngr_db_ap_model_update",0xcd0);
      }
      FUN_00407f30(DAT_007cc64c);
      return 0xffffffff;
    }
    iVar3 = apdb_get_dft_radio_freq_by_id(param_3,param_1 + 0x218,uVar8 & 0xff);
    if (iVar3 == 0) {
      iVar9 = iVar9 + 1;
    }
    else {
      iVar7 = iVar7 + 1;
    }
    uVar6 = 1;
    if (bVar1) {
      if (iVar3 == 0) {
        if (local_54[0] != 0) {
          iVar4 = local_54[0];
          if (iVar9 <= local_54[0]) {
            iVar4 = iVar9;
          }
          uVar5 = local_54[iVar4 + 4];
          goto LAB_0061df50;
        }
      }
      else if ((iVar3 == 1) && (uVar6 = 1, 0 < local_58)) {
        iVar4 = local_58;
        if (iVar7 <= local_58) {
          iVar4 = iVar7;
        }
        uVar5 = local_54[iVar4];
LAB_0061df50:
        iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(uVar5);
        uVar6 = 1;
        if ((iVar4 != -1) && (iVar4 = *(int *)(DAT_007cc650 + iVar4 * 8 + 4), iVar4 != 0)) {
          uVar6 = *(undefined1 *)(iVar4 + 0x48);
        }
      }
    }
    uVar8 = uVar8 + 1;
    rdmngr_db_init_comPara(param_3,iVar2 + 4,iVar3,uVar6);
  } while( true );
}

