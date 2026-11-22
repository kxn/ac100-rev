// func endes @ 0044b09c size=1024

void endes(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  byte local_608;
  undefined1 local_607;
  undefined1 local_606;
  undefined1 local_605;
  byte local_604;
  undefined1 local_603;
  undefined1 local_602;
  undefined1 local_601;
  undefined1 local_600 [128];
  undefined1 local_580 [128];
  undefined1 local_500 [128];
  byte abStack_480 [128];
  byte local_400 [8];
  undefined1 local_3f8 [120];
  byte local_380 [8];
  byte local_378 [128];
  byte local_2f8;
  undefined1 local_2f7;
  undefined1 local_2f6;
  undefined1 local_2f5;
  int local_2f0 [48];
  int local_230 [64];
  int local_130 [64];
  byte *local_30;
  
  memcpy(local_130,&DAT_00683ecc,0x100);
  memcpy(local_230,&DAT_00683fcc,0x100);
  memcpy(local_2f0,&DAT_006840cc,0xc0);
  local_608 = 0;
  local_607 = 0;
  local_606 = 0;
  local_605 = 0;
  local_604 = 0;
  local_603 = 0;
  local_602 = 0;
  local_601 = 0;
  pbVar1 = local_378;
  local_30 = abStack_480;
  do {
    iVar2 = 0;
    do {
      pbVar1[iVar2] = 0;
      pbVar1[(int)(local_400 + (iVar2 - (int)local_378))] = 0;
      iVar7 = iVar2 - (int)local_378;
      iVar2 = iVar2 + 1;
      pbVar1[(int)(abStack_480 + iVar7)] = 0;
    } while (iVar2 != 8);
    pbVar1 = pbVar1 + 8;
  } while (pbVar1 != &local_2f8);
  iVar2 = 0;
  do {
    local_500[iVar2 + 0x40] = 0;
    local_500[iVar2] = 0;
    local_600[iVar2 + 0x40] = 0;
    local_600[iVar2] = 0;
    local_580[iVar2 + 0x40] = 0;
    puVar8 = local_580 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar8 = 0;
  } while (iVar2 != 0x40);
  keychange(param_2,abStack_480);
  bit2byte(param_1,local_500 + 0x40);
  piVar4 = local_130;
  iVar2 = 0;
  do {
    puVar8 = local_500 + iVar2;
    iVar7 = *piVar4;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
    *puVar8 = local_500[iVar7 + 0x3f];
  } while (iVar2 != 0x40);
  puVar8 = local_3f8;
  byte2bit(local_500,&local_608);
  local_378[0] = local_608;
  local_378[1] = local_607;
  local_378[2] = local_606;
  local_378[3] = local_605;
  local_400[0] = local_604;
  local_400[1] = local_603;
  local_400[2] = local_602;
  local_400[3] = local_601;
  pbVar1 = local_400;
  do {
    iVar2 = 0;
    do {
      iVar7 = iVar2 + 1;
      puVar8[(int)(local_378 + (iVar2 - (int)local_400))] = puVar8[iVar2 + -8];
      iVar2 = iVar7;
    } while (iVar7 != 4);
    bit2byte(pbVar1,local_600 + 0x40);
    piVar4 = local_2f0;
    iVar2 = 0;
    do {
      puVar5 = local_600 + iVar2;
      iVar7 = *piVar4;
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      *puVar5 = local_600[iVar7 + 0x3f];
    } while (iVar2 != 0x30);
    byte2bit(local_600,pbVar1);
    pbVar6 = local_30;
    iVar2 = 0;
    do {
      pbVar3 = pbVar1 + iVar2;
      iVar7 = iVar2 - (int)local_400;
      iVar2 = iVar2 + 1;
      *pbVar3 = pbVar1[(int)(pbVar6 + iVar7)] ^ *pbVar3;
    } while (iVar2 != 6);
    s_replace(pbVar1);
    iVar2 = 0;
    do {
      pbVar3 = pbVar1 + iVar2;
      iVar7 = iVar2 - (int)local_400;
      pbVar6 = puVar8 + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar6 = *pbVar3 ^ pbVar1[(int)(local_378 + iVar7)];
    } while (iVar2 != 4);
    pbVar1 = pbVar1 + 8;
    puVar8 = puVar8 + 8;
  } while (pbVar1 != local_380);
  iVar2 = 0;
  do {
    iVar7 = iVar2 + 1;
    *(byte *)(param_3 + iVar2) = local_380[iVar2];
    iVar2 = iVar7;
  } while (iVar7 != 4);
  *(byte *)(param_3 + 4) = local_2f8;
  *(undefined1 *)(param_3 + 5) = local_2f7;
  *(undefined1 *)(param_3 + 6) = local_2f6;
  *(undefined1 *)(param_3 + 7) = local_2f5;
  bit2byte(param_3,local_580 + 0x40);
  piVar4 = local_230;
  iVar2 = 0;
  do {
    iVar7 = *piVar4;
    piVar4 = piVar4 + 1;
    puVar8 = local_580 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar8 = local_580[iVar7 + 0x3f];
  } while (iVar2 != 0x40);
  byte2bit(local_580,param_3);
  return;
}

