// func cw_priv_radio_role_table_control_free @ 0057e450 size=116

undefined4 cw_priv_radio_role_table_control_free(int param_1)

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
      printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_control_free ENTER\n",
             "cw_priv_radio_role_table_control_free",0x17c);
      iVar1 = *(int *)(param_1 + 0x10);
    }
  }
  if (iVar1 != 0) {
    cw_priv_radio_role_table_control_val_destroy();
  }
  return 0;
}

