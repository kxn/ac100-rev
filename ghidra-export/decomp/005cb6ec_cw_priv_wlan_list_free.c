// func cw_priv_wlan_list_free @ 005cb6ec size=84

undefined4 cw_priv_wlan_list_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

