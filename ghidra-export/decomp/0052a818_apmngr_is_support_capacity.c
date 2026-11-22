// func apmngr_is_support_capacity @ 0052a818 size=72

/* WARNING: Removing unreachable block (ram,0x0052a820) */

bool apmngr_is_support_capacity(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_1 < 0) {
    iVar1 = param_1 + 0x1f;
  }
  return (1 << (param_1 % 0x20 & 0x1fU) & (&cap_supp)[iVar1 >> 5]) != 0;
}

