// func shaUpdate @ 00449c48 size=692

void shaUpdate(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  for (iVar12 = 0; iVar12 < param_3; iVar12 = iVar12 + 1) {
    uVar2 = param_1[0x55];
    uVar6 = uVar2 + 3;
    if (-1 < (int)uVar2) {
      uVar6 = uVar2;
    }
    iVar5 = (int)uVar6 >> 2;
    uVar6 = param_1[iVar5 + 5];
    param_1[iVar5 + 5] = uVar6 << 8;
    param_1[iVar5 + 5] = (uint)*(byte *)(param_2 + iVar12) | uVar6 << 8;
    param_1[0x55] = uVar2 + 1;
    if ((uVar2 + 1 & 0x3f) == 0) {
      iVar5 = 0x10;
      puVar3 = param_1;
      do {
        iVar5 = iVar5 + 1;
        uVar6 = puVar3[0xd] ^ puVar3[0x12] ^ puVar3[7] ^ puVar3[5];
        puVar3[0x15] = uVar6 * 2 - ((int)uVar6 >> 0x1f);
        puVar3 = puVar3 + 1;
      } while (iVar5 != 0x50);
      iVar5 = 0;
      uVar7 = *param_1;
      uVar2 = param_1[2];
      uVar6 = param_1[3];
      uVar8 = param_1[1];
      uVar9 = param_1[4];
      do {
        uVar10 = uVar6;
        uVar6 = uVar2;
        uVar4 = uVar7;
        iVar1 = iVar5 + 0x14;
        iVar5 = iVar5 + 4;
        uVar7 = uVar9 + 0x5a827999 + (uVar4 >> 0x1b) + uVar4 * 0x20 + *(int *)((int)param_1 + iVar1)
                + ((uVar10 ^ uVar6) & uVar8 ^ uVar10);
        uVar2 = (uVar8 >> 2) + uVar8 * 0x40000000;
        uVar8 = uVar4;
        uVar9 = uVar10;
      } while (iVar5 != 0x50);
      iVar5 = 0;
      do {
        uVar9 = uVar6;
        uVar8 = uVar7;
        uVar6 = uVar2;
        iVar1 = iVar5 + 100;
        iVar5 = iVar5 + 4;
        uVar2 = (uVar4 >> 2) + uVar4 * 0x40000000;
        uVar7 = uVar10 + 0x6ed9eba1 + (uVar8 >> 0x1b) + uVar8 * 0x20 + (uVar6 ^ uVar4 ^ uVar9) +
                *(int *)((int)param_1 + iVar1);
        uVar4 = uVar8;
        uVar10 = uVar9;
      } while (iVar5 != 0x50);
      iVar5 = 0;
      do {
        uVar10 = uVar7;
        uVar4 = uVar6;
        uVar6 = uVar2;
        iVar1 = iVar5 + 0xb4;
        iVar5 = iVar5 + 4;
        uVar2 = (uVar8 >> 2) + uVar8 * 0x40000000;
        uVar7 = uVar9 + 0x8f1bbcdc + (uVar10 >> 0x1b) + uVar10 * 0x20 +
                *(int *)((int)param_1 + iVar1) + ((uVar6 | uVar8) & uVar4 | uVar6 & uVar8);
        uVar8 = uVar10;
        uVar9 = uVar4;
      } while (iVar5 != 0x50);
      iVar5 = 0;
      do {
        uVar11 = uVar7;
        uVar9 = uVar2;
        uVar8 = uVar6;
        iVar1 = iVar5 + 0x104;
        iVar5 = iVar5 + 4;
        uVar2 = (uVar10 >> 2) + uVar10 * 0x40000000;
        uVar7 = uVar4 + 0xca62c1d6 + (uVar11 >> 0x1b) + uVar11 * 0x20 + (uVar9 ^ uVar10 ^ uVar8) +
                *(int *)((int)param_1 + iVar1);
        uVar6 = uVar9;
        uVar4 = uVar8;
        uVar10 = uVar11;
      } while (iVar5 != 0x50);
      param_1[0x55] = 0;
      *param_1 = uVar7 + *param_1;
      param_1[1] = uVar11 + param_1[1];
      param_1[2] = uVar2 + param_1[2];
      param_1[3] = uVar9 + param_1[3];
      param_1[4] = uVar8 + param_1[4];
      uVar6 = param_1[0x57];
    }
    else {
      uVar6 = param_1[0x57];
    }
    param_1[0x57] = uVar6 + 8;
    param_1[0x56] = param_1[0x56] + (uint)(uVar6 + 8 < 8);
  }
  return;
}

