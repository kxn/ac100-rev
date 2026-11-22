// func cw_80211_station_session_key_parse @ 00569284 size=440

undefined4 cw_80211_station_session_key_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x1c,0x6f);
  if (__s == (void *)0x0) {
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_station_session_key_parse",0x72);
    }
  }
  else {
    memset(__s,0,0x1c);
    cw_protocol_retrieve_bytes(param_1,__s,6);
    uVar2 = cw_protocol_retrieve16(param_1);
    *(short *)((int)__s + 6) = (short)uVar2;
    if ((uVar2 & 0xc000) == uVar2) {
      cw_protocol_retrieve_bytes(param_1,(int)__s + 8,6);
      cw_protocol_retrieve_bytes(param_1,(int)__s + 0xe,6);
      *(short *)((int)__s + 0x14) = *(short *)(param_2 + 0xe) + -0x14;
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1);
      *(int *)((int)__s + 0x18) = iVar3;
      if (iVar3 != 0) {
        *(void **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read key\n","cw_80211_station_session_key_parse",0x8c
              );
      }
    }
    else if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d flags(0x%04x) is wrong\n","cw_80211_station_session_key_parse",
             0x7e,(uint)*(ushort *)((int)__s + 6));
    }
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

