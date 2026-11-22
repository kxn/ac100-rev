// func cw_priv_bw_ctrl_free @ 005ac3a4 size=88

undefined4 cw_priv_bw_ctrl_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

