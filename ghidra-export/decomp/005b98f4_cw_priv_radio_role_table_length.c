// func cw_priv_radio_role_table_length @ 005b98f4 size=212

uint cw_priv_radio_role_table_length(char *param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_length ENTER\n",
           "cw_priv_radio_role_table_length",0xa8);
  }
  uVar2 = 0;
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\0') {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_005b9884(param_1);
      uVar2 = iVar1 + 1;
    }
    uVar2 = uVar2 & 0xffff;
    if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_DEBUG]%32s():%4d len=%d\n","cw_priv_radio_role_table_length",0xb1,uVar2);
    }
  }
  return uVar2;
}

