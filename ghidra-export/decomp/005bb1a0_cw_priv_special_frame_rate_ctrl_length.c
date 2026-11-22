// func cw_priv_special_frame_rate_ctrl_length @ 005bb1a0 size=28

int cw_priv_special_frame_rate_ctrl_length(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = (*(byte *)(param_1 + 2) + 1) * 4;
  }
  return iVar1;
}

