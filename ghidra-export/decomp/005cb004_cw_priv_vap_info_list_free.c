// func cw_priv_vap_info_list_free @ 005cb004 size=112

undefined4 cw_priv_vap_info_list_free(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_priv_vap_info_list_free",0x198);
    }
  }
  else {
    uVar2 = 0;
    cw_priv_vap_info_list_destroy();
  }
  return uVar2;
}

