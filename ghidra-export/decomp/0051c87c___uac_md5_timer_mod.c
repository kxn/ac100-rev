// func __uac_md5_timer_mod @ 0051c87c size=468

/* WARNING: Removing unreachable block (ram,0x0051c974) */
/* WARNING: Removing unreachable block (ram,0x0051c960) */
/* WARNING: Removing unreachable block (ram,0x0051c9a8) */

int __uac_md5_timer_mod(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != -1) {
    uac_mutex_take(g_wheel_md5_timer_base,0xffffffff);
    iVar2 = WHEEL_MD5_TIMER_GET(param_1);
    if (iVar2 == 0) {
      uac_mutex_give(g_wheel_md5_timer_base);
      if (wheel_md5_timer_warning_switch == '\0') {
        param_1 = -1;
      }
      else {
        printf("[WHEEL_MD5_TIMER_WARNING]%s()/%d Failed to find the timer %d.\n",
               "__uac_md5_timer_mod",0x1fe,param_1);
        param_1 = -1;
      }
    }
    else {
      if (param_4 == 0) {
        uVar3 = (uint)(param_2 * 1000 + param_3 / 1000) / 500;
        bVar1 = wheel_md5_timer_debug_switch != '\0';
        *(uint *)(iVar2 + 0x58) = uVar3;
        if (bVar1) {
          printf("[WHEEL_MD5_TIMER_DEBUG]%s()/%d timer(%d)\'s interval modified to %lu secs.\n\n",
                 "__uac_md5_timer_mod",0x206,*(undefined4 *)(iVar2 + 0xc),(uVar3 * 500) / 1000);
        }
      }
      if ((*(byte *)(iVar2 + 0x54) & 4) == 0) {
        *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x58) + DAT_007822e0;
        uac_list_remove(iVar2);
        internal_add_timer(iVar2);
      }
      else {
        *(byte *)(iVar2 + 0x54) = *(byte *)(iVar2 + 0x54) | 0x10;
      }
      uac_mutex_give(g_wheel_md5_timer_base);
    }
  }
  return param_1;
}

