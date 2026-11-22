// func cw_priv_lag_config_free @ 005b4348 size=76

undefined4 cw_priv_lag_config_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00407df0();
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    FUN_00407df0(iVar1);
  }
  return 0;
}

