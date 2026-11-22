// func MD4Final @ 0044c118 size=140

void MD4Final(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  MD4Update(param_2,0,0);
  iVar1 = 0;
  puVar3 = param_2;
  while( true ) {
    puVar5 = (undefined1 *)(param_1 + iVar1);
    uVar4 = *puVar3;
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      *puVar5 = (char)uVar4;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 >> 8;
    } while (iVar2 != 4);
    iVar1 = iVar1 + 4;
    if (iVar1 == 0x10) break;
    puVar3 = (uint *)((int)param_2 + iVar1);
  }
  return;
}

