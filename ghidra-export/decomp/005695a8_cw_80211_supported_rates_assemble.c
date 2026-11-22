// func cw_80211_supported_rates_assemble @ 005695a8 size=280

undefined4 cw_80211_supported_rates_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  
  pbVar3 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar3 < 0x20) {
    cw_protocol_restore8();
    if (*(ushort *)(param_2 + 0xe) - 1 == (uint)pbVar3[1]) {
      cw_protocol_restore_raw_bytes(param_1,pbVar3 + 2);
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to write supported rates\n",
               "cw_80211_supported_rates_assemble",0x98);
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_80211_supported_rates_assemble",0x90
             ,(uint)*pbVar3);
    }
  }
  return uVar4;
}

