// func wips_channel_get @ 004c7dd8 size=136

/* WARNING: Removing unreachable block (ram,0x004c7dfc) */

void wips_channel_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = 0;
  if (param_2 != 0) {
    piVar3 = &DAT_006a80a8;
    iVar2 = 1;
    while( true ) {
      iVar5 = iVar2 + 0x1f;
      if (-1 < iVar2) {
        iVar5 = iVar2;
      }
      iVar4 = iVar1 * 4;
      if ((1 << (iVar2 % 0x20 & 0x1fU) & *(uint *)(param_1 + (iVar5 >> 5) * 4)) >>
          (iVar2 % 0x20 & 0x1fU) == 1) {
        iVar1 = iVar1 + 1;
        *(int *)(param_2 + iVar4) = iVar2;
      }
      piVar3 = piVar3 + 1;
      if (piVar3 == (int *)"wips_counter_interval") break;
      iVar2 = *piVar3;
    }
  }
  return;
}

