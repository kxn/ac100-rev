// func cw_priv_region_list_free @ 005ba7f8 size=152

undefined4 cw_priv_region_list_free(int param_1)

{
  int iVar1;
  
  if (capwap_debug_switch == 0) {
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d cw_priv_region_list_free ENTER\n","cw_priv_region_list_free",
             0x138);
      iVar1 = *(int *)(param_1 + 0x10);
    }
  }
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    FUN_00407df0(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

