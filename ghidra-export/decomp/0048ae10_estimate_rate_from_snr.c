// func estimate_rate_from_snr @ 0048ae10 size=980

uint estimate_rate_from_snr(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined *puVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  param_1 = param_1 & 0xff;
  param_4 = param_4 & 0xff;
  uVar9 = param_2 >> 0x18;
  uVar8 = (param_2 << 0x10) >> 0x18;
  uVar7 = (param_2 << 8) >> 0x18;
  if (param_1 == 0) {
    return 0;
  }
  if (4 < uVar8) {
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Invalid mode %d, convert to max mode %d.\n\n",
             "estimate_rate_from_snr",0x115,uVar8,4);
    }
    uVar8 = 4;
  }
  if (3 < uVar9) {
    if (wsta_roam_strategy_switch != '\0') {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Invalid bw %d, convert to max bw %d.\n\n",
             "estimate_rate_from_snr",0x11b,uVar9,3);
    }
    uVar9 = 3;
  }
  if (uVar7 < 0x11) {
    if ((uVar7 == 0) && (uVar7 = 1, wsta_roam_strategy_switch != '\0')) {
      printf("[WSTA_ROAM_STRATEGY]%s()/%d Invalid nss %d, convert to min nss %d.\n\n",
             "estimate_rate_from_snr",0x126,0,1);
    }
  }
  else if (wsta_roam_strategy_switch == '\0') {
    uVar7 = 0x10;
  }
  else {
    printf("[WSTA_ROAM_STRATEGY]%s()/%d Invalid nss %d, convert to max nss %d.\n\n",
           "estimate_rate_from_snr",0x121,uVar7,0x10);
    uVar7 = 0x10;
  }
  if (uVar8 == 1) {
    if (uVar9 != 0) {
      uVar9 = 1;
    }
    if (4 < uVar7) {
      uVar7 = 4;
    }
  }
  else if (uVar8 == 0) {
    uVar7 = 1;
    uVar9 = 0;
  }
  else if ((uVar8 == 2) || (uVar8 == 3)) {
    if (3 < uVar9) {
      uVar9 = 3;
    }
    if (8 < uVar7) {
      uVar7 = 8;
    }
  }
  else {
    if (3 < uVar9) {
      uVar9 = 3;
    }
    if (0x10 < uVar7) {
      uVar7 = 0x10;
    }
  }
  if (param_4 == 0) {
    puVar4 = &estimate_snr_rate_table_2g;
  }
  else {
    if (param_4 != 1) {
      printf("invalid band %d, quit estimating.\n",param_4);
      return 0;
    }
    puVar4 = &estimate_snr_rate_table_5g;
  }
  pbVar3 = puVar4 + uVar8 * 0x38;
  iVar1 = 0;
  pbVar6 = pbVar3;
  while ((uVar5 = (uint)*pbVar6, uVar5 <= param_1 && (uVar5 != 0xff))) {
    pbVar6 = pbVar6 + 4;
    if (iVar1 == 0xd) goto LAB_0048af24;
    iVar1 = iVar1 + 1;
  }
  if ((iVar1 == 0xd) || (uVar5 == 0xff)) {
LAB_0048af24:
    uVar5 = (uint)*(ushort *)(pbVar3 + iVar1 * 4 + 2);
  }
  else if (iVar1 == 0) {
    if (*(ushort *)(pbVar3 + 2) == 0) {
      return 0;
    }
    uVar5 = (uint)*pbVar3;
    if (uVar5 == 0) {
      return 0;
    }
    if (uVar5 == 0) {
      trap(7);
    }
    uVar5 = (*(ushort *)(pbVar3 + 2) * param_1) / uVar5 & 0xffff;
  }
  else {
    pbVar3 = pbVar3 + (iVar1 + -1) * 4;
    uVar10 = (uint)*pbVar3;
    uVar2 = 0;
    if (uVar5 != uVar10) {
      if (uVar5 - uVar10 == 0) {
        trap(7);
      }
      uVar2 = (int)((uint)*(ushort *)(pbVar6 + 2) - (uint)*(ushort *)(pbVar3 + 2)) /
              (int)(uVar5 - uVar10) & 0xffff;
    }
    uVar5 = uVar2 * (param_1 - uVar10) + (uint)*(ushort *)(pbVar3 + 2) & 0xffff;
  }
  if (*(int *)(&nsdTable + uVar8 * 0x10) == 0) {
    trap(7);
  }
  uVar10 = (int)(uVar5 * uVar7 * *(int *)(&nsdTable + (uVar8 * 4 + uVar9) * 4)) /
           *(int *)(&nsdTable + uVar8 * 0x10) & 0xffff;
  if (wsta_roam_strategy_switch != '\0') {
    printf("[WSTA_ROAM_STRATEGY]%s()/%d [mode:%d][snr:%d][band:%d] => [subRate:%dMbps][bw:%d][nss:%d] => [estimated_rate]:%dMbps\n\n"
           ,"estimate_rate_from_snr",0x186,uVar8,param_1,param_4,uVar5,uVar9,uVar7,uVar10);
  }
  return uVar10;
}

