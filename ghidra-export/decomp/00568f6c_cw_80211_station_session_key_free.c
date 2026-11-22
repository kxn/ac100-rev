// func cw_80211_station_session_key_free @ 00568f6c size=84

undefined4 cw_80211_station_session_key_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x18) != 0) {
      FUN_00407df0();
    }
    FUN_00407df0(iVar1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

