// func undes @ 0044b49c size=1008

void undes(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  byte *pbVar7;
  undefined1 local_600;
  undefined1 local_5ff;
  undefined1 local_5fe;
  undefined1 local_5fd;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5fa;
  undefined1 local_5f9;
  undefined1 local_5f8 [128];
  undefined1 local_578 [128];
  byte local_4f8 [128];
  undefined1 auStack_478 [120];
  undefined1 auStack_400 [8];
  byte local_3f8 [128];
  undefined1 local_378;
  undefined1 local_377;
  undefined1 local_376;
  undefined1 local_375;
  undefined1 local_370 [128];
  undefined1 local_2f0;
  undefined1 local_2ef;
  undefined1 local_2ee;
  undefined1 local_2ed;
  int local_2e8 [48];
  int local_228 [64];
  int local_128 [64];
  
  memcpy(local_128,&DAT_00683ecc,0x100);
  memcpy(local_228,&DAT_00683fcc,0x100);
  memcpy(local_2e8,&DAT_006840cc,0xc0);
  local_600 = 0;
  local_5ff = 0;
  local_5fe = 0;
  local_5fd = 0;
  local_5fc = 0;
  local_5fb = 0;
  local_5fa = 0;
  local_5f9 = 0;
  puVar1 = local_370;
  do {
    iVar2 = 0;
    do {
      puVar1[iVar2] = 0;
      puVar1[(int)(local_3f8 + (iVar2 - (int)local_370))] = 0;
      iVar6 = iVar2 - (int)local_370;
      iVar2 = iVar2 + 1;
      puVar1[(int)(auStack_478 + iVar6)] = 0;
    } while (iVar2 != 8);
    puVar1 = puVar1 + 8;
  } while (puVar1 != &local_2f0);
  iVar2 = 0;
  do {
    local_4f8[iVar2 + 0x40] = 0;
    local_4f8[iVar2] = 0;
    local_5f8[iVar2 + 0x40] = 0;
    local_5f8[iVar2] = 0;
    local_578[iVar2 + 0x40] = 0;
    puVar1 = local_578 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar1 = 0;
  } while (iVar2 != 0x40);
  keychange(param_2,auStack_478);
  bit2byte(param_1,local_4f8 + 0x40);
  piVar4 = local_128;
  iVar2 = 0;
  do {
    pbVar3 = local_4f8 + iVar2;
    iVar6 = *piVar4;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
    *pbVar3 = local_4f8[iVar6 + 0x3f];
  } while (iVar2 != 0x40);
  byte2bit(local_4f8,&local_600);
  local_378 = local_600;
  local_377 = local_5ff;
  local_376 = local_5fe;
  local_375 = local_5fd;
  local_2f0 = local_5fc;
  local_2ef = local_5fb;
  local_2ee = local_5fa;
  local_2ed = local_5f9;
  puVar1 = &local_2f0;
  do {
    iVar2 = 0;
    do {
      puVar5 = puVar1 + iVar2;
      iVar6 = iVar2 - (int)local_370;
      iVar2 = iVar2 + 1;
      puVar1[(int)(local_3f8 + iVar6 + -8)] = *puVar5;
    } while (iVar2 != 4);
    bit2byte(puVar1,local_5f8 + 0x40);
    piVar4 = local_2e8;
    iVar2 = 0;
    do {
      puVar5 = local_5f8 + iVar2;
      iVar6 = *piVar4;
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      *puVar5 = local_5f8[iVar6 + 0x3f];
    } while (iVar2 != 0x30);
    byte2bit(local_5f8,puVar1);
    iVar2 = 0;
    do {
      pbVar3 = puVar1 + iVar2;
      iVar6 = iVar2 + (0x78 - (int)local_370);
      iVar2 = iVar2 + 1;
      *pbVar3 = puVar1[(int)(local_4f8 + iVar6)] ^ *pbVar3;
    } while (iVar2 != 6);
    s_replace(puVar1);
    iVar2 = 0;
    puVar5 = puVar1 + -8;
    do {
      pbVar7 = puVar1 + iVar2;
      iVar6 = iVar2 - (int)local_370;
      pbVar3 = puVar5 + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar3 = *pbVar7 ^ puVar1[(int)(local_3f8 + iVar6)];
    } while (iVar2 != 4);
    puVar1 = puVar5;
  } while (local_370 != puVar5);
  iVar2 = 0;
  do {
    puVar1 = (undefined1 *)(param_3 + iVar2);
    puVar5 = local_370 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar1 = *puVar5;
  } while (iVar2 != 4);
  *(byte *)(param_3 + 4) = local_3f8[0];
  *(byte *)(param_3 + 5) = local_3f8[1];
  *(byte *)(param_3 + 6) = local_3f8[2];
  *(byte *)(param_3 + 7) = local_3f8[3];
  bit2byte(param_3,local_578 + 0x40);
  piVar4 = local_228;
  iVar2 = 0;
  do {
    iVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    puVar1 = local_578 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar1 = local_578[iVar6 + 0x3f];
  } while (iVar2 != 0x40);
  byte2bit(local_578,param_3);
  return;
}

