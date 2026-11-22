// func transfer_hex_to_int @ 00452bf0 size=80

int transfer_hex_to_int(byte param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (int)(char)param_1;
  uVar1 = (uint)param_1;
  if (uVar1 - 0x30 < 10) {
    return iVar2 + -0x30;
  }
  if (5 < uVar1 - 0x61) {
    iVar2 = iVar2 + -0x37;
    if (5 < uVar1 - 0x41) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return iVar2 + -0x57;
}

