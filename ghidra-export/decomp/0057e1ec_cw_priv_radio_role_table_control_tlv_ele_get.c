// func cw_priv_radio_role_table_control_tlv_ele_get @ 0057e1ec size=236

undefined4 cw_priv_radio_role_table_control_tlv_ele_get(byte *param_1,ushort param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_control_tlv_ele_get enter\n",
           "cw_priv_radio_role_table_control_tlv_ele_get",0x1c1);
  }
  if ((param_1 == (byte *)0x0) || (1 < param_2)) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d val is null or tlv msg element type is illegal!\n",
             "cw_priv_radio_role_table_control_tlv_ele_get",0x1c6);
    }
  }
  else {
    for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
      if (*(int *)(param_1 + 4) == 0) {
        return 0;
      }
      pbVar2 = (byte *)(*(int *)(param_1 + 4) + iVar1 * 8);
      if (*pbVar2 == param_2) {
        return *(undefined4 *)(pbVar2 + 4);
      }
    }
  }
  return 0;
}

