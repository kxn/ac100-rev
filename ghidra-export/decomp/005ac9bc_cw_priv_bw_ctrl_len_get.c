// func cw_priv_bw_ctrl_len_get @ 005ac9bc size=160

uint cw_priv_bw_ctrl_len_get(char *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 == (char *)0x0) || (piVar1 = *(int **)(param_1 + 0xc), piVar1 == (int *)0x0)) {
    uVar3 = 0xffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d ctrl_val is null.\n","cw_priv_bw_ctrl_len_get",0x1d5);
    }
  }
  else {
    if (*param_1 == '\0') {
      iVar2 = *piVar1;
    }
    else {
      if (*param_1 != '\x04') {
        return 0xb;
      }
      iVar2 = *piVar1;
    }
    uVar3 = iVar2 * 6 + 0xdU & 0xffff;
  }
  return uVar3;
}

