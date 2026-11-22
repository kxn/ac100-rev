// func FUN_004360d4 @ 004360d4 size=244

void FUN_004360d4(int param_1,void *param_2)

{
  int iVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char local_48;
  char local_47 [35];
  
  iVar4 = 0;
  pcVar3 = &local_48;
  memset(&local_48,0,0x20);
  memcpy(&local_48,param_2,0xc);
  iVar1 = (int)local_48;
  do {
    if (iVar1 == 0) {
      return;
    }
    while( true ) {
      if (5 < iVar4) {
        return;
      }
      iVar5 = (int)pcVar3[1];
      if ((iVar1 == 0x3a) || (iVar1 == 0x2d)) break;
      iVar1 = _a2x();
      bVar2 = _a2x(iVar5);
      *(byte *)(param_1 + iVar4) = (byte)(iVar1 << 4) | bVar2;
      if (iVar5 == 0) {
        return;
      }
      iVar1 = (int)pcVar3[2];
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 2;
      if (iVar1 == 0) {
        return;
      }
    }
    pcVar3 = pcVar3 + 1;
    iVar1 = iVar5;
  } while( true );
}

