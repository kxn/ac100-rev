// func cw_priv_radio_role_table_control_length @ 0057dcd0 size=152

short cw_priv_radio_role_table_control_length(byte *param_1)

{
  short sVar1;
  int iVar2;
  
  if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_control_length ENTER\n",
           "cw_priv_radio_role_table_control_length",0x68);
  }
  sVar1 = 0;
  if (param_1 != (byte *)0x0) {
    sVar1 = 1;
    for (iVar2 = 0; iVar2 < (int)(uint)*param_1; iVar2 = iVar2 + 1) {
      sVar1 = *(short *)(*(int *)(param_1 + 4) + iVar2 * 8 + 2) + 3 + sVar1;
    }
  }
  return sVar1;
}

