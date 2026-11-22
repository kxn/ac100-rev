// func uac_timer_restart @ 00525730 size=1

/* WARNING: Removing unreachable block (ram,0x00524c94) */
/* WARNING: Removing unreachable block (ram,0x00524c74) */
/* WARNING: Removing unreachable block (ram,0x00524c80) */
/* WARNING: Removing unreachable block (ram,0x00524c84) */
/* WARNING: Removing unreachable block (ram,0x00524c98) */
/* WARNING: Removing unreachable block (ram,0x00524ca8) */
/* WARNING: Removing unreachable block (ram,0x00524cc8) */
/* WARNING: Removing unreachable block (ram,0x00524ccc) */

int uac_timer_restart(int param_1)

{
  int iVar1;
  int iVar2;
  int in_t9;
  int iVar3;
  
  iVar3 = *(int *)(in_t9 + 0x233cc8);
  if (param_1 != -1) {
    iVar2 = *(int *)(iVar3 + 0x239468);
    uac_mutex_take(*(undefined4 *)(iVar2 + 0x3bd4),0xffffffff);
    iVar1 = WHEEL_TIMER_GET(param_1);
    if (iVar1 == 0) {
      uac_mutex_give(*(undefined4 *)(iVar2 + 0x3bd4));
      if (**(char **)(iVar3 + 0x2394d4) == '\0') {
        param_1 = -1;
      }
      else {
        (**(code **)(iVar3 + 0x2398d0))
                  (*(int *)(iVar3 + 0x239128) + 0x3ea4,*(int *)(iVar3 + 0x239128) + 0x43a0,0x21c,
                   param_1);
        param_1 = -1;
      }
    }
    else {
      if ((*(byte *)(iVar1 + 0x54) & 4) == 0) {
        *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x58) + *(int *)(iVar2 + 0x3be0);
        uac_list_remove(iVar1);
        internal_add_timer(iVar1);
      }
      else {
        *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 0x10;
      }
      uac_mutex_give(*(undefined4 *)(iVar2 + 0x3bd4));
    }
  }
  return param_1;
}

