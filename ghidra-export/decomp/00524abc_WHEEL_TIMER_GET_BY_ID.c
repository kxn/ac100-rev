// func WHEEL_TIMER_GET_BY_ID @ 00524abc size=120

int WHEEL_TIMER_GET_BY_ID(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1 << (*(uint *)(PTR_DAT_007591ac + 0x2064) & 0x1f);
  iVar1 = iVar3 + -1;
  if (iVar1 <= param_1) {
    iVar2 = 0;
    if (param_1 < iVar1 + DAT_007c53ec) {
      iVar2 = *(int *)(DAT_007c53e8 + (param_1 + (1 - iVar3)) * 4);
    }
    return iVar2;
  }
  return DAT_007c53e4 + param_1 * 0x6c;
}

