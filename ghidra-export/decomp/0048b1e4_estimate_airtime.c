// func estimate_airtime @ 0048b1e4 size=1

/* WARNING: Removing unreachable block (ram,0x0048b1f4) */

uint estimate_airtime(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = ((param_3 & 0xffff) * (param_4 & 0xff)) / 100 & 0xffff;
  if (uVar1 != 0) {
    if (uVar1 == 0) {
      trap(7);
    }
    uVar1 = (uint)((param_2 + param_1) * 100) / uVar1;
    if (100 < uVar1) {
      uVar1 = 100;
    }
    return uVar1 & 0xff;
  }
  return 0xff;
}

