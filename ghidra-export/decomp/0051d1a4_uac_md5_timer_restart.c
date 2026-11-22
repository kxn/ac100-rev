// func uac_md5_timer_restart @ 0051d1a4 size=1

/* WARNING: Removing unreachable block (ram,0x0051c974) */
/* WARNING: Removing unreachable block (ram,0x0051c954) */
/* WARNING: Removing unreachable block (ram,0x0051c960) */
/* WARNING: Removing unreachable block (ram,0x0051c964) */
/* WARNING: Removing unreachable block (ram,0x0051c978) */
/* WARNING: Removing unreachable block (ram,0x0051c988) */
/* WARNING: Removing unreachable block (ram,0x0051c9a8) */
/* WARNING: Removing unreachable block (ram,0x0051c9ac) */

int uac_md5_timer_restart(int param_1)

{
  int iVar1;
  int iVar2;
  int in_t9;
  int iVar3;
  
  iVar3 = *(int *)(in_t9 + 0x23c254);
  if (param_1 != -1) {
    iVar2 = *(int *)(iVar3 + 0x2393ac);
    uac_mutex_take(*(undefined4 *)(iVar2 + 0x22d4),0xffffffff);
    iVar1 = WHEEL_MD5_TIMER_GET(param_1);
    if (iVar1 == 0) {
      uac_mutex_give(*(undefined4 *)(iVar2 + 0x22d4));
      if (**(char **)(iVar3 + 0x239434) == '\0') {
        param_1 = -1;
      }
      else {
        (**(code **)(iVar3 + 0x2398d0))
                  (*(int *)(iVar3 + 0x239128) + 0x2790,*(int *)(iVar3 + 0x239128) + 0x2d58,0x1fe,
                   param_1);
        param_1 = -1;
      }
    }
    else {
      if ((*(byte *)(iVar1 + 0x54) & 4) == 0) {
        *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x58) + *(int *)(iVar2 + 0x22e0);
        uac_list_remove(iVar1);
        internal_add_timer(iVar1);
      }
      else {
        *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 0x10;
      }
      uac_mutex_give(*(undefined4 *)(iVar2 + 0x22d4));
    }
  }
  return param_1;
}

