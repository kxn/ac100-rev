// func cw_80211_station_session_key_assemble @ 00569138 size=332

undefined4 cw_80211_station_session_key_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar3,6);
  if ((*(ushort *)(iVar3 + 6) & 0xc000) == *(ushort *)(iVar3 + 6)) {
    cw_protocol_restore16(param_1);
    cw_protocol_restore_raw_bytes(param_1,iVar3 + 8,6);
    cw_protocol_restore_raw_bytes(param_1,iVar3 + 0xe,6);
    if ((*(ushort *)(param_2 + 0xe) - 0x14 == (uint)*(ushort *)(iVar3 + 0x14)) &&
       (*(int *)(iVar3 + 0x18) != 0)) {
      cw_protocol_restore_raw_bytes(param_1);
      uVar4 = 0xffffffff;
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to write key\n","cw_80211_station_session_key_assemble",
               0xb6);
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d flags(0x%o4x) is wrong\n","cw_80211_station_session_key_assemble"
             ,0xaa,(uint)*(ushort *)(iVar3 + 6));
    }
  }
  return uVar4;
}

