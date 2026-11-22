// func arp_defend_str2upper @ 004768c0 size=72

void arp_defend_str2upper(byte *param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = param_1 + param_2;
  while (pbVar1 = pbVar1 + -1, param_1 <= pbVar1) {
    if ((byte)(*pbVar1 + 0x9f) < 0x1a) {
      *pbVar1 = *pbVar1 & 0xdf;
    }
  }
  return;
}

