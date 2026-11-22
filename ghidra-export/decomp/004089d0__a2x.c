// func _a2x @ 004089d0 size=88

uint _a2x(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0x47) {
    if (0x40 < param_1) {
      return param_1 - 0x37U & 0xff;
    }
    uVar1 = param_1 - 0x30;
    if (9 < uVar1) {
      return 0;
    }
  }
  else {
    uVar1 = param_1 - 0x57;
    if (5 < param_1 - 0x61U) {
      return 0;
    }
  }
  return uVar1 & 0xff;
}

