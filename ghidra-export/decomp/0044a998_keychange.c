// func keychange @ 0044a998 size=612

void keychange(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 auStack_70c [20];
  undefined1 local_6f0 [27];
  undefined1 local_6d5;
  undefined1 local_6d4 [92];
  undefined1 local_678 [63];
  undefined1 auStack_639 [65];
  int local_5f8 [16];
  int local_5b8 [48];
  int local_4f8 [56];
  undefined1 local_418 [1028];
  
  memcpy(local_4f8,&DAT_00683a50,0xe0);
  memcpy(local_5b8,&DAT_00683b30,0xc0);
  memcpy(local_5f8,&DAT_00683bf0,0x40);
  bit2byte(param_1,auStack_639 + 1);
  piVar4 = local_4f8;
  iVar3 = 0;
  do {
    puVar5 = local_678 + iVar3;
    iVar6 = *piVar4;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
    *puVar5 = auStack_639[iVar6];
  } while (iVar3 != 0x38);
  iVar3 = 0;
  do {
    puVar8 = local_678 + iVar3;
    puVar5 = local_6d4 + iVar3;
    iVar3 = iVar3 + 1;
    *puVar5 = *puVar8;
  } while (iVar3 != 0x1c);
  iVar3 = 0x1c;
  do {
    iVar6 = iVar3 + 1;
    auStack_70c[iVar3] = local_678[iVar3];
    iVar3 = iVar6;
  } while (iVar6 != 0x38);
  puVar5 = local_418;
  iVar3 = 0;
  do {
    iVar9 = *(int *)((int)local_5f8 + iVar3);
    for (iVar6 = 1; uVar2 = local_6d4[0], uVar1 = local_6f0[0], iVar6 <= iVar9; iVar6 = iVar6 + 1) {
      puVar8 = local_6d4;
      iVar7 = 0;
      do {
        puVar8 = puVar8 + 1;
        iVar7 = iVar7 + 1;
        puVar8[-1] = *puVar8;
      } while (iVar7 != 0x1b);
      local_6d4[0x1b] = uVar2;
      puVar8 = local_6f0;
      iVar7 = 0;
      do {
        puVar8 = puVar8 + 1;
        iVar7 = iVar7 + 1;
        puVar8[-1] = *puVar8;
      } while (iVar7 != 0x1b);
      local_6d5 = uVar1;
    }
    iVar6 = 0;
    do {
      puVar8 = local_6d4 + iVar6;
      iVar9 = iVar6 + 0x1c;
      iVar6 = iVar6 + 1;
      local_6d4[iVar9] = *puVar8;
    } while (iVar6 != 0x1c);
    do {
      iVar9 = iVar6 + 1;
      local_6d4[iVar6 + 0x1c] = auStack_70c[iVar6];
      iVar6 = iVar9;
    } while (iVar9 != 0x38);
    piVar4 = local_5b8;
    iVar6 = 0;
    do {
      iVar9 = *piVar4;
      puVar8 = puVar5 + iVar6;
      iVar6 = iVar6 + 1;
      piVar4 = piVar4 + 1;
      *puVar8 = local_6d4[iVar9 + 0x1b];
    } while (iVar6 != 0x30);
    iVar3 = iVar3 + 4;
    puVar5 = puVar5 + 0x40;
  } while (iVar3 != 0x40);
  iVar3 = 0;
  do {
    puVar5 = local_418 + iVar3;
    iVar3 = iVar3 + 0x40;
    byte2bit(puVar5,param_2);
    param_2 = param_2 + 8;
  } while (iVar3 != 0x400);
  return;
}

