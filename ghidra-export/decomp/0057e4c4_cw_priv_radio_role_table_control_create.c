// func cw_priv_radio_role_table_control_create @ 0057e4c4 size=628

int cw_priv_radio_role_table_control_create(byte *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (capwap_debug_switch == 0) {
    uVar5 = (uint)*param_1;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      uVar5 = (uint)*param_1;
    }
    else {
      printf("[CW_DEBUG]%32s():%4d enter cw_priv_radio_role_table_control_create\n",
             "cw_priv_radio_role_table_control_create",0x138);
      uVar5 = (uint)*param_1;
    }
  }
  if (1 < uVar5 - 1) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d Ele num(%d) is wrong\n","cw_priv_radio_role_table_control_create",
           0x141,uVar5);
    return 0;
  }
  puVar2 = (undefined1 *)cw_protocol_clone(param_1,8);
  if (puVar2 == (undefined1 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_radio_role_table_control_create",
           0x149);
    return 0;
  }
  *(undefined4 *)(puVar2 + 4) = 0;
  if (*(int *)(param_1 + 4) == 0) {
    if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0057e69c;
    __format = "[CW_ERROR]%32s():%4d tlv list is null\n";
    uVar3 = 0x150;
  }
  else {
    *puVar2 = (char)uVar5;
    iVar4 = 0;
    iVar1 = cw_protocol_clone(*(undefined4 *)(param_1 + 4),(uint)*param_1 << 3);
    *(int *)(puVar2 + 4) = iVar1;
    if (iVar1 != 0) {
      for (; iVar4 < (int)uVar5; iVar4 = iVar4 + 1) {
        iVar6 = *(int *)(puVar2 + 4);
        iVar1 = *(int *)(param_1 + 4) + iVar4 * 8;
        uVar3 = cw_protocol_clone(*(undefined4 *)(iVar1 + 4),*(undefined2 *)(iVar1 + 2));
        *(undefined4 *)(iVar6 + iVar4 * 8 + 4) = uVar3;
      }
      uVar3 = cw_priv_radio_role_table_control_length(puVar2);
      iVar1 = cw_protocol_msg_ele_create(0x90,uVar3,puVar2);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n",
               "cw_priv_radio_role_table_control_create",0x167);
      }
      cw_priv_radio_role_table_control_val_destroy(puVar2);
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0057e69c;
    __format = "[CW_ERROR]%32s():%4d failed to clone tlv list\n";
    uVar3 = 0x159;
  }
  printf(__format,"cw_priv_radio_role_table_control_create",uVar3);
LAB_0057e69c:
  FUN_00407df0(puVar2);
  return 0;
}

