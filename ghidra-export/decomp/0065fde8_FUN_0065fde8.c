// func FUN_0065fde8 @ 0065fde8 size=76

void FUN_0065fde8(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  uint *puVar6;
  
  iVar5 = 0;
  do {
    pbVar1 = param_2 + 1;
    puVar6 = (uint *)(param_1 + iVar5);
    pbVar2 = param_2 + 2;
    iVar5 = iVar5 + 4;
    bVar4 = *param_2;
    pbVar3 = param_2 + 3;
    param_2 = param_2 + 4;
    *puVar6 = (uint)*pbVar1 << 8 | (uint)*pbVar2 << 0x10 | (uint)bVar4 | (uint)*pbVar3 << 0x18;
  } while (iVar5 != 0x40);
  return;
}

