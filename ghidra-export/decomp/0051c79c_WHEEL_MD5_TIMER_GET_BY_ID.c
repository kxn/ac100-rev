// func WHEEL_MD5_TIMER_GET_BY_ID @ 0051c79c size=120

int WHEEL_MD5_TIMER_GET_BY_ID(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1 << (*(uint *)(PTR_DAT_007591ac + 0x2044) & 0x1f);
  iVar1 = iVar3 + -1;
  if (iVar1 <= param_1) {
    iVar2 = 0;
    if (param_1 < iVar1 + DAT_00783aec) {
      iVar2 = *(int *)(DAT_00783ae8 + (param_1 + (1 - iVar3)) * 4);
    }
    return iVar2;
  }
  return DAT_00783ae4 + param_1 * 0x6c;
}

