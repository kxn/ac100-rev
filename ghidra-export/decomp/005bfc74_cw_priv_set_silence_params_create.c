// func cw_priv_set_silence_params_create @ 005bfc74 size=240

int cw_priv_set_silence_params_create(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined1 *)cw_protocol_clone(param_1,4);
  if (puVar1 == (undefined1 *)0x0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_set_silence_params_create",0xa6
            );
    }
  }
  else {
    *puVar1 = *param_1;
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 2);
    iVar2 = cw_protocol_msg_ele_create(0x9d,3,puVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n",
               "cw_priv_set_silence_params_create",0xb1);
      }
      FUN_00407df0(puVar1);
    }
  }
  return iVar2;
}

