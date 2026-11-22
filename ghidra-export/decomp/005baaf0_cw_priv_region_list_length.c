// func cw_priv_region_list_length @ 005baaf0 size=196

uint cw_priv_region_list_length(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_region_list_length ENTER\n","cw_priv_region_list_length",
           0x93);
  }
  uVar2 = 0;
  if (param_1 != 0) {
    iVar1 = _calculate_region_list_length(param_1);
    uVar2 = iVar1 + 1U & 0xffff;
    if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_DEBUG]%32s():%4d len=%d\n","cw_priv_region_list_length",0x9c,uVar2);
    }
  }
  return uVar2;
}

