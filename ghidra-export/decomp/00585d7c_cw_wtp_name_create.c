// func cw_wtp_name_create @ 00585d7c size=368

int cw_wtp_name_create(short *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  puVar1 = (undefined2 *)cw_protocol_clone(param_1,8);
  if (puVar1 == (undefined2 *)0x0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_wtp_name_create",0xb0);
    }
  }
  else {
    *(undefined4 *)(puVar1 + 2) = 0;
    if (*param_1 == 0) {
      uVar4 = *puVar1;
    }
    else if (*(int *)(param_1 + 2) == 0) {
      uVar4 = *puVar1;
    }
    else {
      iVar2 = cw_protocol_duplicate_string();
      *(int *)(puVar1 + 2) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone wtp name\n","cw_wtp_name_create",0xbb);
        }
        FUN_00407df0(puVar1);
        uVar4 = *puVar1;
      }
      else {
        uVar4 = *puVar1;
      }
    }
    iVar2 = cw_protocol_msg_ele_create(0x2d,uVar4,puVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(puVar1 + 2);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(puVar1 + 2);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_wtp_name_create",0xc4
                );
          iVar3 = *(int *)(puVar1 + 2);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(puVar1);
    }
  }
  return iVar2;
}

