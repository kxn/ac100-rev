// func rdmngr_db_ap_connect @ 0061e030 size=776

/* WARNING: Type propagation algorithm not settling */

undefined4 rdmngr_db_ap_connect(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int *piVar7;
  uint uVar8;
  uint *__s;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int local_60;
  int local_5c [10];
  uint local_34;
  int local_30;
  
  local_5c[9] = (int)*(ushort *)(param_1 + 0x10);
  iVar11 = *(int *)(param_1 + 0x14);
  local_5c[5] = 0;
  local_5c[6] = 0;
  local_5c[7] = 0;
  local_5c[8] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  local_5c[3] = 0;
  local_5c[4] = 0;
  local_5c[0] = 0;
  local_60 = 0;
  if (((iVar11 == 4) || (iVar11 == 8)) || (iVar11 == 6)) {
    bVar1 = true;
  }
  else {
    bVar1 = iVar11 == 5;
    if (!bVar1) goto LAB_0061e0cc;
  }
  rdmngr_db_get_radio_list_by_ap_id
            ((int)*(short *)(param_1 + 0x18),local_5c + 5,4,local_5c,local_5c + 1,4,&local_60);
LAB_0061e0cc:
  iVar11 = 0;
  iVar9 = 0;
  uVar10 = 1;
  FUN_004082d0(DAT_007cc64c,0xffffffff);
  local_34 = local_5c[9] << 4;
  local_30 = param_1 + 0x218;
  do {
    if (param_2 < (int)uVar10) {
      FUN_00407f30(DAT_007cc64c);
      return 0;
    }
    iVar2 = rdmngr_db_generate_rd_idx(local_5c[9],uVar10);
    iVar12 = iVar2 * 8;
    piVar7 = (int *)(DAT_007cc650 + iVar12);
    if ((piVar7[1] == 0) && (*piVar7 == 0)) {
      iVar3 = FUN_004082a0(1,0x54,0xc0c);
      piVar7[1] = iVar3;
      puVar4 = *(undefined4 **)(DAT_007cc650 + iVar12 + 4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_00407f30(DAT_007cc64c);
        return 0xffffffff;
      }
      *puVar4 = 0xffffffff;
    }
    __s = *(uint **)(DAT_007cc650 + iVar12 + 4);
    if (*__s == 0xffffffff) {
      uVar8 = uVar10 & 0xf | local_34;
      memset(__s,0,0x54);
      *__s = uVar8;
      __s[1] = uVar8;
      iVar12 = apdb_get_dft_radio_freq_by_id(param_3,local_30,uVar10 & 0xff);
      if (iVar12 == 0) {
        iVar9 = iVar9 + 1;
      }
      else {
        iVar11 = iVar11 + 1;
      }
      uVar6 = 1;
      if (bVar1) {
        if (iVar12 == 0) {
          if (local_5c[0] != 0) {
            iVar3 = local_5c[0];
            if (iVar9 <= local_5c[0]) {
              iVar3 = iVar9;
            }
            uVar5 = local_5c[iVar3 + 4];
            goto LAB_0061e2f0;
          }
        }
        else if ((iVar12 == 1) && (uVar6 = 1, 0 < local_60)) {
          iVar3 = local_60;
          if (iVar11 <= local_60) {
            iVar3 = iVar11;
          }
          uVar5 = local_5c[iVar3];
LAB_0061e2f0:
          iVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar5);
          uVar6 = 1;
          if ((iVar3 != -1) && (iVar3 = *(int *)(DAT_007cc650 + iVar3 * 8 + 4), iVar3 != 0)) {
            uVar6 = *(undefined1 *)(iVar3 + 0x48);
          }
        }
      }
      rdmngr_db_init_comPara(param_3,__s + 1,iVar12,uVar6);
    }
    else if (*(char *)(__s + 2) == '\0') {
      iVar9 = iVar9 + 1;
    }
    else {
      iVar11 = iVar11 + 1;
    }
    uVar10 = uVar10 + 1;
    rdmngr_db_init_state(iVar2);
  } while( true );
}

