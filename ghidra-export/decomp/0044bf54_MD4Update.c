// func MD4Update @ 0044bf54 size=452

void MD4Update(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte local_50 [56];
  undefined1 local_18 [8];
  
  if (((param_3 != 0) || (*(int *)(param_1 + 0x18) == 0)) && (*(int *)(param_1 + 0x18) == 0)) {
    pbVar2 = (byte *)(param_1 + 0x10);
    uVar7 = param_3;
    if (param_3 != 0) {
      do {
        bVar1 = *pbVar2;
        *pbVar2 = (byte)(bVar1 + uVar7);
        uVar7 = bVar1 + uVar7 >> 8;
        pbVar2 = pbVar2 + 1;
      } while (uVar7 != 0);
    }
    if (param_3 == 0x200) {
      MDblock(param_1);
    }
    else {
      uVar7 = param_3 >> 3;
      if (param_3 < 0x201) {
        uVar3 = 0;
        uVar4 = uVar7;
        if (uVar7 != 0) {
          do {
            pbVar2 = local_50 + uVar3;
            pbVar8 = (byte *)(param_2 + uVar3);
            uVar3 = uVar3 + 1;
            *pbVar2 = *pbVar8;
          } while (uVar3 != uVar7);
        }
        while( true ) {
          if (0x3f < uVar4 + 1) break;
          local_50[uVar4 + 1] = 0;
          uVar4 = uVar4 + 1;
        }
        pbVar2 = local_50 + uVar7;
        bVar1 = (byte)(1 << (7 - (param_3 & 7) & 0x1f));
        *pbVar2 = -bVar1 & (bVar1 | *pbVar2);
        if (uVar7 < 0x38) {
          iVar6 = 0;
          do {
            iVar5 = iVar6 + 1;
            local_18[iVar6] = *(undefined1 *)(param_1 + iVar6 + 0x10);
            iVar6 = iVar5;
          } while (iVar5 != 8);
        }
        else {
          MDblock(param_1,local_50);
          iVar6 = 0;
          do {
            pbVar2 = local_50 + iVar6;
            iVar6 = iVar6 + 1;
            *pbVar2 = 0;
          } while (iVar6 != 0x38);
          iVar6 = 0;
          do {
            iVar5 = iVar6 + 1;
            local_18[iVar6] = *(undefined1 *)(param_1 + iVar6 + 0x10);
            iVar6 = iVar5;
          } while (iVar5 != 8);
        }
        MDblock(param_1,local_50);
        *(undefined4 *)(param_1 + 0x18) = 1;
      }
    }
  }
  return;
}

