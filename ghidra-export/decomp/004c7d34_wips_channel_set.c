// func wips_channel_set @ 004c7d34 size=76

/* WARNING: Removing unreachable block (ram,0x004c7d5c) */

void wips_channel_set(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  
  if (param_2 < 0xc0) {
    iVar1 = param_2 + 0x1f;
    if (-1 < param_2) {
      iVar1 = param_2;
    }
    puVar2 = (uint *)(param_1 + (iVar1 >> 5) * 4);
    *puVar2 = *puVar2 | 1 << (param_2 % 0x20 & 0x1fU);
  }
  return;
}

