// func cw_80211_add_wlan_free @ 00563340 size=104

undefined4 cw_80211_add_wlan_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 8) == 0) {
      iVar1 = *(int *)(iVar2 + 0x1c);
    }
    else {
      FUN_00407df0();
      iVar1 = *(int *)(iVar2 + 0x1c);
    }
    if (iVar1 != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar2);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

