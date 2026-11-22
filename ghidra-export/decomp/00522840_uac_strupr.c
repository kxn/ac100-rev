// func uac_strupr @ 00522840 size=68

byte * uac_strupr(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  if (param_1 != (byte *)0x0) {
    while (bVar1 = *param_1, bVar1 != 0) {
      if (bVar1 - 0x61 < 0x1a) {
        *param_1 = bVar1 - 0x20;
        param_1 = param_1 + 1;
      }
      else {
        param_1 = param_1 + 1;
      }
    }
  }
  return pbVar2;
}

