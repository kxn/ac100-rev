// func cw_80211_direct_sequence_control_len_get @ 005651f0 size=72

undefined4 cw_80211_direct_sequence_control_len_get(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 != 0) && (uVar1 = 0x13, (*(uint *)(param_1 + 8) & 0xff00ffff) == 0xff00ffff)) &&
     (*(int *)(param_1 + 0xc) == -1)) {
    if (*(int *)(param_1 + 0x10) == -1) {
      uVar1 = 8;
    }
    return uVar1;
  }
  return uVar1;
}

