// func wips_ap_del @ 004c5ce4 size=268

undefined4 wips_ap_del(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = *(short *)(param_1 + 0x10);
  FUN_004082d0(wips_global_mutex,0xffffffff);
  iVar3 = FUN_004081b0(&g_wips_list);
  while (iVar3 != 0) {
    iVar4 = FUN_00408680(iVar3);
    iVar3 = FUN_004081b0(iVar3 + 0x9c);
    while (iVar5 = iVar3, iVar3 = iVar4, iVar5 != 0) {
      iVar3 = FUN_00408680(iVar5);
      if (*(short *)(iVar5 + 0x38) == sVar1) {
        *(undefined2 *)(iVar5 + 0x38) = 0xffff;
      }
    }
  }
  FUN_00407f30(wips_global_mutex);
  FUN_004082d0(wips_global_mutex,0xffffffff);
  iVar3 = FUN_004081b0(&g_white_list);
  if (iVar3 != 0) {
    sVar2 = *(short *)(iVar3 + 0x4c);
    while( true ) {
      if (sVar2 == sVar1) {
        *(undefined2 *)(iVar3 + 0x4c) = 0xffff;
        *(undefined4 *)(iVar3 + 0x50) = 0;
        *(undefined4 *)(iVar3 + 0x54) = 0;
      }
      iVar3 = FUN_00408680(iVar3);
      if (iVar3 == 0) break;
      sVar2 = *(short *)(iVar3 + 0x4c);
    }
  }
  FUN_00407f30(wips_global_mutex);
  return 0;
}

