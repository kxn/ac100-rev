// func FUN_0040a270 @ 0040a270 size=80

uint FUN_0040a270(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1 << 0x18) >> 0x1c;
  uVar1 = (param_2 << 0x18) >> 0x1c;
  if (uVar1 < uVar2) {
    uVar1 = uVar2;
  }
  uVar2 = (param_1 << 0x10) >> 0x18;
  uVar3 = (param_2 << 0x10) >> 0x18;
  if (uVar3 < uVar2) {
    uVar3 = uVar2;
  }
  uVar2 = param_1 & 0xf;
  if ((param_1 & 0xf) <= (param_2 & 0xf)) {
    uVar2 = param_2 & 0xf;
  }
  return uVar1 << 4 | uVar3 << 8 | uVar2 | param_2 & 0xffff0000;
}

