// func cascade @ 005249c4 size=248

int cascade(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (wheel_timer_debug_switch != '\0') {
    printf("[WHEEL_TIMER_DEBUG]%s()/%d Do a cascade operation, index : %d\n","cascade",0x12f,param_2
          );
  }
  param_1 = param_1 + param_2 * 0xc;
  iVar1 = uac_list_first(param_1);
  while (iVar1 != 0) {
    iVar2 = uac_list_next(iVar1);
    uac_list_remove(iVar1);
    internal_add_timer(iVar1);
    iVar1 = iVar2;
  }
  uac_list_init(param_1);
  return param_2;
}

