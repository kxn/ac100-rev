// func uac_timer_remove @ 00525754 size=308

void uac_timer_remove(int param_1)

{
  int iVar1;
  
  if (param_1 != -1) {
    uac_mutex_take(g_wheel_timer_base,0xffffffff);
    iVar1 = WHEEL_TIMER_GET(param_1);
    if (iVar1 == 0) {
      if (wheel_timer_warning_switch != '\0') {
        printf("[WHEEL_TIMER_WARNING]%s()/%d Failed to find the timer %d.\n","uac_timer_remove",
               0x252,param_1);
      }
    }
    else if ((*(byte *)(iVar1 + 0x54) & 4) == 0) {
      if (*(code **)(iVar1 + 100) != (code *)0x0) {
        (**(code **)(iVar1 + 100))(*(undefined4 *)(iVar1 + 0x68));
      }
      uac_list_remove(iVar1);
      uac_id_free(DAT_007c5400,*(uint *)(iVar1 + 0xc) & 0xfffff);
      *(undefined1 *)(iVar1 + 0x54) = 0;
    }
    else {
      *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 8;
    }
    uac_mutex_give(g_wheel_timer_base);
    return;
  }
  return;
}

