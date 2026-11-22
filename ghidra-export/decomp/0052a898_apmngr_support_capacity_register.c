// func apmngr_support_capacity_register @ 0052a898 size=64

undefined4 apmngr_support_capacity_register(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0x60) {
    (&cap_supp)[(int)param_1 >> 5] = 1 << (param_1 & 0x1f) | (&cap_supp)[(int)param_1 >> 5];
    uVar1 = 0;
  }
  return uVar1;
}

