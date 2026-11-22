// func WHEEL_TIMER_GET @ 00524b34 size=104

int WHEEL_TIMER_GET(uint param_1)

{
  int iVar1;
  
  iVar1 = WHEEL_TIMER_GET_BY_ID(param_1 & 0xfffff);
  if (iVar1 != 0) {
    if ((*(byte *)(iVar1 + 0x54) & 1) == 0) {
      iVar1 = 0;
    }
    else if ((*(uint *)(iVar1 + 0xc) ^ param_1) >> 0x14 != 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

