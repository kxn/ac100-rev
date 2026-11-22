// func uac_strlwr @ 00522884 size=68

byte * uac_strlwr(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  if (param_1 != (byte *)0x0) {
    while (bVar1 = *param_1, bVar1 != 0) {
      if (bVar1 - 0x41 < 0x1a) {
        *param_1 = bVar1 + 0x20;
        param_1 = param_1 + 1;
      }
      else {
        param_1 = param_1 + 1;
      }
    }
  }
  return pbVar2;
}

