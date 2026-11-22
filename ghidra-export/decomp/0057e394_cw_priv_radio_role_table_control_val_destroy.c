// func cw_priv_radio_role_table_control_val_destroy @ 0057e394 size=188

undefined4 cw_priv_radio_role_table_control_val_destroy(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((capwap_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
    if (param_1 == (undefined1 *)0x0) goto LAB_0057e414;
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  else {
    printf("[CW_DEBUG]%32s():%4d enter cw_priv_radio_role_table_control_val_destroy\n",
           "cw_priv_radio_role_table_control_val_destroy",0x59);
    if (param_1 == (undefined1 *)0x0) {
LAB_0057e414:
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n",
             "cw_priv_radio_role_table_control_val_destroy",0x5c);
      return 0xffffffff;
    }
    uVar2 = *(undefined4 *)(param_1 + 4);
  }
  cw_priv_radio_role_table_control_tlv_ele_free(uVar2,*param_1);
  FUN_00407df0(param_1);
  return 0;
}

