// func dfs @ 004b0180 size=1656

undefined4
dfs(int param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,byte param_7,
   void *param_8,int param_9,int param_10,int param_11,int param_12,int *param_13,void *param_14)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint local_40;
  uint local_3c;
  
  uVar14 = (uint)param_7;
  if (param_3 == 0) {
    uVar16 = (uint)*(ushort *)(param_1 + 0xc);
    cVar1 = *(char *)((int)param_14 + param_4 + uVar16 * 0x2a + 3);
  }
  else {
    cVar1 = *(char *)((int)param_14 + param_4 + param_2 * 0x2a + 3);
    uVar16 = param_2;
  }
  uVar15 = (int)cVar1 & 0xffff;
  if (*(char *)((int)param_14 + uVar14 + uVar16 * 0x2a + 6) == '\x01') {
    if (rrm_algo_switch == '\0') {
      return 0;
    }
    printf("[RRM_PKT]%s()/%d ap_id = %d, target_ch = %d, cur_ch = %d\n",&DAT_006a1728,0x41,uVar16,
           uVar14,uVar15);
    return 0;
  }
  iVar8 = param_10 + uVar16 * 0xc;
  iVar6 = param_11 + uVar16 * 0xc;
  if (uVar15 != uVar14) {
    *(byte *)((int)param_14 + param_4 + uVar16 * 0x2a + 3) = param_7;
    iVar7 = FUN_00407fe0(iVar6);
    if (iVar7 != 0) {
      iVar7 = FUN_004081b0(iVar6);
      for (; iVar7 != 0; iVar7 = FUN_00408680(iVar7)) {
        iVar13 = 0;
        puVar9 = (ushort *)(iVar7 + param_4 * 6 + 0x12);
        while (iVar13 < (int)(uint)*(byte *)((int)param_14 +
                                            (uint)*(ushort *)(iVar7 + 0xc) * 0x2a + 2)) {
          iVar11 = (iVar13 * 4 + uVar15 + 8) * 2;
          iVar12 = iVar11 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a;
          *(ushort *)((int)param_14 + iVar12 + 2) = *(short *)((int)param_14 + iVar12 + 2) - *puVar9
          ;
          iVar12 = (iVar13 * 4 + uVar14 + 8) * 2 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a;
          *(ushort *)((int)param_14 + iVar12 + 2) = *puVar9 + *(short *)((int)param_14 + iVar12 + 2)
          ;
          uVar3 = *(ushort *)(iVar7 + 0xc);
          if ((int)*(char *)((int)param_14 + iVar13 + (uint)uVar3 * 0x2a + 3) == uVar15) {
            param_12 = param_12 - (uint)*puVar9;
            *(ushort *)((int)param_14 + (uint)uVar3 * 0x2a + 10) =
                 *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10) - *puVar9;
            *(undefined2 *)
             ((int)param_14 + (iVar13 + 4) * 2 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a + 4) =
                 *(undefined2 *)((int)param_14 + iVar11 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a + 2)
            ;
          }
          uVar3 = *(ushort *)(iVar7 + 0xc);
          if ((int)*(char *)((int)param_14 + iVar13 + (uint)uVar3 * 0x2a + 3) == uVar14) {
            uVar4 = *puVar9;
            puVar9 = puVar9 + 1;
            param_12 = param_12 + (uint)uVar4;
            iVar11 = iVar13 * 4;
            *(ushort *)((int)param_14 + (uint)uVar3 * 0x2a + 10) =
                 uVar4 + *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10);
            iVar12 = iVar13 + 4;
            iVar13 = iVar13 + 1;
            *(undefined2 *)((int)param_14 + iVar12 * 2 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a + 4)
                 = *(undefined2 *)
                    ((int)param_14 +
                    (iVar11 + uVar14 + 8) * 2 + (uint)*(ushort *)(iVar7 + 0xc) * 0x2a + 2);
          }
          else {
            iVar13 = iVar13 + 1;
            puVar9 = puVar9 + 1;
          }
        }
      }
    }
    uVar3 = *(ushort *)((int)param_14 + (param_4 * 4 + uVar14 + 8) * 2 + uVar16 * 0x2a + 2);
    uVar4 = *(ushort *)((int)param_14 + (param_4 * 4 + uVar15 + 8) * 2 + uVar16 * 0x2a + 2);
    param_12 = param_12 + ((uint)uVar3 - (uint)uVar4);
    *(ushort *)((int)param_14 + uVar16 * 0x2a + 10) =
         (uVar3 + *(short *)((int)param_14 + uVar16 * 0x2a + 10)) - uVar4;
    *(ushort *)((int)param_14 + (param_4 + 4) * 2 + uVar16 * 0x2a + 4) = uVar3;
  }
  if (param_4 == *(byte *)((int)param_14 + uVar16 * 0x2a + 2) - 1) {
    if (param_3 == 0) {
      iVar7 = FUN_00408680(param_1);
    }
    else {
      iVar7 = FUN_00407fe0(iVar8);
    }
    if (iVar7 == 0) {
      if (param_12 < *param_13) {
        *param_13 = param_12;
        memcpy(param_8,param_14,param_9 * 0x2a);
      }
      goto LAB_004b0420;
    }
    bVar2 = *(byte *)((int)param_14 + uVar16 * 0x2a + 2);
  }
  else {
    bVar2 = *(byte *)((int)param_14 + uVar16 * 0x2a + 2);
  }
  if (param_4 < (int)(bVar2 - 1)) {
    param_4 = param_4 + 1;
    if (param_3 != 0) {
      param_1 = 0;
    }
    local_3c = 1 << (uVar14 & 0x1f) | param_5;
  }
  else if (param_3 == 0) {
    param_4 = 0;
    param_1 = FUN_00408680(param_1);
    local_3c = 0;
  }
  else {
    param_4 = 0;
    param_3 = 0;
    param_1 = FUN_004081b0(iVar8);
    local_3c = 0;
  }
  for (local_40 = 0; (int)local_40 < param_6; local_40 = local_40 + 1) {
    if ((1 << (local_40 & 0x1f) & local_3c) == 0) {
      if (param_6 == 0) {
        trap(7);
      }
      iVar8 = dfs(param_1,param_2,param_3,param_4,local_3c,param_6,
                  (int)(local_40 + uVar16) % param_6 & 0xff,param_8,param_9,param_10,param_11,
                  param_12,param_13,param_14);
      if (iVar8 != 0) {
        return 0xffffffff;
      }
    }
  }
LAB_004b0420:
  if (uVar15 != uVar14) {
    *(char *)((int)param_14 + param_4 + uVar16 * 0x2a + 3) = (char)uVar15;
    iVar8 = FUN_00407fe0(iVar6);
    if (iVar8 != 0) {
      for (iVar6 = FUN_004081b0(iVar6); iVar6 != 0; iVar6 = FUN_00408680(iVar6)) {
        iVar8 = 0;
        psVar10 = (short *)(iVar6 + param_4 * 6 + 0x12);
        while (iVar8 < (int)(uint)*(byte *)((int)param_14 +
                                           (uint)*(ushort *)(iVar6 + 0xc) * 0x2a + 2)) {
          iVar13 = (iVar8 * 4 + uVar15 + 8) * 2;
          iVar7 = iVar13 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a;
          *(short *)((int)param_14 + iVar7 + 2) = *psVar10 + *(short *)((int)param_14 + iVar7 + 2);
          iVar7 = (iVar8 * 4 + uVar14 + 8) * 2 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a;
          *(short *)((int)param_14 + iVar7 + 2) = *(short *)((int)param_14 + iVar7 + 2) - *psVar10;
          uVar3 = *(ushort *)(iVar6 + 0xc);
          if ((int)*(char *)((int)param_14 + iVar8 + (uint)uVar3 * 0x2a + 3) == uVar15) {
            *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10) =
                 *psVar10 + *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10);
            *(undefined2 *)
             ((int)param_14 + (iVar8 + 4) * 2 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a + 4) =
                 *(undefined2 *)((int)param_14 + iVar13 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a + 2)
            ;
          }
          uVar3 = *(ushort *)(iVar6 + 0xc);
          if ((int)*(char *)((int)param_14 + iVar8 + (uint)uVar3 * 0x2a + 3) == uVar14) {
            sVar5 = *psVar10;
            psVar10 = psVar10 + 1;
            iVar13 = iVar8 * 4;
            *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10) =
                 *(short *)((int)param_14 + (uint)uVar3 * 0x2a + 10) - sVar5;
            iVar7 = iVar8 + 4;
            iVar8 = iVar8 + 1;
            *(undefined2 *)((int)param_14 + iVar7 * 2 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a + 4) =
                 *(undefined2 *)
                  ((int)param_14 +
                  (iVar13 + uVar14 + 8) * 2 + (uint)*(ushort *)(iVar6 + 0xc) * 0x2a + 2);
          }
          else {
            iVar8 = iVar8 + 1;
            psVar10 = psVar10 + 1;
          }
        }
      }
    }
    sVar5 = *(short *)((int)param_14 + (param_4 * 4 + uVar15 + 8) * 2 + uVar16 * 0x2a + 2);
    *(short *)((int)param_14 + uVar16 * 0x2a + 10) =
         (sVar5 + *(short *)((int)param_14 + uVar16 * 0x2a + 10)) -
         *(short *)((int)param_14 + (param_4 * 4 + uVar14 + 8) * 2 + uVar16 * 0x2a + 2);
    *(short *)((int)param_14 + (param_4 + 4) * 2 + uVar16 * 0x2a + 4) = sVar5;
  }
  return 0;
}

