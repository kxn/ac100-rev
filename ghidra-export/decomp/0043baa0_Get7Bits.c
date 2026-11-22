// func Get7Bits @ 0043baa0 size=68

/* WARNING: Removing unreachable block (ram,0x0043bac8) */

ushort Get7Bits(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + 7;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  return *(ushort *)(param_1 + (iVar1 >> 3)) >> (8U - param_2 % 8 & 0x1f) & 0xfe;
}

