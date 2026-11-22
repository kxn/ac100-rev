// func cw_80211_station_qos_parse @ 00568c8c size=228

undefined4 cw_80211_station_qos_parse(int param_1,int param_2)

{
  ushort uVar1;
  void *__s;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(8,0x67);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_station_qos_parse",0x6a);
    }
  }
  else {
    memset(__s,0,8);
    cw_protocol_retrieve_bytes(param_1,__s,6);
    cw_protocol_restore16(param_1,*(undefined2 *)((int)__s + 6));
    *(void **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

