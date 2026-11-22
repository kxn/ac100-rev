// func s_replace @ 0044abfc size=1184

void s_replace(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char local_348;
  char local_347;
  char local_346;
  char local_345;
  undefined1 local_344;
  undefined1 local_343;
  undefined1 local_342;
  undefined1 local_341;
  byte local_340 [136];
  byte abStack_2b8 [64];
  byte abStack_278 [64];
  byte abStack_238 [64];
  byte abStack_1f8 [64];
  char acStack_1b8 [64];
  char acStack_178 [64];
  char acStack_138 [64];
  char acStack_f8 [64];
  int local_b8 [32];
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  memcpy(local_b8,&DAT_00683c30,0x80);
  memcpy(acStack_f8,&DAT_00683cb0,0x40);
  memcpy(acStack_138,&DAT_00683cf0,0x40);
  memcpy(acStack_178,&DAT_00683d30,0x40);
  memcpy(acStack_1b8,&DAT_00683d70,0x40);
  memcpy(abStack_1f8,&DAT_00683db0,0x40);
  memcpy(abStack_238,&DAT_00683df0,0x40);
  memcpy(abStack_278,&DAT_00683e30,0x40);
  memcpy(abStack_2b8,&DAT_00683e70,0x40);
  iVar1 = 0;
  local_340[0] = 0;
  local_340[1] = 0;
  local_340[2] = 0;
  local_340[3] = 0;
  local_340[4] = 0;
  local_340[5] = 0;
  local_340[6] = 0;
  local_340[7] = 0;
  local_348 = '\0';
  local_347 = 0;
  local_346 = 0;
  local_345 = 0;
  local_344 = 0;
  local_343 = 0;
  local_342 = 0;
  local_341 = 0;
  do {
    iVar2 = iVar1 + 0x48;
    iVar1 = iVar1 + 1;
    local_340[iVar2] = 0;
  } while (iVar1 != 0x40);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 8;
    iVar1 = iVar1 + 1;
    local_340[iVar2] = 0;
  } while (iVar1 != 0x40);
  pbVar8 = local_340 + 0x49;
  cVar13 = '\0';
  bit2byte(param_1,local_340 + 0x48);
  cVar12 = '\0';
  cVar11 = '\0';
  cVar10 = '\0';
  local_38 = 0;
  iVar1 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  do {
    iVar2 = 0;
    do {
      pbVar5 = local_340 + 8 + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar5 = 0;
    } while (iVar2 != 0x40);
    local_340[0xe] = pbVar8[-1];
    local_340[0xf] = pbVar8[4];
    byte2bit(local_340 + 8,local_340);
    iVar2 = 0;
    uVar9 = (uint)local_340[0];
    do {
      pbVar5 = local_340 + 8 + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar5 = 0;
    } while (iVar2 != 0x40);
    local_340[0xc] = *pbVar8;
    local_340[0xd] = pbVar8[1];
    local_340[0xe] = pbVar8[2];
    local_340[0xf] = pbVar8[3];
    byte2bit(local_340 + 8,local_340);
    uVar3 = (uint)local_340[0];
    if (iVar1 - 1U < 7) {
      iVar2 = uVar9 * 0x10;
      switch(iVar1) {
      case 1:
        cVar11 = acStack_138[uVar3 + iVar2];
        break;
      case 2:
        cVar12 = acStack_178[uVar3 + iVar2];
        break;
      case 3:
        cVar13 = acStack_1b8[uVar3 + iVar2];
        break;
      case 4:
        local_2c = (uint)abStack_1f8[uVar3 + iVar2];
        break;
      case 5:
        local_30 = (uint)abStack_238[uVar3 + iVar2];
        break;
      case 6:
        local_34 = (uint)abStack_278[uVar3 + iVar2];
        break;
      case 7:
        local_38 = (uint)abStack_2b8[uVar3 + iVar2];
      }
    }
    else {
      cVar10 = acStack_f8[uVar3 + uVar9 * 0x10];
    }
    iVar1 = iVar1 + 1;
    pbVar8 = pbVar8 + 6;
  } while (iVar1 != 8);
  local_348 = cVar11 + cVar10 * '\x10';
  local_347 = cVar13 + cVar12 * '\x10';
  local_346 = (char)local_30 + (char)local_2c * '\x10';
  local_345 = (char)local_38 + (char)local_34 * '\x10';
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 0x48;
    iVar1 = iVar1 + 1;
    local_340[iVar2] = 0;
  } while (iVar1 != 0x40);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 8;
    iVar1 = iVar1 + 1;
    local_340[iVar2] = 0;
  } while (iVar1 != 0x40);
  bit2byte(&local_348,local_340 + 0x48);
  piVar4 = local_b8;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 8;
    iVar7 = *piVar4;
    iVar1 = iVar1 + 1;
    piVar4 = piVar4 + 1;
    local_340[iVar2] = local_340[iVar7 + 0x47];
  } while (iVar1 != 0x20);
  iVar1 = 0;
  do {
    puVar6 = (undefined1 *)(param_1 + iVar1);
    iVar1 = iVar1 + 1;
    *puVar6 = 0;
  } while (iVar1 != 8);
  byte2bit(local_340 + 8,param_1);
  return;
}

