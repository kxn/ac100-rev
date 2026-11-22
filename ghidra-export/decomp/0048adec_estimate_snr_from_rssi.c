// func estimate_snr_from_rssi @ 0048adec size=36

uint estimate_snr_from_rssi(char param_1,char param_2)

{
  if (param_2 == 0) {
    return (int)param_1 + 0x5fU & 0xff;
  }
  return (int)param_1 - (int)param_2 & 0xff;
}

