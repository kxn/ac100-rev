// func wsta_roam_db_global_stats_cumulate @ 00482340 size=692

undefined4 wsta_roam_db_global_stats_cumulate(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  piVar1 = DAT_0076755c;
  uVar2 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    uVar4 = piVar1[1];
    iVar5 = *param_1;
    uVar3 = uVar4 + param_1[1];
    piVar1[1] = uVar3;
    *piVar1 = (uint)(uVar3 < uVar4) + *piVar1 + iVar5;
    uVar4 = piVar1[3];
    iVar5 = param_1[2];
    uVar3 = uVar4 + param_1[3];
    piVar1[3] = uVar3;
    piVar1[2] = (uint)(uVar3 < uVar4) + piVar1[2] + iVar5;
    uVar4 = piVar1[5];
    iVar5 = param_1[4];
    uVar3 = uVar4 + param_1[5];
    piVar1[5] = uVar3;
    piVar1[4] = (uint)(uVar3 < uVar4) + piVar1[4] + iVar5;
    uVar4 = piVar1[7];
    iVar5 = param_1[6];
    uVar3 = uVar4 + param_1[7];
    piVar1[7] = uVar3;
    piVar1[6] = (uint)(uVar3 < uVar4) + piVar1[6] + iVar5;
    uVar4 = piVar1[9];
    iVar5 = param_1[8];
    uVar3 = uVar4 + param_1[9];
    piVar1[9] = uVar3;
    piVar1[8] = (uint)(uVar3 < uVar4) + piVar1[8] + iVar5;
    uVar3 = piVar1[0xb] + param_1[0xb];
    piVar1[10] = (uint)(uVar3 < (uint)piVar1[0xb]) + piVar1[10] + param_1[10];
    piVar1[0xb] = uVar3;
    uVar4 = piVar1[0xd];
    iVar5 = param_1[0xc];
    uVar3 = uVar4 + param_1[0xd];
    piVar1[0xd] = uVar3;
    piVar1[0xc] = (uint)(uVar3 < uVar4) + piVar1[0xc] + iVar5;
    uVar4 = piVar1[0xf];
    iVar5 = param_1[0xe];
    uVar3 = uVar4 + param_1[0xf];
    piVar1[0xf] = uVar3;
    piVar1[0xe] = (uint)(uVar3 < uVar4) + piVar1[0xe] + iVar5;
    uVar4 = piVar1[0x11];
    iVar5 = param_1[0x10];
    uVar3 = uVar4 + param_1[0x11];
    piVar1[0x11] = uVar3;
    piVar1[0x10] = (uint)(uVar3 < uVar4) + piVar1[0x10] + iVar5;
    uVar4 = piVar1[0x13];
    iVar5 = param_1[0x12];
    uVar3 = uVar4 + param_1[0x13];
    piVar1[0x13] = uVar3;
    piVar1[0x12] = (uint)(uVar3 < uVar4) + piVar1[0x12] + iVar5;
    uVar4 = piVar1[0x15];
    iVar5 = param_1[0x14];
    uVar3 = uVar4 + param_1[0x15];
    piVar1[0x15] = uVar3;
    piVar1[0x14] = (uint)(uVar3 < uVar4) + piVar1[0x14] + iVar5;
    uVar3 = piVar1[0x17] + param_1[0x17];
    piVar1[0x16] = (uint)(uVar3 < (uint)piVar1[0x17]) + piVar1[0x16] + param_1[0x16];
    piVar1[0x17] = uVar3;
    uVar4 = piVar1[0x19];
    iVar5 = param_1[0x18];
    uVar3 = uVar4 + param_1[0x19];
    piVar1[0x19] = uVar3;
    piVar1[0x18] = (uint)(uVar3 < uVar4) + piVar1[0x18] + iVar5;
    uVar4 = piVar1[0x1b];
    iVar5 = param_1[0x1a];
    uVar3 = uVar4 + param_1[0x1b];
    piVar1[0x1b] = uVar3;
    piVar1[0x1a] = (uint)(uVar3 < uVar4) + piVar1[0x1a] + iVar5;
    uVar4 = piVar1[0x1d];
    iVar5 = param_1[0x1c];
    uVar3 = uVar4 + param_1[0x1d];
    piVar1[0x1d] = uVar3;
    uVar2 = l_wsta_roam_data;
    piVar1[0x1c] = (uint)(uVar3 < uVar4) + piVar1[0x1c] + iVar5;
    FUN_00407f30(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

