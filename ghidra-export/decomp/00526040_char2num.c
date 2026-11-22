// func char2num @ 00526040 size=1

int char2num(byte param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  iVar1 = (int)(char)(uVar2 - 0x30);
  if (9 < (uVar2 - 0x30 & 0xff)) {
    if (uVar2 - 0x61 < 6) {
      return (int)(char)(param_1 + 0xa9);
    }
    iVar1 = 0x30;
    if (uVar2 - 0x41 < 6) {
      return (int)(char)(param_1 - 0x37);
    }
  }
  return iVar1;
}

