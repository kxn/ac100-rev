// func estimate_snr_from_rcpi @ 0048adcc size=1

uint estimate_snr_from_rcpi(char param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (-0x5f < param_1) {
    uVar1 = (int)param_1 + 0x5fU & 0xff;
  }
  return uVar1;
}

