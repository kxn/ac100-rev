// func cw_priv_radio_role_table_control_tlv_ele_free @ 0057e2d8 size=188

undefined4 cw_priv_radio_role_table_control_tlv_ele_free(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n",
             "cw_priv_radio_role_table_control_tlv_ele_free",0x1e1);
    }
  }
  else {
    iVar3 = 0;
    iVar2 = param_1;
    while (iVar3 < (int)(param_2 & 0xff)) {
      iVar3 = iVar3 + 1;
      if (*(int *)(iVar2 + 4) != 0) {
        FUN_00407df0();
      }
      iVar2 = iVar2 + 8;
    }
    uVar1 = 0;
    FUN_00407df0(param_1);
  }
  return uVar1;
}

