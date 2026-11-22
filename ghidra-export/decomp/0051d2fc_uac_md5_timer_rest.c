// func uac_md5_timer_rest @ 0051d2fc size=1

/* WARNING: Removing unreachable block (ram,0x0051d3b8) */

uint uac_md5_timer_rest(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_t9;
  
  uVar4 = 0;
  if (param_1 != -1) {
    iVar3 = *(int *)(in_t9 + 0x23c0b0);
    uac_mutex_take(*(undefined4 *)(iVar3 + 0x22d4),0xffffffff);
    iVar1 = WHEEL_MD5_TIMER_GET(param_1);
    if (iVar1 == 0) {
      if (**(char **)(in_t9 + 0x23c138) != '\0') {
        (**(code **)(in_t9 + 0x23c5d4))
                  (*(int *)(in_t9 + 0x23be2c) + 0x2790,*(int *)(in_t9 + 0x23be2c) + 0x2d84,0x25a,
                   param_1);
      }
    }
    else if ((*(byte *)(iVar1 + 0x54) & 4) == 0) {
      iVar2 = *(uint *)(iVar1 + 0x5c) - *(uint *)(iVar3 + 0x22e0);
      if (*(uint *)(iVar1 + 0x5c) <= *(uint *)(iVar3 + 0x22e0)) {
        iVar2 = 0;
      }
      uVar4 = (uint)(iVar2 * 500) / 1000;
    }
    uac_mutex_give(*(undefined4 *)(iVar3 + 0x22d4));
  }
  return uVar4;
}

