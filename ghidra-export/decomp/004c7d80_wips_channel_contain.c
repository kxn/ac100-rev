// func wips_channel_contain @ 004c7d80 size=88

/* WARNING: Removing unreachable block (ram,0x004c7d94) */

bool wips_channel_contain(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_2 < 0xc0) {
    iVar2 = param_2;
    if (param_2 < 0) {
      iVar2 = param_2 + 0x1f;
    }
    bVar1 = (1 << (param_2 % 0x20 & 0x1fU) & *(uint *)(param_1 + (iVar2 >> 5) * 4)) >>
            (param_2 % 0x20 & 0x1fU) == 1;
  }
  return bVar1;
}

