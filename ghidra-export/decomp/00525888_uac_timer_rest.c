// func uac_timer_rest @ 00525888 size=1

/* WARNING: Removing unreachable block (ram,0x00525944) */

uint uac_timer_rest(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_t9;
  
  uVar4 = 0;
  if (param_1 != -1) {
    iVar3 = *(int *)(in_t9 + 0x233be0);
    uac_mutex_take(*(undefined4 *)(iVar3 + 0x3bd4),0xffffffff);
    iVar1 = WHEEL_TIMER_GET(param_1);
    if (iVar1 == 0) {
      if (**(char **)(in_t9 + 0x233c4c) != '\0') {
        (**(code **)(in_t9 + 0x234048))
                  (*(int *)(in_t9 + 0x2338a0) + 0x3ea4,*(int *)(in_t9 + 0x2338a0) + 0x43c4,0x278,
                   param_1);
      }
    }
    else if ((*(byte *)(iVar1 + 0x54) & 4) == 0) {
      iVar2 = *(uint *)(iVar1 + 0x5c) - *(uint *)(iVar3 + 0x3be0);
      if (*(uint *)(iVar1 + 0x5c) <= *(uint *)(iVar3 + 0x3be0)) {
        iVar2 = 0;
      }
      uVar4 = (uint)(iVar2 * 500) / 1000;
    }
    uac_mutex_give(*(undefined4 *)(iVar3 + 0x3bd4));
  }
  return uVar4;
}

