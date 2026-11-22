// func wsta_roam_db_ap_stats_cumulate @ 0048264c size=308

undefined4 wsta_roam_db_ap_stats_cumulate(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  iVar1 = apmngr_db_get_ap_max();
  if (((int)(param_1 & 0xffff) < iVar1) && (param_2 != 0)) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    pcVar4 = (char *)(DAT_00767558 + (param_1 & 0xffff) * 0x28);
    if (*pcVar4 != '\0') {
      uVar5 = 0;
      uVar3 = *(uint *)(pcVar4 + 0xc);
      iVar1 = *(int *)(param_2 + 8);
      uVar2 = uVar3 + *(int *)(param_2 + 0xc);
      *(uint *)(pcVar4 + 0xc) = uVar2;
      *(uint *)(pcVar4 + 8) = (uint)(uVar2 < uVar3) + *(int *)(pcVar4 + 8) + iVar1;
      uVar3 = *(uint *)(pcVar4 + 0x14);
      iVar1 = *(int *)(param_2 + 0x10);
      uVar2 = uVar3 + *(int *)(param_2 + 0x14);
      *(uint *)(pcVar4 + 0x14) = uVar2;
      *(uint *)(pcVar4 + 0x10) = (uint)(uVar2 < uVar3) + *(int *)(pcVar4 + 0x10) + iVar1;
      uVar3 = *(uint *)(pcVar4 + 0x1c);
      iVar1 = *(int *)(param_2 + 0x18);
      uVar2 = uVar3 + *(int *)(param_2 + 0x1c);
      *(uint *)(pcVar4 + 0x1c) = uVar2;
      *(uint *)(pcVar4 + 0x18) = (uint)(uVar2 < uVar3) + *(int *)(pcVar4 + 0x18) + iVar1;
      uVar3 = *(uint *)(pcVar4 + 0x24);
      iVar1 = *(int *)(param_2 + 0x20);
      uVar2 = uVar3 + *(int *)(param_2 + 0x24);
      *(uint *)(pcVar4 + 0x24) = uVar2;
      *(uint *)(pcVar4 + 0x20) = (uint)(uVar2 < uVar3) + *(int *)(pcVar4 + 0x20) + iVar1;
    }
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar5;
}

