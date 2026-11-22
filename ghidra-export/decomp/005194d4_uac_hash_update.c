// func uac_hash_update @ 005194d4 size=220

uint uac_hash_update(byte *param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  
  uVar5 = param_3 + param_2;
  pbVar7 = param_1;
  for (uVar8 = param_2; 3 < uVar8; uVar8 = uVar8 - 4) {
    pbVar3 = pbVar7 + 1;
    bVar4 = *pbVar7;
    pbVar1 = pbVar7 + 2;
    pbVar2 = pbVar7 + 3;
    pbVar7 = pbVar7 + 4;
    iVar6 = (uint)bVar4 + (uint)*pbVar3 * 0x100 + (uint)*pbVar1 * 0x10000 +
            (uint)*pbVar2 * 0x1000000 + uVar5;
    uVar5 = ~(iVar6 * 0x8000) + iVar6;
    uVar5 = (uVar5 >> 10 ^ uVar5) * 9;
    uVar5 = uVar5 >> 6 ^ uVar5;
    uVar5 = ~(uVar5 << 0xb) + uVar5;
    uVar5 = uVar5 >> 0x10 ^ uVar5;
  }
  iVar6 = param_2 - (param_2 & 0xfffffffc);
  param_1 = param_1 + (param_2 & 0xfffffffc);
  if (iVar6 != 2) {
    if (iVar6 != 3) {
      if (iVar6 != 1) {
        return uVar5;
      }
      bVar4 = *param_1;
      goto LAB_005195a8;
    }
    uVar5 = uVar5 + (uint)param_1[2] * 0x10000;
  }
  uVar5 = uVar5 ^ (uint)param_1[1] << 8;
  bVar4 = *param_1;
LAB_005195a8:
  return uVar5 + bVar4;
}

